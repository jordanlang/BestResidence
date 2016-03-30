#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "ui_ajout.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Ajout ajout_bien(this);
    ajout_bien.exec();

    if(!annule) {
        //ui->tableBiens->
    }
}



// ----------------- SETTER ------------------

void MainWindow::setTypeAnnonce(QString a)
{
    this->typeAnnonce = a;
}

void MainWindow::setTypeBien(QString b)
{
    this->typeBien = b;
}

void MainWindow::setNbPieces(int p)
{
    this->nbPieces = p;
}

void MainWindow::setSuperficie(double s)
{
    this->superficie = s;
}

void MainWindow::setAdresse(QString a)
{
    this->adresse = a;
}

void MainWindow::setVille(QString v)
{
    this->ville = v;
}

void MainWindow::setCodePostal(QString cp)
{
    this->codePostal = cp;
}

void MainWindow::setDescription(QString d)
{
    this->description = d;
}

void MainWindow::setPrix(double p)
{
    this->prix = p;
}

void MainWindow::setPhotoPrincipale(QString pp)
{
    this->photoPrincipale = pp;
}

void MainWindow::setPhotosSupp(QString ps[])
{
    this->photosSupp[0] = ps[0];
}

void MainWindow::setAnnule(bool b)
{
    this->annule = b;
}
