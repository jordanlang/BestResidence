#include <QMessageBox>
#include <ctime>
#include <QFileDialog>
#include "ajout.h"
#include "ui_ajout.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


Ajout::Ajout(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->b_valider->setStyleSheet("color: rgb(0, 0, 0)");
    ((MainWindow*)this->parent())->setAnnule(true);
    this->nb_photos = 0;
    for(int i=0; i<((MainWindow*)this->parent())->clients.length(); i++)
    {
        ui->q_client->addItem(((MainWindow*)this->parent())->clients.value(i)->getNom() + " (" + ((MainWindow*)this->parent())->clients.value(i)->getId() + ")", ((MainWindow*)this->parent())->clients.value(i)->getId());
    }
}

Ajout::~Ajout()
{
    delete ui;
}

const std::string currentDate() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}

void Ajout::on_b_valider_clicked()
{
    MainWindow* parent = qobject_cast<MainWindow*>(this->parent());
    if (parent == 0) { return; }

    if((ui->q_nbPieces->value() == 0)
            || (ui->q_superficieTerrain->value() == 0)
            || (ui->q_adresse->text() == "")
            || (ui->q_ville->text() == "")
            || (ui->q_codePostal->text() == "")
            || (ui->q_description->toPlainText() == "")
            || (ui->q_prix->value() == 0))
    {
        QMessageBox::information(this, "Validation impossible", "Certains champs n'ont pas été remplis correctement");
        if(ui->q_nbPieces->value() == 0) {
            QPalette palette = ui->l_nbPieces->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_nbPieces->setPalette(palette);
        } else {
            QPalette palette = ui->l_nbPieces->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_nbPieces->setPalette(palette);
        }

        if(ui->q_superficieTerrain->value() == 0) {
            QPalette palette = ui->l_superficieTerrain->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_superficieTerrain->setPalette(palette);
        } else {
            QPalette palette = ui->l_superficieTerrain->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_superficieTerrain->setPalette(palette);
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
            ui->q_codePostal->setPalette(palette);
        } else {
            QPalette palette = ui->q_codePostal->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->q_codePostal->setPalette(palette);
        }

        if(ui->q_description->toPlainText() == "") {
            QPalette palette = ui->l_description->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_description->setPalette(palette);
        } else {
            QPalette palette = ui->l_description->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_description->setPalette(palette);
        }

        if(ui->q_prix->value() == 0) {
            QPalette palette = ui->l_prix->palette();
            QBrush brush(QColor(255, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_prix->setPalette(palette);
        } else {
            QPalette palette = ui->l_prix->palette();
            QBrush brush(QColor(0, 0, 0, 255));
            brush.setStyle(Qt::SolidPattern);
            palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
            ui->l_prix->setPalette(palette);
        }
    }
    else
    {
        QList<QString> ps;
        QString date = QString::fromStdString(currentDate());
        for(int i=0;i<ui->listWidget->count();i++)
        {
            ps.append(ui->listWidget->item(i)->text());
        }

        Client* prop;
        for(int i=0;i<parent->clients.length();i++)
        {
            if(parent->clients.value(i)->getId() == ui->q_client->currentData().toString())
            {

                prop = parent->clients.value(i);
            }
        }

        Annonce* a = new Annonce(ui->q_typeAnnonce->currentText(), ui->q_typeBien->currentText(), ui->q_nbPieces->value(), ui->q_superficieTerrain->value(), ui->q_adresse->text(), ui->q_ville->text(), ui->q_codePostal->text(), ui->q_description->toPlainText(), ui->q_prix->value(), QDate::fromString(date, "dd-MM-yyyy"), ui->l_photoPrincipal->text(), ps, 0, prop, NULL);
        parent->annonces.append(a);
        parent->setAnnule(false);
        this->close();
    }
}

void Ajout::on_b_annuler_clicked()
{
    ((MainWindow*)this->parent())->setAnnule(true);
    this->close();
}

void Ajout::on_b_parcourirPrincipal_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/", tr("Images (*.png *.xpm *.jpg)"));
    ui->q_photoPrincipale->setText(fileNames.join(" "));
}

void Ajout::on_b_parcourirSupp_clicked()
{
    QString fileNames = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/", tr("Images (*.png *.xpm *.jpg)"));
    ui->q_photosSupp->setText(fileNames);
}

void Ajout::on_b_ajouterPrincipal_clicked()
{
    ui->l_photoPrincipal->setText(ui->q_photoPrincipale->text());
    ui->q_photoPrincipale->setText("");
}

void Ajout::on_b_ajouterSupp_clicked()
{
    if(this->nb_photos<8)
    {
        this->nb_photos++;
        ui->listWidget->addItem(ui->q_photosSupp->text());
        ui->q_photosSupp->setText("");
    }
    else
    {
        QMessageBox::warning(this,"","Impossible d'ajouter plus de 8 photos");
    }
}
