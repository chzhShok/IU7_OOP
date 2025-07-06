#include "Controller.hpp"

Controller::Controller(QWidget *parent) : QWidget(parent) {
    setupLayout();
    createFloorButtonsSection();
    createLiftButtonsSection();
    setupInitialFloorHighlight();

    QObject::connect(this, &Controller::reachFloorSignal, this, &Controller::reachFloor);
}

void Controller::setupLayout() {
    _layout = std::make_unique<QVBoxLayout>();
    setLayout(_layout.get());
}

void Controller::createFloorButtonsSection() {
    addSectionHeader("Floor buttons", FLOORS + 1, _buttons_floor);

    for (size_t i = 0; i < FLOORS; i++) {
        int floor_number = FLOORS - i;
        auto button = createFloorButton(floor_number);
        _buttons_floor.insert(_buttons_floor.begin(), button);
        _is_visit.push_back(false);
    }
}

void Controller::createLiftButtonsSection() {
    addSectionHeader("Lift buttons", 2 * FLOORS + 2, _buttons_lift);

    for (size_t i = 0; i < FLOORS; i++) {
        int floor_number = FLOORS - i;
        auto button = createFloorButton(floor_number);
        _buttons_lift.insert(_buttons_lift.begin(), button);
    }
}

void Controller::addSectionHeader(const QString &text, int floor, std::vector<std::shared_ptr<Button>> &buttons) {
    auto header_button = std::make_shared<Button>();
    header_button->setDisabled(true);
    header_button->setStyleSheet("background-color:blue; color:white");
    header_button->setFloor(floor);
    header_button->setText(text);

    buttons.insert(buttons.begin(), header_button);
    _layout->addWidget(dynamic_cast<QPushButton *>(header_button.get()));
}

std::shared_ptr<Button> Controller::createFloorButton(int floor_number) {
    auto button = std::make_shared<Button>();
    button->setFloor(floor_number);
    button->setText(QString::number(floor_number));
    button->setStyleSheet(QString("background-color:") + COLORBUTTONINACTIVE + QString("; color:") + COLORTEXTBUTTONINACTIVE);

    _layout->addWidget(dynamic_cast<QPushButton *>(button.get()));
    QObject::connect(button.get(), &Button::pressSignal, this, &Controller::decideTarget);

    return button;
}

void Controller::setupInitialFloorHighlight() {
    if (START_FLOOR > 0 && START_FLOOR <= FLOORS) {
        _buttons_floor[START_FLOOR - 1]->highlightCurrentFloor(true);
        _buttons_lift[START_FLOOR - 1]->highlightCurrentFloor(true);
    }
}

void Controller::decideTarget(bool is_new_press, int floor) {
    _state = BUSY;

    if (is_new_press)
        _handleNewButtonPress(floor);
    else
        _handleNextTarget();
}

void Controller::_handleNewButtonPress(int floor) {
    _is_visit[floor - 1] = true;

    _identifyNewTarget(floor);
    _targetFloor = floor;

    _decideDirection();

    emit(_direction == STAY) ? reachFloorSignal() : moveCabinSignal();
}

void Controller::_handleNextTarget() {
    int next_floor;
    if (!_identifyNewTarget(next_floor))
        return;

    _targetFloor = next_floor;
    _decideDirection();

    if (_direction != STAY) {
        _updateFloor();
        emit moveCabinSignal();
    } else {
        emit reachFloorSignal();
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

    if (_curFloor > 0 && _curFloor <= FLOORS) {
        _buttons_floor[_curFloor - 1]->highlightCurrentFloor(false);
        _buttons_lift[_curFloor - 1]->highlightCurrentFloor(false);
    }

    _curFloor = _targetFloor;

    if (_curFloor > 0 && _curFloor <= FLOORS) {
        _buttons_floor[_curFloor - 1]->highlightCurrentFloor(true);
        _buttons_lift[_curFloor - 1]->highlightCurrentFloor(true);
    }

    emit _buttons_floor[_targetFloor - 1]->unpressSignal();
    emit _buttons_lift[_targetFloor - 1]->unpressSignal();

    _is_visit[_targetFloor - 1] = false;

    emit stopCabinSignal();

    if (!_identifyNewTarget(_targetFloor))
        _state = FREE;
}

void Controller::_updateFloor() {
    if (_curFloor > 0 && _curFloor <= FLOORS) {
        _buttons_floor[_curFloor - 1]->highlightCurrentFloor(false);
        _buttons_lift[_curFloor - 1]->highlightCurrentFloor(false);
    }

    _curFloor += _direction;
    qDebug() << "[...] Лифт едет на этаж № " << _curFloor;

    if (_curFloor > 0 && _curFloor <= FLOORS) {
        _buttons_floor[_curFloor - 1]->highlightCurrentFloor(true);
        _buttons_lift[_curFloor - 1]->highlightCurrentFloor(true);
    }
}
