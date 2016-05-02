#ifndef STATS_CLIENTS_H
#define STATS_CLIENTS_H

#include <QDialog>
#include "ui_stats_clients.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

class StatsClients : public QDialog
{
    Q_OBJECT

public:
    explicit StatsClients(QWidget *parent = Q_NULLPTR, QString biens_dispos = "", QString biens_archives = "", QString nb_clients = "", QString nb_clients_rech = "", QString nb_contrats = "", QString client_ancien = "", QString client_recent = "", Qt::WindowFlags f = Qt::WindowFlags());
    ~StatsClients();

private slots:
    void on_btn_fermer_clicked();

private:
    Ui::StatsClients *ui;
};

#endif // STATS_CLIENTS_H
