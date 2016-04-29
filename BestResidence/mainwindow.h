#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "annonce.h"
#include <QMainWindow>
#include <QTableWidget>
#include <QDomDocument>
#include <QtXml>
#include <QList>
#include <iostream>
#include "client.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Client c;
    Annonce a;
    QList<Annonce*> annonces;
    QList<Client*> clients;
    QString aff_annonces_vente[1000][22];
    QString aff_annonces_location[1000][22];
    QString aff_histo_vente[1000][22];
    QString aff_histo_location[1000][22];
    int nb_annonces = 0;
    int nb_clients = 0;
    int nb_aff_annonces_vente = 0;
    int nb_aff_annonces_location = 0;
    int nb_aff_histo_vente = 0;
    int nb_aff_histo_location = 0;
    void addTabAnnoncesVente();
    void addTabAnnoncesLocation();
    void addTabHistoVente();
    void addTabHistoLocation();
    void addTabClients();
    void initAnnonces();
    void setAnnule(bool);

    QList<Annonce*>* get_aff_annonces_ventes();

private slots:
    void on_pushButton_clicked();
    void on_tableOffreVente_clicked(const QModelIndex &index);
    void on_tableOffreLocation_clicked(const QModelIndex &index);
    void on_tableBienVendu_clicked(const QModelIndex &index);
    void on_tableBienLoue_clicked(const QModelIndex &index);

private:
    void readXmlFile();
    void writeXmlFile();
    Ui::MainWindow *ui;
    QDomDocument *dom;
    bool annule;

    QTableWidgetItem* wdg_photo;
    QTableWidgetItem* wdg_bien;
    QTableWidgetItem* wdg_pieces;
    QTableWidgetItem* wdg_superficie;
    QTableWidgetItem* wdg_ville;
    QTableWidgetItem* wdg_prix;
    QTableWidgetItem* wdg_date;
    QTableWidgetItem* wdg_id_client;
    QTableWidgetItem* wdg_nom;
    QTableWidgetItem* wdg_prenom;
    QTableWidgetItem* wdg_courriel;
    QTableWidgetItem* wdg_telephone;
};

#endif // MAINWINDOW_H
