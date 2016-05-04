#include <QMessageBox>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajout.h"
#include "ui_ajout.h"
#include "annoncewindow.h"
#include "ui_annoncewindow.h"
#include "ajoutclient.h"
#include "ui_ajoutclient.h"
#include "stats_immo.h"
#include "ui_stats_immo.h"
#include "stats_clients.h"
#include "ui_stats_clients.h"
#include "choix_client.h"
#include "ui_choix_client.h"
#include <string>
#include "ui_clientwindow.h"
#include "clientwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableOffreLocation->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableOffreVente->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableBienLoue->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableBienVendu->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableClient->setSelectionBehavior(QAbstractItemView::SelectRows);
    int w = ui->l_icon->width()+210;
    int h= ui->l_icon->height()+210;
    QPixmap *pixmap_img2 = new QPixmap("../../../../BestResidence/Img/icon.png");
    ui->l_icon->setPixmap((*pixmap_img2).scaled(w,h,Qt::KeepAspectRatio));
    readXmlFile();
    set_aff_annonces_vente();
    this->aff_annonces_vente = immo_tri_date_decroissante(this->aff_annonces_vente);
    addTabAnnoncesVente();
    set_aff_annonces_location();
    this->aff_annonces_location = immo_tri_date_decroissante(this->aff_annonces_location);
    addTabAnnoncesLocation();
    set_aff_histo_vente();
    this->aff_histo_vente = immo_tri_date_decroissante(this->aff_histo_vente);
    addTabHistoVente();
    set_aff_histo_location();
    this->aff_histo_location = immo_tri_date_decroissante(this->aff_histo_location);
    addTabHistoLocation();
    set_aff_clients();
    this->aff_clients = client_tri_date_decroissante(this->aff_clients);
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
    //QString fileXmlName = "/Users/jordan/Dropbox/Cours/L3 - S6/Interface homme-machine/Projet/BestResidence/BestResidence/annonces.xml";
    QString fileXmlName = "../../../../BestResidence/annonces.xml";
    QFile fileXml(fileXmlName);

    QString xml_typeAnnonce;
    QString xml_typeBien;
    QString xml_nbPieces;
    QString xml_superficie;
    QString xml_adresse;
    QString xml_ville;
    QString xml_codePostal;
    QString xml_description;
    QString xml_prix;
    QString xml_date;
    QString xml_photoPrincipale;
    QList<QString> xml_photosSupp;
    QString xml_histo;
    QString xml_idprop;
    QString xml_idclient;

    QString xml_identifiant;
    QString xml_genre;
    QString xml_nom;
    QString xml_prenom;
    QString xml_dateNaissance;
    QString xml_adresseClient;
    QString xml_villeClient;
    QString xml_codePostalClient;
    QString xml_courriel;
    QString xml_telephone;
    QString xml_nbContrats;
    QString xml_dateCreation;

    // Ouverture du fichier XML en lecture seule et en mode texte (Sort de la fonction si le fichier ne peut etre ouvert).
    if (!fileXml.open(QFile::ReadOnly | QFile::Text))
        return;

    // Initialise l'instance reader avec le flux XML venant de file
    reader.setDevice(&fileXml);

    // charge les informations du fichier xml dans l'application
    QString element_immo = "immobilier";
    QString element_client = "client";
    reader.readNext();
    while (!reader.atEnd())
    {
        if(reader.isStartElement()) {
            if(reader.name() == element_client) {
                if(element_client == "client") {
                    xml_identifiant = "";
                    xml_genre = "";
                    xml_nom = "";
                    xml_prenom = "";
                    xml_dateNaissance = "";
                    xml_adresseClient = "";
                    xml_villeClient = "";
                    xml_codePostalClient = "";
                    xml_courriel = "";
                    xml_telephone = "";
                    xml_nbContrats = "";
                    xml_dateCreation = "";
                    element_client = "identifiant";
                } else if(element_client == "identifiant") {
                    xml_identifiant = reader.readElementText();
                    element_client = "genre";
                } else if(element_client == "genre") {
                    xml_genre = reader.readElementText();
                    element_client = "nom";
                } else if(element_client == "nom") {
                    xml_nom = reader.readElementText();
                    element_client = "prenom";
                } else if(element_client == "prenom") {
                    xml_prenom = reader.readElementText();
                    element_client = "datenaissance";
                } else if(element_client == "datenaissance") {
                    xml_dateNaissance = reader.readElementText();
                    element_client = "adresseclient";
                } else if(element_client == "adresseclient") {
                    xml_adresseClient = reader.readElementText();
                    element_client = "villeclient";
                } else if(element_client == "villeclient") {
                    xml_villeClient = reader.readElementText();
                    element_client = "codepostalclient";
                } else if(element_client == "codepostalclient") {
                    xml_codePostalClient = reader.readElementText();
                    element_client = "courriel";
                } else if(element_client == "courriel") {
                    xml_courriel = reader.readElementText();
                    element_client = "telephone";
                } else if(element_client == "telephone") {
                    xml_telephone = reader.readElementText();
                    element_client = "nbcontrats";
                } else if(element_client == "nbcontrats") {
                    xml_nbContrats = reader.readElementText();
                    element_client = "datecreation";
                } else if(element_client == "datecreation") {
                    xml_dateCreation = reader.readElementText();
                    element_client = "client";
                    if(xml_identifiant.toInt()>=Client::id)
                        Client::id=xml_identifiant.toInt()+1;
                    Client* c = new Client(xml_identifiant, xml_genre, xml_nom, xml_prenom, xml_dateNaissance, xml_adresseClient, xml_villeClient, xml_codePostalClient, xml_courriel, xml_telephone, xml_nbContrats.toInt(), QDate::fromString(xml_dateCreation, "dd/MM/yyyy"));
                    clients.append(c);
                }
            } else if(reader.name() == element_immo) {
                if(element_immo == "immobilier") {
                    xml_typeAnnonce = "";
                    xml_typeBien = "";
                    xml_nbPieces = "";
                    xml_superficie = "";
                    xml_adresse = "";
                    xml_ville = "";
                    xml_codePostal = "";
                    xml_description = "";
                    xml_prix = "";
                    xml_date = "";
                    xml_photoPrincipale = "";
                    xml_photosSupp.clear();
                    xml_histo = "";
                    xml_idprop = "";
                    xml_idclient = "";
                    element_immo = "annonce";
                } else if(element_immo == "annonce") {
                    xml_typeAnnonce = reader.readElementText();
                    element_immo = "bien";
                } else if(element_immo == "bien") {
                    xml_typeBien = reader.readElementText();
                    element_immo = "pieces";
                } else if(element_immo == "pieces") {
                    xml_nbPieces = reader.readElementText();
                    element_immo = "superficie";
                } else if(element_immo == "superficie") {
                    xml_superficie = reader.readElementText();
                    element_immo = "adresse";
                } else if(element_immo == "adresse") {
                    xml_adresse = reader.readElementText();
                    element_immo = "ville";
                } else if(element_immo == "ville") {
                    xml_ville = reader.readElementText();
                    element_immo = "codepostal";
                } else if(element_immo == "codepostal") {
                    xml_codePostal = reader.readElementText();
                    element_immo = "description";
                } else if(element_immo == "description") {
                    xml_description = reader.readElementText();
                    element_immo = "prix";
                } else if(element_immo == "prix") {
                    xml_prix = reader.readElementText();
                    element_immo = "date";
                } else if(element_immo == "date") {
                    xml_date = reader.readElementText();
                    element_immo = "principale";
                } else if(element_immo == "principale") {
                    xml_photoPrincipale = reader.readElementText();
                    element_immo = "supp1";
                } else if(element_immo == "supp1") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "supp2";
                } else if(element_immo == "supp2") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "supp3";
                } else if(element_immo == "supp3") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "supp4";
                } else if(element_immo == "supp4") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "supp5";
                } else if(element_immo == "supp5") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "supp6";
                } else if(element_immo == "supp6") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "supp7";
                } else if(element_immo == "supp7") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "supp8";
                } else if(element_immo == "supp8") {
                    QString s = reader.readElementText();
                    if(s!="")
                        xml_photosSupp.append(s);
                    element_immo = "histo";
                } else if(element_immo == "histo") {
                    xml_histo = reader.readElementText();
                    element_immo = "idprop";
                } else if(element_immo == "idprop") {
                    xml_idprop = reader.readElementText();
                    element_immo = "idclient";
                } else if(element_immo == "idclient") {
                    xml_idclient = reader.readElementText();
                    element_immo = "immobilier";

                    Client* prop;
                    bool trouve = 0;
                    for(int i=0;i<clients.length();i++)
                    {
                        if(clients.value(i)->getId() == xml_idprop)
                        {
                            prop = clients.value(i);
                            trouve = 1;
                        }
                    }
                    if(!trouve) {
                        prop = new Client();
                    }

                    Client* client;
                    trouve = 0;
                    for(int i=0;i<clients.length();i++)
                    {
                        if(clients.value(i)->getId() == xml_idclient)
                        {
                            client = clients.value(i);
                            trouve = 1;
                        }
                    }
                    if(!trouve) {
                        client = new Client();
                    }

                    Annonce* a = new Annonce(xml_typeAnnonce, xml_typeBien, xml_nbPieces.toInt(), xml_superficie.toDouble(), xml_adresse, xml_ville, xml_codePostal, xml_description, xml_prix.toDouble(), QDate::fromString(xml_date, "dd/MM/yyyy"), xml_photoPrincipale, xml_photosSupp, xml_histo.toInt(), prop, client);
                    annonces.append(a);
                }
            }
        }
        reader.readNext();
    }

    fileXml.close();
}

