#include "janelalogin.h"
#include "ui_janelalogin.h"


static QSqlDatabase bancoDeDados;

JanelaLogin::JanelaLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::JanelaLogin)
{
    ui->setupUi(this);

    bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
    bancoDeDados.setDatabaseName("/home/solid/Downloads/db_agenda");

    if(!bancoDeDados.open()){
        ui->statusBar->showMessage("Banco desconectado", 10000);
    }else{
        ui->statusBar->showMessage("Banco conectado", 3000);
    }
}

JanelaLogin::~JanelaLogin()
{
    delete ui;
}

void JanelaLogin::on_btLogin_clicked()
{
    QString username = ui->leUsername->text();
    QString senha = ui->leSenha->text();

    if(!bancoDeDados.isOpen()){
        qDebug() << "Banco de dados não conectado";
        return;
    }

    QSqlQuery query;
    query.exec("select * from tb_colaboradores where username = '" + username + "' and senha = '" + senha + "'");
    int cont = 0;
    while(query.next()){
        cont++;
    }

    if(cont){
        this->close();
        fm_principal f_principal;
        f_principal.setModal(true);
        f_principal.exec();
    }else{
        ui->statusBar->showMessage("Usuario não cadastrado", 5000);
        ui->leSenha->clear();
        ui->leUsername->clear();
        ui->leUsername->setFocus();
    }

}
