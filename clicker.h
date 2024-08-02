#ifndef CLICKER_H
#define CLICKER_H

#include <QMainWindow>
#include <QTimer>

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

private:
    Ui::Clicker *ui;
    QTimer *updTimer;
};
#endif // CLICKER_H
