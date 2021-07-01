#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent)
{

}

void Menu::InitializeMainMenu()
{
    QLabel *MainMenu_lbl = new QLabel("Физика:");
    MainMenu_lbl->setMinimumWidth(200);

    QComboBox *cbox = new QComboBox;
    cbox->addItem("игровая");
    cbox->addItem("естественная");
    cbox->setMinimumWidth(200);

    MainMenu_btn_start = new QPushButton("Играть!");
    MainMenu_btn_start->setMinimumWidth(200);

    lay = new QVBoxLayout;
    lay->addSpacerItem(new QSpacerItem(1,100, QSizePolicy::Expanding, QSizePolicy::Expanding));
    lay->addWidget(MainMenu_lbl);
    lay->addSpacerItem(new QSpacerItem(1,50, QSizePolicy::Preferred, QSizePolicy::Preferred));
    lay->addWidget(cbox);
    lay->addSpacerItem(new QSpacerItem(1,50, QSizePolicy::Preferred, QSizePolicy::Preferred));
    lay->addWidget(MainMenu_btn_start);
    lay->addSpacerItem(new QSpacerItem(1,100, QSizePolicy::Expanding, QSizePolicy::Expanding));
}

void Menu::InitializeGameOverMenu()
{
    QLabel *lbl1 = new QLabel("Ваш счет:");
    lbl1->setMinimumWidth(200);
    QLabel *lbl2 = new QLabel("Какие-то цифры");
    lbl2->setMinimumWidth(200);
    GOM_btn1_inMainMenu = new QPushButton("В главное меню");
    GOM_btn1_inMainMenu->setMinimumWidth(200);
    GOM_btn2_start = new QPushButton("Заного");
    GOM_btn2_start->setMinimumWidth(200);

    lay = new QVBoxLayout;
    lay->addSpacerItem(new QSpacerItem(1,100, QSizePolicy::Expanding, QSizePolicy::Expanding));
    lay->addWidget(lbl1);
    lay->addSpacerItem(new QSpacerItem(1,50, QSizePolicy::Preferred, QSizePolicy::Preferred));
    lay->addWidget(lbl2);
    lay->addSpacerItem(new QSpacerItem(1,50, QSizePolicy::Preferred, QSizePolicy::Preferred));
    lay->addWidget(GOM_btn1_inMainMenu);
    lay->addSpacerItem(new QSpacerItem(1,50, QSizePolicy::Preferred, QSizePolicy::Preferred));
    lay->addWidget(GOM_btn2_start);
    lay->addSpacerItem(new QSpacerItem(1,100, QSizePolicy::Expanding, QSizePolicy::Expanding));
}
