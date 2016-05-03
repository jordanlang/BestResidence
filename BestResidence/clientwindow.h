#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include "ui_clientwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"


class ClientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = Q_NULLPTR,Client *monClient = new Client(), Qt::WindowFlags f = Qt::WindowFlags());
    ~ClientWindow();
    bool getRefresh();
    void setAnnule(bool);

private slots:
    void on_b_retour_clicked();
    void on_b_supprimer_clicked();
    void on_b_modifier_clicked();

private:
    Ui::DialogClient *ui;
    MainWindow * p;
    Client *client;
    bool refresh;
    bool annule;
};

#endif // CLIENTWINDOW_H
