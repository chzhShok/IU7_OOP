#include <QDebug>

#include "Button.hpp"
#include "Config.hpp"

Button::Button(QWidget *parent) : QPushButton(parent) {
    QObject::connect(this, &Button::clicked, this, &Button::pressSlot);
    QObject::connect(this, &Button::unpressSignal, this, &Button::unpressSlot);

    _state = INACTIVE;
    _currentButtonFloor = START_FLOOR;
}

void Button::setFloor(int floor) {
    _currentButtonFloor = floor;
}

void Button::pressSlot() {
    if (_state == ACTIVE)
        return;

    setStyleSheet(QString("background-color:") + COLORBUTTONACTIVE + QString("; color:") + COLORTEXTBUTTONINACTIVE);
    update();

    qDebug() << "[!] Вызов на этаж №" << _currentButtonFloor;

    _state = ACTIVE;
    setDisabled(true);

    emit pressSignal(true, _currentButtonFloor);
}

void Button::unpressSlot() {
    if (_state == INACTIVE) return;

    setStyleSheet("background-color: gray; color: black");
    update();

    _state = INACTIVE;
    setDisabled(false);
}

void Button::highlightCurrentFloor(bool is_current) {
    if (is_current)
        setStyleSheet("background-color: gray; color: black");
    else if (_state == INACTIVE)
        setStyleSheet(QString("background-color:") + COLORBUTTONINACTIVE + QString("; color:") + COLORTEXTBUTTONINACTIVE);

    update();
}
