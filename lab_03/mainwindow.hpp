#pragma once

#include <QMainWindow>

#include "Facade.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow {
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

private:
    void connectButtons();
    Ui::MainWindow *ui;
    Facade _facade;
private slots:
    void on_loadButton_clicked();
    void on_addCameraButton_clicked();
    void on_setCameraButton_clicked();
    void on_moveButton_clicked();
    void on_rotateButton_clicked();
    void on_scaleButton_clicked();
    void on_deleteSelectedButton_clicked();
    void on_objectsCompositeButton_clicked();


private:
    void drawScene();
    void updateCameraList();
    void updateObjectList();
    std::vector<size_t> getSelectedObjectIds();
    std::vector<size_t> getSelectedCameraIds();
};
