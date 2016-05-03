#include "ajoutclient.h"
#include "ui_ajoutclient.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <ctime>

AjoutClient::AjoutClient(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::ajoutClient)
{
    ui->setupUi(this);
    modif = 0;
}

AjoutClient::AjoutClient(QWidget *parent, Client* client, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::ajoutClient)
{
    ui->setupUi(this);
    setup();
    modif = 1;
    cl_a_modif = client;
    ui->genre->setCurrentIndex(ui->genre->findText(client->getGenre()));
    ui->q_nom->setText(client->getNom());
    ui->q_prenom->setText(client->getPrenom());
    ui->date->setDate(QDate::fromString(client->getDateNaissance(), "dd/MM/yyyy"));
    ui->q_adresse->setText(client->getAdresseClient());
    ui->q_ville->setText(client->getVilleClient());
    ui->q_codePostal->setText(client->getCodePostalClient());
    ui->q_courriel->setText(client->getCourriel());
    ui->q_telephone->setText(client->getTelephone());
}

void AjoutClient::setup()
{
    ui->b_valider->setStyleSheet("color: rgb(0, 0, 0)");
}

AjoutClient::~AjoutClient()
{
    delete ui;
}

const std::string currentDate2() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}

void AjoutClient::on_b_valider_clicked()
{
    MainWindow* parent = qobject_cast<MainWindow*>(this->parent());
    if (parent == 0) { return; }

    if(
            ( ui->q_nom->text()== "")
            || (ui->q_adresse->text() == "")
            || (ui->q_ville->text() == "")
            || (ui->q_codePostal->text() == "")
            || (ui->q_courriel->text() == "")
            || (ui->q_telephone->text() == "")
            || (ui->q_prenom->text() == "")
                )
    {
        QMessageBox::information(this, "Validation impossible", "Certains champs n'ont pas été remplis correctement");
        if(ui->q_nom->text() == "") {
            QPalette palette = ui->l_nom->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_nom->setPalette(palette);
        } else {
            QPalette palette = ui->l_nom->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_nom->setPalette(palette);
        }

        if(ui->q_prenom->text() == "") {
            QPalette palette = ui->l_prenom->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_prenom->setPalette(palette);
        } else {
            QPalette palette = ui->l_prenom->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_prenom->setPalette(palette);
        }

        if(ui->q_adresse->text() == "") {
            QPalette palette = ui->l_adresse->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_adresse->setPalette(palette);
        } else {
            QPalette palette = ui->l_adresse->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_adresse->setPalette(palette);
        }

        if(ui->q_ville->text() == "") {
            QPalette palette = ui->l_ville->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_ville->setPalette(palette);
        } else {
            QPalette palette = ui->l_ville->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_ville->setPalette(palette);
        }

        if(ui->q_codePostal->text() == "") {
            QPalette palette = ui->q_codePostal->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_codePostal->setPalette(palette);
        } else {
            QPalette palette = ui->q_codePostal->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_codePostal->setPalette(palette);
        }

        if(ui->q_telephone->text() == "") {
            QPalette palette = ui->l_telephone->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_telephone->setPalette(palette);
        } else {
            QPalette palette = ui->l_telephone->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_telephone->setPalette(palette);
        }

        if(ui->q_courriel->text() == "") {
            QPalette palette = ui->l_courriel->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_courriel->setPalette(palette);
        } else {
            QPalette palette = ui->l_courriel->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_courriel->setPalette(palette);
        }
    }
    else
    {
        if(modif==0)
        {
            QString date = QString::fromStdString(currentDate2());
            Client* c = new Client(QString::number(Client::id++), ui->genre->currentText(), ui->q_nom->text(), ui->q_prenom->text(),ui->date->date().toString("dd/MM/yyyy"), ui->q_adresse->text(), ui->q_ville->text(), ui->q_codePostal->text(), ui->q_courriel->text(), ui->q_telephone->text(),0, QDate::fromString(date, "dd-MM-yyyy"));
            parent->clients.append(c);
        }
        else
        {
            cl_a_modif->setGenre(ui->genre->currentText());
            cl_a_modif->setNom(ui->q_nom->text());
            cl_a_modif->setPrenom(ui->q_prenom->text());
            cl_a_modif->setDateNaissance(ui->date->date().toString("dd/MM/yyyy"));
            cl_a_modif->setAdresseClient(ui->q_adresse->text());
            cl_a_modif->setVilleClient(ui->q_ville->text());
            cl_a_modif->setCodePostalClient(ui->q_codePostal->text());
            cl_a_modif->setCourriel(ui->q_courriel->text());
            cl_a_modif->setTelephone(ui->q_telephone->text());
        }

        parent->setAnnule(false);
        this->close();
    }
}

void AjoutClient::on_b_annuler_clicked()
{
    ((MainWindow*)this->parent())->setAnnule(true);
    this->close();
}
