#ifndef STATS_IMMO_H
#define STATS_IMMO_H

#include <QDialog>
#include "ui_stats_immo.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

class StatsImmo : public QDialog
{
    Q_OBJECT

public:
    explicit StatsImmo(QWidget *parent = Q_NULLPTR, QString biens_dispos = "", QString biens_archives = "", QString nb_clients = "", QString nb_annonces = "", QString prix_moyen = "", QString pieces_moyenne = "", QString annonces_photo = "", QString annonce_ancienne = "", QString annonce_recente = "", Qt::WindowFlags f = Qt::WindowFlags());
    ~StatsImmo();

private slots:
    void on_btn_fermer_clicked();

private:
    Ui::StatsImmo *ui;
};




#endif // STATS_IMMO_H
