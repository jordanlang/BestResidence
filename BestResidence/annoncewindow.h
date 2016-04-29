#ifndef ANNONCEWINDOW_H
#define ANNONCEWINDOW_H

#include <QDialog>
#include "ui_annoncewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

class AnnonceWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AnnonceWindow(QWidget *parent = Q_NULLPTR,int line=0, QString type = "Vente", Qt::WindowFlags f = Qt::WindowFlags());
    ~AnnonceWindow();

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
#endif // ANNONCEWINDOW_H
