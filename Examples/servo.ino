#include<caserial.h>
#include <Servo.h>  

Servo myservo;

SerialCom data(1,1);


int valueReceived[1];




void setup() {

  data.begin();
  
}

void loop() {


  data.Get(valueReceived);

}
