/********************************************************************************
** Form generated from reading UI file 'ajout.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUT_H
#define UI_AJOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QComboBox *q_typeBien;
    QLabel *l_typeBien;
    QLabel *l_superficieTerrain;
    QSpinBox *q_superficieTerrain;
    QLabel *l_mCarre;
    QLabel *l_nbPieces;
    QSpinBox *q_nbPieces;
    QLineEdit *q_adresse;
    QLabel *l_adresse;
    QLineEdit *q_codePostal;
    QLabel *l_ville;
    QLineEdit *q_ville;
    QLabel *l_description;
    QTextEdit *q_description;
    QLabel *l_prix;
    QDoubleSpinBox *q_prix;
    QLabel *l_euros;
    QLabel *l_photoPrincipale;
    QLineEdit *q_photoPrincipale;
    QPushButton *b_parcourirPrincipal;
    QLabel *l_typeAnnonce;
    QComboBox *q_typeAnnonce;
    QPushButton *b_ajouterPrincipal;
    QPushButton *b_ajouterSupp;
    QLabel *l_photosSupp;
    QPushButton *b_parcourirSupp;
    QLineEdit *q_photosSupp;
    QPushButton *b_valider;
    QPushButton *b_annuler;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(605, 573);
        q_typeBien = new QComboBox(Dialog);
        q_typeBien->setObjectName(QStringLiteral("q_typeBien"));
        q_typeBien->setGeometry(QRect(170, 70, 201, 31));
        l_typeBien = new QLabel(Dialog);
        l_typeBien->setObjectName(QStringLiteral("l_typeBien"));
        l_typeBien->setGeometry(QRect(60, 70, 91, 16));
        l_superficieTerrain = new QLabel(Dialog);
        l_superficieTerrain->setObjectName(QStringLiteral("l_superficieTerrain"));
        l_superficieTerrain->setGeometry(QRect(340, 120, 131, 21));
        q_superficieTerrain = new QSpinBox(Dialog);
        q_superficieTerrain->setObjectName(QStringLiteral("q_superficieTerrain"));
        q_superficieTerrain->setGeometry(QRect(480, 120, 48, 24));
        l_mCarre = new QLabel(Dialog);
        l_mCarre->setObjectName(QStringLiteral("l_mCarre"));
        l_mCarre->setGeometry(QRect(530, 120, 61, 20));
        l_nbPieces = new QLabel(Dialog);
        l_nbPieces->setObjectName(QStringLiteral("l_nbPieces"));
        l_nbPieces->setGeometry(QRect(130, 120, 121, 20));
        q_nbPieces = new QSpinBox(Dialog);
        q_nbPieces->setObjectName(QStringLiteral("q_nbPieces"));
        q_nbPieces->setGeometry(QRect(260, 120, 48, 24));
        q_adresse = new QLineEdit(Dialog);
        q_adresse->setObjectName(QStringLiteral("q_adresse"));
        q_adresse->setGeometry(QRect(170, 160, 381, 21));
        l_adresse = new QLabel(Dialog);
        l_adresse->setObjectName(QStringLiteral("l_adresse"));
        l_adresse->setGeometry(QRect(100, 160, 71, 16));
        q_codePostal = new QLineEdit(Dialog);
        q_codePostal->setObjectName(QStringLiteral("q_codePostal"));
        q_codePostal->setGeometry(QRect(402, 200, 151, 21));
        l_ville = new QLabel(Dialog);
        l_ville->setObjectName(QStringLiteral("l_ville"));
        l_ville->setGeometry(QRect(120, 200, 41, 20));
        q_ville = new QLineEdit(Dialog);
        q_ville->setObjectName(QStringLiteral("q_ville"));
        q_ville->setGeometry(QRect(170, 200, 221, 21));
        l_description = new QLabel(Dialog);
        l_description->setObjectName(QStringLiteral("l_description"));
        l_description->setGeometry(QRect(30, 250, 131, 16));
        q_description = new QTextEdit(Dialog);
        q_description->setObjectName(QStringLiteral("q_description"));
        q_description->setGeometry(QRect(170, 240, 381, 131));
        l_prix = new QLabel(Dialog);
        l_prix->setObjectName(QStringLiteral("l_prix"));
        l_prix->setGeometry(QRect(420, 380, 41, 21));
        q_prix = new QDoubleSpinBox(Dialog);
        q_prix->setObjectName(QStringLiteral("q_prix"));
        q_prix->setGeometry(QRect(460, 380, 67, 24));
        l_euros = new QLabel(Dialog);
        l_euros->setObjectName(QStringLiteral("l_euros"));
        l_euros->setGeometry(QRect(530, 380, 21, 21));
        l_photoPrincipale = new QLabel(Dialog);
        l_photoPrincipale->setObjectName(QStringLiteral("l_photoPrincipale"));
        l_photoPrincipale->setGeometry(QRect(50, 420, 111, 20));
        q_photoPrincipale = new QLineEdit(Dialog);
        q_photoPrincipale->setObjectName(QStringLiteral("q_photoPrincipale"));
        q_photoPrincipale->setGeometry(QRect(170, 420, 241, 21));
        b_parcourirPrincipal = new QPushButton(Dialog);
        b_parcourirPrincipal->setObjectName(QStringLiteral("b_parcourirPrincipal"));
        b_parcourirPrincipal->setGeometry(QRect(420, 420, 31, 21));
        l_typeAnnonce = new QLabel(Dialog);
        l_typeAnnonce->setObjectName(QStringLiteral("l_typeAnnonce"));
        l_typeAnnonce->setGeometry(QRect(40, 40, 111, 20));
        q_typeAnnonce = new QComboBox(Dialog);
        q_typeAnnonce->setObjectName(QStringLiteral("q_typeAnnonce"));
        q_typeAnnonce->setGeometry(QRect(170, 40, 201, 26));
        b_ajouterPrincipal = new QPushButton(Dialog);
        b_ajouterPrincipal->setObjectName(QStringLiteral("b_ajouterPrincipal"));
        b_ajouterPrincipal->setGeometry(QRect(480, 420, 71, 21));
        b_ajouterSupp = new QPushButton(Dialog);
        b_ajouterSupp->setObjectName(QStringLiteral("b_ajouterSupp"));
        b_ajouterSupp->setGeometry(QRect(480, 460, 71, 21));
        l_photosSupp = new QLabel(Dialog);
        l_photosSupp->setObjectName(QStringLiteral("l_photosSupp"));
        l_photosSupp->setGeometry(QRect(0, 460, 161, 20));
        b_parcourirSupp = new QPushButton(Dialog);
        b_parcourirSupp->setObjectName(QStringLiteral("b_parcourirSupp"));
        b_parcourirSupp->setGeometry(QRect(420, 460, 31, 21));
        q_photosSupp = new QLineEdit(Dialog);
        q_photosSupp->setObjectName(QStringLiteral("q_photosSupp"));
        q_photosSupp->setGeometry(QRect(170, 460, 241, 21));
        b_valider = new QPushButton(Dialog);
        b_valider->setObjectName(QStringLiteral("b_valider"));
        b_valider->setGeometry(QRect(432, 521, 151, 41));
        b_annuler = new QPushButton(Dialog);
        b_annuler->setObjectName(QStringLiteral("b_annuler"));
        b_annuler->setGeometry(QRect(282, 521, 151, 41));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        q_typeBien->clear();
        q_typeBien->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Maison", 0)
         << QApplication::translate("Dialog", "Appartement", 0)
         << QApplication::translate("Dialog", "Ch\303\242teau", 0)
         << QApplication::translate("Dialog", "Ferme", 0)
         << QApplication::translate("Dialog", "Bureau", 0)
         << QApplication::translate("Dialog", "Commerce", 0)
        );
        l_typeBien->setText(QApplication::translate("Dialog", "Type de bien :", 0));
        l_superficieTerrain->setText(QApplication::translate("Dialog", "Superficie du terrain :", 0));
        l_mCarre->setText(QApplication::translate("Dialog", "m2", 0));
        l_nbPieces->setText(QApplication::translate("Dialog", "Nombre de pi\303\250ces :", 0));
        l_adresse->setText(QApplication::translate("Dialog", "Adresse :", 0));
        q_codePostal->setText(QString());
        q_codePostal->setPlaceholderText(QApplication::translate("Dialog", "Code Postal", 0));
        l_ville->setText(QApplication::translate("Dialog", "Ville :", 0));
        l_description->setText(QApplication::translate("Dialog", "Description du bien :", 0));
        l_prix->setText(QApplication::translate("Dialog", "Prix :", 0));
        l_euros->setText(QApplication::translate("Dialog", "\342\202\254", 0));
        l_photoPrincipale->setText(QApplication::translate("Dialog", " Photo principale :", 0));
        b_parcourirPrincipal->setText(QApplication::translate("Dialog", "...", 0));
        l_typeAnnonce->setText(QApplication::translate("Dialog", "Type d'annonce :", 0));
        q_typeAnnonce->clear();
        q_typeAnnonce->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "Location", 0)
         << QApplication::translate("Dialog", "Vente", 0)
        );
        b_ajouterPrincipal->setText(QApplication::translate("Dialog", "Ajouter", 0));
        b_ajouterSupp->setText(QApplication::translate("Dialog", "Ajouter", 0));
        l_photosSupp->setText(QApplication::translate("Dialog", " Photos suppl\303\251mentaires :", 0));
        b_parcourirSupp->setText(QApplication::translate("Dialog", "...", 0));
        b_valider->setText(QApplication::translate("Dialog", "Valider", 0));
        b_annuler->setText(QApplication::translate("Dialog", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUT_H
