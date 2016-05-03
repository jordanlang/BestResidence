#include "clientwindow.h"
#include "client.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_clientwindow.h"
#include "ajoutclient.h"
#include "ui_ajoutclient.h"

ClientWindow::ClientWindow(QWidget *parent,Client *monClient, Qt::WindowFlags f ) :
    QDialog(parent, f),
    ui(new Ui::DialogClient)
{
    this->client=monClient;

    this->p = ((MainWindow*)this->parent());
    this->refresh=false;


    ui->setupUi(this);
    ui->l_adresse->setText(monClient->getAdresseClient());
    ui->l_ville->setText(monClient->getVilleClient());
    ui->l_codeP->setText(monClient->getCodePostalClient());
    ui->l_nom->setText(monClient->getGenre() + " " + monClient->getNom() + " " + monClient->getPrenom());
    ui->l_courriel->setText(monClient->getCourriel());
    ui->l_dateCreation->setText("Date de création du client : " + monClient->getDateCreation().toString("dd/MM/yyyy"));
    ui->l_dateNaissance->setText("Date de naissance :" + monClient->getDateNaissance());
    ui->l_id->setText("Numéro identifiant : " + monClient->getId());
    ui->l_nbContrats->setText(QString::number(monClient->getNbContrats()));
    ui->l_telephone->setText(monClient->getTelephone());



}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::setAnnule(bool b)
{
    this->annule = b;
}

void ClientWindow::on_b_retour_clicked()
{
    this->close();
}

void ClientWindow::on_b_supprimer_clicked()
{
    this->p->clients.removeAt(this->p->clients.indexOf(this->client));
    this->refresh=true;
    this->close();
}

void ClientWindow::on_b_modifier_clicked()
{
    AjoutClient add(((MainWindow*)this->parent()), this->client);
    add.exec();
    ((MainWindow*)this->parent())->majAllTables();
    this->close();
    ClientWindow aff_win(((MainWindow*)this->parent()), this->client);
    aff_win.exec();
}

bool ClientWindow::getRefresh(){
    return this->refresh;
}
