#include <QMessageBox>
#include "stats_clients.h"
#include "ui_stats_clients.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


StatsClients::StatsClients(QWidget *parent, QString biens_dispos, QString biens_archives, QString nb_clients, QString nb_clients_rech, QString nb_contrats, QString client_ancien, QString client_recent, Qt::WindowFlags f ) :
    QDialog(parent, f),
    ui(new Ui::StatsClients)
{
    ui->setupUi(this);
    ui->biens_dispos->setText(biens_dispos);
    ui->biens_archives->setText(biens_archives);
    ui->nb_clients->setText(nb_clients);
    ui->nb_clients_rech->setText(nb_clients_rech);
    ui->contrats_moyenne->setText(nb_contrats);
    ui->client_ancien->setText(client_ancien);
    ui->client_recent->setText(client_recent);
    ui->btn_fermer->setStyleSheet("color: rgb(0, 0, 0)");
}

StatsClients::~StatsClients()
{
    delete ui;
}

void StatsClients::on_btn_fermer_clicked()
{
    this->close();
}

