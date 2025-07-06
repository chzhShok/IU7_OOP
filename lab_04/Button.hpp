#pragma once

#include <QPushButton>

class Button : public QPushButton {
    Q_OBJECT;

    using ButtonState = enum {
        ACTIVE,
        INACTIVE
    };

public:
    explicit Button(QWidget *parent = nullptr);
    ~Button() override = default;

    void setFloor(int floor);
    void highlightCurrentFloor(bool is_current);

signals:
    void pressSignal(bool, int);
    void unpressSignal();

public slots:
    void pressSlot();
    void unpressSlot();

private:
    ButtonState _state;
    size_t _currentButtonFloor;
};
