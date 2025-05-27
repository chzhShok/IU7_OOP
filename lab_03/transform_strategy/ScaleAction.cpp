#include "ScaleAction.hpp"
#include "MoveAction.hpp"

ScaleAction::ScaleAction(double mx, double my, double mz) {
    _matrix[0][0] = mx;
    _matrix[1][1] = my;
    _matrix[2][2] = mz;
}

ScaleAction::ScaleAction(double m) {
    _matrix[0][0] = m;
    _matrix[1][1] = m;
    _matrix[2][2] = m;
}

ScaleAction::ScaleAction(const Vertex &center, double mx, double my, double mz) {
    MoveAction toCenter(Vertex(-center.getX(), -center.getY(), -center.getZ()));
    _matrix *= toCenter.getMatrix();
    ScaleAction scale(mx, my, mz);
    _matrix *= scale.getMatrix();
    MoveAction fromCenter(center);
    _matrix *= fromCenter.getMatrix();
}

ScaleAction::ScaleAction(const Vertex &center, double m) {
    MoveAction toCenter(Vertex(-center.getX(), -center.getY(), -center.getZ()));
    _matrix *= toCenter.getMatrix();
    ScaleAction scale(m);
    _matrix *= scale.getMatrix();
    MoveAction fromCenter(center);
    _matrix *= fromCenter.getMatrix();
}