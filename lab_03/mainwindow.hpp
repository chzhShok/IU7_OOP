#pragma once

#include <QDateTime>
#include <QMainWindow>

#include "Facade.hpp"
#include "ui_mainwindow.h"

class MyMainWindow : public QMainWindow {
public:
    MyMainWindow(QWidget *parent = 0);
    virtual ~MyMainWindow();

private:
    void connectButtons();
    Ui::MainWindow *ui;
    Facade _facade;
private slots:
    void on_loadButton_clicked();
    void on_cameraAddPushbutton_clicked();
    void on_cameraDeletePushbutton_clicked();
    void on_cameraSetPushbutton_clicked();
    void on_objectMovePushbutton_clicked();
    void on_objectRotatePushbutton_clicked();
    void on_objectScalePushbutton_clicked();
    void on_objectDeletePushbutton_clicked();
    void on_objectCompositePushbutton_clicked();
    void on_undoButton_clicked();
    void on_swapEdgesVisibilityButton_clicked();
    void logError(const QString &message);
    void logMessage(const QString &message);

private:
    void drawScene();
    void updateCameraList();
    void updateObjectList();
    std::vector<size_t> getSelectedObjectIds();
    std::vector<size_t> getSelectedCameraIds();
};
