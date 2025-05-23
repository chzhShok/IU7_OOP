#pragma once

#include <QObject>
#include <QTimer>

class Doors : public QObject {
    Q_OBJECT

    using doorsState = enum {
        OPEN,
        CLOSED,
        OPENING,
        CLOSING
    };

public:
    Doors();
    ~Doors() override = default;

signals:
    void doorClosed();

public slots:
    void startClosing();
    void startOpening();
    void open();
    void close();

private:
    doorsState _state;

    QTimer _openTimer;
    QTimer _closeTimer;
    QTimer _waitTimer;
};
