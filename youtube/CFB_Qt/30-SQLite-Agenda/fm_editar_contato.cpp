#include "fm_editar_contato.h"
#include "ui_fm_editar_contato.h"

fm_editar_contato::fm_editar_contato(QWidget *parent, int id_contato) :
    QDialog(parent),
    ui(new Ui::fm_editar_contato)
{
    ui->setupUi(this);
}

fm_editar_contato::~fm_editar_contato()
{
    delete ui;
}
