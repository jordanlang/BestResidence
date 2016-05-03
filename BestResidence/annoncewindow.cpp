#include <QMessageBox>
#include "annoncewindow.h"
#include "ui_annoncewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "annonce.h"
#include "choix_client.h"
#include "ui_choix_client.h"

AnnonceWindow::AnnonceWindow(QWidget *parent,Annonce *monAnnonce, Qt::WindowFlags f ) :
    QDialog(parent, f),
    ui(new Ui::DialogAnnonce)
{
    ui->setupUi(this);
    this->refresh= false;

    QTableWidgetItem* wdg_adresse = new QTableWidgetItem();
    QTableWidgetItem* wdg_pieces = new QTableWidgetItem();
    QTableWidgetItem* wdg_superficie = new QTableWidgetItem();
    QTableWidgetItem* wdg_ville = new QTableWidgetItem();
    QTableWidgetItem* wdg_prix = new QTableWidgetItem();
    QPixmap *pixmap_img;
    QPixmap *pixmap_img2;
    QString desc = "Description :";
    ui->table->clearContents();
    this->numPhoto=0;
    this->annonce=monAnnonce;
    p = ((MainWindow*)this->parent());

    this->type=monAnnonce->getTypeAnnonce();
    this->histo=monAnnonce->getHisto();
    this->photos=monAnnonce->getPhotosSupp();

    wdg_adresse->setText(monAnnonce->getAdresse());
    wdg_pieces->setText(QString::number(monAnnonce->getNbPieces()));
    wdg_superficie->setText(QString::number(monAnnonce->getSuperficie()) + " m²");
    wdg_ville->setText(monAnnonce->getVille());
    wdg_prix->setText(QString::number(monAnnonce->getPrix()) + " €");
    desc += monAnnonce->getDescription();

    QString date = monAnnonce->getDate().toString("dd/MM/yyyy");

    pixmap_img = new QPixmap(monAnnonce->getPhotoPrincipale());
    pixmap_img2 = new QPixmap(monAnnonce->getPhotosSupp().value(0));

    if(type=="Vente" && histo==0)
    {
        ui->date->setText("Offre disponible depuis le " + date);
        ui->b_typeAnnonce->setText("Vendu");
    }
    else if(type=="Location" && histo ==0)
    {
        ui->date->setText("Offre disponible depuis le " + date);
        ui->b_typeAnnonce->setText("Loué");
    }
    else if(type=="Vente" && histo ==1)
    {
        ui->date->setText("Vendu le " + date);
        ui->b_typeAnnonce->setText("Remettre en vente");
    }

    else if(type=="Location" && histo ==1)
    {
        ui->date->setText("Loué depuis le " + date);
        ui->b_typeAnnonce->setText("Remettre en location");
    }
    ui->table->insertColumn(0);
    ui->table->setItem(0, 0, wdg_prix);
    ui->table->setItem(1, 0, wdg_pieces);
    ui->table->setItem(2, 0, wdg_superficie);
    ui->table->setItem(3, 0, wdg_ville);
    ui->table->setItem(4, 0, wdg_adresse);
    ui->description->setText(desc);
    ui->description->setReadOnly(true);
    int w = ui->l_photo->width();
    int h = ui->l_photo->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->l_photo->setPixmap((*pixmap_img).scaled(w,h,Qt::KeepAspectRatio));

    w = ui->photoSupp->width();
    h= ui->photoSupp->height();

    ui->photoSupp->setPixmap((*pixmap_img2).scaled(w,h,Qt::KeepAspectRatio));
    ui->l_nbPhotos->setText(QString::number(monAnnonce->getPhotosSupp().length()) + " photos disponibles" );


}

AnnonceWindow::~AnnonceWindow()
{
    delete ui;
}

const std::string currentDate3() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

    return buf;
}

void AnnonceWindow::on_b_retour_clicked()
{
    this->close();
}

void AnnonceWindow::on_b_supprimer_clicked()
{
    this->p->annonces.removeAt(this->p->annonces.indexOf(this->annonce));
    this->refresh=true;
    this->close();
}

void AnnonceWindow::on_b_typeAnnonce_clicked()
{
    if(this->annonce->getHisto() == 0)
    {
        QString date = QString::fromStdString(currentDate3());
        ChoixClient choix(this);
        choix.exec();
        if(!annule) {
            this->annonce->setIdClient(choix.getIdClient());
            this->annonce->setDate(QDate::fromString(date, "dd-MM-yyyy"));
            this->annonce->setHisto(1);
        }
    }
    else
    {
        QString date = QString::fromStdString(currentDate3());
        Annonce* ann = new Annonce(this->annonce->getTypeAnnonce(), this->annonce->getTypeBien(), this->annonce->getNbPieces(), this->annonce->getSuperficie(), this->annonce->getAdresse(), this->annonce->getVille(), this->annonce->getCodePostal(), this->annonce->getDescription(), this->annonce->getPrix(), QDate::fromString(date, "dd-MM-yyyy"), this->annonce->getPhotoPrincipale(), this->annonce->getPhotosSupp(), 0, this->annonce->getIdProp(), this->annonce->getIdClient());
        ((MainWindow*)this->parent())->annonces.append(ann);
    }
    this->refresh=true;
    this->close();
}

void AnnonceWindow::on_b_next_clicked()
{
    QPixmap *pixmap_img2;
    this->numPhoto=(this->numPhoto+1)%this->photos.length();
    int i = this->numPhoto;

    pixmap_img2 = new QPixmap(this->photos.value(i));


    int w = ui->photoSupp->width();
    int h= ui->photoSupp->height();

    ui->photoSupp->setPixmap((*pixmap_img2).scaled(w,h,Qt::KeepAspectRatio));

}

void AnnonceWindow::on_b_previous_clicked()
{

    QPixmap *pixmap_img2;
    if(this->numPhoto-1<0)
        this->numPhoto=this->photos.length()-1;
    else
        this->numPhoto--;
    int i = this->numPhoto;


    pixmap_img2 = new QPixmap(this->photos.value(i));

    int w = ui->photoSupp->width();
    int h= ui->photoSupp->height();

    ui->photoSupp->setPixmap((*pixmap_img2).scaled(w,h,Qt::KeepAspectRatio));

}

bool AnnonceWindow::getRefresh(){
    return this->refresh;
}

void AnnonceWindow::setAnnule(bool b)
{
    this->annule = b;
}
