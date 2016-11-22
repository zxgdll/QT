#include "custombutton.h"
CustomButton::CustomButton(QWidget *parent):
    QPushButton(parent)
{
    connect(this,&CustomButton::clicked,
            this,&CustomButton::onButtonClicked);
}

