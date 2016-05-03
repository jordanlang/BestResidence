#ifndef AJOUTCLIENT_H
#define AJOUTCLIENT_H

#include <QDialog>
#include "ui_ajoutclient.h"
#include "client.h"


class AjoutClient : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutClient(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    explicit AjoutClient(QWidget *parent = Q_NULLPTR, Client* client = new Client(), Qt::WindowFlags f = Qt::WindowFlags());
    ~AjoutClient();

private slots:

    void on_b_valider_clicked();
    void on_b_annuler_clicked();


private:
    void setup();
    Ui::ajoutClient *ui;
    Client* cl_a_modif;
    bool modif;
};

#endif // AJOUTCLIENT_H
