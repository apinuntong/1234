#include <Wire.h>               
#define address2 99                         
byte received_from_computer=1;             
byte code=0; 
byte i=0;
char ph_data[20];                
byte in_char=0;                                 
float ph_float,ph2_float;                 
void setup()                                
{
  Serial.begin(115200);           
  Wire.begin(); 
  delay(1000);  
}  
void loop(){                   
  for(int x=0;x<2;x++){
    Wire.beginTransmission(address2); 
    Wire.write(114);       
    Wire.endTransmission();        
    
    
    delay(1400);                   
    
    Wire.requestFrom(address2,20,1); 
    code=Wire.read();               
    
    switch (code){                 
      case 1:                      
       // Serial.println("Success"); 
      break;                       
    
     case 2:                        
       Serial.println("Failed");   
     break;                        
    
     case 254:                     
       Serial.println("Pending");   
     break;                        
     
     case 255:                     
       Serial.println("No Data");  
     break;                        
    }
    
 
 
 
 
  while(Wire.available()){          
   in_char = Wire.read();           
   ph_data[i]= in_char;             
   i+=1;                            
    if(in_char==0){                
         i=0  ;                  
        Wire.endTransmission();    
        break;                     
    }
  }
  ph_float=atof(ph_data); 
  ph2_float=ph2_float+ph_float;
  // Serial.println(ph_float); 
  }
  ph2_float=ph2_float/2;
  if(ph2_float>9)
  ph2_float=ph2_float*1.058;
  if(ph2_float<9)
  ph2_float=ph2_float*1.023391813f;
  Serial.println(ph_data); 
  Serial.println(ph2_float); 
  ph2_float=0;
}
 

     
  
 
