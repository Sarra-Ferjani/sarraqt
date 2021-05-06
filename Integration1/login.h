#ifndef LOGIN_H
#define LOGIN_H
#include "sarra.h"
#include "jalel.h"
#include "motez.h"
#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_connecter_clicked();

private:
    Ui::Login *ui;
    sarra *sarrra;
    jalel *jalal;
    motez *motaz;
};

#endif // LOGIN_H
