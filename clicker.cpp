#include "clicker.h"
#include "ui_clicker.h"

long long cps { 0 }, clickDmg { 1 }, balance { 0 };
const long long clickUpgradesBaseCost[] = { 25, 7500, 85500 };
const long long   cpsUpgradesBaseCost[] = { 10, 2500, 12500 };
const long long clickUpgrades[] = { 1, 10, 50 };
const long long   cpsUpgrades[] = { 1, 8 , 23 };
long long curClickUpgrades[] = { 0, 0, 0 };
long long   curCpsUpgrades[] = { 0, 0, 0 };
const double coef = 3.14;

Clicker::Clicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clicker)
{

    ui->setupUi(this);
    updTimer = new QTimer(this);
    connect(updTimer, &QTimer::timeout, this, on_upd_timer_timeout);
    updTimer->start(1000);

}

Clicker::~Clicker()
{
    delete ui;
}

void Clicker::updateScreen(){

    ui->balanceLbl->setText(QString::number(balance));
    ui->dmgLbl->setText(QString::number(clickDmg));
    ui->cpsLbl->setText(QString::number(cps));

    ui->clickUpdLbl1->setText(QString::number((long long)
    (clickUpgradesBaseCost[0]*pow(coef, curClickUpgrades[0]))));
    ui->clickUpdLbl2->setText(QString::number((long long)
    (clickUpgradesBaseCost[1]*pow(coef, curClickUpgrades[1]))));
    ui->clickUpdLbl3->setText(QString::number((long long)
    (clickUpgradesBaseCost[2]*pow(coef, curClickUpgrades[2]))));

    ui->cpsUpdLbl1->setText(QString::number((long long)
    (cpsUpgradesBaseCost[0]*pow(coef, curCpsUpgrades[0]))));
    ui->cpsUpdLbl2->setText(QString::number((long long)
    (cpsUpgradesBaseCost[1]*pow(coef, curCpsUpgrades[1]))));
    ui->cpsUpdLbl3->setText(QString::number((long long)
    (cpsUpgradesBaseCost[2]*pow(coef, curCpsUpgrades[2]))));

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

