#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
    ShowMainMenu();
}

void MainMenu::ShowMainMenu()
{
    menu = new Menu();
    menu->InitializeMainMenu();
    AddMenuToLayout(menu);

    connect(menu->MainMenu_btn_start, SIGNAL(clicked()), this, SLOT(StartGame()));
}

void MainMenu::StartGame()
{
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete layout();

    game = new GameField();

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->setMargin(0);
    layout1->addWidget(game);
    setLayout(layout1);

    game->setFocus();

    connect(game, SIGNAL(GameOver()), this, SLOT(ShowGameOverMenu()));
}

void MainMenu::ShowGameOverMenu()
{
    menu = new Menu();
    menu->InitializeGameOverMenu();
    AddMenuToLayout(menu);

    connect(menu->GOM_btn2_start, SIGNAL(clicked()), this, SLOT(StartGame()));
    connect(menu->GOM_btn1_inMainMenu, SIGNAL(clicked()), this, SLOT(ShowMainMenu()));
}

void MainMenu::AddMenuToLayout(Menu *_menu)
{
    qDeleteAll(this->findChildren<QWidget *>(QString(), Qt::FindDirectChildrenOnly));
    delete layout();

    mainLay = new QHBoxLayout;
    mainLay->addSpacerItem(new QSpacerItem(10,1, QSizePolicy::Expanding, QSizePolicy::Expanding));

    mainLay->addLayout(_menu->lay);
    mainLay->addSpacerItem(new QSpacerItem(10,1, QSizePolicy::Expanding, QSizePolicy::Expanding));
    setLayout(mainLay);
}
