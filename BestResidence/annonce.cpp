#include <QMessageBox>
#include "annonce.h"
#include "ui_annonce.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Annonce::Annonce(QWidget *parent,int line, QString type, Qt::WindowFlags f ) :
    QDialog(parent, f),
    ui(new Ui::DialogAnnonce)
{
    ui->setupUi(this);
    ui->b_typeAnnonce->setText(type);
    QTableWidgetItem* wdg_adresse = new QTableWidgetItem();
    QTableWidgetItem* wdg_pieces = new QTableWidgetItem();
    QTableWidgetItem* wdg_superficie = new QTableWidgetItem();
    QTableWidgetItem* wdg_ville = new QTableWidgetItem();
    QTableWidgetItem* wdg_prix = new QTableWidgetItem();
    QPixmap *pixmap_img;
    QPixmap *pixmap_img2;
    QString desc = "Description :";
    ui->table->clearContents();
    this->line=line;

    this->numPhoto=0;
    p = ((MainWindow*)this->parent());
    this->type=type;
    if(type=="Vendu")
    {
        wdg_adresse->setText(p->aff_annonces_vente[line][4]);
        wdg_pieces->setText(p->aff_annonces_vente[line][2]);
        wdg_superficie->setText(p->aff_annonces_vente[line][3]);
        wdg_ville->setText(p->aff_annonces_vente[line][5]);
        wdg_prix->setText(p->aff_annonces_vente[line][8]);
        desc += p->aff_annonces_vente[line][7];
        ui->date->setText("Offre disponible depuis le " + p->aff_annonces_vente[line][9]);
        pixmap_img = new QPixmap(p->aff_annonces_vente[line][10]);
        pixmap_img2 = new QPixmap(p->aff_annonces_vente[line][11]);
    }
    else if(type=="Loué")
    {
        wdg_adresse->setText(p->aff_annonces_location[line][4]);
        wdg_pieces->setText(p->aff_annonces_location[line][2]);
        wdg_superficie->setText(p->aff_annonces_location[line][3]);
        wdg_ville->setText(p->aff_annonces_location[line][5]);
        wdg_prix->setText(p->aff_annonces_location[line][8]);
        desc += p->aff_annonces_location[line][7];
        ui->date->setText("Offre disponible depuis le " + p->aff_annonces_location[line][9]);
        pixmap_img = new QPixmap(p->aff_annonces_location[line][10]);
        pixmap_img2 = new QPixmap(p->aff_annonces_location[line][11]);
    }
    else if(type=="Remettre en vente")
    {
        wdg_adresse->setText(p->aff_histo_vente[line][4]);
        wdg_pieces->setText(p->aff_histo_vente[line][2]);
        wdg_superficie->setText(p->aff_histo_vente[line][3]);
        wdg_ville->setText(p->aff_histo_vente[line][5]);
        wdg_prix->setText(p->aff_histo_vente[line][8]);
        desc += p->aff_annonces_vente[line][7];
        ui->date->setText("Vendu le " + p->aff_histo_vente[line][9]);
        pixmap_img = new QPixmap(p->aff_histo_vente[line][10]);
        pixmap_img2 = new QPixmap(p->aff_histo_vente[line][11]);
    }

    else if(type=="Remettre en location")
    {
        wdg_adresse->setText(p->aff_histo_location[line][4]);
        wdg_pieces->setText(p->aff_histo_location[line][2]);
        wdg_superficie->setText(p->aff_histo_location[line][3]);
        wdg_ville->setText(p->aff_histo_location[line][5]);
        wdg_prix->setText(p->aff_histo_location[line][8]);
        desc += p->aff_annonces_location[line][7];
        ui->date->setText("Loué depuis le " + p->aff_histo_location[line][9]);
        pixmap_img = new QPixmap(p->aff_histo_location[line][10]);
        pixmap_img2 = new QPixmap(p->aff_histo_location[line][11]);
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

}

Annonce::~Annonce()
{
    delete ui;
}

void Annonce::on_b_retour_clicked()
{
    this->close();
}

void Annonce::on_b_typeAnnonce_clicked()
{
    p->setHisto(1);
    this->close();
}

void Annonce::on_b_next_clicked()
{
    QPixmap *pixmap_img2;
    this->numPhoto=(this->numPhoto+1)%8;
    int i = this->numPhoto;
    int line = this->line;
    if(type=="Vendu")
    {
        pixmap_img2 = new QPixmap(p->aff_annonces_vente[line][11+i]);
    }
    else if(type=="Loué")
    {
        pixmap_img2 = new QPixmap(p->aff_annonces_location[line][11+i]);
    }
    else if(type=="Remettre en vente")
    {
        pixmap_img2 = new QPixmap(p->aff_histo_vente[line][11+i]);
    }

    else if(type=="Remettre en location")
    {

        pixmap_img2 = new QPixmap(p->aff_histo_location[line][11+i]);
    }

    int w = ui->photoSupp->width();
    int h= ui->photoSupp->height();

    ui->photoSupp->setPixmap((*pixmap_img2).scaled(w,h,Qt::KeepAspectRatio));

}

void Annonce::on_b_previous_clicked()
{
    QPixmap *pixmap_img2;
    if(this->numPhoto-1<0)
        this->numPhoto=7;
    else
        this->numPhoto--;
    int i = this->numPhoto;
    if(type=="Vendu")
    {
        pixmap_img2 = new QPixmap(p->aff_annonces_vente[line][11+i]);
    }
    else if(type=="Loué")
    {
        pixmap_img2 = new QPixmap(p->aff_annonces_location[line][11+i]);
    }
    else if(type=="Remettre en vente")
    {
        pixmap_img2 = new QPixmap(p->aff_histo_vente[line][11+i]);
    }

    else if(type=="Remettre en location")
    {

        pixmap_img2 = new QPixmap(p->aff_histo_location[line][11+i]);
    }

    int w = ui->photoSupp->width();
    int h= ui->photoSupp->height();

    ui->photoSupp->setPixmap((*pixmap_img2).scaled(w,h,Qt::KeepAspectRatio));
}
