#include "fm_principal.h"
#include "ui_fm_principal.h"

fm_principal::fm_principal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_principal)
{
    ui->setupUi(this);
}

fm_principal::~fm_principal()
{
    delete ui;
}

void fm_principal::on_btAdicionar_clicked()
{
    fm_novocontato f_novocontato;
    f_novocontato.exec();
}

void fm_principal::on_btPesuisar_clicked()
{
    fm_pesquisacontatos f_pesquisacontatos ;
    f_pesquisacontatos.exec();
}
