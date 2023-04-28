
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inventory.h"
#include "delivery.h"
#include <vector>
#include <queue>
#include <string>
#include <chrono>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    std::priority_queue<Delivery> createScheduledDelivery(std::string contact, std::string address, std::string phone, std::string schedule, std::priority_queue<Delivery> docket);
    void printNextDelivery(std::priority_queue<Delivery> &docket);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
