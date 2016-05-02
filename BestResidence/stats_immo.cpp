#include <QMessageBox>
#include "stats_immo.h"
#include "ui_stats_immo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


StatsImmo::StatsImmo(QWidget *parent, QString biens_dispos, QString biens_archives, QString nb_clients, QString nb_annonces, QString prix_moyen, QString pieces_moyenne, QString annonces_photo, QString annonce_ancienne, QString annonce_recente, Qt::WindowFlags f ) :
    QDialog(parent, f),
    ui(new Ui::StatsImmo)
{
    ui->setupUi(this);
    ui->biens_dispo->text() = biens_dispos;
    ui->biens_archives->text() = biens_archives;
    ui->nb_clients->text() = nb_clients;
    ui->nb_annonces->text() = nb_annonces;
    ui->prix_moyen->text() = prix_moyen + " €";
    ui->pieces_moyenne->text() = pieces_moyenne;
    ui->annonces_photo->text() = annonces_photo + " %";
    ui->annonce_ancienne->text() = annonce_ancienne;
    ui->annonce_recente->text() = annonce_recente;
}

StatsImmo::~StatsImmo()
{
    delete ui;
}

void StatsImmo::on_btn_fermer_clicked()
{
    this->close();
}
