#include "annonce.h"
#include "mainwindow.h"

Annonce::Annonce()
{
}

Annonce::Annonce(QString annonce, QString bien, int pieces, double superficie, QString adresse, QString ville, QString codepostal, QString description, double prix, QString date, QString pp, QList<QString> ps, int histo, int idprop, int idclient)
{
    this->setTypeAnnonce(annonce);
    this->setTypeBien(bien);
    this->setNbPieces(pieces);
    this->setSuperficie(superficie);
    this->setAdresse(adresse);
    this->setVille(ville);
    this->setCodePostal(codepostal);
    this->setDescription(description);
    this->setDate(date);
    this->setPrix(prix);
    this->setPhotoPrincipale(pp);
    this->setPhotosSupp(ps);
    this->setHisto(histo);
    this->setIdProp(idprop);
    this->setIdClient(idclient);
}

Annonce::~Annonce()
{
}

void Annonce::setTypeAnnonce(QString a)
{
    this->typeAnnonce = a;
}

void Annonce::setTypeBien(QString b)
{
    this->typeBien = b;
}

void Annonce::setNbPieces(int p)
{
    this->nbPieces = p;
}

void Annonce::setSuperficie(double s)
{
    this->superficie = s;
}

void Annonce::setAdresse(QString a)
{
    this->adresse = a;
}

void Annonce::setVille(QString v)
{
    this->ville = v;
}

void Annonce::setCodePostal(QString cp)
{
    this->codePostal = cp;
}

void Annonce::setDescription(QString d)
{
    this->description = d;
}

void Annonce::setDate(QString d)
{
    this->date = d;
}

void Annonce::setPrix(double p)
{
    this->prix = p;
}

void Annonce::setPhotoPrincipale(QString pp)
{
    this->photoPrincipale = pp;
}

void Annonce::setPhotosSupp(QList<QString> ps)
{
    for(int i=0; i<ps.length(); i++) {
        this->photosSupp.append(ps.value(i));
    }
}

void Annonce::setHisto(int b)
{
    this->histo = b;
}

void Annonce::setIdProp(int id)
{
    this->idprop = id;
}

void Annonce::setIdClient(int id)
{
    this->idclient = id;
}

QString Annonce::getTypeAnnonce()
{
    return this->typeAnnonce;
}

QString Annonce::getTypeBien()
{
    return this->typeBien;
}

int Annonce::getNbPieces()
{
    return this->nbPieces;
}

double Annonce::getSuperficie()
{
    return this->superficie;
}

QString Annonce::getAdresse()
{
    return this->adresse;
}

QString Annonce::getVille()
{
    return this->ville;
}

QString Annonce::getCodePostal()
{
    return this->codePostal;
}

QString Annonce::getDescription()
{
    return this->description;
}

QString Annonce::getDate()
{
    return this->date;
}

double Annonce::getPrix()
{
    return this->prix;
}

QString Annonce::getPhotoPrincipale()
{
    return this->photoPrincipale;
}

QList<QString> Annonce::getPhotosSupp()
{
    return this->photosSupp;
}

int Annonce::getHisto()
{
    return this->histo;
}

int Annonce::getIdProp()
{
    return this->idprop;
}

int Annonce::getIdClient()
{
    return this->idclient;
}

