//#include "QtWidgetsApplication2.h"
#include <QtWidgets/QApplication>
#include<QtWidgets/qboxlayout.h>
#include<QtWidgets/qpushbutton.h>
#include<QtWidgets/qlabel.h>
#include<QtWidgets/qlineedit.h>
#include<QtWidgets/qformlayout.h>
#include<QtWidgets/qlistwidget.h>
#include<vector>
#include<string>
#include"BlocGUI.h"
using std::vector;
using std::string;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RepoLocatar repo;
    Service serv{ repo };

    BlocGUI gui{serv};
    gui.show();
    //QtWidgetsApplication2 w;
    
    /*QWidget w{};
    QHBoxLayout* lyMain = new QHBoxLayout{};
    w.setLayout(lyMain);
  
    auto lst = new QListWidget;
    lyMain->addWidget(lst);

    /*lyMain->addWidget(new QLabel{ "Hello" });
    lyMain->addWidget(new QLineEdit{ "World" });*/
    
  /*  auto lyBtns = new QVBoxLayout;
    lyBtns->addWidget(new QPushButton{ "Buton1" });
    lyBtns->addWidget(new QPushButton{ "Buton2" });
    lyBtns->addWidget(new QPushButton{ "Buton3" });
    lyMain->addLayout(lyBtns);*/
    

/*    auto stgLy=new QVBoxLayout;



    auto formLy=new QFormLayout;
    formLy->addRow("Nume", new QLineEdit);
    formLy->addRow("Prenume", new QLineEdit);
    formLy->addRow("Pret", new QLineEdit);
    stgLy->addLayout(formLy);
    
    
    auto lyBtn = new QHBoxLayout;
    lyBtn->addWidget(new QPushButton{ "&Adauga" });
    lyBtn->addWidget(new QPushButton{ "&Sterge" });
    lyBtn->addWidget(new QPushButton{ "&Modifica" });
    lyBtn->addWidget(new QPushButton{ "&Exit" });
    stgLy->addLayout(lyBtn);

    lyMain->addLayout(stgLy);






    vector<string> allProduct{ "Product1", "Product2", "Product3","Product5","Product12"};

    for (const auto& product : allProduct)
    {
		lst->addItem(QString::fromStdString(product));
	}
    
   lst->addItem("Item1");
   lst->addItem("Item2");
    w.show();*/
    return a.exec();
}