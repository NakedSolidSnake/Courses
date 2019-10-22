#include "fm_pesquisacontatos.h"
#include "ui_fm_pesquisacontatos.h"
#include "fm_editar_contato.h"
#include <QtSql>
#include <QMessageBox>

fm_pesquisacontatos::fm_pesquisacontatos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fm_pesquisacontatos)
{
    ui->setupUi(this);
    QSqlQuery query;
    query.prepare("select * from tb_contatos");
    if(query.exec()){
        int cont = 0;
        ui->twContatos->setColumnCount(4);
        while(query.next()){
            ui->twContatos->insertRow(cont);
            ui->twContatos->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->twContatos->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->twContatos->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->twContatos->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->twContatos->setRowHeight(cont, 20);
            cont++;
        }

        ui->twContatos->setColumnWidth(0, 30);
        ui->twContatos->setColumnWidth(1, 150);
        ui->twContatos->setColumnWidth(3, 260);


        QStringList header = {"ID", "Nome", "Telefone", "E-mail"};
        ui->twContatos->setHorizontalHeaderLabels(header);
        ui->twContatos->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->twContatos->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->twContatos->verticalHeader()->setVisible(false);
        ui->twContatos->setStyleSheet("QTableView {selection-background-color:blue}");


    }else{
        QMessageBox::warning(this, "Erro", "Erro ao pesquisar na tabela de contatos");
    }
}

fm_pesquisacontatos::~fm_pesquisacontatos()
{
    delete ui;
}

void fm_pesquisacontatos::on_btExcluir_clicked()
{
    int linha = ui->twContatos->currentRow();
    int id = ui->twContatos->item(linha, 0)->text().toInt();
    QSqlQuery query;
    query.prepare("delete from tb_contatos where id_contato = " + QString::number(id));
    if(query.exec()){
        QMessageBox::information(this, "", "Item excluido");
        ui->twContatos->removeRow(linha);
    }else{
        QMessageBox::warning(this, "Erro", "Erro ao excluir item");
    }
}

void fm_pesquisacontatos::on_btEditar_clicked()
{
    int linha = ui->twContatos->currentRow();
    int id = ui->twContatos->item(linha, 0)->text().toInt();
    fm_editar_contato f_editar_contato (this, id);
    f_editar_contato.exec();

    //update table widget
}
