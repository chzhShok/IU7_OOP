#include <QFileDialog>
#include <QtWidgets/QMessageBox>

#include "logic/actions/actions.hpp"
#include "logic/utils/file_utils.hpp"

#include "ui/mainwindow.hpp"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Холст
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    connect(ui->clear_all_button, &QPushButton::clicked, this, &MainWindow::on_clear_all_clicked);
    connect(ui->load_figure_button, &QPushButton::clicked, this, &MainWindow::on_load_figure_clicked);
    connect(ui->move_submit_button, &QPushButton::clicked, this, &MainWindow::on_move_submit_clicked);
    connect(ui->rotate_submit_button, &QPushButton::clicked, this, &MainWindow::on_rotate_submit_clicked);
    connect(ui->scale_submit_button, &QPushButton::clicked, this, &MainWindow::on_scale_submit_clicked);
}

void MainWindow::on_load_figure_clicked() {
    QString path = QFileDialog::getExistingDirectory(this, "Выберите директорию");

    if (path.isEmpty())
        QMessageBox::information(this, "Ошибка", "Директория пустая");

    Action action;
    action.type = UPLOAD;
    action.path = dir_path_to_files_paths(path);

    if (!action.path.path_vertices || !action.path.path_edges) {
        QMessageBox::information(this, "Ошибка", "Нужных файлов нет в папке");
    } else {
        ErrorFigure error = manage_action(action);
        if (!error_is_ok(error))
            QMessageBox::information(this, "Ошибка", manage_error(error));
        else
            draw();
    }
}

void MainWindow::on_clear_all_clicked() {
    // move
    ui->dx_move->setValue(0.0);
    ui->dy_move->setValue(0.0);
    ui->dz_move->setValue(0.0);

    // rotate
    ui->x_rotate->setValue(0.0);
    ui->y_rotate->setValue(0.0);
    ui->z_rotate->setValue(0.0);

    ui->dx_rotate->setValue(0.0);
    ui->dy_rotate->setValue(0.0);
    ui->dz_rotate->setValue(0.0);

    // scale
    ui->x_scale->setValue(0.0);
    ui->y_scale->setValue(0.0);
    ui->z_scale->setValue(0.0);
    ui->k_scale->setValue(0.0);
}

void MainWindow::on_move_submit_clicked() {
    Action action;
    action.type = MOVE;
    action.move = {
        .dx = ui->dx_move->value(),
        .dy = ui->dy_move->value(),
        .dz = ui->dz_move->value(),
    };

    ErrorFigure error = manage_action(action);
    if (!error_is_ok(error))
        QMessageBox::information(this, "Ошибка", manage_error(error));
    else
        draw();
}

void MainWindow::on_rotate_submit_clicked() {
    Action action;
    action.type = ROTATE;
    action.rotate = {
        .x = ui->x_rotate->value(),
        .y = ui->y_rotate->value(),
        .z = ui->z_rotate->value(),
        .dx = ui->dx_rotate->value(),
        .dy = ui->dy_rotate->value(),
        .dz = ui->dz_rotate->value()
    };

    ErrorFigure error = manage_action(action);
    if (!error_is_ok(error))
        QMessageBox::information(this, "Ошибка", manage_error(error));
    else
        draw();
}

void MainWindow::on_scale_submit_clicked() {
    Action action;
    action.type = SCALE;
    action.scale = {
        .x = ui->x_scale->value(),
        .y = ui->y_scale->value(),
        .z = ui->z_scale->value(),
        .k = ui->k_scale->value(),
    };

    ErrorFigure error = manage_action(action);
    if (!error_is_ok(error))
        QMessageBox::information(this, "Ошибка", manage_error(error));
    else
        draw();
}

void MainWindow::draw() {
    Action action;
    action.type = DRAW;
    action.view = {
        .scene = ui->graphicsView->scene(),
        .width = ui->graphicsView->scene()->width(),
        .height = ui->graphicsView->scene()->height()
    };

    ErrorFigure error = manage_action(action);
    if (!error_is_ok(error))
        QMessageBox::information(this, "Ошибка", manage_error(error));
}

MainWindow::~MainWindow() {
    delete ui;
}
