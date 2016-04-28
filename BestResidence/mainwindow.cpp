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
    initAnnonces();
    addTabAnnoncesVente();
    addTabAnnoncesLocation();
    addTabHistoVente();
    addTabHistoLocation();
    addTabClients();
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
                    element_client = "genre";
                } else if(element_client == "genre") {
                    clients[id_client][1] = reader.readElementText();
                    element_client = "nom";
                } else if(element_client == "nom") {
                    clients[id_client][2] = reader.readElementText();
                    element_client = "prenom";
                } else if(element_client == "prenom") {
                    clients[id_client][3] = reader.readElementText();
                    element_client = "datenaissance";
                } else if(element_client == "datenaissance") {
                    clients[id_client][4] = reader.readElementText();
                    element_client = "adresseclient";
                } else if(element_client == "adresseclient") {
                    clients[id_client][5] = reader.readElementText();
                    element_client = "villeclient";
                } else if(element_client == "villeclient") {
                    clients[id_client][6] = reader.readElementText();
                    element_client = "codepostalclient";
                } else if(element_client == "codepostalclient") {
                    clients[id_client][7] = reader.readElementText();
                    element_client = "courriel";
                } else if(element_client == "courriel") {
                    clients[id_client][8] = reader.readElementText();
                    element_client = "telephone";
                } else if(element_client == "telephone") {
                    clients[id_client][9] = reader.readElementText();
                    element_client = "nbcontrats";
                } else if(element_client == "nbcontrats") {
                    clients[id_client][10] = reader.readElementText();
                    element_client = "datecreation";
                } else if(element_client == "datecreation") {
                    clients[id_client][11] = reader.readElementText();
                    id_client += 1;
                    element_client = "client";
                }
            }
        }
        reader.readNext();
    }

    fileXml.close();
}

void MainWindow::initAnnonces()
{
    nb_aff_annonces_vente = 0;
    nb_aff_annonces_location = 0;
    nb_aff_histo_vente = 0;
    nb_aff_histo_location = 0;

    for(int i=0; i<nb_annonces; i++)
    {
        if(annonces[i][0] == "Vente" && annonces[i][19] == "0") {
            for(int j=0; j<22; j++) {
                aff_annonces_vente[nb_aff_annonces_vente][j] = annonces[i][j];
            }
            nb_aff_annonces_vente += 1;
        } else if(annonces[i][0] == "Location" && annonces[i][19] == "0") {
            for(int j=0; j<22; j++) {
                aff_annonces_location[nb_aff_annonces_location][j] = annonces[i][j];
            }
            nb_aff_annonces_location += 1;
        } else if(annonces[i][0] == "Vente" && annonces[i][19] == "1") {
            for(int j=0; j<22; j++) {
                aff_histo_vente[nb_aff_histo_vente][j] = annonces[i][j];
            }
            nb_aff_histo_vente += 1;
        } else {
            for(int j=0; j<22; j++) {
                aff_histo_location[nb_aff_histo_location][j] = annonces[i][j];
            }
            nb_aff_histo_location += 1;
        }
    }
}

void MainWindow::addTabAnnoncesVente()
{
    ui->tableOffreVente->clearContents();

    for(int i=0; i<nb_aff_annonces_vente; i++)
    {
        wdg_photo = new QTableWidgetItem();
        wdg_bien = new QTableWidgetItem();
        wdg_pieces = new QTableWidgetItem();
        wdg_superficie = new QTableWidgetItem();
        wdg_ville = new QTableWidgetItem();
        wdg_prix = new QTableWidgetItem();
        wdg_date = new QTableWidgetItem();

        QIcon icon(aff_annonces_vente[i][10]);
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces_vente[i][1]);
        wdg_pieces->setText(aff_annonces_vente[i][2]);
        wdg_superficie->setText(aff_annonces_vente[i][3]);
        wdg_ville->setText(aff_annonces_vente[i][5]);
        wdg_prix->setText(aff_annonces_vente[i][8]);
        wdg_date->setText(aff_annonces_vente[i][9]);

        ui->tableOffreVente->insertRow(i);
        ui->tableOffreVente->setItem(i, 0, wdg_photo);
        ui->tableOffreVente->setItem(i, 1, wdg_bien);
        ui->tableOffreVente->setItem(i, 2, wdg_pieces);
        ui->tableOffreVente->setItem(i, 3, wdg_superficie);
        ui->tableOffreVente->setItem(i, 4, wdg_ville);
        ui->tableOffreVente->setItem(i, 5, wdg_prix);
        ui->tableOffreVente->setItem(i, 6, wdg_date);
    }
}

