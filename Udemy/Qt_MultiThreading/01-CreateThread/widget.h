#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btStart_clicked();

private:
    Ui::Widget *ui;
    QThread *thread;
};

#endif // WIDGET_H
