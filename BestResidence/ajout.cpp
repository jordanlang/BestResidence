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
    setup();
    modif = 0;
}

Ajout::Ajout(QWidget *parent, Annonce* annonce, Qt::WindowFlags f) :
    QDialog(parent, f),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setup();
    modif = 1;
    ann_a_modif = annonce;
    ui->q_typeAnnonce->setCurrentIndex(ui->q_typeAnnonce->findText(annonce->getTypeAnnonce()));
    ui->q_client->setCurrentIndex(ui->q_client->findData(annonce->getProp()->getId()));
    ui->q_typeBien->setCurrentIndex(ui->q_typeBien->findText(annonce->getTypeBien()));
    ui->q_adresse->setText(annonce->getAdresse());
    ui->q_ville->setText(annonce->getVille());
    ui->q_codePostal->setText(annonce->getCodePostal());
    ui->q_nbPieces->setValue(annonce->getNbPieces());
    ui->q_superficieTerrain->setValue(annonce->getSuperficie());
    ui->q_description->setText(annonce->getDescription());
    ui->q_prix->setValue(annonce->getPrix());
    ui->l_photoPrincipal->setText(annonce->getPhotoPrincipale());
    this->nb_photos = annonce->getPhotosSupp().length();
    ui->listWidget->setVisible(true);
    for(int i=0; i<annonce->getPhotosSupp().length(); i++)
    {
        ui->listWidget->addItem(annonce->getPhotosSupp().value(i));
    }
}

void Ajout::setup()
{
    ui->b_valider->setStyleSheet("color: rgb(0, 0, 0)");
    ((MainWindow*)this->parent())->setAnnule(true);
    this->nb_photos = 0;
    for(int i=0; i<((MainWindow*)this->parent())->clients.length(); i++)
    {
        ui->q_client->addItem(((MainWindow*)this->parent())->clients.value(i)->getNom() + " (" + ((MainWindow*)this->parent())->clients.value(i)->getId() + ")", ((MainWindow*)this->parent())->clients.value(i)->getId());
    }
    ui->listWidget->setVisible(false);
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
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QList<QString> file = ui->listWidget->item(i)->text().split('/');

            QString filePath ="../../../../BestResidence/Photos/"+file.value(file.length()-1);
            QFile::copy(ui->listWidget->item(i)->text(),filePath);
            ps.append(filePath);
        }

        Client* prop;
        for(int i=0;i<parent->clients.length();i++)
        {
            if(parent->clients.value(i)->getId() == ui->q_client->currentData().toString())
            {
                prop = parent->clients.value(i);
            }
        }
        QList<QString> file = ui->l_photoPrincipal->text().split('/');

        QString filePath ="../../../../BestResidence/Photos/"+file.value(file.length()-1);
        QFile::copy(ui->l_photoPrincipal->text(),filePath);
        if(modif == 0)
        {
            QString date = QString::fromStdString(currentDate());

            Annonce* a = new Annonce(ui->q_typeAnnonce->currentText(), ui->q_typeBien->currentText(), ui->q_nbPieces->value(), ui->q_superficieTerrain->value(), ui->q_adresse->text(), ui->q_ville->text(), ui->q_codePostal->text(), ui->q_description->toPlainText(), ui->q_prix->value(), QDate::fromString(date, "dd-MM-yyyy"), filePath, ps, 0, prop, NULL);
            parent->annonces.append(a);
            prop->setNbContrats(prop->getNbContrats()+1);
        }
        else
        {
            ann_a_modif->setTypeAnnonce(ui->q_typeAnnonce->currentText());
            ann_a_modif->setTypeBien(ui->q_typeBien->currentText());
            ann_a_modif->setNbPieces(ui->q_nbPieces->value());
            ann_a_modif->setSuperficie(ui->q_superficieTerrain->value());
            ann_a_modif->setAdresse(ui->q_adresse->text());
            ann_a_modif->setVille(ui->q_ville->text());
            ann_a_modif->setCodePostal(ui->q_codePostal->text());
            ann_a_modif->setDescription(ui->q_description->toPlainText());
            ann_a_modif->setPrix(ui->q_prix->value());
            ann_a_modif->setPhotoPrincipale(filePath);
            ann_a_modif->setPhotosSupp(ps);
            ann_a_modif->setProp(prop);
        }

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
    if(ui->q_photoPrincipale->text() != "") {
        ui->l_photoPrincipal->setText(ui->q_photoPrincipale->text());
        ui->q_photoPrincipale->setText("");
    } else {
        QMessageBox::warning(this,"","Cliquez sur le bouton parcourir pour ajouter une photo");
    }
}

void Ajout::on_b_ajouterSupp_clicked()
{
    if(this->nb_photos<8)
    {
        if(ui->q_photosSupp->text() != "")
        {
            this->nb_photos++;
            ui->listWidget->addItem(ui->q_photosSupp->text());
            ui->q_photosSupp->setText("");
            ui->listWidget->setVisible(true);
        } else
        {
            QMessageBox::warning(this,"","Cliquez sur le bouton parcourir pour ajouter une photo");
        }
    }
    else
    {
        QMessageBox::warning(this,"","Impossible d'ajouter plus de 8 photos");
    }
}

void Ajout::on_b_supprPrincipale_clicked()
{
    ui->l_photoPrincipal->setText("");
}

void Ajout::on_b_supprSupp_clicked()
{
    ui->listWidget->clear();
    nb_photos =0;
}
