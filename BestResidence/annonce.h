#ifndef ANNONCE_H
#define ANNONCE_H

#include <QMainWindow>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <iostream>



class Annonce : public QObject
{
    Q_OBJECT

public:
    explicit Annonce();
    explicit Annonce(QString, QString, int, double, QString, QString, QString, QString, double, QString, QString, QList<QString>, int, int, int);
    ~Annonce();

    void setTypeAnnonce(QString);
    void setTypeBien(QString);
    void setNbPieces(int);
    void setSuperficie(double);
    void setAdresse(QString);
    void setVille(QString);
    void setCodePostal(QString);
    void setDescription(QString);
    void setDate(QString);
    void setPrix(double);
    void setPhotoPrincipale(QString);
    void setPhotosSupp(QList<QString>);
    void setHisto(int);
    void setIdProp(int);
    void setIdClient(int);

    QString getTypeAnnonce();
    QString getTypeBien();
    int getNbPieces();
    double getSuperficie();
    QString getAdresse();
    QString getVille();
    QString getCodePostal();
    QString getDescription();
    QString getDate();
    double getPrix();
    QString getPhotoPrincipale();
    QList<QString> getPhotosSupp();
    int getHisto();
    int getIdProp();
    int getIdClient();


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
    QString date;
    QString photoPrincipale;
    QList<QString> photosSupp;
    int histo;
    int idprop;
    int idclient;
};

#endif // ANNONCE_H
