#include "clicker.h"
#include "ui_clicker.h"

long long cps { 0 }, clickDmg { 1 }, balance { 0 };

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

void Clicker::on_upd_timer_timeout(){

    balance += cps;
    ui->balanceLbl->setText(QString::number(balance));

};

void Clicker::on_clickBtn_clicked()
{
    balance += clickDmg;
    ui->balanceLbl->setText(QString::number(balance));
}

