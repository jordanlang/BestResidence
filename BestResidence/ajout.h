#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>
#include "ui_ajout.h"
#include "annonce.h"

class Ajout : public QDialog
{
    Q_OBJECT

public:
    explicit Ajout(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    explicit Ajout(QWidget *parent = Q_NULLPTR, Annonce* annonce = new Annonce(), Qt::WindowFlags f = Qt::WindowFlags());
    ~Ajout();

private slots:
    void on_b_valider_clicked();
    void on_b_annuler_clicked();
    void on_b_parcourirPrincipal_clicked();
    void on_b_parcourirSupp_clicked();
    void on_b_ajouterPrincipal_clicked();
    void on_b_ajouterSupp_clicked();
    void on_b_supprSupp_clicked();
    void on_b_supprPrincipale_clicked();

private:
    void setup();
    Ui::Dialog *ui;
    int nb_photos;
    Annonce* ann_a_modif;
    bool modif;
};

#endif // AJOUT_H
