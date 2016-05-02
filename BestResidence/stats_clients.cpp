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
    ui->biens_dispos->text() = biens_dispos;
    ui->biens_archives->text() = biens_archives;
    ui->nb_clients->text() = nb_clients;
    ui->nb_clients_rech->text() = nb_clients_rech;
    ui->contrats_moyenne->text() = nb_contrats;
    ui->client_ancien->text() = client_ancien;
    ui->client_recent->text() = client_recent;
}

StatsClients::~StatsClients()
{
    delete ui;
}

void StatsClients::on_btn_fermer_clicked()
{
    this->close();
}

