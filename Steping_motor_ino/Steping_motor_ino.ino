char buffer[18];
int  tong;
int  b=0;
int dirpin = 2;
int steppin = 3;

void setup()
{
Serial.begin(9600);
Serial.flush();
  pinMode(dirpin, OUTPUT);
  pinMode(steppin, OUTPUT);
}
void loop()
{
  
if (Serial.available() > 0) {
int index=0;
delay(100); // let the buffer fill up
int numChar = Serial.available();
while (numChar--) {
buffer[index++] = Serial.read();
}
splitString(buffer);
}
  
}
void splitString(char* data) {
char* parameter;
parameter = data;
setLED(parameter);
Serial.flush();
}
void setLED(char* data) {
int Ans = strtol(data, NULL, 10);
Ans = constrain(Ans,0,10000);
tong=Ans;
Serial.print("run: ");
Serial.println(tong);
  //if(tong > b ){
      int n= tong-b;
      int o=0;
      if(n>10){
         o = n/10;
      }
      n=(n*9)+o;
      digitalWrite(dirpin, HIGH);
      //delay(1000);
      runing(n);
     // Serial.print("+y: ");
      //Serial.println(n);
      b=tong;
      goto num;
   // }
  /*else if(tong < b){
      int n = b-tong;
      int o=0;
      if(n>10){
         o = n/10;
      }
      n=(n*9)+ o ;//+(int)();
      digitalWrite(dirpin, LOW);
      //delay(1000);
      runing(n);
      //Serial.print("-y: ");
      //Serial.println(n);
      b=tong;
      goto num;
    }*/
num:
buffer[0]=0;buffer[1]=0;buffer[2]=0;buffer[3]=0;

}
void runing(int x){
    for (int i = 0; i< x; i++)       
  {
    digitalWrite(steppin, LOW);  
    delayMicroseconds(15);
    digitalWrite(steppin, HIGH); 
    delayMicroseconds(35);      
  }   
}
