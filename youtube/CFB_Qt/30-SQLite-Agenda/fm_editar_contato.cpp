#include "fm_editar_contato.h"
#include "ui_fm_editar_contato.h"
#include <QtSql>
#include <QMessageBox>

fm_editar_contato::fm_editar_contato(QWidget *parent, int id_contato) :
    QDialog(parent),
    ui(new Ui::fm_editar_contato)
{
    ui->setupUi(this);
    id = id_contato;
    QSqlQuery query;
    query.prepare("select * from tb_contatos where id_contato=" + QString::number(id_contato));
    if(query.exec()){
        query.first();
        ui->leNome->setText(query.value(1).toString());
        ui->leTelefone->setText(query.value(2).toString());
        ui->leEmail->setText(query.value(3).toString());


    }else {
        QMessageBox::warning(this, "Erro", "Erro ao selecionar contato");
    }
}

fm_editar_contato::~fm_editar_contato()
{
    delete ui;
}

void fm_editar_contato::on_btCancelar_clicked()
{
    this->close();
}

void fm_editar_contato::on_btGravar_clicked()
{
    QString nome = ui->leNome->text();
    QString telefone = ui->leTelefone->text();
    QString email = ui->leEmail ->text();

    QSqlQuery query;
    query.prepare("update tb_contatos set nome_contato='" + nome + "', telefone_contato='" + telefone + "', email_contato='" + email + "' where id_contato = " + QString::number(id));
    if(query.exec()){
        this->close();
    }else{
        QMessageBox::warning(this, "Erro", "Erro ao atualizar contato");
    }
}