void MainWindow::set_aff_annonces_vente()
{
    this->aff_annonces_vente.clear();
    for(int i=0; i<annonces.length(); i++)
    {
        if(annonces.value(i)->getTypeAnnonce() == "Vente" && annonces.value(i)->getHisto() == 0)
        {
            this->aff_annonces_vente.append(annonces.value(i));
        }
    }
}

QList<Annonce*> MainWindow::get_aff_annonces_vente()
{
    return this->aff_annonces_vente;
}



void MainWindow::set_aff_histo_vente()
{
    this->aff_histo_vente.clear();
    for(int i=0; i<annonces.length(); i++)
    {
        if(annonces.value(i)->getTypeAnnonce() == "Vente" && annonces.value(i)->getHisto() == 1)
        {
            this->aff_histo_vente.append(annonces.value(i));
        }
    }
}

QList<Annonce*> MainWindow::get_aff_histo_vente()
{
    return this->aff_histo_vente;
}



void MainWindow::set_aff_annonces_location()
{
    this->aff_annonces_location.clear();
    for(int i=0; i<annonces.length(); i++)
    {
        if(annonces.value(i)->getTypeAnnonce() == "Location" && annonces.value(i)->getHisto() == 0)
        {
            this->aff_annonces_location.append(annonces.value(i));
        }
    }
}

QList<Annonce*> MainWindow::get_aff_annonces_location()
{
    return this->aff_annonces_location;
}



void MainWindow::set_aff_histo_location()
{
    this->aff_histo_location.clear();
    for(int i=0; i<annonces.length(); i++)
    {
        if(annonces.value(i)->getTypeAnnonce() == "Location" && annonces.value(i)->getHisto() == 1)
        {
            this->aff_histo_location.append(annonces.value(i));
        }
    }
}

QList<Annonce*> MainWindow::get_aff_histo_location()
{
    return this->aff_histo_location;
}

void MainWindow::set_aff_clients()
{
    this->aff_clients.clear();
    for(int i=0; i<clients.length(); i++)
    {
        this->aff_clients.append(clients.value(i));
    }
}

QList<Client*> MainWindow::get_aff_clients()
{
    return this->aff_clients;
}


