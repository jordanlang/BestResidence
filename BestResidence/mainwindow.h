#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setTypeAnnonce(QString);
    void setTypeBien(QString);
    void setNbPieces(int);
    void setSuperficie(double);
    void setAdresse(QString);
    void setVille(QString);
    void setCodePostal(QString);
    void setDescription(QString);
    void setPrix(double);
    void setPhotoPrincipale(QString);
    void setPhotosSupp(QString[]);
    void setAnnule(bool);
    QString annonces[10000][6];
    int nb_annonces;
    void addTabToList();

private slots:
    void on_pushButton_clicked();
    void on_tableBiens_clicked(const QModelIndex &index);

private:
    void readXmlFile();
    void writeXmlFile();
    Ui::MainWindow *ui;
    QDomDocument *dom;
    QString typeAnnonce;
    QString typeBien;
    int nbPieces;
    double superficie;
    QString adresse;
    QString ville;
    QString codePostal;
    QString description;
    double prix;
    QString photoPrincipale;
    QString photosSupp[10];
    bool annule;
    QTableWidgetItem* wdg_photo;
    QTableWidgetItem* wdg_bien;
    QTableWidgetItem* wdg_pieces;
    QTableWidgetItem* wdg_superficie;
    QTableWidgetItem* wdg_ville;
    QTableWidgetItem* wdg_prix;
};

#endif // MAINWINDOW_H
