#include <QMessageBox>
#include "choix_client.h"
#include "ui_choix_client.h"
#include "annoncewindow.h"
#include "ui_annoncewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


ChoixClient::ChoixClient(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::ChoixClient)
{
    ui->setupUi(this);
    for(int i=0; i<((MainWindow*)this->parent()->parent())->clients.length(); i++)
    {
        ui->cbo_choix_client->addItem(((MainWindow*)this->parent()->parent())->clients.value(i)->getNom() + " (" + ((MainWindow*)this->parent()->parent())->clients.value(i)->getId() + ")", ((MainWindow*)this->parent()->parent())->clients.value(i)->getId());
    }
}

ChoixClient::~ChoixClient()
{
    delete ui;
}

void ChoixClient::on_btn_annuler_clicked()
{
    ((AnnonceWindow*)this->parent())->setAnnule(true);
    this->close();
}

void ChoixClient::on_btn_valider_clicked()
{
    this->id_client = ui->cbo_choix_client->currentData().toInt();
    ((AnnonceWindow*)this->parent())->setAnnule(false);
    this->close();
}

int ChoixClient::getIdClient()
{
    return this->id_client;
}