void MainWindow::addTabAnnoncesVente()
{
    ui->tableOffreVente->setIconSize(QSize(100, 200));
    ui->tableOffreVente->setColumnWidth(0,200);
    int nb = ui->tableOffreVente->rowCount();
    for(int k=0; k<nb; k++)
    {
        ui->tableOffreVente->removeRow(0);
    }
    QList<Annonce*> aff_annonces = this->aff_annonces_vente;

    for(int i=0; i<aff_annonces.length(); i++)
    {
        QTableWidgetItem* wdg_photo = new QTableWidgetItem();
        QTableWidgetItem* wdg_bien= new QTableWidgetItem();
        QTableWidgetItem* wdg_pieces = new QTableWidgetItem();
        QTableWidgetItem* wdg_superficie = new QTableWidgetItem();
        QTableWidgetItem* wdg_ville = new QTableWidgetItem();
        QTableWidgetItem* wdg_prix = new QTableWidgetItem();
        QTableWidgetItem* wdg_date = new QTableWidgetItem();
        wdg_photo->setFlags(wdg_photo->flags() ^ Qt::ItemIsEditable);
        wdg_bien->setFlags(wdg_bien->flags() ^ Qt::ItemIsEditable);
        wdg_pieces->setFlags(wdg_pieces->flags() ^ Qt::ItemIsEditable);
        wdg_superficie->setFlags(wdg_superficie->flags() ^ Qt::ItemIsEditable);
        wdg_ville->setFlags(wdg_ville->flags() ^ Qt::ItemIsEditable);
        wdg_prix->setFlags(wdg_prix->flags() ^ Qt::ItemIsEditable);
        wdg_date->setFlags(wdg_date->flags() ^ Qt::ItemIsEditable);

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate().toString("dd/MM/yyyy"));

        ui->tableOffreVente->insertRow(i);
        ui->tableOffreVente->setRowHeight(i,100);
        ui->tableOffreVente->setItem(i, 0, wdg_photo);
        ui->tableOffreVente->setItem(i, 1, wdg_bien);
        ui->tableOffreVente->setItem(i, 2, wdg_pieces);
        ui->tableOffreVente->setItem(i, 3, wdg_superficie);
        ui->tableOffreVente->setItem(i, 4, wdg_ville);
        ui->tableOffreVente->setItem(i, 5, wdg_prix);
        ui->tableOffreVente->setItem(i, 6, wdg_date);

        ui->tableOffreVente->resizeRowsToContents();
        ui->tableOffreVente->resizeColumnsToContents();
        ui->tableOffreVente->horizontalHeader()->setStretchLastSection(true);
        ui->tableOffreVente->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

void MainWindow::addTabAnnoncesLocation()
{
    ui->tableOffreLocation->setIconSize(QSize(100, 200));
    ui->tableOffreLocation->setColumnWidth(0,200);
    int nb = ui->tableOffreLocation->rowCount();
    for(int k=0; k<nb; k++)
    {
        ui->tableOffreLocation->removeRow(0);
    }
    QList<Annonce*> aff_annonces = this->aff_annonces_location;

    for(int i=0; i<aff_annonces.length(); i++)
    {
        QTableWidgetItem* wdg_photo = new QTableWidgetItem();
        QTableWidgetItem* wdg_bien= new QTableWidgetItem();
        QTableWidgetItem* wdg_pieces = new QTableWidgetItem();
        QTableWidgetItem* wdg_superficie = new QTableWidgetItem();
        QTableWidgetItem* wdg_ville = new QTableWidgetItem();
        QTableWidgetItem* wdg_prix = new QTableWidgetItem();
        QTableWidgetItem* wdg_date = new QTableWidgetItem();

        wdg_photo->setFlags(wdg_photo->flags() ^ Qt::ItemIsEditable);
        wdg_bien->setFlags(wdg_bien->flags() ^ Qt::ItemIsEditable);
        wdg_pieces->setFlags(wdg_pieces->flags() ^ Qt::ItemIsEditable);
        wdg_superficie->setFlags(wdg_superficie->flags() ^ Qt::ItemIsEditable);
        wdg_ville->setFlags(wdg_ville->flags() ^ Qt::ItemIsEditable);
        wdg_prix->setFlags(wdg_prix->flags() ^ Qt::ItemIsEditable);
        wdg_date->setFlags(wdg_date->flags() ^ Qt::ItemIsEditable);

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate().toString("dd/MM/yyyy"));

        ui->tableOffreLocation->insertRow(i);
        ui->tableOffreLocation->setRowHeight(i,100);
        ui->tableOffreLocation->setItem(i, 0, wdg_photo);
        ui->tableOffreLocation->setItem(i, 1, wdg_bien);
        ui->tableOffreLocation->setItem(i, 2, wdg_pieces);
        ui->tableOffreLocation->setItem(i, 3, wdg_superficie);
        ui->tableOffreLocation->setItem(i, 4, wdg_ville);
        ui->tableOffreLocation->setItem(i, 5, wdg_prix);
        ui->tableOffreLocation->setItem(i, 6, wdg_date);

        ui->tableOffreLocation->resizeRowsToContents();
        ui->tableOffreLocation->resizeColumnsToContents();
        ui->tableOffreLocation->horizontalHeader()->setStretchLastSection(true);
        ui->tableOffreLocation->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

void MainWindow::addTabHistoVente()
{
    ui->tableBienVendu->setIconSize(QSize(100, 200));
    ui->tableBienVendu->setColumnWidth(0,200);
    int nb = ui->tableBienVendu->rowCount();
    for(int k=0; k<nb; k++)
    {
        ui->tableBienVendu->removeRow(0);
    }
    QList<Annonce*> aff_annonces = this->aff_histo_vente;

    for(int i=0; i<aff_annonces.length(); i++)
    {

        QTableWidgetItem* wdg_photo = new QTableWidgetItem();
        QTableWidgetItem* wdg_bien= new QTableWidgetItem();
        QTableWidgetItem* wdg_pieces = new QTableWidgetItem();
        QTableWidgetItem* wdg_superficie = new QTableWidgetItem();
        QTableWidgetItem* wdg_ville = new QTableWidgetItem();
        QTableWidgetItem* wdg_prix = new QTableWidgetItem();
        QTableWidgetItem* wdg_date = new QTableWidgetItem();
        QTableWidgetItem* wdg_client = new QTableWidgetItem();

        wdg_photo->setFlags(wdg_photo->flags() ^ Qt::ItemIsEditable);
        wdg_bien->setFlags(wdg_bien->flags() ^ Qt::ItemIsEditable);
        wdg_pieces->setFlags(wdg_pieces->flags() ^ Qt::ItemIsEditable);
        wdg_superficie->setFlags(wdg_superficie->flags() ^ Qt::ItemIsEditable);
        wdg_ville->setFlags(wdg_ville->flags() ^ Qt::ItemIsEditable);
        wdg_prix->setFlags(wdg_prix->flags() ^ Qt::ItemIsEditable);
        wdg_date->setFlags(wdg_date->flags() ^ Qt::ItemIsEditable);
        wdg_client->setFlags(wdg_client->flags() ^ Qt::ItemIsEditable);

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate().toString("dd/MM/yyyy"));
        wdg_client->setText(aff_annonces.value(i)->getClient()->getId());

        ui->tableBienVendu->insertRow(i);
        ui->tableBienVendu->setRowHeight(i,100);
        ui->tableBienVendu->setItem(i, 0, wdg_photo);
        ui->tableBienVendu->setItem(i, 1, wdg_bien);
        ui->tableBienVendu->setItem(i, 2, wdg_pieces);
        ui->tableBienVendu->setItem(i, 3, wdg_superficie);
        ui->tableBienVendu->setItem(i, 4, wdg_ville);
        ui->tableBienVendu->setItem(i, 5, wdg_prix);
        ui->tableBienVendu->setItem(i, 6, wdg_date);
        ui->tableBienVendu->setItem(i, 7, wdg_client);

        ui->tableBienVendu->resizeRowsToContents();
        ui->tableBienVendu->resizeColumnsToContents();
        ui->tableBienVendu->horizontalHeader()->setStretchLastSection(true);
        ui->tableBienVendu->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

void MainWindow::addTabHistoLocation()
{
    int nb = ui->tableBienLoue->rowCount();
    ui->tableBienLoue->setIconSize(QSize(100, 200));
    ui->tableBienLoue->setColumnWidth(0,200);
    for(int k=0; k<nb; k++)
    {
        ui->tableBienLoue->removeRow(0);
    }
    QList<Annonce*> aff_annonces = this->aff_histo_location;

    for(int i=0; i<aff_annonces.length(); i++)
    {
        QTableWidgetItem* wdg_photo = new QTableWidgetItem();
        QTableWidgetItem* wdg_bien= new QTableWidgetItem();
        QTableWidgetItem* wdg_pieces = new QTableWidgetItem();
        QTableWidgetItem* wdg_superficie = new QTableWidgetItem();
        QTableWidgetItem* wdg_ville = new QTableWidgetItem();
        QTableWidgetItem* wdg_prix = new QTableWidgetItem();
        QTableWidgetItem* wdg_date = new QTableWidgetItem();
        QTableWidgetItem* wdg_client = new QTableWidgetItem();

        wdg_photo->setFlags(wdg_photo->flags() ^ Qt::ItemIsEditable);
        wdg_bien->setFlags(wdg_bien->flags() ^ Qt::ItemIsEditable);
        wdg_pieces->setFlags(wdg_pieces->flags() ^ Qt::ItemIsEditable);
        wdg_superficie->setFlags(wdg_superficie->flags() ^ Qt::ItemIsEditable);
        wdg_ville->setFlags(wdg_ville->flags() ^ Qt::ItemIsEditable);
        wdg_prix->setFlags(wdg_prix->flags() ^ Qt::ItemIsEditable);
        wdg_date->setFlags(wdg_date->flags() ^ Qt::ItemIsEditable);
        wdg_client->setFlags(wdg_client->flags() ^ Qt::ItemIsEditable);

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate().toString("dd/MM/yyyy"));
        wdg_client->setText(aff_annonces.value(i)->getClient()->getId());

        ui->tableBienLoue->insertRow(i);
        ui->tableBienLoue->setRowHeight(i,100);
        ui->tableBienLoue->setItem(i, 0, wdg_photo);
        ui->tableBienLoue->setItem(i, 1, wdg_bien);
        ui->tableBienLoue->setItem(i, 2, wdg_pieces);
        ui->tableBienLoue->setItem(i, 3, wdg_superficie);
        ui->tableBienLoue->setItem(i, 4, wdg_ville);
        ui->tableBienLoue->setItem(i, 5, wdg_prix);
        ui->tableBienLoue->setItem(i, 6, wdg_date);
        ui->tableBienLoue->setItem(i, 7, wdg_client);

        ui->tableBienLoue->resizeRowsToContents();
        ui->tableBienLoue->resizeColumnsToContents();
        ui->tableBienLoue->horizontalHeader()->setStretchLastSection(true);
        ui->tableBienLoue->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

void MainWindow::addTabClients()
{
    int nb = ui->tableClient->rowCount();
    for(int k=0; k<nb; k++)
    {
        ui->tableClient->removeRow(0);
    }
    QList<Client*> aff_c = this->aff_clients;

    for(int i=0; i<aff_c.length(); i++)
    {
        QTableWidgetItem* wdg_id_client = new QTableWidgetItem();
        QTableWidgetItem* wdg_nom = new QTableWidgetItem();
        QTableWidgetItem* wdg_prenom = new QTableWidgetItem();
        QTableWidgetItem* wdg_courriel = new QTableWidgetItem();
        QTableWidgetItem* wdg_telephone = new QTableWidgetItem();
        QTableWidgetItem* wdg_ville = new QTableWidgetItem();

        wdg_id_client->setFlags(wdg_id_client->flags() ^ Qt::ItemIsEditable);
        wdg_nom->setFlags(wdg_nom->flags() ^ Qt::ItemIsEditable);
        wdg_prenom->setFlags(wdg_prenom->flags() ^ Qt::ItemIsEditable);
        wdg_courriel->setFlags(wdg_courriel->flags() ^ Qt::ItemIsEditable);
        wdg_ville->setFlags(wdg_ville->flags() ^ Qt::ItemIsEditable);
        wdg_telephone->setFlags(wdg_telephone->flags() ^ Qt::ItemIsEditable);

        wdg_id_client->setText(aff_c.value(i)->getId());
        wdg_nom->setText(aff_c.value(i)->getNom());
        wdg_prenom->setText(aff_c.value(i)->getPrenom());
        wdg_ville->setText(aff_c.value(i)->getVilleClient());
        wdg_courriel->setText(aff_c.value(i)->getCourriel());
        wdg_telephone->setText(aff_c.value(i)->getTelephone());

        ui->tableClient->insertRow(i);
        ui->tableClient->setItem(i, 0, wdg_id_client);
        ui->tableClient->setItem(i, 1, wdg_nom);
        ui->tableClient->setItem(i, 2, wdg_prenom);
        ui->tableClient->setItem(i, 3, wdg_ville);
        ui->tableClient->setItem(i, 4, wdg_courriel);
        ui->tableClient->setItem(i, 5, wdg_telephone);

        ui->tableClient->resizeRowsToContents();
        ui->tableClient->resizeColumnsToContents();
        ui->tableClient->horizontalHeader()->setStretchLastSection(true);
        ui->tableClient->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }
}

void MainWindow::writeXmlFile()
{
    //QString fileXmlName = "/Users/jordan/Dropbox/Cours/L3 - S6/Interface homme-machine/Projet/BestResidence/BestResidence/annonces.xml";
    QString fileXmlName = "../../../../BestResidence/annonces.xml";
    QFile fileXml(fileXmlName);

    // Ouverture du fichier en écriture et en texte. (sort de la fonction si le fichier ne s'ouvre pas)
    if(!fileXml.open(QFile::WriteOnly | QFile::Text))
        return;
    QXmlStreamWriter writer(&fileXml);

    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("bestresidence");

    for(int i=0; i<this->clients.length(); i++)
    {
        Client *c = this->clients.value(i);
        writer.writeStartElement("client");
        writer.writeTextElement("identifiant", c->getId());
        writer.writeTextElement("genre", c->getGenre());
        writer.writeTextElement("nom", c->getNom());
        writer.writeTextElement("prenom", c->getPrenom());
        writer.writeTextElement("datenaissance", c->getDateNaissance());
        writer.writeTextElement("adresseclient", c->getAdresseClient());
        writer.writeTextElement("villeclient", c->getVilleClient());
        writer.writeTextElement("codepostalclient", c->getCodePostalClient());
        writer.writeTextElement("courriel", c->getCourriel());
        writer.writeTextElement("telephone", c->getTelephone());
        writer.writeTextElement("nbcontrats", QString::number(c->getNbContrats()));
        writer.writeTextElement("datecreation", c->getDateCreation().toString("dd/MM/yyyy"));
        writer.writeEndElement();
    }

    for(int i=0; i<annonces.length(); i++)
    {
        Annonce* a = annonces.value(i);
        writer.writeStartElement("immobilier");
        writer.writeTextElement("annonce", a->getTypeAnnonce());
        writer.writeTextElement("bien", a->getTypeBien());
        writer.writeTextElement("pieces", QString::number(a->getNbPieces()));
        writer.writeTextElement("superficie", QString::number(a->getSuperficie()));
        writer.writeTextElement("adresse", a->getAdresse());
        writer.writeTextElement("ville", a->getVille());
        writer.writeTextElement("codepostal", a->getCodePostal());
        writer.writeTextElement("description", a->getDescription());
        writer.writeTextElement("prix", QString::number(a->getPrix()));
        writer.writeTextElement("date", a->getDate().toString("dd/MM/yyyy"));
        writer.writeTextElement("principale", a->getPhotoPrincipale());
        for(int i =0;i<8;i++)
        {
            if(i<a->getPhotosSupp().length())
                writer.writeTextElement("supp"+QString::number(i+1), a->getPhotosSupp().value(i));
            else
                writer.writeTextElement("supp"+QString::number(i+1), "");
        }
        writer.writeTextElement("histo", QString::number(a->getHisto()));
        writer.writeTextElement("idprop", a->getProp()->getId());
        if(a->getClient() != NULL) {
            writer.writeTextElement("idclient", a->getClient()->getId());
        } else {
            writer.writeTextElement("idclient", "");
        }
        writer.writeEndElement();
    }

    writer.writeEndElement();
    writer.writeEndDocument();

    fileXml.close();
}

void MainWindow::majAllTables()
{
    set_aff_annonces_vente();
    this->aff_annonces_vente = immo_tri_date_decroissante(this->aff_annonces_vente);
    addTabAnnoncesVente();
    set_aff_annonces_location();
    this->aff_annonces_location = immo_tri_date_decroissante(this->aff_annonces_location);
    addTabAnnoncesLocation();
    set_aff_histo_vente();
    this->aff_histo_vente = immo_tri_date_decroissante(this->aff_histo_vente);
    addTabHistoVente();
    set_aff_histo_location();
    this->aff_histo_location = immo_tri_date_decroissante(this->aff_histo_location);
    addTabHistoLocation();
    set_aff_clients();
    this->aff_clients = client_tri_date_decroissante(this->aff_clients);
    addTabClients();
}


void MainWindow::on_pushButton_clicked()
{
    if(clients.length() > 0)
    {
        Ajout ajout_bien(this, Qt::WindowFlags());
        ajout_bien.exec();

        if(!annule) {
            set_aff_annonces_vente();
            this->aff_annonces_vente = immo_tri_date_decroissante(this->aff_annonces_vente);
            addTabAnnoncesVente();
            set_aff_annonces_location();
            this->aff_annonces_location = immo_tri_date_decroissante(this->aff_annonces_location);
            addTabAnnoncesLocation();
            set_aff_histo_vente();
            this->aff_histo_vente = immo_tri_date_decroissante(this->aff_histo_vente);
            addTabHistoVente();
            set_aff_histo_location();
            this->aff_histo_location = immo_tri_date_decroissante(this->aff_histo_location);
            addTabHistoLocation();
        }
    } else {
        QMessageBox::warning(this, "Impossible", "Impossible d'ajouter une annonce, il n'existe aucun client");
    }

}

void MainWindow::on_tableOffreVente_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_annonces_vente.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        set_aff_annonces_vente();
        this->aff_annonces_vente = immo_tri_date_decroissante(this->aff_annonces_vente);
        addTabAnnoncesVente();
        set_aff_histo_vente();
        this->aff_histo_vente = immo_tri_date_decroissante(this->aff_histo_vente);
        addTabHistoVente();
    }
}

void MainWindow::on_tableOffreLocation_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_annonces_location.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        set_aff_annonces_location();
        this->aff_annonces_location = immo_tri_date_decroissante(this->aff_annonces_location);
        addTabAnnoncesLocation();
        set_aff_histo_location();
        this->aff_histo_location = immo_tri_date_decroissante(this->aff_histo_location);
        addTabHistoLocation();
    }
}

