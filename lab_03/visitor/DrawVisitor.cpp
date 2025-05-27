#include "DrawVisitor.hpp"
#include "Camera.hpp"
#include "CameraProjectionAction.hpp"
#include "CarcassModel.hpp"
#include "Composite.hpp"

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera) : _drawer(drawer), _camera(camera) {}

Vertex DrawVisitor::getCameraProjection(const Vertex &point) const {
    CameraProjectionAction action(_camera);
    Vertex copy(point);
    action.transformPoint(copy);
    return copy;
}

#define FOCUS 500.0
#define R (1 / FOCUS)

void DrawVisitor::visit(CarcassModel &model) const {
    auto vertices = model._model->getVertices();
    auto edges = model._model->getEdges();

    for (auto &edge: edges) {
        Vertex &v1 = vertices[edge.getFirst()];
        Vertex &v2 = vertices[edge.getSecond()];
        Vertex proj1(getCameraProjection(v1));
        Vertex proj2(getCameraProjection(v2));

        proj1.setX(proj1.getX() * (1 / (R * proj1.getZ())));
        proj1.setY(proj1.getY() * (1 / (R * proj1.getZ())));

        proj2.setX(proj2.getX() * (1 / (R * proj2.getZ())));
        proj2.setY(proj2.getY() * (1 / (R * proj2.getZ())));

        if (proj1.getZ() > 0 && proj2.getZ() > 0)
            _drawer->drawLine(proj1, proj2);
    }
}

void DrawVisitor::visit(Camera &camera) const {
    (void) camera;
}
