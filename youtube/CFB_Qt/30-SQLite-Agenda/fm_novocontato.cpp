#include "fm_novocontato.h"
#include "ui_fm_novocontato.h"
#include <QMessageBox>


fm_novocontato::fm_novocontato(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_novocontato)
{
    ui->setupUi(this);
}

fm_novocontato::~fm_novocontato()
{
    delete ui;
}



void fm_novocontato::on_btGravar_clicked()
{
    QString nome = ui->leNome->text();
    QString telefone = ui->leTelefone->text();
    QString email = ui->leEmail->text();

    QSqlQuery query;

    query.prepare("insert into tb_contatos (nome_contato, telefone_contato, email_contato) values "
                  "('" + nome + "','" + telefone + "','" + email + "')");
    if(query.exec()){
        QMessageBox::information(this, "", "Registro gravado com sucesso");
        ui->leNome->clear();
        ui->leTelefone->clear();
        ui->leEmail->clear();
        ui->leNome->setFocus();

    }else{
        qDebug() << "Erro ao inserir registro";
    }

}
