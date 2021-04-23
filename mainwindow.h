#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "tarif.h"
#include "statistiques.h"
#include "gestion_des_livreur.h"
#include <QTimer>
#include "arduino.h"
#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
void on_pushButton_clicked();
void on_pushButton_2_clicked();
void on_pushButton_3_clicked();
void on_pushButton_4_clicked();




private:
    Ui::MainWindow *ui;
    tarif tabT;
    gestion_des_livreur tabL;
    statistiques *stat;
    QTimer *timer;
    Arduino  A;
    QByteArray data;


};
#endif // MAINWINDOW_H
