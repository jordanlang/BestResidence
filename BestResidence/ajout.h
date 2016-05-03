#ifndef AJOUT_H
#define AJOUT_H

#include <QDialog>
#include "ui_ajout.h"

class Ajout : public QDialog
{
    Q_OBJECT

public:
    explicit Ajout(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
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
    Ui::Dialog *ui;
    int nb_photos;
};

#endif // AJOUT_H
