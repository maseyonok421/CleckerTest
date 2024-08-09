#include "clicker.h"
#include "ui_clicker.h"

long long cps { 0 }, clickDmg { 1 }, balance { 0 };
constexpr long long clickUpgradesBaseCost[] = { 25, 7500, 85500 };
constexpr long long   cpsUpgradesBaseCost[] = { 10, 2500, 12500 };
constexpr long long clickUpgrades[] = { 1, 10, 50 };
constexpr long long   cpsUpgrades[] = { 1, 8 , 23 };
long long curClickUpgrades[] = { 0, 0, 0 };
long long   curCpsUpgrades[] = { 0, 0, 0 };
constexpr double coef = 2.63;
const QString greenButtonStyle = "QPushButton{ \
    color: white; \
    background-color: rgba(0, 255, 85, 70); \
    border: none; \
    font-size: 27pt; \
    } \
    QPushButton:hover{ \
        background-color: rgba(25, 255, 100, 85); \
    } \
    QPushButton:pressed{ \
        background-color: rgba(0, 255, 0, 65); \
    }";
const QString redButtonStyle = "QPushButton{\
    color: white;\
    background-color: rgba(255, 80, 100, 60);\
    border: none;\
    font-size: 27pt;\
    }\
    QPushButton:hover{\
        background-color: rgba(255, 80, 100, 75);\
    }\
    QPushButton:pressed{\
        background-color: rgba(255, 80, 100, 90);\
    }";

Clicker::Clicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clicker)
{

    ui->setupUi(this);
    updTimer = new QTimer(this);
    connect(updTimer, &QTimer::timeout, this, on_upd_timer_timeout);
    updTimer->start(1000);
    updateScreen();

}

Clicker::~Clicker()
{
    delete ui;
}

void Clicker::updateScreen(){

    ui->balanceLbl->setText(QString::number(balance));
    ui->dmgLbl->setText("Dmg: " + QString::number(clickDmg));
    ui->cpsLbl->setText("Cps: " + QString::number(cps));

    auto updClickCostLbl { [&]( QLabel *lbl, int idx ){

        lbl->setText(QString::number((long long)
        (clickUpgradesBaseCost[idx]*pow(coef, curClickUpgrades[idx]))));

    }};
    auto updCpsCostLbl { [&] ( QLabel *lbl, int idx){

        lbl->setText(QString::number((long long)
        (cpsUpgradesBaseCost[idx]*pow(coef, curCpsUpgrades[idx]))));

    }};

    auto paintClickButtons { [&]( QPushButton *btn, int idx ){

        int curCost = clickUpgradesBaseCost[idx] * pow(coef, curClickUpgrades[idx]);
        if (balance < curCost) btn->setStyleSheet(redButtonStyle);
        else                   btn->setStyleSheet(greenButtonStyle);

    }};
    auto paintCpsButtons { [&]( QPushButton *btn, int idx ){

        int curCost = cpsUpgradesBaseCost[idx] * pow(coef, curCpsUpgrades[idx]);
        if (balance < curCost) btn->setStyleSheet(redButtonStyle);
        else                   btn->setStyleSheet(greenButtonStyle);

    }};

    updClickCostLbl(ui->clickUpdLbl1, 0);
    updClickCostLbl(ui->clickUpdLbl2, 1);
    updClickCostLbl(ui->clickUpdLbl3, 2);

    updCpsCostLbl(ui->cpsUpdLbl1, 0);
    updCpsCostLbl(ui->cpsUpdLbl2, 1);
    updCpsCostLbl(ui->cpsUpdLbl3, 2);

    paintClickButtons(ui->clickUpdBtn1, 0);
    paintClickButtons(ui->clickUpdBtn2, 1);
    paintClickButtons(ui->clickUpdBtn3, 2);

    paintCpsButtons(ui->cpsUpdBtn1, 0);
    paintCpsButtons(ui->cpsUpdBtn2, 1);
    paintCpsButtons(ui->cpsUpdBtn3, 2);

};

void Clicker::on_upd_timer_timeout(){

    balance += cps;
    updateScreen();

};

void Clicker::on_clickBtn_clicked()
{
    balance += clickDmg;
    updateScreen();
}


void Clicker::on_clickUpdBtn1_clicked()
{
    int curCost = clickUpgradesBaseCost[0] * pow(coef, curClickUpgrades[0]);
    if (balance >= curCost){
        balance -= curCost;
        curClickUpgrades[0] ++;
        clickDmg += clickUpgrades[0];
        updateScreen();
    }
}


void Clicker::on_clickUpdBtn2_clicked()
{
    int curCost = clickUpgradesBaseCost[1] * pow(coef, curClickUpgrades[1]);
    if (balance >= curCost){
        balance -= curCost;
        curClickUpgrades[1] ++;
        clickDmg += clickUpgrades[1];
        updateScreen();
    }
}


void Clicker::on_clickUpdBtn3_clicked()
{
    int curCost = clickUpgradesBaseCost[2] * pow(coef, curClickUpgrades[2]);
    if (balance >= curCost){
        balance -= curCost;
        curClickUpgrades[2] ++;
        clickDmg += clickUpgrades[2];
        updateScreen();
    }
}


void Clicker::on_cpsUpdBtn1_clicked()
{
    int curCost = cpsUpgradesBaseCost[0] * pow(coef, curCpsUpgrades[0]);
    if (balance >= curCost){
        balance -= curCost;
        curCpsUpgrades[0] ++;
        cps += cpsUpgrades[0];
        updateScreen();
    }
}


void Clicker::on_cpsUpdBtn2_clicked()
{
    int curCost = cpsUpgradesBaseCost[1] * pow(coef, curCpsUpgrades[1]);
    if (balance >= curCost){
        balance -= curCost;
        curCpsUpgrades[1] ++;
        cps += cpsUpgrades[1];
        updateScreen();
    }
}


void Clicker::on_cpsUpdBtn3_clicked()
{
    int curCost = cpsUpgradesBaseCost[2] * pow(coef, curCpsUpgrades[2]);
    if (balance >= curCost){
        balance -= curCost;
        curCpsUpgrades[2] ++;
        cps += cpsUpgrades[2];
        updateScreen();
    }
}

