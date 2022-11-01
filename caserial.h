#ifndef caserial_h   
#define caserial_h

#include "Arduino.h"

class SerialCom
{
  private:
    String _receivedStr;
    int _stringLength=0;
    int _numOfValsReceived;
    int _digitsPerValReceived;
    int _numOfValsSend;
    String _sendStr;
    bool _counterStart = false;
    int _counter = 0;
    

  public:
    void begin(int baudRate = 9600);
    SerialCom(int numOfValsRec=1, int digitsPerValRec=1);
    void Send(int sendVals[]);
    void Get(int* valsRec);

};

#endif
