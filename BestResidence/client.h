#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <iostream>


class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client();
    explicit Client(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, int, QString);
    ~Client();

    void setId(QString);
    void setGenre(QString);
    void setNom(QString);
    void setPrenom(QString);
    void setDateNaissance(QString);
    void setAdresseClient(QString);
    void setVilleClient(QString);
    void setCodePostalClient(QString);
    void setCourriel(QString);
    void setTelephone(QString);
    void setNbContrats(int);
    void setDateCreation(QString);

    QString getId();
    QString getGenre();
    QString getNom();
    QString getPrenom();
    QString getDateNaissance();
    QString getAdresseClient();
    QString getVilleClient();
    QString getCodePostalClient();
    QString getCourriel();
    QString getTelephone();
    int getNbContrats();
    QString getDateCreation();

    static int id;


private slots:


private:

    QString identifiant;
    QString genre;
    QString nom;
    QString prenom;
    QString dateNaissance;
    QString adresseClient;
    QString villeClient;
    QString codePostalClient;
    QString courriel;
    QString telephone;
    int nbContrats;
    QString dateCreation;
};

#endif // CLIENT_H
