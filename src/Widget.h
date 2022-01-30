#pragma once
#include <QThread>

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMutex>


#include <QThread>
 
class Widget : public QWidget
{
    Q_OBJECT
 
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void createView();
 
private:
    QVBoxLayout *mainLayout;
};



