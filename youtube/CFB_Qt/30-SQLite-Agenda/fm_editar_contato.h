#ifndef FM_EDITAR_CONTATO_H
#define FM_EDITAR_CONTATO_H

#include <QDialog>

namespace Ui {
class fm_editar_contato;
}

class fm_editar_contato : public QDialog
{
    Q_OBJECT

public:
    explicit fm_editar_contato(QWidget *parent = nullptr, int id_contato = 0);
    ~fm_editar_contato();

private slots:
    void on_btCancelar_clicked();

    void on_btGravar_clicked();

private:
    Ui::fm_editar_contato *ui;
    int id;
};

#endif // FM_EDITAR_CONTATO_H
