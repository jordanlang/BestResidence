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
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readXmlFile();
    //initAnnonces();
    addTabAnnoncesVente();
    addTabAnnoncesLocation();
    addTabHistoVente();
    addTabHistoLocation();
    addTabClients();
    //addTabClients();
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
    QString fileXmlName = "/Users/romainhry/Dropbox/L3/S6/IHM/BestResidence/BestResidence/annonces.xml";
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
            if(reader.name() == element_immo) {
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
                    Annonce* a = new Annonce(xml_typeAnnonce, xml_typeBien, xml_nbPieces.toInt(), xml_superficie.toDouble(), xml_adresse, xml_ville, xml_codePostal, xml_description, xml_prix.toDouble(), xml_date, xml_photoPrincipale, xml_photosSupp, xml_histo.toInt(), xml_idprop.toInt(), xml_idclient.toInt());
                    annonces.append(a);
                }
            } else if(reader.name() == element_client) {
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
                    Client* c = new Client(xml_identifiant, xml_genre, xml_nom, xml_prenom, xml_dateNaissance, xml_adresseClient, xml_villeClient, xml_codePostalClient, xml_courriel, xml_telephone, xml_nbContrats.toInt(), xml_dateCreation);
                    clients.append(c);
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


void MainWindow::addTabAnnoncesVente()
{
    ui->tableOffreVente->clearContents();
    set_aff_annonces_vente();
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

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate());

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
    set_aff_annonces_location();
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

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate());

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
    set_aff_histo_vente();
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

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate());

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

    set_aff_histo_location();
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

        QIcon icon(aff_annonces.value(i)->getPhotoPrincipale());
        wdg_photo->setIcon(icon);
        wdg_bien->setText(aff_annonces.value(i)->getTypeBien());
        wdg_pieces->setText(QString::number(aff_annonces.value(i)->getNbPieces()));
        wdg_superficie->setText(QString::number(aff_annonces.value(i)->getSuperficie()));
        wdg_ville->setText(aff_annonces.value(i)->getVille());
        wdg_prix->setText(QString::number(aff_annonces.value(i)->getPrix()));
        wdg_date->setText(aff_annonces.value(i)->getDate());

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

    for(int i=0; i<this->clients.length(); i++)
    {
        Client* clientAffiche = this->clients.value(i);

        QTableWidgetItem* wdg_id_client = new QTableWidgetItem();
        QTableWidgetItem* wdg_nom = new QTableWidgetItem();
        QTableWidgetItem* wdg_prenom = new QTableWidgetItem();
        QTableWidgetItem* wdg_courriel = new QTableWidgetItem();
        QTableWidgetItem* wdg_telephone = new QTableWidgetItem();
        QTableWidgetItem* wdg_ville = new QTableWidgetItem();

        wdg_id_client->setText(clientAffiche->getId());
        wdg_nom->setText(clientAffiche->getNom());
        wdg_prenom->setText(clientAffiche->getPrenom());
        wdg_ville->setText(clientAffiche->getVilleClient());
        wdg_courriel->setText(clientAffiche->getCourriel());
        wdg_telephone->setText(clientAffiche->getTelephone());

        ui->tableClient->insertRow(i);
        ui->tableClient->setItem(i, 0, wdg_id_client);
        ui->tableClient->setItem(i, 1, wdg_nom);
        ui->tableClient->setItem(i, 2, wdg_prenom);
        ui->tableClient->setItem(i, 3, wdg_ville);
        ui->tableClient->setItem(i, 4, wdg_courriel);
        ui->tableClient->setItem(i, 5, wdg_telephone);
    }
}

void MainWindow::writeXmlFile()
{
    //QString fileXmlName = "/Users/jordan/Dropbox/Cours/L3 - S6/Interface homme-machine/Projet/BestResidence/BestResidence/annonces.xml";
    QString fileXmlName = "/Users/romainhry/Dropbox/L3/S6/IHM/BestResidence/BestResidence/annonces.xml";
    QFile fileXml(fileXmlName);

    // Ouverture du fichier en écriture et en texte. (sort de la fonction si le fichier ne s'ouvre pas)
    if(!fileXml.open(QFile::WriteOnly | QFile::Text))
        return;
    QXmlStreamWriter writer(&fileXml);

    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("bestresidence");

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
        writer.writeTextElement("date", a->getDate());
        writer.writeTextElement("principale", a->getPhotoPrincipale());
        for(int i =0;i<8;i++)
        {
            if(i<a->getPhotosSupp().length())
                writer.writeTextElement("supp"+QString::number(i+1), a->getPhotosSupp().value(i));
            else
                writer.writeTextElement("supp"+QString::number(i+1), "");
        }
        writer.writeTextElement("histo", QString::number(a->getHisto()));
        writer.writeTextElement("idprop", QString::number(a->getIdProp()));
        writer.writeTextElement("idclient", QString::number(a->getIdClient()));
        writer.writeEndElement();
    }

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
        writer.writeTextElement("datecreation", c->getDateCreation());
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
        addTabAnnoncesVente();
        addTabAnnoncesLocation();
        addTabHistoVente();
        addTabHistoLocation();
    }
}

void MainWindow::on_tableOffreVente_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_annonces_vente.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        addTabAnnoncesVente();
        addTabHistoVente();
    }
}

void MainWindow::on_tableOffreLocation_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_annonces_location.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        addTabAnnoncesLocation();
        addTabHistoLocation();
    }
}

void MainWindow::on_tableBienVendu_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_histo_vente.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        addTabAnnoncesVente();
        addTabHistoVente();
    }
}

void MainWindow::on_tableBienLoue_clicked(const QModelIndex &index)
{
    AnnonceWindow voir_annonce(this,this->aff_histo_location.value(index.row()));
    voir_annonce.exec();
    if (voir_annonce.getRefresh())
    {
        addTabAnnoncesLocation();
        addTabHistoLocation();
    }
}

void MainWindow::setAnnule(bool b)
{
    this->annule = b;
}

void MainWindow::on_ajout_client_clicked()
{
    AjoutClient ajoutClient(this);
    ajoutClient.exec();
    if(!annule) {
        addTabClients();
    }
}
