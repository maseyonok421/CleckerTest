#ifndef CLICKER_H
#define CLICKER_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QLabel>
#include <QPushButton>

#include "savesmanager.h"
#include "CONSTANS.cpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class Clicker;
}
QT_END_NAMESPACE

class Clicker : public QMainWindow
{
    Q_OBJECT

public:
    Clicker(QWidget *parent = nullptr);
    ~Clicker();

private slots:
    void on_clickBtn_clicked();
    void on_upd_timer_timeout();


    void updateScreen();
    void updLabels();
    void updCosts();
    void paintButtons();


    void on_clickUpdBtn_clicked( int idx );
    void on_cpsUpdBtn_clicked(   int idx );

    void on_clickUpdBtn1_clicked();
    void on_clickUpdBtn2_clicked();
    void on_clickUpdBtn3_clicked();

    void on_cpsUpdBtn1_clicked();
    void on_cpsUpdBtn2_clicked();
    void on_cpsUpdBtn3_clicked();

private:
    Ui::Clicker *ui;
    QTimer *updTimer;
    SavesManager savesManager;
};
#endif // CLICKER_H
