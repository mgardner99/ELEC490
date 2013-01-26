#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include "DataPoint.h"
#include <queue>
#include <sstream>

using namespace std;
using namespace boost::asio;

class Communication{
public:
    Communication(string comPort);
    void update();
    vector<DataPoint>* getData();

private:
    serial_port* port;
    io_service* io;
    char msg[512];
    vector<DataPoint>* data;
    queue<char> q;
    int valNum;

    void readData();
    void dataSet(int sense);
    bool mutex;


};

#endif // COMMUNICATION_H

