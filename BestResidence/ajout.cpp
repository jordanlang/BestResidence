#include <QMessageBox>
#include "ajout.h"
#include "ui_ajout.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Ajout::Ajout(QWidget *parent, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Ajout::~Ajout()
{
    delete ui;
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
        QString ps[10];

        parent->setTypeAnnonce(ui->q_typeAnnonce->currentText());
        parent->setTypeBien(ui->q_typeBien->currentText());
        parent->setNbPieces(ui->q_nbPieces->value());
        parent->setSuperficie(ui->q_superficieTerrain->value());
        parent->setAdresse(ui->q_adresse->text());
        parent->setVille(ui->q_ville->text());
        parent->setCodePostal(ui->q_codePostal->text());
        parent->setDescription(ui->q_description->toPlainText());
        parent->setPrix(ui->q_prix->value());
        parent->setPhotoPrincipale(ui->q_photoPrincipale->text());
        ps[0] = ui->q_photosSupp->text();
        parent->setPhotosSupp(ps);

        parent->setAnnule(false);
        this->close();
    }
}

void Ajout::on_b_annuler_clicked()
{
    ((MainWindow*)this->parent())->setAnnule(true);
    this->close();
}
