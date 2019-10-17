#ifndef NOVO_H
#define NOVO_H

#include <QDialog>

namespace Ui {
class Novo;
}

class Novo : public QDialog
{
    Q_OBJECT

public:
    explicit Novo(QWidget *parent = nullptr);
    ~Novo();

private:
    Ui::Novo *ui;
};

#endif // NOVO_H
