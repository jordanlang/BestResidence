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
    readXmlFile();
    addTabToList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readXmlFile()
{
    QXmlStreamReader reader; // Objet servant à la lecture du fichier Xml
    QString fileXmlName = "/Users/jordan/Dropbox/Cours/L3 - S6/Interface homme-machine/Projet/BestResidence/BestResidence/annonces.xml";
    QFile fileXml(fileXmlName);

    // Ouverture du fichier XML en lecture seule et en mode texte (Sort de la fonction si le fichier ne peut etre ouvert).
    if (!fileXml.open(QFile::ReadOnly | QFile::Text))
        return;

    // Initialise l'instance reader avec le flux XML venant de file
    reader.setDevice(&fileXml);

    // charge les informations du fichier xml dans l'application
    QString element = "id";
    int id = 0;
    reader.readNext();
    while (!reader.atEnd())
    {
        if(reader.isStartElement()) {
            if(reader.name() == element) {
                if(element == "id") {
                    nb_annonces += 1;
                    element = "annonce";
                } else if(element == "annonce") {
                    annonces[id][0] = reader.readElementText();
                    element = "bien";
                } else if(element == "bien") {
                    annonces[id][1] = reader.readElementText();
                    element = "pieces";
                } else if(element == "pieces") {
                    annonces[id][2] = reader.readElementText();
                    element = "superficie";
                } else if(element == "superficie") {
                    annonces[id][3] = reader.readElementText();
                    element = "ville";
                } else if(element == "ville") {
                    annonces[id][4] = reader.readElementText();
                    element = "prix";
                } else if(element == "prix") {
                    annonces[id][5] = reader.readElementText();
                    id += 1;
                    element = "id";
                }
            }
        }
        reader.readNext();
    }

    fileXml.close();
}

void MainWindow::addTabToList()
{
    ui->tableBiens->clear();

    for(int i=0; i<nb_annonces; i++)
    {
        wdg_bien = new QTableWidgetItem();
        wdg_pieces = new QTableWidgetItem();
        wdg_superficie = new QTableWidgetItem();
        wdg_ville = new QTableWidgetItem();
        wdg_prix = new QTableWidgetItem();

        wdg_bien->setText(annonces[i][1]);
        wdg_pieces->setText(annonces[i][2]);
        wdg_superficie->setText(annonces[i][3]);
        wdg_ville->setText(annonces[i][4]);
        wdg_prix->setText(annonces[i][5]);

        ui->tableBiens->insertRow(i);
        ui->tableBiens->setItem(i, 1, wdg_bien);
        ui->tableBiens->setItem(i, 2, wdg_pieces);
        ui->tableBiens->setItem(i, 3, wdg_superficie);
        ui->tableBiens->setItem(i, 4, wdg_ville);
        ui->tableBiens->setItem(i, 5, wdg_prix);
    }
}

void MainWindow::writeXmlFile()
{

}

void MainWindow::on_pushButton_clicked()
{
    Ajout ajout_bien(this);
    ajout_bien.exec();

    if(!annule) {
        annonces[nb_annonces][1] = this->typeBien;
        annonces[nb_annonces][2] = QString::number(this->nbPieces);
        annonces[nb_annonces][3] = QString::number(this->superficie);
        annonces[nb_annonces][4] = this->ville;
        annonces[nb_annonces][5] = QString::number(this->prix);
        nb_annonces += 1;

        addTabToList();
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