void MainWindow::on_tableBienVendu_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_histo_vente.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        set_aff_annonces_vente();
        this->aff_annonces_vente = immo_tri_date_decroissante(this->aff_annonces_vente);
        addTabAnnoncesVente();
        set_aff_histo_vente();
        this->aff_histo_vente = immo_tri_date_decroissante(this->aff_histo_vente);
        addTabHistoVente();
    }
}

void MainWindow::on_tableBienLoue_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_histo_location.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        set_aff_annonces_location();
        this->aff_annonces_location = immo_tri_date_decroissante(this->aff_annonces_location);
        addTabAnnoncesLocation();
        set_aff_histo_location();
        this->aff_histo_location = immo_tri_date_decroissante(this->aff_histo_location);
        addTabHistoLocation();
    }
}

void MainWindow::on_tableClient_clicked(const QModelIndex &index)
{
    ClientWindow voirClient(this,this->aff_clients.value(index.row()));
    voirClient.exec();
    if (voirClient.getRefresh())
    {
        set_aff_clients();
        this->aff_clients = client_tri_date_decroissante(this->aff_clients);
        addTabClients();
    }
}

void MainWindow::setAnnule(bool b)
{
    this->annule = b;
}

void MainWindow::on_ajout_client_clicked()
{
    AjoutClient ajoutClient(this, Qt::WindowFlags());
    ajoutClient.exec();
    if(!annule) {
        set_aff_clients();
        this->aff_clients = client_tri_date_decroissante(this->aff_clients);
        addTabClients();
    }
}

