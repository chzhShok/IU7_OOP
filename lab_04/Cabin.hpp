#pragma once

#include <QObject>
#include <QTimer>

#include "Doors.hpp"

class Cabin : public QObject {
    Q_OBJECT

    using cabinState = enum {
        WAIT,
        MOVING,
        STOP
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() override = default;

signals:
    void openDoors();
    void cabinFinished(bool, int = 1);

public slots:
    void stopCabin();
    void moveCabin();
    void free();

private:
    cabinState _state;
    Doors _doors;
    QTimer _moveTimer;
};
