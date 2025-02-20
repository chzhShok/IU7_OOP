#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void on_clear_all_clicked();

    void on_load_figure_clicked();

    void on_move_submit_clicked();

    void on_rotate_submit_clicked();

    void on_scale_submit_clicked();

    void draw();
};

#endif// MAINWINDOW_HPP
