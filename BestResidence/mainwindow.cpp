#include <QMessageBox>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "ui_ajout.h"
#include "annonce.h"
#include "ui_annonce.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dom = new QDomDocument("annonces");
    QFile xml_doc("annonces.xml");// On choisit le fichier contenant les informations XML.
    if(!xml_doc.open(QIODevice::ReadOnly))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé");
        return;
    }
    if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
    {
            xml_doc.close();
            QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
            return;
    }
    xml_doc.close();
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

void MainWindow::on_tableBiens_clicked(const QModelIndex &index)
{

    QMessageBox::warning(this,"bla",QString::number(index.row()));
    Annonce voir_annonce(this);

}
