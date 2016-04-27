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
    writeXmlFile();
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
    QString element_immo = "immobilier";
    QString element_client = "client";
    int id_immo = 0;
    int id_client = 0;
    reader.readNext();
    while (!reader.atEnd())
    {
        if(reader.isStartElement()) {
            if(reader.name() == element_immo) {
                if(element_immo == "immobilier") {
                    nb_annonces += 1;
                    element_immo = "annonce";
                } else if(element_immo == "annonce") {
                    annonces[id_immo][0] = reader.readElementText();
                    element_immo = "bien";
                } else if(element_immo == "bien") {
                    annonces[id_immo][1] = reader.readElementText();
                    element_immo = "pieces";
                } else if(element_immo == "pieces") {
                    annonces[id_immo][2] = reader.readElementText();
                    element_immo = "superficie";
                } else if(element_immo == "superficie") {
                    annonces[id_immo][3] = reader.readElementText();
                    element_immo = "adresse";
                } else if(element_immo == "adresse") {
                    annonces[id_immo][4] = reader.readElementText();
                    element_immo = "ville";
                } else if(element_immo == "ville") {
                    annonces[id_immo][5] = reader.readElementText();
                    element_immo = "codepostal";
                } else if(element_immo == "codepostal") {
                    annonces[id_immo][6] = reader.readElementText();
                    element_immo = "description";
                } else if(element_immo == "description") {
                    annonces[id_immo][7] = reader.readElementText();
                    element_immo = "prix";
                } else if(element_immo == "prix") {
                    annonces[id_immo][8] = reader.readElementText();
                    element_immo = "date";
                } else if(element_immo == "date") {
                    annonces[id_immo][9] = reader.readElementText();
                    element_immo = "principale";
                } else if(element_immo == "principale") {
                    annonces[id_immo][10] = reader.readElementText();
                    element_immo = "supp1";
                } else if(element_immo == "supp1") {
                    annonces[id_immo][11] = reader.readElementText();
                    element_immo = "supp2";
                } else if(element_immo == "supp2") {
                    annonces[id_immo][12] = reader.readElementText();
                    element_immo = "supp3";
                } else if(element_immo == "supp3") {
                    annonces[id_immo][13] = reader.readElementText();
                    element_immo = "supp4";
                } else if(element_immo == "supp4") {
                    annonces[id_immo][14] = reader.readElementText();
                    element_immo = "supp5";
                } else if(element_immo == "supp5") {
                    annonces[id_immo][15] = reader.readElementText();
                    element_immo = "supp6";
                } else if(element_immo == "supp6") {
                    annonces[id_immo][16] = reader.readElementText();
                    element_immo = "supp7";
                } else if(element_immo == "supp7") {
                    annonces[id_immo][17] = reader.readElementText();
                    element_immo = "supp8";
                } else if(element_immo == "supp8") {
                    annonces[id_immo][18] = reader.readElementText();
                    element_immo = "histo";
                } else if(element_immo == "histo") {
                    annonces[id_immo][19] = reader.readElementText();
                    element_immo = "idprop";
                } else if(element_immo == "idprop") {
                    annonces[id_immo][20] = reader.readElementText();
                    element_immo = "idclient";
                } else if(element_immo == "idclient") {
                    annonces[id_immo][21] = reader.readElementText();
                    id_immo += 1;
                    element_immo = "immobilier";
                }
            } else if(reader.name() == element_client) {
                if(element_client == "client") {
                    nb_clients += 1;
                    element_client = "identifiant";
                } else if(element_client == "identifiant") {
                    clients[id_client][0] = reader.readElementText();
                    element_client = "nom";
                } else if(element_client == "nom") {
                    clients[id_client][1] = reader.readElementText();
                    element_client = "prenom";
                } else if(element_client == "prenom") {
                    clients[id_client][2] = reader.readElementText();
                    element_client = "adresseclient";
                } else if(element_client == "adresseclient") {
                    clients[id_client][3] = reader.readElementText();
                    element_client = "villeclient";
                } else if(element_client == "villeclient") {
                    clients[id_client][4] = reader.readElementText();
                    element_client = "contact";
                } else if(element_client == "contact") {
                    clients[id_client][5] = reader.readElementText();
                    element_client = "nbcontrats";
                } else if(element_client == "nbcontrats") {
                    clients[id_client][6] = reader.readElementText();
                    element_client = "datecreation";
                } else if(element_client == "datecreation") {
                    clients[id_client][7] = reader.readElementText();
                    id_client += 1;
                    element_client = "client";
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
        wdg_ville->setText(annonces[i][5]);
        wdg_prix->setText(annonces[i][8]);

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
    QString fileXmlName = "/Users/jordan/Dropbox/Cours/L3 - S6/Interface homme-machine/Projet/BestResidence/BestResidence/annonces.xml";
    QFile fileXml(fileXmlName);

    // Ouverture du fichier en écriture et en texte. (sort de la fonction si le fichier ne s'ouvre pas)
    if(!fileXml.open(QFile::WriteOnly | QFile::Text))
        return;
    QXmlStreamWriter writer(&fileXml);

    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("bestresidence");

    for(int i=0; i<nb_annonces; i++)
    {
        writer.writeStartElement("immobilier");
        writer.writeTextElement("annonce", annonces[i][0]);
        writer.writeTextElement("bien", annonces[i][1]);
        writer.writeTextElement("pieces", annonces[i][2]);
        writer.writeTextElement("superficie", annonces[i][3]);
        writer.writeTextElement("adresse", annonces[i][4]);
        writer.writeTextElement("ville", annonces[i][5]);
        writer.writeTextElement("codepostal", annonces[i][6]);
        writer.writeTextElement("description", annonces[i][7]);
        writer.writeTextElement("prix", annonces[i][8]);
        writer.writeTextElement("date", annonces[i][9]);
        writer.writeTextElement("principale", annonces[i][10]);
        writer.writeTextElement("supp1", annonces[i][11]);
        writer.writeTextElement("supp2", annonces[i][12]);
        writer.writeTextElement("supp3", annonces[i][13]);
        writer.writeTextElement("supp4", annonces[i][14]);
        writer.writeTextElement("supp5", annonces[i][15]);
        writer.writeTextElement("supp6", annonces[i][16]);
        writer.writeTextElement("supp7", annonces[i][17]);
        writer.writeTextElement("supp8", annonces[i][18]);
        writer.writeTextElement("histo", annonces[i][19]);
        writer.writeEndElement();
    }

    for(int i=0; i<nb_clients; i++)
    {
        writer.writeStartElement("client");
        writer.writeTextElement("identifiant", clients[i][0]);
        writer.writeTextElement("nom", clients[i][1]);
        writer.writeTextElement("prenom", clients[i][2]);
        writer.writeTextElement("adresseclient", clients[i][3]);
        writer.writeTextElement("villeclient", clients[i][4]);
        writer.writeTextElement("contact", clients[i][5]);
        writer.writeTextElement("nbcontrats", clients[i][6]);
        writer.writeTextElement("datecreation", clients[i][7]);
        writer.writeEndElement();
    }

    writer.writeEndElement();
    writer.writeEndDocument();

    fileXml.close();
}

void MainWindow::on_pushButton_clicked()
{
    Ajout ajout_bien(this);
    ajout_bien.exec();

    if(!annule) {
        annonces[nb_annonces][0] = this->typeAnnonce;
        annonces[nb_annonces][1] = this->typeBien;
        annonces[nb_annonces][2] = QString::number(this->nbPieces);
        annonces[nb_annonces][3] = QString::number(this->superficie);
        annonces[nb_annonces][4] = this->adresse;
        annonces[nb_annonces][5] = this->ville;
        annonces[nb_annonces][6] = this->codePostal;
        annonces[nb_annonces][7] = this->description;
        annonces[nb_annonces][8] = QString::number(this->prix);
        annonces[nb_annonces][9] = this->photoPrincipale;
        annonces[nb_annonces][10] = this->photosSupp[0];
        annonces[nb_annonces][11] = this->photosSupp[1];
        annonces[nb_annonces][12] = this->photosSupp[2];
        annonces[nb_annonces][13] = this->photosSupp[3];
        annonces[nb_annonces][14] = this->photosSupp[4];
        annonces[nb_annonces][15] = this->photosSupp[5];
        annonces[nb_annonces][16] = this->photosSupp[6];
        annonces[nb_annonces][17] = this->photosSupp[7];

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
    for(int i=0; i<8; i++) {
        this->photosSupp[i] = ps[i];
    }
}

void MainWindow::setAnnule(bool b)
{
    this->annule = b;
}

void MainWindow::on_tableBiens_clicked(const QModelIndex &index)
{
    Annonce voir_annonce(this,index.row());
}
