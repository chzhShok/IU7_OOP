#include "Doors.hpp"
#include "Config.hpp"
#include <QDebug>

Doors::Doors() : _state(CLOSED) {
    QObject::connect(&_openTimer, &QTimer::timeout, this, &Doors::open);
    QObject::connect(&_waitTimer, &QTimer::timeout, this, &Doors::startClosing);
    QObject::connect(&_closeTimer, &QTimer::timeout, this, &Doors::close);
}

void Doors::startOpening() {
    if (_state != CLOSED)
        return;

    _state = OPENING;
    qDebug() << "Двери открываются";
    _openTimer.start(DOOR_TIME);
}

void Doors::open() {
    if (_state != OPENING)
        return;

    _state = OPEN;
    qDebug() << "[!] Двери открыты!";
    _waitTimer.start(WAIT_TIME);
}

void Doors::startClosing() {
    if (_state != OPEN)
        return;

    _state = CLOSING;
    qDebug() << "Двери закрываются";
    _closeTimer.start(DOOR_TIME);
}

void Doors::close() {
    if (_state != CLOSING)
        return;

    _state = CLOSED;
    qDebug() << "[!] Двери закрылись!";
    emit doorClosed();
}
