#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include "DataPoint.h"

using namespace std;
using namespace boost::asio;

class Communication{
public:
    Communication(string comPort);
    void update();

private:
    serial_port* port;
    io_service* io;
    char msg[512];
    vector<DataPoint>* data;


};

#endif // COMMUNICATION_H


