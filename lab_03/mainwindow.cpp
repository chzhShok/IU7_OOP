#include "mainwindow.hpp"

#include <QMessageBox>
#include <QPushButton>
#include <cmath>

#include "AddCameraCommand.hpp"
#include "CompositeObjectCommand.hpp"
#include "DrawSceneQtCommand.hpp"
#include "Exception.hpp"
#include "GetCameraIDsSceneCommand.hpp"
#include "GetObjectIDsSceneCommand.hpp"
#include "JsonLoadCommandDecorator.hpp"
#include "ListLoadCommand.hpp"
#include "MatrixLoadCommand.hpp"
#include "MoveObjectCommand.hpp"
#include "RemoveCameraCommand.hpp"
#include "RemoveObjectCommand.hpp"
#include "RotateObjectCommand.hpp"
#include "ScaleObjectCommand.hpp"
#include "SetCameraCommand.hpp"
#include "SwapEdgesVisibility.hpp"
#include "TxtLoadCommandDecorator.hpp"
#include "Vertex.hpp"

double degreesToRadians(double angle) {
    return angle / 180.0 * M_PI;
}

void MyMainWindow::logMessage(const QString &message) {
    QString timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss] ");
    ui->logText->append(timestamp + message);
}

void MyMainWindow::logError(const QString &message) {
    QString errorMsg = QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss] ") + "<font color='red'>[ОШИБКА] " + message + "</font>";
    ui->logText->append(errorMsg);
    QMessageBox::critical(nullptr, "Ошибка", message);
}

MyMainWindow::MyMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene);
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->sceneRect());
    connectButtons();
}

MyMainWindow::~MyMainWindow() {
    delete ui;
}

void MyMainWindow::connectButtons() {
    connect(ui->loadButton, &QPushButton::clicked, this, &MyMainWindow::on_loadButton_clicked);
    connect(ui->addCameraButton, &QPushButton::clicked, this, &MyMainWindow::on_cameraAddPushbutton_clicked);
    connect(ui->deleteCameraButton, &QPushButton::clicked, this, &MyMainWindow::on_cameraDeletePushbutton_clicked);
    connect(ui->setCameraButton, &QPushButton::clicked, this, &MyMainWindow::on_cameraSetPushbutton_clicked);
    connect(ui->moveButton, &QPushButton::clicked, this, &MyMainWindow::on_objectMovePushbutton_clicked);
    connect(ui->rotateButton, &QPushButton::clicked, this, &MyMainWindow::on_objectRotatePushbutton_clicked);
    connect(ui->scaleButton, &QPushButton::clicked, this, &MyMainWindow::on_objectScalePushbutton_clicked);
    connect(ui->deleteSelectedButton, &QPushButton::clicked, this, &MyMainWindow::on_objectDeletePushbutton_clicked);
    connect(ui->compositeButton, &QPushButton::clicked, this, &MyMainWindow::on_objectCompositePushbutton_clicked);
    connect(ui->stepBackButton, &QPushButton::clicked, this, &MyMainWindow::on_undoButton_clicked);
    connect(ui->swapEdgesVisibilityButton, &QPushButton::clicked, this, &MyMainWindow::on_swapEdgesVisibilityButton_clicked);
}

void MyMainWindow::on_loadButton_clicked() {
    std::string str = ui->fileNameLine->text().toStdString();
    const char *fname = str.c_str();

    logMessage("Начата загрузка модели из файла: " + QString(fname));

    std::shared_ptr<BaseLoadCommand> command;

    if (ui->figureTypeComboBox->currentText() == "Список") {
        command = std::make_shared<ListLoadCommand>();
        logMessage("Выбрано представление: Список");
    } else {
        command = std::make_shared<MatrixLoadCommand>();
        logMessage("Выбрано представление: Матрица");
    }

    std::shared_ptr<BaseCommand> decorator;
    if (ui->fileTypeComboBox->currentText() == "Txt") {
        decorator = std::make_shared<TxtLoadCommandDecorator>(*command, fname);
        logMessage("Выбран формат файла: TXT");
    } else {
        decorator = std::make_shared<JsonLoadCommandDecorator>(*command, fname);
        logMessage("Выбран формат файла: Json");
    }

    try {
        _facade.execute(*decorator);
        logMessage("Модель успешно загружена");
    } catch (Exception &exc) {
        QString errorMsg = QString("Ошибка загрузки: ") + exc.what();
        logMessage("<font color='red'>" + errorMsg + "</font>");
        QMessageBox::critical(nullptr, "Ошибка", errorMsg);
        return;
    }

    drawScene();
    updateObjectList();
}

