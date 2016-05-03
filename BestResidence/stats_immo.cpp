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
    ui->biens_dispo->setText(biens_dispos);
    ui->biens_archives->setText(biens_archives);
    ui->nb_clients->setText(nb_clients);
    ui->nb_annonces->setText(nb_annonces);
    ui->prix_moyen->setText(prix_moyen + " €");
    ui->pieces_moyenne->setText(pieces_moyenne);
    ui->annonces_photo->setText(annonces_photo + " %");
    ui->annonce_ancienne->setText(annonce_ancienne);
    ui->annonce_recente->setText(annonce_recente);
    ui->btn_fermer->setStyleSheet("color: rgb(0, 0, 0)");
}

StatsImmo::~StatsImmo()
{
    delete ui;
}

void StatsImmo::on_btn_fermer_clicked()
{
    this->close();
}
