#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <cmath>

#include "AddCameraCommand.hpp"
#include "CompositeObjectCommand.hpp"
#include "CsvLoadCommandDecorator.hpp"
#include "DeleteObjectCommand.hpp"
#include "DrawSceneQtCommand.hpp"
#include "Exception.hpp"
#include "GetCameraIDsSceneCommand.hpp"
#include "GetObjectIDsSceneCommand.hpp"
#include "ListLoadCommand.hpp"
#include "MatrixLoadCommand.hpp"
#include "MoveObjectCommand.hpp"
#include "RemoveCameraCommand.hpp"
#include "RotateObjectCommand.hpp"
#include "ScaleObjectCommand.hpp"
#include "SetCameraCommand.hpp"
#include "TxtLoadCommandDecorator.hpp"
#include "Vertex.hpp"

double degToRad(double angle) {
    return angle / 180.0 * M_PI;
}

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->canvas->setScene(new QGraphicsScene);
    ui->canvas->scene()->setSceneRect(ui->canvas->sceneRect());
    ui->canvas->setBackgroundBrush(Qt::white);

    ui->structureComboBox->addItem("Список", 0);
    ui->structureComboBox->addItem("Матрица", 1);
    ui->objectsList->setSelectionMode(QAbstractItemView::MultiSelection);
}

MyMainWindow::~MyMainWindow() {
    delete ui;
}

bool endsWith(const std::string &str, const std::string &suffix) {
    if (str.length() >= suffix.length())
        return (0 == str.compare(str.length() - suffix.length(), suffix.length(), suffix));
    else
        return false;
}

//TODO
void MyMainWindow::on_loadButton_clicked() {
    std::string fileName = ui->filePath->text().toStdString();

    std::shared_ptr<BaseLoadCommand> command;

    if (ui->structureComboBox->currentText() == "Список")
        command = std::make_shared<ListLoadCommand>();
    else
        command = std::make_shared<MatrixLoadCommand>();

    std::shared_ptr<BaseCommand> decorator;
    if (endsWith(fileName, ".csv"))
        decorator = std::make_shared<CsvLoadCommandDecorator>(*command, fileName);
    else
        decorator = std::make_shared<TxtLoadCommandDecorator>(*command, fileName);

    try {
        _facade.execute(*decorator);
    } catch (BaseException &exc) {
        QMessageBox::critical(nullptr, "Ошибка", exc.what());
        return;
    }

    drawScene();
    updateObjectList();
}

//TODO
void MyMainWindow::on_addCameraButton_clicked() {
    double x = ui->xCameraSpin->value();
    double y = ui->yCameraSpin->value();
    double z = ui->zCameraSpin->value();

    Vertex pos(x, y, z);
    AddCameraCommand command(pos);

    _facade.execute(command);

    updateCameraList();
    updateObjectList();
}

//TODO
void MyMainWindow::on_setCameraButton_clicked() {
    auto cams = getSelectedCameraIds();
    if (cams.size() != 1) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать ровно одну камеру.");
        return;
    }

    SetCameraCommand command(cams[0]);
    _facade.execute(command);
    drawScene();
}

void MyMainWindow::updateCameraList() {
    ui->cameraList->clear();

    GetCameraIDsSceneCommand ids;

    _facade.execute(ids);
    std::vector<size_t> cameraIds = ids.getIDs();

    for (size_t id: cameraIds)
        ui->cameraList->addItem(QString::number(id));
}

void MyMainWindow::updateObjectList() {
    ui->objectsList->clear();

    GetObjectIDsSceneCommand ids;

    _facade.execute(ids);
    std::vector<size_t> objectIds = ids.getIDs();

    for (size_t id: objectIds)
        ui->objectsList->addItem(QString::number(id));
}

//TODO
std::vector<size_t> MyMainWindow::getSelectedObjectIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->objectsList->count(); i++) {
        if (ui->objectsList->item(i)->isSelected()) {
            ids.push_back(ui->objectsList->item(i)->text().toInt());
        }
    }
    return ids;
}

//TODO
std::vector<size_t> MyMainWindow::getSelectedCameraIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->cameraList->count(); i++) {
        if (ui->cameraList->item(i)->isSelected()) {
            ids.push_back(ui->cameraList->item(i)->text().toInt());
        }
    }
    return ids;
}

//TODO
void MyMainWindow::drawScene() {
    ui->canvas->scene()->clear();
    ui->canvas->scene()->setSceneRect(ui->canvas->sceneRect());
    DrawSceneQtCommand drawcommand(ui->canvas->scene());
    _facade.execute(drawcommand);
}

//TODO
void MyMainWindow::on_moveButton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->xMoveSpin->value();
    double y = ui->yMoveSpin->value();
    double z = ui->zMoveSpin->value();
    for (auto &id: objs) {
        MoveObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

//TODO
void MyMainWindow::on_rotateButton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }

    double x = degToRad(ui->xRotateSpin->value());
    double y = degToRad(ui->yRotateSpin->value());
    double z = degToRad(ui->zRotateSpin->value());
    for (auto &id: objs) {
        RotateObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

//TODO
void MyMainWindow::on_scaleButton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    double x = ui->xScaleSpin->value();
    double y = ui->yScaleSpin->value();
    double z = ui->zScaleSpin->value();
    for (auto &id: objs) {
        ScaleObjectCommand command(id, x, y, z);
        _facade.execute(command);
    }

    drawScene();
}

//TODO
void MyMainWindow::on_deleteSelectedButton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    for (auto &id: objs) {
        RemoveCameraCommand command1(id);
        _facade.execute(command1);
        DeleteObjectCommand command2(id);
        _facade.execute(command2);
    }

    drawScene();
    updateObjectList();
    updateCameraList();
}

//TODO
void MyMainWindow::on_objectsCompositeButton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.size() == 0) {
        QMessageBox::critical(nullptr, "Ошибка", "Нужно выбрать хотя бы один Объект.");
        return;
    }
    CompositeObjectCommand command(objs);
    _facade.execute(command);

    drawScene();
    updateObjectList();
    updateCameraList();
}
