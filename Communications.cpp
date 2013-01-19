

#include "Communication.h"

Communication::Communication(string comPort){


    io = new io_service();
    port = new serial_port(*io,comPort);

   // port->open(comPort);

    port->set_option(serial_port_base::baud_rate(9600));
    data = new vector<DataPoint>();

    for(int i  = 0; i < 6; i++)
        data->push_back(DataPoint());

cout<<"this far"<<endl;
}

void Communication::update(){
   int size = port->read_some(buffer(msg,512));

   for(int i = 0; i < size; i++){
       cout<<msg[i];
   }
   cout<<endl;
}
