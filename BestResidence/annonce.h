#ifndef ANNONCE_H
#define ANNONCE_H

#include <QDialog>
#include "ui_annonce.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Annonce : public QDialog
{
    Q_OBJECT

public:
    explicit Annonce(QWidget *parent = Q_NULLPTR,int line=0, QString type = "Vente", Qt::WindowFlags f = Qt::WindowFlags());
    ~Annonce();

private slots:
    void on_b_retour_clicked();
    void on_b_typeAnnonce_clicked();
    void on_b_previous_clicked();
    void on_b_next_clicked();

private:
    Ui::DialogAnnonce *ui;
    MainWindow * p;
    QString type;
    int numPhoto;
    int line;
};
#endif // ANNONCE_H
