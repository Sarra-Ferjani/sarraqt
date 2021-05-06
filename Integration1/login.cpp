#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_connecter_clicked()
{
    QString username = ui->id_edit->text();
        QString password = ui->mdp_edit->text();

        if(username ==  "livreur" && password == "0000") {
            QMessageBox::information(this, "Login", "Username and password is correct");
            //hide();
            sarrra = new sarra(this);
            sarrra->show();
        }
        else if(username ==  "livraison" && password == "0000") {
            QMessageBox::information(this, "Login", "Username and password is correct");
            //hide();
            jalal = new jalel(this);
            jalal->show();

        }
        else if(username ==  "commande" && password == "0000") {
            QMessageBox::information(this, "Login", "Username and password is correct");
            //hide();
            motaz = new motez(this);
            motaz->show();

        }
        else{QMessageBox::warning(this,"Login", "Username and password is not correct");
}
}
