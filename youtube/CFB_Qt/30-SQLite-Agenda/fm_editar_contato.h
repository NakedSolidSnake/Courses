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
    explicit fm_editar_contato(QWidget *parent = nullptr);
    ~fm_editar_contato();

private:
    Ui::fm_editar_contato *ui;
};

#endif // FM_EDITAR_CONTATO_H
