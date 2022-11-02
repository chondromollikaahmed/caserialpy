
#include "caserial.h"

SerialCom::SerialCom(int _numOfValsReceived, int _digitsPerValReceived) {

  _numOfValsReceived = _numOfValsReceived;
  _digitsPerValReceived = _digitsPerValReceived;
  _stringLength = _numOfValsReceived * _digitsPerValReceived + 1;

}

void SerialCom::begin(int baudRate) {
  Serial.begin(baudRate);
}

void SerialCom::Send(int sendVals[]) {

  String _sendString;
  for (int i = 0; i < sizeof(sendVals); i++)
  {
    _sendString += String(sendVals[i]) + "#";

  }
  Serial.println(_sendString);
}


void SerialCom::Get(int* valsRec)
{

  while (Serial.available()) {

    char c = Serial.read();

    if (c == '$') {
      _counterStart = true;
    }
    if (_counterStart) {
      if (_counter < _stringLength) {
        _receivedStr = String(_receivedStr + c);
        _counter++;
      }

      if (_counter >= _stringLength) {
        for (int i = 0; i < _numOfValsReceived; i++)
        {
          int num = (i * _digitsPerValReceived) + 1;
          valsRec[i] = _receivedStr.substring(num, num + _digitsPerValReceived).toInt();
        }
        _receivedStr = "";
        _counter = 0;
        _counterStart = false;
      }
    }
  }

}