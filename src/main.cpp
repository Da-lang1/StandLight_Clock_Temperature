#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "time.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidService.h"
#include "TempHumidView.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    // time_t timeSec;
    // struct tm *timeData;
    
    Button modeButton(27);
    Button powerButton(28);
    ClockCheck clockCheck;
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));
    View view(&led1, &led2, &led3, &led4, &led5,&lcd);
    TempHumidView tempHumidView(&lcd);
    ClockView clockView(&lcd);
    Service service(&view);
    ClockService clockService(&clockView);
    TempHumidService tempHumidService(&tempHumidView);
    Controller control(&service, &clockService,&tempHumidService);
    Listener listener(&modeButton,&powerButton, &control, &clockCheck, &dht);

    
    // DHT_Data dhtData;
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        // dhtData = dht.readData();
        // if(dhtData.error == 0){
        //     std::cout   << "humidity : "
        //                 << dhtData.RH <<"." << dhtData.RHDec << "%"
        //                 <<"Temperature : "
        //                 <<dhtData.Temp <<"." << dhtData.TempDec << "C"
        //                 <<std::endl;
        // }
        delay(10);
        // listener.checkEvent();
        // view.lightView();
        // timeSec = time(NULL);
        // timeData = localtime(&timeSec);
        // std::cout << "timeSec : " << timeSec << std::endl;
        // std::cout << timeData->tm_hour<< ":"
        //           << timeData->tm_min << ":"
        //           << timeData->tm_sec << std::endl;
        // delay(50);
    }

    return 0;
}