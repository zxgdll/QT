#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QObject>
class CustomButton:public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent=0);
private:
    void onButtonClicked();
};
#endif // CUSTOMBUTTON_H
