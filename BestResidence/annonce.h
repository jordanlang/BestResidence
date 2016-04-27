#ifndef ANNONCE_H
#define ANNONCE_H

#include <QDialog>
#include "ui_annonce.h"

class Annonce : public QDialog
{
    Q_OBJECT

public:
    explicit Annonce(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~Annonce();

private slots:
    void on_b_retour_clicked();

private:
    Ui::DialogAnnonce *ui;
};
#endif // ANNONCE_H
