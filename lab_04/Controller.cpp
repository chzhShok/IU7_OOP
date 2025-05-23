#include "Controller.hpp"

Controller::Controller(QWidget *parent) : QWidget(parent) {
    _layout = std::make_unique<QVBoxLayout>();
    setLayout(this->_layout.get());

    auto new_button = std::make_shared<Button>();
    new_button->setDisabled(true);
    new_button->setStyleSheet("background-color:blue; color:white");
    new_button->setFloor(FLOORS + 1);
    new_button->setText("Floor buttons");

    this->_buttons_floor.insert(this->_buttons_floor.begin(), new_button);
    _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

    for (size_t i = 0; i < FLOORS; i++) {
        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));
        new_button->setStyleSheet(QString("background-color:") + COLORBUTTONINACTIVE + QString("; color:") + COLORTEXTBUTTONINACTIVE);

        _buttons_floor.insert(_buttons_floor.begin(), new_button);
        _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        _is_visit.push_back(false);

        QObject::connect(new_button.get(), &Button::pressSignal, this, &Controller::newTarget);
    }

    auto lift_button = std::make_shared<Button>();
    lift_button->setDisabled(true);
    lift_button->setStyleSheet("background-color:blue; color:white");
    lift_button->setFloor(2 * FLOORS + 2);
    lift_button->setText("Lift buttons");

    this->_buttons_lift.insert(_buttons_lift.begin(), lift_button);
    _layout->addWidget(dynamic_cast<QPushButton *>(lift_button.get()));


    for (size_t i = 0; i < FLOORS; i++) {
        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));
        new_button->setStyleSheet(QString("background-color:") + COLORBUTTONINACTIVE + QString("; color:") + COLORTEXTBUTTONINACTIVE);

        _buttons_lift.insert(_buttons_lift.begin(), new_button);
        _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        _is_visit.push_back(false);

        QObject::connect(new_button.get(), &Button::pressSignal, this, &Controller::newTarget);
    }

    QObject::connect(this, &Controller::reachFloorSignal, this, &Controller::reachFloor);
}

void Controller::newTarget(bool got_new, int floor) {
    _state = BUSY;
    if (got_new) {
        _is_visit[floor - 1] = true;

        _identifyNewTarget(floor);
        _targetFloor = floor;
        _decideDirection();
        if (_direction == STAY)
            emit reachFloorSignal();
        else
            emit moveCabinSignal();
    } else if (_identifyNewTarget(floor)) {
        _targetFloor = floor;
        _decideDirection();

        if (_direction != STAY) {
            _updateFloor();
            emit moveCabinSignal();
        } else {
            emit reachFloorSignal();
        }
    }
}

void Controller::_decideDirection() {
    if (_targetFloor > _curFloor) {
        _direction = UP;
    } else if (_targetFloor < _curFloor) {
        _direction = DOWN;
    } else {
        _last_direction = _direction;
        _direction = STAY;
    }
}

bool Controller::_identifyNewTarget(int &new_target) {
    bool rc = false;

    Direction dir;

    if (_direction != STAY)
        dir = _direction;
    else
        dir = (_last_direction == STAY) ? UP : _last_direction;

    for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i += dir)
        if (_is_visit[i - 1]) {
            new_target = i;
            rc = true;
        }

    if (!rc) {
        dir = ((dir == UP) ? DOWN : UP);

        for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i += dir) {
            if (_is_visit[i - 1]) {
                new_target = i;
                rc = true;
            }
        }
    }

    return rc;
}

void Controller::reachFloor() {
    if (_state != BUSY)
        return;

    qDebug() << "[^] Лифт приехал на этаж № " << _targetFloor;

    emit _buttons_floor[_targetFloor - 1]->unpressSignal();
    emit _buttons_lift[_targetFloor - 1]->unpressSignal();

    _is_visit[_targetFloor - 1] = false;

    emit stopCabinSignal();

    if (!_identifyNewTarget(_targetFloor))
        _state = FREE;
}

void Controller::_updateFloor() {
    _curFloor += _direction;

    qDebug() << "[...] Лифт едет на этаж № " << _curFloor;
}