void MainWindow::on_ov_btn_rechercher_clicked()
{
    recherche_offre_vente();
}

void MainWindow::on_ol_btn_rechercher_clicked()
{
    recherche_offre_location();
}

void MainWindow::on_bv_btn_rechercher_clicked()
{
    recherche_bien_vendu();
}

void MainWindow::on_bl_btn_rechercher_clicked()
{
    recherche_bien_loue();
}

void MainWindow::on_cl_btn_rechercher_clicked()
{
    recherche_client();
}

void MainWindow::on_ov_btn_stats_clicked()
{
    recherche_offre_vente();
    affiche_stats_immo(this->aff_annonces_vente);
}

void MainWindow::on_ol_btn_stats_clicked()
{
    recherche_offre_location();
    affiche_stats_immo(this->aff_annonces_location);
}

void MainWindow::on_bv_btn_stats_clicked()
{
    recherche_bien_vendu();
    affiche_stats_immo(this->aff_histo_vente);
}

void MainWindow::on_bl_btn_stats_clicked()
{
    recherche_bien_loue();
    affiche_stats_immo(this->aff_histo_location);
}

void MainWindow::on_cl_btn_stats_clicked()
{
    recherche_client();
    affiche_stats_client(this->aff_clients);
}

// ********************* FONCTIONS DE RECHERCHE ET DE TRI ************************

void MainWindow::recherche_offre_vente()
{
    set_aff_annonces_vente();
    if(ui->ov_txt_ville->text() != "")
    {
        QString s = ui->ov_txt_ville->text();
        QChar c = s.at(0);
        if(c >= '0' && c <= '9')
            this->aff_annonces_vente = this->immo_recherche_codepostal(this->aff_annonces_vente, ui->ov_txt_ville->text());
        else
            this->aff_annonces_vente = this->immo_recherche_ville(this->aff_annonces_vente, ui->ov_txt_ville->text());
    }
    if(ui->ov_cbx_photo->isChecked())
        this->aff_annonces_vente = this->immo_recherche_avec_photo(this->aff_annonces_vente);
    if(ui->ov_rb_tri_croissant->isChecked())
        this->aff_annonces_vente = this->immo_tri_date_croissante(this->aff_annonces_vente);
    else
        this->aff_annonces_vente = this->immo_tri_date_decroissante(this->aff_annonces_vente);
    if(ui->ov_txt_prix_min->text() != "" && ui->ov_txt_prix_max->text() != "")
        this->aff_annonces_vente = this->immo_recherche_prix(this->aff_annonces_vente, ui->ov_txt_prix_min->text().toDouble(), ui->ov_txt_prix_max->text().toDouble());
    if(ui->ov_txt_pieces_min->text() != "" && ui->ov_txt_pieces_max->text() != "")
        this->aff_annonces_vente = this->immo_recherche_pieces(this->aff_annonces_vente, ui->ov_txt_pieces_min->text().toInt(), ui->ov_txt_pieces_max->text().toInt());
    this->aff_annonces_vente = this->immo_recherche_type(this->aff_annonces_vente, ui->ov_cbx_maison->isChecked(), ui->ov_cbx_appartement->isChecked(), ui->ov_cbx_bureau->isChecked(), ui->ov_cbx_chateau->isChecked(), ui->ov_cbx_ferme->isChecked(), ui->ov_cbx_commerce->isChecked());
    addTabAnnoncesVente();
}

