#include <QMessageBox>
#include "annoncewindow.h"
#include "ui_annoncewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "annonce.h"
#include "choix_client.h"
#include "ui_choix_client.h"
#include "client.h"
#include "ajout.h"
#include "ui_ajout.h"

AnnonceWindow::AnnonceWindow(QWidget *parent,Annonce *monAnnonce, Qt::WindowFlags f ) :
    QDialog(parent, f),
    ui(new Ui::DialogAnnonce)
{
    ui->setupUi(this);
    this->refresh= false;

    QPixmap *pixmap_img;
    QPixmap *pixmap_img2;
    QString desc = "Description : \n";
    this->numPhoto=0;
    this->annonce=monAnnonce;
    p = ((MainWindow*)this->parent());
    this->type=monAnnonce->getTypeAnnonce();
    this->histo=monAnnonce->getHisto();
    this->photos=monAnnonce->getPhotosSupp();

    ui->l_adresse->setText(monAnnonce->getAdresse());
    ui->l_pieces->setText(QString::number(monAnnonce->getNbPieces()));
    ui->l_surface->setText(QString::number(monAnnonce->getSuperficie()) + " m²");
    ui->l_ville->setText(monAnnonce->getVille());
    ui->l_prix->setStyleSheet("QLabel { color : orange; }");
    ui->l_codeP->setText(monAnnonce->getCodePostal());
    ui->l_prix->setText(QString::number(monAnnonce->getPrix()) + " €");
    ui->l_client->setText(monAnnonce->getProp()->getNom() + " " + monAnnonce->getProp()->getPrenom());
    ui->l_id->setText("ID : " + monAnnonce->getProp()->getId());
    ui->l_contact->setText(monAnnonce->getProp()->getCourriel());
    desc += monAnnonce->getDescription();

    QString date = monAnnonce->getDate().toString("dd/MM/yyyy");
    if(monAnnonce->getPhotoPrincipale()=="")
    {
        pixmap_img = new QPixmap("../../../../BestResidence/Img/no_image.png");
    }
    else
    {
        pixmap_img = new QPixmap(monAnnonce->getPhotoPrincipale());
    }


    if(type=="Vente" && histo==0)
    {
        ui->date->setText("Offre disponible depuis le " + date);
        ui->b_typeAnnonce->setText("Vendu");
    }
    else if(type=="Location" && histo ==0)
    {
        ui->date->setText("Offre disponible depuis le " + date);
        ui->l_loyer->setText("Loyer :");
        ui->b_typeAnnonce->setText("Loué");
    }
    else if(type=="Vente" && histo ==1)
    {
        ui->date->setText("Vendu le " + date);
        ui->b_typeAnnonce->setText("Remettre en vente");
        ui->b_modifier->setVisible(false);
        ui->b_supprimer->setVisible(false);
    }

    else if(type=="Location" && histo ==1)
    {
        ui->date->setText("Loué depuis le " + date);
        ui->l_loyer->setText("Loyer :");
        ui->b_typeAnnonce->setText("Remettre en location");
        ui->b_modifier->setVisible(false);
        ui->b_supprimer->setVisible(false);
    }
    ui->description->setText(desc);
    ui->description->setReadOnly(true);
    int w = ui->l_photo->width();
    int h = ui->l_photo->height();

    // set a scaled pixmap to a w x h window keeping its aspect ratio
    ui->l_photo->setPixmap((*pixmap_img).scaled(w,h,Qt::KeepAspectRatio));

    if(photos.length() !=0)
    {
        pixmap_img2 = new QPixmap(photos.value(0));
        w = ui->photoSupp->width();
        h = ui->photoSupp->height();
        ui->photoSupp->setPixmap((*pixmap_img2).scaled(w,h,Qt::KeepAspectRatio));
        ui->l_nbPhotos->setText(QString::number(photos.length()) + " photo(s) disponible(s)" );
    }
    else
    {
        ui->groupPhotos->setVisible(false);
    }
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
            Client* client;
            for(int i=0;i<((MainWindow*)this->parent())->clients.length();i++)
            {
                if(((MainWindow*)this->parent())->clients.value(i)->getId() == QString::number(choix.getIdClient()))
                {
                    client = ((MainWindow*)this->parent())->clients.value(i);
                }
            }
            client->setNbContrats(client->getNbContrats()+1);
            this->annonce->setClient(client);
            this->annonce->setDate(QDate::fromString(date, "dd-MM-yyyy"));
            this->annonce->setHisto(1);
        }
    }
    else
    {
        QString date = QString::fromStdString(currentDate3());
        Annonce* ann = new Annonce(this->annonce->getTypeAnnonce(), this->annonce->getTypeBien(), this->annonce->getNbPieces(), this->annonce->getSuperficie(), this->annonce->getAdresse(), this->annonce->getVille(), this->annonce->getCodePostal(), this->annonce->getDescription(), this->annonce->getPrix(), QDate::fromString(date, "dd-MM-yyyy"), this->annonce->getPhotoPrincipale(), this->annonce->getPhotosSupp(), 0, this->annonce->getProp(), this->annonce->getClient());
        ((MainWindow*)this->parent())->annonces.append(ann);
        this->annonce->getProp()->setNbContrats(this->annonce->getProp()->getNbContrats()+1);
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

void AnnonceWindow::on_b_modifier_clicked()
{
    Ajout add(((MainWindow*)this->parent()), this->annonce);
    add.exec();
    ((MainWindow*)this->parent())->majAllTables();
    this->close();
    AnnonceWindow aff_win(((MainWindow*)this->parent()), this->annonce);
    aff_win.exec();
}
