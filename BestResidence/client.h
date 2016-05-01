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
    explicit Client(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, int, QDate);
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
    void setDateCreation(QDate);

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
    QDate getDateCreation();

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
    QDate dateCreation;
};

#endif // CLIENT_H