void MainWindow::recherche_offre_location()
{
    set_aff_annonces_location();
    if(ui->ol_txt_ville->text() != "")
    {
        QString s = ui->ol_txt_ville->text();
        QChar c = s.at(0);
        if(c >= '0' && c <= '9')
            this->aff_annonces_location = this->immo_recherche_codepostal(this->aff_annonces_location, ui->ol_txt_ville->text());
        else
            this->aff_annonces_location = this->immo_recherche_ville(this->aff_annonces_location, ui->ol_txt_ville->text());
    }
    if(ui->ol_cbx_photo->isChecked())
        this->aff_annonces_location = this->immo_recherche_avec_photo(this->aff_annonces_location);
    if(ui->ol_rb_tri_croissant->isChecked())
        this->aff_annonces_location = this->immo_tri_date_croissante(this->aff_annonces_location);
    else
        this->aff_annonces_location = this->immo_tri_date_decroissante(this->aff_annonces_location);
    if(ui->ol_txt_prix_min->text() != "" && ui->ol_txt_prix_max->text() != "")
        this->aff_annonces_location = this->immo_recherche_prix(this->aff_annonces_location, ui->ol_txt_prix_min->text().toDouble(), ui->ol_txt_prix_max->text().toDouble());
    if(ui->ol_txt_pieces_min->text() != "" && ui->ol_txt_pieces_max->text() != "")
        this->aff_annonces_location = this->immo_recherche_pieces(this->aff_annonces_location, ui->ol_txt_pieces_min->text().toInt(), ui->ol_txt_pieces_max->text().toInt());
    this->aff_annonces_location = this->immo_recherche_type(this->aff_annonces_location, ui->ol_cbx_maison->isChecked(), ui->ol_cbx_appartement->isChecked(), ui->ol_cbx_bureau->isChecked(), ui->ol_cbx_chateau->isChecked(), ui->ol_cbx_ferme->isChecked(), ui->ol_cbx_commerce->isChecked());
    addTabAnnoncesLocation();
}

void MainWindow::recherche_bien_vendu()
{
    set_aff_histo_vente();
    if(ui->bv_txt_ville->text() != "")
    {
        QString s = ui->bv_txt_ville->text();
        QChar c = s.at(0);
        if(c >= '0' && c <= '9')
            this->aff_histo_vente = this->immo_recherche_codepostal(this->aff_histo_vente, ui->bv_txt_ville->text());
        else
            this->aff_histo_vente = this->immo_recherche_ville(this->aff_histo_vente, ui->bv_txt_ville->text());
    }
    if(ui->bv_txt_id_client->text() != "")
        this->aff_histo_vente = this->immo_recherche_id_client(this->aff_histo_vente, ui->bv_txt_id_client->text().toInt());
    if(ui->bv_date_min->date() != QDate::fromString("01/01/2000", "dd/MM/yyyy") && ui->bv_date_max->date() != QDate::fromString("01/01/2000", "dd/MM/yyyy"))
        this->aff_histo_vente = this->immo_recherche_date(this->aff_histo_vente, ui->bv_date_min->date(), ui->bv_date_max->date());
    if(ui->bv_rb_tri_croissant->isChecked())
        this->aff_histo_vente = this->immo_tri_date_croissante(this->aff_histo_vente);
    else
        this->aff_histo_vente = this->immo_tri_date_decroissante(this->aff_histo_vente);
    if(ui->bv_txt_prix_min->text() != "" && ui->bv_txt_prix_max->text() != "")
        this->aff_histo_vente = this->immo_recherche_prix(this->aff_histo_vente, ui->bv_txt_prix_min->text().toDouble(), ui->bv_txt_prix_max->text().toDouble());
    if(ui->bv_txt_pieces_min->text() != "" && ui->bv_txt_pieces_max->text() != "")
        this->aff_histo_vente = this->immo_recherche_pieces(this->aff_histo_vente, ui->bv_txt_pieces_min->text().toInt(), ui->bv_txt_pieces_max->text().toInt());
    this->aff_histo_vente = this->immo_recherche_type(this->aff_histo_vente, ui->bv_cbx_maison->isChecked(), ui->bv_cbx_appartement->isChecked(), ui->bv_cbx_bureau->isChecked(), ui->bv_cbx_chateau->isChecked(), ui->bv_cbx_ferme->isChecked(), ui->bv_cbx_commerce->isChecked());
    addTabHistoVente();
}

void MainWindow::recherche_bien_loue()
{
    set_aff_histo_location();
    if(ui->bl_txt_ville->text() != "")
    {
        QString s = ui->bl_txt_ville->text();
        QChar c = s.at(0);
        if(c >= '0' && c <= '9')
            this->aff_histo_location = this->immo_recherche_codepostal(this->aff_histo_location, ui->bl_txt_ville->text());
        else
            this->aff_histo_location = this->immo_recherche_ville(this->aff_histo_location, ui->bl_txt_ville->text());
    }
    if(ui->bl_txt_id_client->text() != "")
        this->aff_histo_location = this->immo_recherche_id_client(this->aff_histo_location, ui->bl_txt_id_client->text().toInt());
    if(ui->bl_date_min->date() != QDate::fromString("01/01/2000", "dd/MM/yyyy") && ui->bl_date_max->date() != QDate::fromString("01/01/2000", "dd/MM/yyyy"))
        this->aff_histo_location = this->immo_recherche_date(this->aff_histo_location, ui->bl_date_min->date(), ui->bl_date_max->date());
    if(ui->bl_rb_tri_croissant->isChecked())
        this->aff_histo_location = this->immo_tri_date_croissante(this->aff_histo_location);
    else
        this->aff_histo_location = this->immo_tri_date_decroissante(this->aff_histo_location);
    if(ui->bl_txt_prix_min->text() != "" && ui->bl_txt_prix_max->text() != "")
        this->aff_histo_location = this->immo_recherche_prix(this->aff_histo_location, ui->bl_txt_prix_min->text().toDouble(), ui->bl_txt_prix_max->text().toDouble());
    if(ui->bl_txt_pieces_min->text() != "" && ui->bl_txt_pieces_max->text() != "")
        this->aff_histo_location = this->immo_recherche_pieces(this->aff_histo_location, ui->bl_txt_pieces_min->text().toInt(), ui->bl_txt_pieces_max->text().toInt());
    this->aff_histo_location = this->immo_recherche_type(this->aff_histo_location, ui->bl_cbx_maison->isChecked(), ui->bl_cbx_appartement->isChecked(), ui->bl_cbx_bureau->isChecked(), ui->bl_cbx_chateau->isChecked(), ui->bl_cbx_ferme->isChecked(), ui->bl_cbx_commerce->isChecked());
    addTabHistoLocation();
}

