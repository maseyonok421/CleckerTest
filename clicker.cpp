#include "clicker.h"
#include "ui_clicker.h"

Clicker::Clicker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Clicker)
{
    ui->setupUi(this);
}

Clicker::~Clicker()
{
    delete ui;
}
