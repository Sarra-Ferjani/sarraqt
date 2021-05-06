#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"jalel.h"
#include<motez.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   jalal =new jalel(this);
    jalal->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    moatez =new motez (this);
    moatez->show();
}