void MainWindow::addTabAnnoncesLocation()
{
    ui->tableOffreLocation->clearContents();

    for(int i=0; i<nb_aff_annonces_location; i++)
    {
        wdg_photo = new QTableWidgetItem();
        wdg_bien = new QTableWidgetItem();
        wdg_pieces = new QTableWidgetItem();
        wdg_superficie = new QTableWidgetItem();
        wdg_ville = new QTableWidgetItem();
        wdg_prix = new QTableWidgetItem();
        wdg_date = new QTableWidgetItem();

        QIcon icon(aff_annonces_location[i][10]);
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces_location[i][1]);
        wdg_pieces->setText(aff_annonces_location[i][2]);
        wdg_superficie->setText(aff_annonces_location[i][3]);
        wdg_ville->setText(aff_annonces_location[i][5]);
        wdg_prix->setText(aff_annonces_location[i][8]);
        wdg_date->setText(aff_annonces_location[i][9]);

        ui->tableOffreLocation->insertRow(i);
        ui->tableOffreLocation->setItem(i, 0, wdg_photo);
        ui->tableOffreLocation->setItem(i, 1, wdg_bien);
        ui->tableOffreLocation->setItem(i, 2, wdg_pieces);
        ui->tableOffreLocation->setItem(i, 3, wdg_superficie);
        ui->tableOffreLocation->setItem(i, 4, wdg_ville);
        ui->tableOffreLocation->setItem(i, 5, wdg_prix);
        ui->tableOffreLocation->setItem(i, 6, wdg_date);
    }
}

void MainWindow::addTabHistoVente()
{
    ui->tableBienVendu->clearContents();

    for(int i=0; i<nb_aff_histo_vente; i++)
    {
        wdg_photo = new QTableWidgetItem();
        wdg_bien = new QTableWidgetItem();
        wdg_pieces = new QTableWidgetItem();
        wdg_superficie = new QTableWidgetItem();
        wdg_ville = new QTableWidgetItem();
        wdg_prix = new QTableWidgetItem();
        wdg_date = new QTableWidgetItem();

        QIcon icon(aff_histo_vente[i][10]);
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_histo_vente[i][1]);
        wdg_pieces->setText(aff_histo_vente[i][2]);
        wdg_superficie->setText(aff_histo_vente[i][3]);
        wdg_ville->setText(aff_histo_vente[i][5]);
        wdg_prix->setText(aff_histo_vente[i][8]);
        wdg_date->setText(aff_histo_vente[i][9]);

        ui->tableBienVendu->insertRow(i);
        ui->tableBienVendu->setItem(i, 0, wdg_photo);
        ui->tableBienVendu->setItem(i, 1, wdg_bien);
        ui->tableBienVendu->setItem(i, 2, wdg_pieces);
        ui->tableBienVendu->setItem(i, 3, wdg_superficie);
        ui->tableBienVendu->setItem(i, 4, wdg_ville);
        ui->tableBienVendu->setItem(i, 5, wdg_prix);
        ui->tableBienVendu->setItem(i, 6, wdg_date);
    }
}

void MainWindow::addTabHistoLocation()
{
    ui->tableBienLoue->clearContents();

    for(int i=0; i<nb_aff_histo_location; i++)
    {
        wdg_photo = new QTableWidgetItem();
        wdg_bien = new QTableWidgetItem();
        wdg_pieces = new QTableWidgetItem();
        wdg_superficie = new QTableWidgetItem();
        wdg_ville = new QTableWidgetItem();
        wdg_prix = new QTableWidgetItem();
        wdg_date = new QTableWidgetItem();

        QIcon icon(aff_histo_location[i][10]);
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_histo_location[i][1]);
        wdg_pieces->setText(aff_histo_location[i][2]);
        wdg_superficie->setText(aff_histo_location[i][3]);
        wdg_ville->setText(aff_histo_location[i][5]);
        wdg_prix->setText(aff_histo_location[i][8]);
        wdg_date->setText(aff_histo_location[i][9]);

        ui->tableBienLoue->insertRow(i);
        ui->tableBienLoue->setItem(i, 0, wdg_photo);
        ui->tableBienLoue->setItem(i, 1, wdg_bien);
        ui->tableBienLoue->setItem(i, 2, wdg_pieces);
        ui->tableBienLoue->setItem(i, 3, wdg_superficie);
        ui->tableBienLoue->setItem(i, 4, wdg_ville);
        ui->tableBienLoue->setItem(i, 5, wdg_prix);
        ui->tableBienLoue->setItem(i, 6, wdg_date);
    }
}

