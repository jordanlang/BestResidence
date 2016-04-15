#include <QMessageBox>
#include <QTableWidget>
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
        wdg_photo = new QTableWidgetItem();
        wdg_bien = new QTableWidgetItem();
        wdg_pieces = new QTableWidgetItem();
        wdg_superficie = new QTableWidgetItem();
        wdg_ville = new QTableWidgetItem();
        wdg_prix = new QTableWidgetItem();

        wdg_bien->setText(this->typeBien);
        wdg_pieces->setText(QString::number(this->nbPieces));
        wdg_superficie->setText(QString::number(this->superficie));
        wdg_ville->setText(this->ville);
        wdg_prix->setText(QString::number(this->prix));

        int i = ui->tableBiens->rowCount();
        ui->tableBiens->insertRow(i);
        ui->tableBiens->setItem(i, 1, wdg_bien);
        ui->tableBiens->setItem(i, 2, wdg_pieces);
        ui->tableBiens->setItem(i, 3, wdg_superficie);
        ui->tableBiens->setItem(i, 4, wdg_ville);
        ui->tableBiens->setItem(i, 5, wdg_prix);
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