void MainWindow::recherche_client()
{
    set_aff_clients();
    if(ui->cl_txt_id_client->text() != "")
        this->aff_clients = this->client_recherche_id_client(this->aff_clients, ui->cl_txt_id_client->text());
    if(ui->cl_txt_nom->text() != "")
        this->aff_clients = this->client_recherche_nom(this->aff_clients, ui->cl_txt_nom->text());
    if(ui->cl_txt_ville->text() != "")
    {
        QString s = ui->cl_txt_ville->text();
        QChar c = s.at(0);
        if(c >= '0' && c <= '9')
            this->aff_clients = this->client_recherche_codepostal(this->aff_clients, ui->cl_txt_ville->text());
        else
            this->aff_clients = this->client_recherche_ville(this->aff_clients, ui->cl_txt_ville->text());
    }
    if(ui->cl_rb_tri_croissant->isChecked())
        this->aff_clients = this->client_tri_date_croissante(this->aff_clients);
    else
        this->aff_clients = this->client_tri_date_decroissante(this->aff_clients);
    if(ui->cl_txt_nb_min->text() != "" && ui->cl_txt_nb_max->text() != "")
        this->aff_clients = this->client_recherche_nb_contrats(this->aff_clients, ui->cl_txt_nb_min->text().toInt(), ui->cl_txt_nb_max->text().toInt());
    addTabClients();
}

QList<Annonce*> MainWindow::immo_recherche_ville(QList<Annonce*> ann, QString ville)
{
    QList<Annonce*> r_annonces;
    for(int i=0; i<ann.length(); i++) {
        if(ann.value(i)->getVille() == ville) {
            r_annonces.append(ann.value(i));
        }
    }
    return r_annonces;
}

QList<Annonce*> MainWindow::immo_recherche_codepostal(QList<Annonce*> ann, QString codepostal)
{
    QList<Annonce*> r_annonces;
    for(int i=0; i<ann.length(); i++) {
        if(ann.value(i)->getCodePostal() == codepostal) {
            r_annonces.append(ann.value(i));
        }
    }
    return r_annonces;
}

QList<Annonce*> MainWindow::immo_recherche_prix(QList<Annonce*> ann, double min, double max)
{
    QList<Annonce*> r_annonces;
    for(int i=0; i<ann.length(); i++) {
        if((ann.value(i)->getPrix() >= min) && (ann.value(i)->getPrix() <= max)) {
            r_annonces.append(ann.value(i));
        }
    }
    return r_annonces;
}

QList<Annonce*> MainWindow::immo_recherche_pieces(QList<Annonce*> ann, int min, int max)
{
    QList<Annonce*> r_annonces;
    for(int i=0; i<ann.length(); i++) {
        if((ann.value(i)->getNbPieces() >= min) && (ann.value(i)->getNbPieces() <= max)) {
            r_annonces.append(ann.value(i));
        }
    }
    return r_annonces;
}

QList<Annonce*> MainWindow::immo_recherche_type(QList<Annonce*> ann, bool maison, bool appart, bool bureau, bool chateau, bool ferme, bool commerce)
{
    QList<Annonce*> r_annonces;
    int nb_choix = 0;
    if(maison) {
        nb_choix += 1;
        for(int i=0; i<ann.length(); i++) {
            if(ann.value(i)->getTypeBien() == "Maison") {
                r_annonces.append(ann.value(i));
            }
        }
    }
    if(appart) {
        nb_choix += 1;
        for(int i=0; i<ann.length(); i++) {
            if(ann.value(i)->getTypeBien() == "Appartement") {
                r_annonces.append(ann.value(i));
            }
        }
    }
    if(bureau) {
        nb_choix += 1;
        for(int i=0; i<ann.length(); i++) {
            if(ann.value(i)->getTypeBien() == "Bureau") {
                r_annonces.append(ann.value(i));
            }
        }
    }
    if(chateau) {
        nb_choix += 1;
        for(int i=0; i<ann.length(); i++) {
            if(ann.value(i)->getTypeBien() == "Château") {
                r_annonces.append(ann.value(i));
            }
        }
    }
    if(ferme) {
        nb_choix += 1;
        for(int i=0; i<ann.length(); i++) {
            if(ann.value(i)->getTypeBien() == "Ferme") {
                r_annonces.append(ann.value(i));
            }
        }
    }
    if(commerce) {
        nb_choix += 1;
        for(int i=0; i<ann.length(); i++) {
            if(ann.value(i)->getTypeBien() == "Commerce") {
                r_annonces.append(ann.value(i));
            }
        }
    }

    if(nb_choix == 0) {
        for(int i=0; i<ann.length(); i++) {
            r_annonces.append(ann.value(i));
        }
    }

    return r_annonces;
}

QList<Annonce*> MainWindow::immo_recherche_avec_photo(QList<Annonce*> ann)
{
    QList<Annonce*> r_annonces;
    for(int i=0; i<ann.length(); i++) {
        if(ann.value(i)->getPhotoPrincipale() != "") {
            r_annonces.append(ann.value(i));
        }
    }
    return r_annonces;
}

QList<Annonce*> MainWindow::immo_recherche_date(QList<Annonce*> ann, QDate min, QDate max)
{
    QList<Annonce*> r_annonces;
    for(int i=0; i<ann.length(); i++) {
        if((ann.value(i)->getDate() >= min) && (ann.value(i)->getDate() <= max)) {
            r_annonces.append(ann.value(i));
        }
    }
    return r_annonces;
}

QList<Annonce*> MainWindow::immo_recherche_id_client(QList<Annonce*> ann, int id)
{
    QList<Annonce*> r_annonces;
    for(int i=0; i<ann.length(); i++) {
        if(ann.value(i)->getClient()->getId().toInt() == id) {
            r_annonces.append(ann.value(i));
        }
    }
    return r_annonces;
}

QList<Annonce*> MainWindow::immo_tri_date_croissante(QList<Annonce*> ann)
{
    QList<Annonce*> annonces_tmp = ann;
    QList<Annonce*> tri_annonces;
    int remove;
    for(int i=0; i<ann.length(); i++)
    {
        Annonce* pp = annonces_tmp.value(0);
        remove = 0;
        for(int j=1; j<annonces_tmp.length(); j++)
        {
            if(annonces_tmp.value(j)->getDate() < pp->getDate())
            {
                pp = annonces_tmp.value(j);
                remove = j;
            }
        }
        tri_annonces.append(pp);
        annonces_tmp.removeAt(remove);
    }
    return tri_annonces;
}

QList<Annonce*> MainWindow::immo_tri_date_decroissante(QList<Annonce*> ann)
{
    QList<Annonce*> annonces_tmp = ann;
    QList<Annonce*> tri_annonces;
    int remove;
    for(int i=0; i<ann.length(); i++)
    {
        Annonce* pg = annonces_tmp.value(0);
        remove = 0;
        for(int j=1; j<annonces_tmp.length(); j++)
        {
            if(annonces_tmp.value(j)->getDate() > pg->getDate())
            {
                pg = annonces_tmp.value(j);
                remove = j;
            }
        }
        tri_annonces.append(pg);
        annonces_tmp.removeAt(remove);
    }
    return tri_annonces;
}

