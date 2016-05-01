#include "client.h"
#include "mainwindow.h"

int Client::id =0;

Client::Client()
{
}

Client::Client(QString id, QString genre, QString nom, QString prenom, QString dateNaissance, QString adresse, QString ville, QString codePostal, QString courriel, QString telephone, int nbContrats, QDate dateCreation)
{
    this->setId(id);
    this->setGenre(genre);
    this->setNom(nom);
    this->setPrenom(prenom);
    this->setDateNaissance(dateNaissance);
    this->setAdresseClient(adresse);
    this->setVilleClient(ville);
    this->setCodePostalClient(codePostal);
    this->setCourriel(courriel);
    this->setTelephone(telephone);
    this->setNbContrats(nbContrats);
    this->setDateCreation(dateCreation);
}

Client::~Client()
{
}

void Client::setId(QString id)
{
    this->identifiant = id;
}


void Client::setGenre(QString g)
{
    this->genre = g;
}

void Client::setNom(QString n)
{
    this->nom = n;
}

void Client::setPrenom(QString p)
{
    this->prenom = p;
}

void Client::setDateNaissance(QString d)
{
    this->dateNaissance = d;
}

void Client::setAdresseClient(QString a)
{
    this->adresseClient = a;
}

void Client::setVilleClient(QString v)
{
    this->villeClient = v;
}

void Client::setCodePostalClient(QString cp)
{
    this->codePostalClient = cp;
}

void Client::setCourriel(QString c)
{
    this->courriel = c;
}

void Client::setTelephone(QString t)
{
    this->telephone = t;
}

void Client::setNbContrats(int nc)
{
    this->nbContrats = nc;
}

void Client::setDateCreation(QDate dc)
{
    this->dateCreation = dc;
}

QString Client::getId()
{
    return this->identifiant;
}

QString Client::getGenre()
{
    return this->genre;
}

QString Client::getNom()
{
    return this->nom;
}

QString Client::getPrenom()
{
    return this->prenom;
}

QString Client::getDateNaissance()
{
    return this->dateNaissance;
}

QString Client::getAdresseClient()
{
    return this->adresseClient;
}

QString Client::getVilleClient()
{
    return this->villeClient;
}

QString Client::getCodePostalClient()
{
    return this->codePostalClient;
}

QString Client::getCourriel()
{
    return this->courriel;
}

QString Client::getTelephone()
{
    return this->telephone;
}

int Client::getNbContrats()
{
    return this->nbContrats;
}

QDate Client::getDateCreation()
{
    return this->dateCreation;
}
