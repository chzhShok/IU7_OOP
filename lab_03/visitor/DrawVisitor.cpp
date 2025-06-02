#include <iostream>

#include "DrawVisitor.hpp"

constexpr double FOCUS = 300.0;

DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<Camera> camera) : __drawer(drawer), __camera(camera) {}

Vertex DrawVisitor::getCameraProjection(const Vertex &point) const {
    CameraProjectionAction action(__camera);
    Vertex copy(point);

    action.transformVertex(copy);

    return copy;
}

void DrawVisitor::visit(CarcassModel &model) const {
    auto rawVertices = model._model->getVertices();
    auto edges = model._model->getEdges();
    auto M = model.getTransformMatrix();
    std::vector<Vertex> vertices;

    vertices.reserve(rawVertices.size());
    for (auto &p: rawVertices) {
        std::vector<double> v = {p.getX(), p.getY(), p.getZ(), 1.0};
        auto r = M.multiplyLeft(v);
        vertices.emplace_back(r[0], r[1], r[2]);
    }

    for (auto &edge: edges) {
        const Vertex &p1 = vertices[edge.getFirst()];
        const Vertex &p2 = vertices[edge.getSecond()];

        Vertex proj1(getCameraProjection(p1));
        Vertex proj2(getCameraProjection(p2));

        double z1 = proj1.getZ();
        proj1.setX(FOCUS * proj1.getX() / (FOCUS + z1));
        proj1.setY(FOCUS * proj1.getY() / (FOCUS + z1));

        double z2 = proj2.getZ();
        proj2.setX(FOCUS * proj2.getX() / (FOCUS + z2));
        proj2.setY(FOCUS * proj2.getY() / (FOCUS + z2));

        if (proj1.getZ() > 0 && proj2.getZ() > 0)
            __drawer->drawLine(proj1, proj2);
    }
}

void DrawVisitor::visit(Camera &camera) const {
    (void) camera;
}

void DrawVisitor::visit(Composite &composite) const {
    for (auto &child: composite)
        child->accept(*this);
}
