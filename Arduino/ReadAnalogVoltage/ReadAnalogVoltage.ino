int aSense0;
int aSense1;

void outData(int sensor, int data);

void setup() {
  Serial.begin(9600);
}

void loop() {
 
  aSense0 = analogRead(A6);
  aSense1 = analogRead(A7);
  
  //transmit the data
  outData('a',aSense0);
  outData('b',aSense1);
  
  delay(100); //this can be changed later
  
  
}


//should output a packet onto the wireless of constant size 6 bytes.
//1 byte sensor label, 4 bytes data, 1 byte footer
void outData(char sensor, int data){
 
  Serial.print(sensor); //1 byte label
  
  for(int i = 0; i < 4 - String(data).length(); i++){
    Serial.print(0); //1 byte ascii 0 buffer to maintain constant packet size
  }
  
  Serial.print(data); //actual data
  Serial.print('z'); //1 byte footer
  
}
