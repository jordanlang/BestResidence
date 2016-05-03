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

    void addTabAnnoncesVente();
    void addTabAnnoncesLocation();
    void addTabHistoVente();
    void addTabHistoLocation();
    void addTabClients();
    void setAnnule(bool);
    void majAllTables();

    QList<Annonce*> get_aff_annonces_vente();
    void set_aff_annonces_vente();
    QList<Annonce*> get_aff_histo_vente();
    void set_aff_histo_vente();
    QList<Annonce*> get_aff_annonces_location();
    void set_aff_annonces_location();
    QList<Annonce*> get_aff_histo_location();
    void set_aff_histo_location();
    QList<Client*> get_aff_clients();
    void set_aff_clients();

    QList<Annonce*> immo_recherche_ville(QList<Annonce*> ann, QString ville);
    QList<Annonce*> immo_recherche_codepostal(QList<Annonce*> ann, QString codepostal);
    QList<Annonce*> immo_recherche_prix(QList<Annonce*> ann, double min, double max);
    QList<Annonce*> immo_recherche_pieces(QList<Annonce*> ann, int min, int max);
    QList<Annonce*> immo_recherche_type(QList<Annonce*> ann, bool maison, bool appart, bool bureau, bool chateau, bool ferme, bool commerce);
    QList<Annonce*> immo_recherche_avec_photo(QList<Annonce*> ann);
    QList<Annonce*> immo_recherche_date(QList<Annonce*> ann, QDate min, QDate max);
    QList<Annonce*> immo_recherche_id_client(QList<Annonce*> ann, int id);
    QList<Annonce*> immo_tri_date_croissante(QList<Annonce*> ann);
    QList<Annonce*> immo_tri_date_decroissante(QList<Annonce*> ann);

    QList<Client*> client_recherche_id_client(QList<Client*> cl, QString id);
    QList<Client*> client_recherche_nom(QList<Client*> cl, QString nom);
    QList<Client*> client_recherche_ville(QList<Client*> cl, QString ville);
    QList<Client*> client_recherche_codepostal(QList<Client*> cl, QString codepostal);
    QList<Client*> client_recherche_nb_contrats(QList<Client*> cl, int min, int max);
    QList<Client*> client_tri_date_croissante(QList<Client*> cl);
    QList<Client*> client_tri_date_decroissante(QList<Client*> cl);

    void recherche_offre_vente();
    void recherche_offre_location();
    void recherche_bien_vendu();
    void recherche_bien_loue();
    void recherche_client();

    void affiche_stats_immo(QList<Annonce*> ann);
    void affiche_stats_client(QList<Client*> cl);

private slots:
    void on_pushButton_clicked();
    void on_tableOffreVente_clicked(const QModelIndex &index);
    void on_tableOffreLocation_clicked(const QModelIndex &index);
    void on_tableBienVendu_clicked(const QModelIndex &index);
    void on_tableBienLoue_clicked(const QModelIndex &index);
    void on_tableClient_clicked(const QModelIndex &index);
    void on_ajout_client_clicked();
    void on_ov_btn_rechercher_clicked();
    void on_ol_btn_rechercher_clicked();
    void on_bv_btn_rechercher_clicked();
    void on_bl_btn_rechercher_clicked();
    void on_cl_btn_rechercher_clicked();
    void on_ov_btn_stats_clicked();
    void on_ol_btn_stats_clicked();
    void on_bv_btn_stats_clicked();
    void on_bl_btn_stats_clicked();
    void on_cl_btn_stats_clicked();

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
    QList<Client*> aff_clients;
};

#endif // MAINWINDOW_H
