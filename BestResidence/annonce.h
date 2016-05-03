#ifndef ANNONCE_H
#define ANNONCE_H

#include <QMainWindow>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <iostream>
#include "client.h"

class Annonce : public QObject
{
    Q_OBJECT

public:
    explicit Annonce();
    explicit Annonce(QString, QString, int, double, QString, QString, QString, QString, double, QDate, QString, QList<QString>, int, Client*, Client*);
    ~Annonce();

    void setTypeAnnonce(QString);
    void setTypeBien(QString);
    void setNbPieces(int);
    void setSuperficie(double);
    void setAdresse(QString);
    void setVille(QString);
    void setCodePostal(QString);
    void setDescription(QString);
    void setDate(QDate);
    void setPrix(double);
    void setPhotoPrincipale(QString);
    void setPhotosSupp(QList<QString>);
    void setHisto(int);
    void setProp(Client*);
    void setClient(Client*);

    QString getTypeAnnonce();
    QString getTypeBien();
    int getNbPieces();
    double getSuperficie();
    QString getAdresse();
    QString getVille();
    QString getCodePostal();
    QString getDescription();
    QDate getDate();
    double getPrix();
    QString getPhotoPrincipale();
    QList<QString> getPhotosSupp();
    int getHisto();
    Client* getProp();
    Client* getClient();

private slots:


private:
    QString typeAnnonce;
    QString typeBien;
    int nbPieces;
    double superficie;
    QString adresse;
    QString ville;
    QString codePostal;
    QString description;
    double prix;
    QDate date;
    QString photoPrincipale;
    QList<QString> photosSupp;
    int histo;
    Client* prop;
    Client* client;
};

#endif // ANNONCE_H
