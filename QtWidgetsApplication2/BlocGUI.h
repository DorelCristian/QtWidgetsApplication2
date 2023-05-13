#pragma once
#include<QtWidgets/qwidget.h>
#include<vector>
#include <QtWidgets/QApplication>
#include<QtWidgets/qboxlayout.h>
#include<QtWidgets/qpushbutton.h>
#include<QtWidgets/qlabel.h>
#include<QtWidgets/qlineedit.h>
#include<QtWidgets/qformlayout.h>
#include<QtWidgets/qlistwidget.h>
#include<QtWidgets/qmessagebox.h>
#include<qdebug>
#include<vector>
#include<string>
#include "ServiceLocatar.h"
using std::vector;
using std::string;

class BlocGUI:public QWidget{
public:
    BlocGUI(Service& srv) :serv { srv } {
		initGUI();
        loadData();
        initConnect();

	}

private:
    Service &serv;
    QListWidget* lst = new QListWidget;
    QPushButton* btnExit = new QPushButton{ "&Exit" };
    QPushButton* btnAdauga = new QPushButton{ "&Adauga" };
    QPushButton* btnSterge = new QPushButton{ "&Sterge" };
    QPushButton* btnModifica = new QPushButton{ "&Modifica" };
    QLineEdit* txtApartament = new QLineEdit;
    QLineEdit* txtNume = new QLineEdit;
    QLineEdit* txtSuprafata = new QLineEdit;
    QLineEdit* txtTipApartament = new QLineEdit;
  

    void initConnect()
    {
        QObject::connect(btnExit, &QPushButton::clicked, [&]() {
            qDebug() << "Exit button apasat!";
            QMessageBox::information(nullptr, "Exit", "Exit button apasat!");
            close();
			//QApplication::quit();
			});
        QObject::connect(btnAdauga, &QPushButton::clicked, [&]() {
			auto apartament=txtApartament->text().toStdString();
            auto nume=txtNume->text().toStdString();
            auto suprafata=txtSuprafata->text().toInt();
            auto tipApartament=txtTipApartament->text().toStdString();
           // qDebug() << "Apartament"<<apartament<<"nume"<<nume<<"suprafata"<<suprafata<<"tip apartament"<<tipApartament;
            //serv.addProduct(apartament,nume,suprafata,tipApartament);
            serv.addLocatar(apartament, nume, suprafata, tipApartament);
            loadData();
            // reincarc lista
			//close();
			//QApplication::quit();
			});
        QObject::connect(btnSterge, &QPushButton::clicked, [&]() {
			auto apartament = txtApartament->text().toStdString();
			auto nume = txtNume->text().toStdString();
			auto suprafata = txtSuprafata->text().toInt();
			auto tipApartament = txtTipApartament->text().toStdString();
		    qDebug() << "Apartament"<<apartament<<"nume"<<nume<<"suprafata"<<suprafata<<"tip apartament"<<tipApartament;
			//serv.addProduct(apartament,nume,suprafata,tipApartament);
            //locatars l{ apartament,nume,suprafata,tipApartament };

			serv.deleteLocatar(apartament);
			loadData();
			// reincarc lista
			//close();
			//QApplication::quit();
			});
        QObject::connect(btnModifica, &QPushButton::clicked, [&]() {
			auto apartament = txtApartament->text().toStdString();
			auto nume = txtNume->text().toStdString();
			auto suprafata = txtSuprafata->text().toInt();
			auto tipApartament = txtTipApartament->text().toStdString();
			// qDebug() << "Apartament"<<apartament<<"nume"<<nume<<"suprafata"<<suprafata<<"tip apartament"<<tipApartament;
			//serv.addProduct(apartament,nume,suprafata,tipApartament);
			serv.updateLocatar(apartament, nume, suprafata, tipApartament);
			loadData();
			// reincarc lista
			//close();
			//QApplication::quit();
			});
        QObject::connect(lst, &QListWidget::itemSelectionChanged, [&]() {
			auto sel = lst->selectedItems();
            if (sel.isEmpty())
            {
				txtApartament->setText("");
				txtNume->setText("");
				txtSuprafata->setText("");
				txtTipApartament->setText("");
				return;
			}
			auto selItem = sel.at(0);
			auto nume = selItem->text();
            QStringList data=nume.split(" ");
            
            QString apartament = data[0];
            QString nume2 =data[1];

            locatars l = serv.findLocatar(apartament.toStdString());
            //QString suprafata = l.get_suprafata().toQString();
            int suprafata = l.get_suprafata();
            string tipApartament = l.get_tip_apartament();
            QString tipApartament2 = QString::fromStdString(tipApartament);
			txtApartament->setText(apartament);
			txtNume->setText(nume2);
            string suprafata2 = std::to_string(suprafata);
            QString suprafata3 = QString::fromStdString(suprafata2);
			txtSuprafata->setText(suprafata3);
			txtTipApartament->setText(tipApartament2);
			});
       // QObject::connect(btnSterge, &QPushButton::clicked, [&]() {})
	}
    void loadData()
    {
        lst->clear();
        //vector<string> allProduct{ "Product1", "Product2", "Product3","Product5","Product12" };
        vector<locatars> allProduct = serv.getAll();

        for ( const auto &product : allProduct)
        {   
            auto item = new QListWidgetItem(QString::fromStdString(product.get_apartament()+" "+product.get_nume()));
            lst->addItem(item);

        }
    }
	void initGUI()
	{
        QHBoxLayout* lyMain = new QHBoxLayout{};
        setLayout(lyMain);

        //lyMain->addWidget(lst);
        

        /*lyMain->addWidget(new QLabel{ "Hello" });
        lyMain->addWidget(new QLineEdit{ "World" });*/
        auto leftLy=new QVBoxLayout;


          auto lyBtns = new QHBoxLayout;
          lyBtns->addWidget(new QPushButton{ "Sortare1" });
          lyBtns->addWidget(new QPushButton{ "Sortare2" });
         //lyBtns->addWidget(new QPushButton{ "Sortare3" });

          auto lyFiltrare=new QHBoxLayout;
          lyFiltrare->addWidget(new QPushButton{ "Filtrare1" });
          lyFiltrare->addWidget(new QPushButton{ "Filtrare2" });
          lyFiltrare->addWidget(new QPushButton{ "Filtrare3" });
         // lyMain->addLayout(lyBtns);
          
          leftLy->addWidget(lst);
          leftLy->addLayout(lyBtns);
          leftLy->addLayout(lyFiltrare);

          lyMain->addLayout(leftLy);

        



        auto stgLy = new QVBoxLayout;



        auto formLy = new QFormLayout;
        formLy->addRow("Apartament", txtApartament);
        formLy->addRow("Nume", txtNume);
        formLy->addRow("Suprafata", txtSuprafata);
        formLy->addRow("Tip Apartament", txtTipApartament);
        stgLy->addLayout(formLy);


        auto lyBtn = new QHBoxLayout;

        lyBtn->addWidget(btnAdauga);
        lyBtn->addWidget(btnSterge);
        lyBtn->addWidget(btnModifica);
        lyBtn->addWidget(btnExit);
        stgLy->addLayout(lyBtn);

        lyMain->addLayout(stgLy);
	}

};