QList<Client*> MainWindow::client_recherche_id_client(QList<Client*> cl, QString id)
{
    QList<Client*> r_clients;
    for(int i=0; i<cl.length(); i++) {
        if(cl.value(i)->getId() == id) {
            r_clients.append(cl.value(i));
        }
    }
    return r_clients;
}

QList<Client*> MainWindow::client_recherche_nom(QList<Client*> cl, QString nom)
{
    QList<Client*> r_clients;
    for(int i=0; i<cl.length(); i++) {
        if(cl.value(i)->getNom() == nom) {
            r_clients.append(cl.value(i));
        }
    }
    return r_clients;
}

QList<Client*> MainWindow::client_recherche_ville(QList<Client*> cl, QString ville)
{
    QList<Client*> r_clients;
    for(int i=0; i<cl.length(); i++) {
        if(cl.value(i)->getVilleClient() == ville) {
            r_clients.append(cl.value(i));
        }
    }
    return r_clients;
}

QList<Client*> MainWindow::client_recherche_codepostal(QList<Client*> cl, QString codepostal)
{
    QList<Client*> r_clients;
    for(int i=0; i<cl.length(); i++) {
        if(cl.value(i)->getCodePostalClient() == codepostal) {
            r_clients.append(cl.value(i));
        }
    }
    return r_clients;
}

QList<Client*> MainWindow::client_recherche_nb_contrats(QList<Client*> cl, int min, int max)
{
    QList<Client*> r_clients;
    for(int i=0; i<cl.length(); i++) {
        if((cl.value(i)->getNbContrats() >= min) && (cl.value(i)->getNbContrats() <= max)) {
            r_clients.append(cl.value(i));
        }
    }
    return r_clients;
}

QList<Client*> MainWindow::client_tri_date_croissante(QList<Client*> cl)
{
    QList<Client*> clients_tmp = cl;
    QList<Client*> tri_clients;
    int remove;
    for(int i=0; i<cl.length(); i++)
    {
        Client* pp = clients_tmp.value(0);
        remove = 0;
        for(int j=1; j<clients_tmp.length(); j++)
        {
            if(clients_tmp.value(j)->getDateCreation() < pp->getDateCreation())
            {
                pp = clients_tmp.value(j);
                remove = j;
            }
        }
        tri_clients.append(pp);
        clients_tmp.removeAt(remove);
    }
    return tri_clients;
}

QList<Client*> MainWindow::client_tri_date_decroissante(QList<Client*> cl)
{
    QList<Client*> clients_tmp = cl;
    QList<Client*> tri_clients;
    int remove;
    for(int i=0; i<cl.length(); i++)
    {
        Client* pg = clients_tmp.value(0);
        remove = 0;
        for(int j=1; j<clients_tmp.length(); j++)
        {
            if(clients_tmp.value(j)->getDateCreation() < pg->getDateCreation())
            {
                pg = clients_tmp.value(j);
                remove = j;
            }
        }
        tri_clients.append(pg);
        clients_tmp.removeAt(remove);
    }
    return tri_clients;
}


// *********************** FONCTIONS STATISTIQUES **********************

void MainWindow::affiche_stats_immo(QList<Annonce*> ann)
{
    int nb_annonces_dispo = 0;
    int nb_annonces_histo = 0;
    int nb_clients = clients.length();
    int nb_annonces_rech = ann.length();
    double prix_moyen = 0;
    double pieces_moyenne = 0;
    double pourcentage = 0;
    double annonces_photo = 0;
    QDate date_ancienne;
    QDate date_recente;
    QString annonce_ancienne = "";
    QString annonce_recente = "";

    for(int i=0; i<annonces.length(); i++)
    {
        if(annonces.value(i)->getHisto() == 0) {
            nb_annonces_dispo += 1;
        } else {
            nb_annonces_histo += 1;
        }
    }

    for(int i=0; i<nb_annonces_rech; i++)
    {
        prix_moyen += ann.value(i)->getPrix();
        pieces_moyenne += ann.value(i)->getNbPieces();
        if(ann.value(i)->getPhotoPrincipale() != "") {
            pourcentage += 1.0;
        }
        if(i==0) {
            date_ancienne = ann.value(i)->getDate();
            date_recente = ann.value(i)->getDate();
        } else {
            if(date_ancienne > ann.value(i)->getDate()) {
                date_ancienne = ann.value(i)->getDate();
            }
            if(date_recente < ann.value(i)->getDate()) {
                date_recente = ann.value(i)->getDate();
            }
        }
    }

    if(nb_annonces_rech != 0) {
        prix_moyen = prix_moyen/nb_annonces_rech;
        pieces_moyenne = pieces_moyenne/nb_annonces_rech;
        annonces_photo = (pourcentage/nb_annonces_rech)*100;
    }
    annonce_ancienne = date_ancienne.toString("dd/MM/yyyy");
    annonce_recente = date_recente.toString("dd/MM/yyyy");

    prix_moyen = roundf(prix_moyen * 100) / 100;
    pieces_moyenne = roundf(pieces_moyenne * 100) / 100;
    annonces_photo = roundf(annonces_photo * 100) / 100;

    StatsImmo aff_stats_immo(this, QString::number(nb_annonces_dispo), QString::number(nb_annonces_histo), QString::number(nb_clients), QString::number(nb_annonces_rech), QString::number(prix_moyen), QString::number(pieces_moyenne), QString::number(annonces_photo), annonce_ancienne, annonce_recente);
    aff_stats_immo.exec();
}

void MainWindow::affiche_stats_client(QList<Client*> cl)
{
    int nb_annonces_dispo = 0;
    int nb_annonces_histo = 0;
    int nb_clients = clients.length();
    int nb_clients_rech = cl.length();
    double nb_contrats = 0;
    QDate date_ancienne;
    QDate date_recente;
    QString client_ancien = "";
    QString client_recent = "";

    for(int i=0; i<annonces.length(); i++)
    {
        if(annonces.value(i)->getHisto() == 0) {
            nb_annonces_dispo += 1;
        } else {
            nb_annonces_histo += 1;
        }
    }

    for(int i=0; i<nb_clients_rech; i++)
    {
        nb_contrats += cl.value(i)->getNbContrats();
        if(i==0) {
            date_ancienne = cl.value(i)->getDateCreation();
            date_recente = cl.value(i)->getDateCreation();
        } else {
            if(date_ancienne > cl.value(i)->getDateCreation()) {
                date_ancienne = cl.value(i)->getDateCreation();
            }
            if(date_recente < cl.value(i)->getDateCreation()) {
                date_recente = cl.value(i)->getDateCreation();
            }
        }
    }

    if(nb_clients_rech != 0) {
        nb_contrats = nb_contrats/nb_clients_rech;
    }
    client_ancien = date_ancienne.toString("dd/MM/yyyy");
    client_recent = date_recente.toString("dd/MM/yyyy");

    nb_contrats = roundf(nb_contrats * 100) / 100;

    StatsClients aff_stats_client(this, QString::number(nb_annonces_dispo), QString::number(nb_annonces_histo), QString::number(nb_clients), QString::number(nb_clients_rech), QString::number(nb_contrats), client_ancien, client_recent);
    aff_stats_client.exec();
}
