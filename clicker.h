#ifndef CLICKER_H
#define CLICKER_H

#include <QMainWindow>

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

private:
    Ui::Clicker *ui;
};
#endif // CLICKER_H
