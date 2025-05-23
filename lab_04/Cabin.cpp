#include <QDebug>

#include "Cabin.hpp"
#include "Config.hpp"

Cabin::Cabin(QObject *parent) : QObject(parent) {
    _state = STOP;

    QObject::connect(this, &Cabin::openDoors, &_doors, &Doors::startOpening);
    QObject::connect(&_moveTimer, &QTimer::timeout, this, &Cabin::freeCabin);
    QObject::connect(&_doors, &Doors::doorClosed, this, &Cabin::freeCabin);
}

void Cabin::stopCabin() {
    _state = WAIT;
    _moveTimer.stop();
    emit openDoors();
}

void Cabin::moveCabin() {
    if (_state != WAIT) {
        _state = MOVING;
        _moveTimer.start(MOVE_TIME);
    }
}

void Cabin::freeCabin() {
    if (_state == STOP)
        return;

    _state = STOP;
    emit cabinFinished(false);
}
