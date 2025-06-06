#include "DrawVisitor.hpp"
#include "Camera.hpp"
#include "CameraProjectionAction.hpp"
#include "CarcassModel.hpp"
#include "Composite.hpp"
#include "FaceBuilder.hpp"

#define FOCUS 500.0
#define R (1 / FOCUS)

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera) : _drawer(drawer), _camera(camera) {}

Vertex DrawVisitor::getCameraProjection(const Vertex &point) const {
    CameraProjectionAction action(_camera);
    Vertex copy(point);
    action.transformVertex(copy);
    return copy;
}

Vector3 DrawVisitor::getCameraPosition() const {
    return Vector3(_camera->_self);
}

Vector3 DrawVisitor::calculateFaceNormal(const Vertex &p1, const Vertex &p2, const Vertex &p3) const {
    Vector3 v1(p1);
    Vector3 v2(p2);
    Vector3 v3(p3);

    Vector3 edge1 = v2 - v1;
    Vector3 edge2 = v3 - v1;

    return edge1.cross(edge2).normalize();
}

Vertex DrawVisitor::calculateModelCenter(const std::vector<Vertex> &points) const {
    if (points.empty()) return Vertex();

    double centerX = 0, centerY = 0, centerZ = 0;
    for (const auto &point: points) {
        centerX += point.getX();
        centerY += point.getY();
        centerZ += point.getZ();
    }

    size_t count = points.size();
    return Vertex(centerX / count, centerY / count, centerZ / count);
}

bool DrawVisitor::isFaceVisible(const std::vector<Vertex> &points, const Face &face, const Vector3 &cameraPos) const {
    if (face.size() < 3)
        return false;

    auto it = face.begin();
    int v1 = *it;
    ++it;
    int v2 = *it;
    ++it;
    int v3 = *it;

    if (static_cast<size_t>(v1) >= points.size() || static_cast<size_t>(v2) >= points.size() || static_cast<size_t>(v3) >= points.size())
        return false;

    Vertex p1(points[v1]);
    Vertex p2(points[v2]);
    Vertex p3(points[v3]);

    Vector3 normal = calculateFaceNormal(p1, p2, p3);
    Vector3 faceCenter = Vector3((p1.getX() + p2.getX() + p3.getX()) / 3.0,
                                 (p1.getY() + p2.getY() + p3.getY()) / 3.0,
                                 (p1.getZ() + p2.getZ() + p3.getZ()) / 3.0);

    Vector3 modelCenter = Vector3(calculateModelCenter(points));
    Vector3 toFace = faceCenter - modelCenter;

    if (normal.dot(toFace) < 0)
        normal = normal * -1;

    Vector3 cameraVec = cameraPos - faceCenter;
    return normal.dot(cameraVec) > 0;
}

void DrawVisitor::visit(CarcassModel &model) const {
    auto points = model._model->getVertices();
    auto edges = model._model->getEdges();
    auto faces = model._model->getFaces();

    if (faces.empty() && !edges.empty())
        faces = FaceBuilder::buildFacesFromEdges(points, edges);

    Vector3 cameraPos = getCameraPosition();

    if (_edgesVisibilityEnabled && !faces.empty()) {
        for (const auto &face: faces) {
            if (isFaceVisible(points, face, cameraPos)) {
                for (auto it1 = face.begin(); it1 != face.end(); ++it1) {
                    for (auto it2 = face.begin(); it2 != face.end(); ++it2) {
                        if (it1 == it2) continue;

                        bool isEdge = false;
                        for (const auto &edge: edges) {
                            if ((edge.getFirst() == static_cast<size_t>(*it1) && edge.getSecond() == static_cast<size_t>(*it2)) ||
                                (edge.getFirst() == static_cast<size_t>(*it2) && edge.getSecond() == static_cast<size_t>(*it1))) {
                                isEdge = true;
                                break;
                            }
                        }

                        if (isEdge) {
                            Vertex p1(points[*it1]);
                            Vertex p2(points[*it2]);
                            Vertex proj1 = getCameraProjection(p1);
                            Vertex proj2 = getCameraProjection(p2);

                            proj1.setX(proj1.getX() * (1 / (R * proj1.getZ())));
                            proj1.setY(proj1.getY() * (1 / (R * proj1.getZ())));

                            proj2.setX(proj2.getX() * (1 / (R * proj2.getZ())));
                            proj2.setY(proj2.getY() * (1 / (R * proj2.getZ())));

                            if (proj1.getZ() > 0 && proj2.getZ() > 0) {
                                _drawer->drawLine(proj1, proj2);
                            }
                        }
                    }
                }
            }
        }
    } else {
        for (auto &edge: edges) {
            Vertex &p1 = points[edge.getFirst()];
            Vertex &p2 = points[edge.getSecond()];
            Vertex proj1(getCameraProjection(p1));
            Vertex proj2(getCameraProjection(p2));

            proj1.setX(proj1.getX() * (1 / (R * proj1.getZ())));
            proj1.setY(proj1.getY() * (1 / (R * proj1.getZ())));

            proj2.setX(proj2.getX() * (1 / (R * proj2.getZ())));
            proj2.setY(proj2.getY() * (1 / (R * proj2.getZ())));

            if (proj1.getZ() > 0 && proj2.getZ() > 0)
                _drawer->drawLine(proj1, proj2);
        }
    }
}

void DrawVisitor::visit(Camera &camera) const {
    (void) camera;
}

void DrawVisitor::visit(Composite &composite) const {
    for (auto &child: composite)
        child->accept(*this);
}
