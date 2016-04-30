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

    QList<Annonce*> annonces;
    QList<Client*> clients;

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

    QList<Annonce*> get_aff_annonces_vente();
    void set_aff_annonces_vente();
    QList<Annonce*> get_aff_histo_vente();
    void set_aff_histo_vente();
    QList<Annonce*> get_aff_annonces_location();
    void set_aff_annonces_location();
    QList<Annonce*> get_aff_histo_location();
    void set_aff_histo_location();

private slots:
    void on_pushButton_clicked();
    void on_tableOffreVente_clicked(const QModelIndex &index);
    void on_tableOffreLocation_clicked(const QModelIndex &index);
    void on_tableBienVendu_clicked(const QModelIndex &index);
    void on_tableBienLoue_clicked(const QModelIndex &index);
    void on_ajout_client_clicked();

private:
    void readXmlFile();
    void writeXmlFile();
    Ui::MainWindow *ui;
    QDomDocument *dom;
    bool annule;

    QList<Annonce*> aff_annonces_vente;
    QList<Annonce*> aff_annonces_location;
    QList<Annonce*> aff_histo_vente;
    QList<Annonce*> aff_histo_location;



};

#endif // MAINWINDOW_H
