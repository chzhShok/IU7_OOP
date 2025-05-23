#include "Lift.hpp"

Lift::Lift(QObject *parent) : QObject(parent) {
    _controller.setStyleSheet("background-color:green");

    QObject::connect(&_cabin, &Cabin::cabinFinished, &_controller, &Controller::decideTarget);
    QObject::connect(&_controller, &Controller::moveCabinSignal, &_cabin, &Cabin::moveCabin);
    QObject::connect(&_controller, &Controller::stopCabinSignal, &_cabin, &Cabin::stopCabin);
}

QWidget *Lift::widget() {
    return &_controller;
}
