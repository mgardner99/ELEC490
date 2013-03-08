#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include "DataPoint.h"
#include <queue>
#include <sstream>
#include <QStringList>

using namespace std;
using namespace boost::asio;

class Communication: public QObject{
    Q_OBJECT
public:
    Communication(string comPort);
    ~Communication();

    vector<DataPoint>* getData();
    static QStringList getPortsList();

private:
    serial_port* port;
    io_service* io;
    char msg[512];
    vector<DataPoint>* data;
    queue<char> q;
   // int valNum;

    void readData();
    void dataSet(int sense);
    bool mutex;
    void findFront(int &size);

public slots:
    void update();

};

#endif // COMMUNICATION_H


