# serial commucation between arduino and python 



## Installation

Use the Arduino IDE to install the libray to use 


## Usages

### import header file 

``` cpp
#include<caserial.cpp>
```

### initializing it in the setup
```cpp
SerailCom serialData (1,1);
//number of value received 
//digits per value recieved
```

### setup() fucntion

``` cpp
  serialData.begin();
  // default baudrate=9600
```

### for sending data 

``` cpp
  serialData.Send('');
```


### for Receiving Data 

``` cpp
  serialData.Get('');
```