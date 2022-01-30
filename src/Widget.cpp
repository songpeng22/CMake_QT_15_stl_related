#include "Widget.h"

#include <QDebug>
#include <QMutex>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createView();
}
 
void Widget::createView()
{
    /*Ìí¼Ó½çÃæ*/    
    QPushButton *openThreadBtn = new QPushButton(tr("open"));
    QPushButton *closeThreadBtn = new QPushButton(tr("close"));
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(openThreadBtn);
    mainLayout->addWidget(closeThreadBtn);
    mainLayout->addStretch();
    connect(openThreadBtn,SIGNAL(clicked(bool)),this,SLOT(openThreadBtnSlot()));
    connect(closeThreadBtn,SIGNAL(clicked(bool)),this,SLOT(closeThreadBtnSlot()));    
 

}
 
Widget::~Widget()
{


}