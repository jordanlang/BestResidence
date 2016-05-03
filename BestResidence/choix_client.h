#ifndef CHOIX_CLIENT_H
#define CHOIX_CLIENT_H

#include <QDialog>
#include "ui_choix_client.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

class ChoixClient : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixClient(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ChoixClient();
    int getIdClient();

private slots:
    void on_btn_annuler_clicked();
    void on_btn_valider_clicked();

private:
    Ui::ChoixClient *ui;
    int id_client;
};

#endif // CHOIX_CLIENT_H
