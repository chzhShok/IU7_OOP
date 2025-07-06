#pragma once

#include <QDebug>
#include <QVBoxLayout>
#include <QWidget>
#include <memory>
#include <vector>

#include "Button.hpp"
#include "Config.hpp"

class Controller : public QWidget {
    Q_OBJECT

    using ControllerState = enum {
        FREE,
        BUSY
    };

    enum Direction {
        DOWN = -1,
        STAY = 0,
        UP = 1
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() override = default;

signals:
    void stopCabinSignal();
    void moveCabinSignal();
    void reachFloorSignal();

public slots:
    void decideTarget(bool, int = 1);
    void reachFloor();

private:
    void setupLayout();
    void createFloorButtonsSection();
    void createLiftButtonsSection();
    void addSectionHeader(const QString &text, int floor, std::vector<std::shared_ptr<Button>> &buttons);
    std::shared_ptr<Button> createFloorButton(int floor_number);
    void setupInitialFloorHighlight();

    void _handleNewButtonPress(int floor);
    void _handleNextTarget();

    bool _identifyNewTarget(int &new_target);
    void _decideDirection();
    void _updateFloor();

    int _curFloor = START_FLOOR;
    int _targetFloor = START_FLOOR;

    Direction _last_direction = STAY;
    Direction _direction = STAY;

    ControllerState _state = FREE;
    std::vector<bool> _is_visit;

    std::vector<std::shared_ptr<Button>> _buttons_floor;
    std::vector<std::shared_ptr<Button>> _buttons_lift;
    std::unique_ptr<QVBoxLayout> _layout;
};
