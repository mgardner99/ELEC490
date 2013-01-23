

#include "Communication.h"

Communication::Communication(string comPort): q(){
   // cout<<"here"<<endl;
    mutex = false;
    io = new io_service();
    port = new serial_port(*io,comPort);



    port->set_option(serial_port_base::baud_rate(9600));
    data = new vector<DataPoint>();

    data->push_back(DataPoint(QPoint(150,150),10)); //remove these when you have actual data
    data->push_back(DataPoint(QPoint(250,250),10));
    for(int i  = 0; i < 4; i++)
        data->push_back(DataPoint());
}

void Communication::update(){
    if(mutex == true)
        return; //mutex WOOT
    mutex = true;
    readData();
//    int temp;
    while(!q.empty()){


        switch (q.front()){
       case 'a': dataSet(0);
           break;
       case 'b': dataSet(1);
           break;
       default: q.pop();
           break;
        }

    }

    valNum = 0;
    mutex = false;
}

void Communication::dataSet(int sense){
   stringstream ss;
   q.pop();
   while(q.front() != 'e'){
       if(q.size() == 0)
           return;

       ss<<q.front();
       q.pop();

   }
   q.pop();
   //cout<<ss.str()<<endl;

   data->at(sense).setVal(atoi(ss.str().c_str()));
}

//fairly convoluted way of reading the incoming datastream from the arduino... YAY
void Communication::readData(){
    static int read = 0;
    static int size = 0;
    size = port->read_some(buffer(msg,512));

    //cout<<"Read "<<size<<" bytes"<<endl;
    read += size;

    for(int i = 0; i < size; i++){
        q.push(msg[i]);
    }

    if(read > 12){
        for (int i = 0; i < q.size(); i++)
            q.pop();
        read = 0;
        return;
        cout<<"Over Flow"<<endl;
    }
    if(read % 3 !=0)
        readData(); //2 byte int from arduino... so if we do not have an even number of read bytes, we have only half an int
    else{
        valNum = read / 3;
        read = 0;
    }
}

vector<DataPoint>* Communication::getData(){
    return data;
}
