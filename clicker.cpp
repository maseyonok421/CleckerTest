#include "clicker.h"
#include "ui_clicker.h"

extern long long cps, clickDmg, balance;
extern long long curClickUpgrades[];
extern long long   curCpsUpgrades[];


Clicker::Clicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clicker)
{

    ui->setupUi(this);

    savesManager.load();

    updTimer = new QTimer(this);
    connect(updTimer, &QTimer::timeout, this, on_upd_timer_timeout);
    updTimer->start(1000);
    updateScreen();

}

Clicker::~Clicker()
{
    delete ui;
}


void Clicker::updLabels(){

    ui->balanceLbl->setText(QString::number(balance));
    ui->dmgLbl->setText("Dmg: " + QString::number(clickDmg));
    ui->cpsLbl->setText("Cps: " + QString::number(cps));

};
void Clicker::updCosts(){

    auto updClickCostLbl { [&]( QLabel *lbl, int idx ){

        lbl->setText(QString::number((long long)
                                     (clickUpgradesBaseCost[idx]*pow(coef, curClickUpgrades[idx]))));

    }};
    auto updCpsCostLbl { [&] ( QLabel *lbl, int idx){

        lbl->setText(QString::number((long long)
                                     (cpsUpgradesBaseCost[idx]*pow(coef, curCpsUpgrades[idx]))));

    }};

    updClickCostLbl(ui->clickUpdLbl1, 0);
    updClickCostLbl(ui->clickUpdLbl2, 1);
    updClickCostLbl(ui->clickUpdLbl3, 2);

    updCpsCostLbl(ui->cpsUpdLbl1, 0);
    updCpsCostLbl(ui->cpsUpdLbl2, 1);
    updCpsCostLbl(ui->cpsUpdLbl3, 2);

}
void Clicker::paintButtons(){

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

    paintClickButtons(ui->clickUpdBtn1, 0);
    paintClickButtons(ui->clickUpdBtn2, 1);
    paintClickButtons(ui->clickUpdBtn3, 2);

    paintCpsButtons(ui->cpsUpdBtn1, 0);
    paintCpsButtons(ui->cpsUpdBtn2, 1);
    paintCpsButtons(ui->cpsUpdBtn3, 2);

}
void Clicker::updateScreen(){

    updLabels();
    updCosts();
    paintButtons();
    savesManager.save();

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

void Clicker::on_updBtn_clicked( int idx, int type ){

    int curCost = ((!type) ? clickUpgradesBaseCost[idx] : cpsUpgradesBaseCost[idx]) *
        pow(coef, ((!type) ? curClickUpgrades[idx] : curCpsUpgrades[idx]));
    if ( balance >= curCost ){
        balance -= curCost;
        if ( !type ){
            curClickUpgrades[idx] ++;
            clickDmg += clickUpgrades[0];
        }
        else{
            curCpsUpgrades[idx] ++;
            cps += cpsUpgrades[idx];
        }
        updateScreen();
    }
};

void Clicker::on_clickUpdBtn1_clicked()
{
    on_updBtn_clicked(0, 0);
}
void Clicker::on_clickUpdBtn2_clicked()
{
    on_updBtn_clicked(1, 0);
}
void Clicker::on_clickUpdBtn3_clicked()
{
    on_updBtn_clicked(2, 0);
}

void Clicker::on_cpsUpdBtn1_clicked()
{
    on_updBtn_clicked(0, 1);
}
void Clicker::on_cpsUpdBtn2_clicked()
{
    on_updBtn_clicked(1, 1);
}
void Clicker::on_cpsUpdBtn3_clicked()
{
    on_updBtn_clicked(2, 1);
}

