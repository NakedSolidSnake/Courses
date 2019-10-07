#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_add_clicked();

    void on_bt_addMany_clicked();

    void on_btMark_clicked();

    void on_bt_Unmark_clicked();

    void on_bt_unmarkall_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
