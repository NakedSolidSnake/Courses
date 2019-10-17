#include "novo.h"
#include "ui_novo.h"

Novo::Novo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Novo)
{
    ui->setupUi(this);
}

Novo::~Novo()
{
    delete ui;
}
