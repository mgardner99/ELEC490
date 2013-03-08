

#include "Communication.h"

//note there is a lot of name hiding in this method... dont get confused
//static!
QStringList Communication::getPortsList(){
    io_service io;
    QStringList ports;

    for(int i = 0; i < 20; i++){
        try{
            stringstream portName;
            portName<<"COM"<<i;
            serial_port port(io,portName.str());
            port.close();
            ports << portName.str().c_str();
        }
        catch(...){

        }
    }
    return ports;
}
Communication::~Communication(){

    port->close();
    delete port;
    io->stop();
    delete io;

    delete data;
}

Communication::Communication(string comPort): q(){
    mutex = false;

    io = new io_service();
    port = new serial_port(*io,comPort);
    port->set_option(serial_port_base::baud_rate(9600));

    data = new vector<DataPoint>();
    data->push_back(DataPoint(QPoint(99,65),0)); //remove these when you have actual data
    data->push_back(DataPoint(QPoint(115,117),0));
    data->push_back(DataPoint(QPoint(35,158),0)); //remove these when you have actual data
    data->push_back(DataPoint(QPoint(93,214),0));
    data->push_back(DataPoint(QPoint(47,244),0)); //remove these when you have actual data
    data->push_back(DataPoint(QPoint(85,324),0));
   // for(int i  = 0; i < 4; i++)
   //     data->push_back(DataPoint());
}

void Communication::update(){
    if(mutex == true)
        return; //mutex WOOT
    mutex = true;

    readData();

    int fudgeFix = 0;
    while(!q.empty()){

        switch (q.front()){
        case 'a': dataSet(0);
            break;
        case 'b': dataSet(1);
            break;
        case 'c': dataSet(2);
            break;
        case 'd': dataSet(3);
            break;
        case 'e': dataSet(4);
            break;
        case 'f': dataSet(5);
            break;
        default:
           //  cout<<"bad byte "<<q.front()<<endl;
             q.pop();

           // cout<<"bad byte "<<endl;
            break;
        }

        fudgeFix++;
        if (fudgeFix > 20){
            int qsz = q.size();
            for(int i = 0; i < qsz; i++)
                q.pop();
            mutex = false;
            break;
        }
    }
    mutex = false;
}

void Communication::dataSet(int sense){
    stringstream ss;

    q.pop();
    while(q.front() != 'z'){ // 'z' is the end packet footer
        if(q.size() == 0)
            return;

        ss<<q.front();
        q.pop();
        if(q.size() == 0)
            return;
    }
    q.pop();
  //  cout<<ss.str()<<endl;
    if(ss.rdbuf()->in_avail()>0)
        data->at(sense).setVal(atoi(ss.str().c_str()));
}

//fairly convoluted way of reading the incoming datastream from the arduino... YAY
void Communication::readData(){
    static int read = 0;
    static int size = 0;

    try{
        size = port->read_some(buffer(msg,512));
    }
    catch(...){
        //fixes a crash where if the thread terminates the program dies
    }

    read += size;

    for(int i = 0; i < size; i++){
        //cout<<msg[i]<<endl;
        q.push(msg[i]);
    }

    if(read > 100){
        for (int i = 0; i < q.size(); i++)
            q.pop();
        read = 0;
        cout<<"Over Flow"<<endl;
        return;
    }

    findFront(read);

    if(q.size() % 6 != 0){ //data will be a 6 byte packet

        readData();

    }

}

vector<DataPoint>* Communication::getData(){
    return data;
}

void Communication::findFront(int &size){
    if(q.size() > 0){

        if (q.front() != 'a' || q.front() != 'b' || q.front() != 'c' | q.front() != 'd' || q.front() != 'e' || q.front() != 'f'){
           q.pop();

           findFront(size);
        }
    }

}
