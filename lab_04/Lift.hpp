#pragma once

#include <QObject>

#include "Cabin.hpp"
#include "Controller.hpp"

class Lift : public QObject {
    Q_OBJECT

public:
    explicit Lift(QObject *parent = nullptr);
    ~Lift() = default;

    QWidget *widget();

private:
    Controller _controller;
    Cabin _cabin;
};