void MyMainWindow::on_cameraAddPushbutton_clicked() {
    double x = ui->xCameraSpin->value();
    double y = ui->yCameraSpin->value();
    double z = ui->zCameraSpin->value();
    Vertex pos(x, y, z);

    AddCameraCommand command(pos);
    try {
        _facade.execute(command);
        logMessage(QString("Добавлена камера [X: %1, Y: %2, Z: %3]").arg(x).arg(y).arg(z));
    } catch (Exception &exc) {
        logError(exc.what());
        return;
    }

    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_cameraDeletePushbutton_clicked() {
    auto cams = getSelectedCameraIds();
    if (cams.empty()) {
        logError("Не выбраны камеры для удаления");
        return;
    }

    for (size_t id: cams) {
        try {
            RemoveCameraCommand command(id);
            _facade.execute(command);
            logMessage(QString("Удалена камера [ID: %1]").arg(id));
        } catch (Exception &exc) {
            logError(exc.what());
        }
    }

    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_cameraSetPushbutton_clicked() {
    auto cams = getSelectedCameraIds();
    if (cams.size() != 1) {
        logError("Для установки должна быть выбрана ровно одна камера");
        return;
    }

    try {
        SetCameraCommand command(cams[0]);
        _facade.execute(command);
        logMessage(QString("Установлена активная камера [ID: %1]").arg(cams[0]));
        drawScene();
    } catch (Exception &exc) {
        logError(exc.what());
    }
}

void MyMainWindow::updateCameraList() {
    ui->camerasList->clear();
    GetCameraIDsSceneCommand ids;
    _facade.execute(ids);

    std::vector<size_t> cameraIds = ids.getIDs();
    for (size_t id: cameraIds)
        ui->camerasList->addItem(QString::number(id));
}

void MyMainWindow::updateObjectList() {
    ui->objectsList->clear();
    GetObjectIDsSceneCommand ids;
    _facade.execute(ids);

    std::vector<size_t> objectIds = ids.getIDs();
    for (size_t id: objectIds)
        ui->objectsList->addItem(QString::number(id));
}

std::vector<size_t> MyMainWindow::getSelectedObjectIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->objectsList->count(); i++)
        if (ui->objectsList->item(i)->isSelected())
            ids.push_back(ui->objectsList->item(i)->text().toInt());

    return ids;
}

std::vector<size_t> MyMainWindow::getSelectedCameraIds() {
    std::vector<size_t> ids;
    for (int i = 0; i < ui->camerasList->count(); i++)
        if (ui->camerasList->item(i)->isSelected())
            ids.push_back(ui->camerasList->item(i)->text().toInt());

    return ids;
}

void MyMainWindow::drawScene() {
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->sceneRect());

    DrawSceneQtCommand drawcommand(ui->graphicsView->scene());
    _facade.execute(drawcommand);
}

void MyMainWindow::on_objectMovePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.empty()) {
        logError("Не выбраны объекты для перемещения");
        return;
    }

    double x = ui->xMoveSpin->value();
    double y = ui->yMoveSpin->value();
    double z = ui->zMoveSpin->value();

    for (auto &id: objs) {
        try {
            MoveObjectCommand command(id, x, y, z);
            _facade.execute(command);
            logMessage(QString("Перемещен объект [ID: %1] на [ΔX: %2, ΔY: %3, ΔZ: %4]").arg(id).arg(x).arg(y).arg(z));
        } catch (Exception &exc) {
            logError(exc.what());
        }
    }

    drawScene();
}

void MyMainWindow::on_objectRotatePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.empty()) {
        logError("Не выбраны объекты для вращения");
        return;
    }

    double x = degreesToRadians(ui->xRotateSpin->value());
    double y = degreesToRadians(ui->yRotateSpin->value());
    double z = degreesToRadians(ui->zRotateSpin->value());

    for (auto &id: objs) {
        try {
            RotateObjectCommand command(id, x, y, z);
            _facade.execute(command);
            logMessage(QString("Повернут объект [ID: %1] на [θX: %2°, θY: %3°, θZ: %4°]").arg(id).arg(x).arg(y).arg(z));
        } catch (Exception &exc) {
            logError(exc.what());
        }
    }

    drawScene();
}

void MyMainWindow::on_objectScalePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.empty()) {
        logError("Не выбраны объекты для масштабирования");
        return;
    }

    double x = ui->xScaleSpin->value();
    double y = ui->yScaleSpin->value();
    double z = ui->zScaleSpin->value();

    for (auto &id: objs) {
        try {
            ScaleObjectCommand command(id, x, y, z);
            _facade.execute(command);
            logMessage(QString("Масштабирован объект [ID: %1] на [KX: %2, KY: %3, KZ: %4]").arg(id).arg(x).arg(y).arg(z));
        } catch (Exception &exc) {
            logError(exc.what());
        }
    }

    drawScene();
}

void MyMainWindow::on_objectDeletePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.empty()) {
        logError("Не выбраны объекты для удаления");
        return;
    }

    for (auto &id: objs) {
        try {
            RemoveObjectCommand command(id);
            _facade.execute(command);
            logMessage(QString("Удален объект [ID: %1]").arg(id));
        } catch (Exception &exc) {
            logError(exc.what());
        }
    }

    drawScene();
    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_objectCompositePushbutton_clicked() {
    auto objs = getSelectedObjectIds();
    if (objs.empty()) {
        logError("Не выбраны объекты для объединения");
        return;
    }

    try {
        CompositeObjectCommand command(objs);
        _facade.execute(command);
        logMessage(QString("Создан композитный объект из %1 элементов").arg(objs.size()));
    } catch (Exception &exc) {
        logError(exc.what());
        return;
    }

    drawScene();
    updateCameraList();
    updateObjectList();
}

void MyMainWindow::on_undoButton_clicked() {
    try {
        if (!_facade.getTransformManager()->undo()) {
            logError("Нет доступных действий для отката");
            return;
        } else {
            logMessage("Выполнен откат последней трансформации");
        }
    } catch (Exception &exc) {
        logError(exc.what());
    }

    drawScene();
}

void MyMainWindow::on_swapEdgesVisibilityButton_clicked() {
    SwapEdgesVisibility swapEdgesVisibility;
    _facade.execute(swapEdgesVisibility);

    drawScene();
}
