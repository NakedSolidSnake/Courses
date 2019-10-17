#ifndef FORM_TAB_H
#define FORM_TAB_H

#include <QWidget>

namespace Ui {
class Form_tab;
}

class Form_tab : public QWidget
{
    Q_OBJECT

public:
    explicit Form_tab(QWidget *parent = nullptr);
    ~Form_tab();

private:
    Ui::Form_tab *ui;
};

#endif // FORM_TAB_H
