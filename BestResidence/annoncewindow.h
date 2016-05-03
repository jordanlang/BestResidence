#ifndef ANNONCEWINDOW_H
#define ANNONCEWINDOW_H

#include <QDialog>
#include "ui_annoncewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "annonce.h"
#include "ajout.h"
#include "ui_ajout.h"

class AnnonceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AnnonceWindow(QWidget *parent = Q_NULLPTR,Annonce *monAnnonce = new Annonce(), Qt::WindowFlags f = Qt::WindowFlags());
    ~AnnonceWindow();
    bool getRefresh();
    void setAnnule(bool);

private slots:
    void on_b_retour_clicked();
    void on_b_typeAnnonce_clicked();
    void on_b_previous_clicked();
    void on_b_next_clicked();
    void on_b_supprimer_clicked();
    void on_b_modifier_clicked();

private:
    Ui::DialogAnnonce *ui;
    MainWindow * p;
    QString type;
    int numPhoto;
    int histo;
    QList<QString> photos;
    Annonce *annonce;
    bool refresh;
    bool annule;
};
#endif // ANNONCEWINDOW_H
