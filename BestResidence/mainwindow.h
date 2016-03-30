#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setTypeAnnonce(QString);
    void setTypeBien(QString);
    void setNbPieces(int);
    void setSuperficie(double);
    void setAdresse(QString);
    void setVille(QString);
    void setCodePostal(QString);
    void setDescription(QString);
    void setPrix(double);
    void setPhotoPrincipale(QString);
    void setPhotosSupp(QString[]);
    void setAnnule(bool);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString typeAnnonce;
    QString typeBien;
    int nbPieces;
    double superficie;
    QString adresse;
    QString ville;
    QString codePostal;
    QString description;
    double prix;
    QString photoPrincipale;
    QString photosSupp[10];
    bool annule;
};

#endif // MAINWINDOW_H