#ifndef JANELALOGIN_H
#define JANELALOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "fm_principal.h"

namespace Ui {
class JanelaLogin;
}

class JanelaLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit JanelaLogin(QWidget *parent = nullptr);
    ~JanelaLogin();

private slots:
    void on_btLogin_clicked();

private:
    Ui::JanelaLogin *ui;
};

#endif // JANELALOGIN_H
