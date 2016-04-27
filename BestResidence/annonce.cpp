#include <QMessageBox>
#include "annonce.h"
#include "ui_annonce.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Annonce::Annonce(QWidget *parent, Qt::WindowFlags f ) :
    QDialog(parent, f),
    ui(new Ui::DialogAnnonce)
{
    ui->setupUi(this);
}

Annonce::~Annonce()
{
    delete ui;
}

void Annonce::on_b_retour_clicked()
{
    this->close();
}