void MainWindow::addTabClients()
{
    ui->tableClient->clearContents();

    for(int i=0; i<nb_clients; i++)
    {
        wdg_id_client = new QTableWidgetItem();
        wdg_nom = new QTableWidgetItem();
        wdg_prenom = new QTableWidgetItem();
        wdg_ville = new QTableWidgetItem();
        wdg_courriel = new QTableWidgetItem();
        wdg_telephone = new QTableWidgetItem();

        wdg_id_client->setText(clients[i][0]);
        wdg_nom->setText(clients[i][2]);
        wdg_prenom->setText(clients[i][3]);
        wdg_ville->setText(clients[i][6]);
        wdg_courriel->setText(clients[i][8]);
        wdg_telephone->setText(clients[i][9]);

        ui->tableBienLoue->insertRow(i);
        ui->tableBienLoue->setItem(i, 0, wdg_id_client);
        ui->tableBienLoue->setItem(i, 1, wdg_nom);
        ui->tableBienLoue->setItem(i, 2, wdg_prenom);
        ui->tableBienLoue->setItem(i, 4, wdg_ville);
        ui->tableBienLoue->setItem(i, 5, wdg_courriel);
        ui->tableBienLoue->setItem(i, 6, wdg_telephone);
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
        writer.writeTextElement("idprop", annonces[i][20]);
        writer.writeTextElement("idclient", annonces[i][21]);
        writer.writeEndElement();
    }

    for(int i=0; i<nb_clients; i++)
    {
        writer.writeStartElement("client");
        writer.writeTextElement("identifiant", clients[i][0]);
        writer.writeTextElement("genre", clients[i][1]);
        writer.writeTextElement("nom", clients[i][2]);
        writer.writeTextElement("prenom", clients[i][3]);
        writer.writeTextElement("datenaissance", clients[i][4]);
        writer.writeTextElement("adresseclient", clients[i][5]);
        writer.writeTextElement("villeclient", clients[i][6]);
        writer.writeTextElement("codepostalclient", clients[i][7]);
        writer.writeTextElement("courriel", clients[i][8]);
        writer.writeTextElement("telephone", clients[i][9]);
        writer.writeTextElement("nbcontrats", clients[i][10]);
        writer.writeTextElement("datecreation", clients[i][11]);
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
        annonces[nb_annonces][9] = this->date;
        annonces[nb_annonces][10] = this->photoPrincipale;
        annonces[nb_annonces][11] = this->photosSupp[0];
        annonces[nb_annonces][12] = this->photosSupp[1];
        annonces[nb_annonces][13] = this->photosSupp[2];
        annonces[nb_annonces][14] = this->photosSupp[3];
        annonces[nb_annonces][15] = this->photosSupp[4];
        annonces[nb_annonces][16] = this->photosSupp[5];
        annonces[nb_annonces][17] = this->photosSupp[6];
        annonces[nb_annonces][18] = this->photosSupp[7];
        annonces[nb_annonces][19] = "0";

        nb_annonces += 1;
        initAnnonces();
        addTabAnnoncesVente();
        addTabAnnoncesLocation();
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

void MainWindow::setDate(QString d)
{
    this->date = d;
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

void MainWindow::setHisto(int b)
{
    this->histo = b;
}


void MainWindow::on_tableOffreVente_clicked(const QModelIndex &index)
{
    Annonce voir_annonce(this,index.row(),"Vendu");
    voir_annonce.exec();
}

void MainWindow::on_tableOffreLocation_clicked(const QModelIndex &index)
{
    Annonce voir_annonce(this,index.row(),"Loué");
    voir_annonce.exec();
}

void MainWindow::on_tableBienVendu_clicked(const QModelIndex &index)
{
    Annonce voir_annonce(this,index.row(),"Remettre en vente");
    voir_annonce.exec();
}

void MainWindow::on_tableBienLoue_clicked(const QModelIndex &index)
{
    Annonce voir_annonce(this,index.row(),"Remettre en location");
    voir_annonce.exec();
}

