#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QtWidgets>

class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);

    QVBoxLayout *lay;

    void InitializeMainMenu();
    void InitializeGameOverMenu();

    QPushButton *MainMenu_btn_start;
    QPushButton *GOM_btn1_inMainMenu;
    QPushButton *GOM_btn2_start;
signals:

};

#endif // MENU_H
