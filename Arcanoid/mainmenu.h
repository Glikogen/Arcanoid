#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "gamefield.h"
#include "menu.h"

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);

    //слой для отступов и меню
    QHBoxLayout *mainLay;

    //игровая логика
    GameField *game;

    //менюшки
    Menu *menu;

signals:
public slots:
    void ShowMainMenu();
    void StartGame();
    void ShowGameOverMenu();
    void AddMenuToLayout(Menu*_menu);
};

#endif // MAINMENU_H
