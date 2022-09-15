#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2,Led *led3,Led *led4,Led *led5,LCD *Lcd)
{
    light1 = led1;
    light2 = led2;
    light3 = led3;
    light4 = led4;
    light5 = led5;
    lightState = LIGHT_OFF;
    this->lcd = Lcd;    //내 객체(인스턴스)가 가지고 있는 변수, 이름 동일해서 붙여줌
}

View::~View()
{

}

void View::setState(int state)
{
    lightState = state;
    char buff[30];
    sprintf(buff,"Light%d  ", state);
    lcd->WriteStringXY(0, 0, buff);
}

// void View::updateState(std::string strState)
// {
//     switch (lightState)
//     {
//         case LIGHT_OFF:
//             if (strState == "modeButton") {
//                 lightState = LIGHT_1;
//             }
//         break;

//         case LIGHT_1:
//             if (strState == "modeButton") {
//                 lightState = LIGHT_2;
//             }
//         break;

//         case LIGHT_2:
//             if (strState == "modeButton") {
//                 lightState = LIGHT_3;
//             }
//         break;

//         case LIGHT_3:
//             if (strState == "modeButton") {
//                 lightState = LIGHT_4;
//             }
//         break;

//         case LIGHT_4:
//             if (strState == "modeButton") {
//                 lightState = LIGHT_5;
//             }
//         break;

//         case LIGHT_5:
//             if (strState == "modeButton") {
//                 lightState = LIGHT_OFF;
//             }
//         break;
//     }
// }


void View::lightView()
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
        break;

        case LIGHT_1:
            lightOn_1();

        break;
        case LIGHT_2:
            lightOn_2();
        break;
        case LIGHT_3:
            lightOn_3();
        break;
        case LIGHT_4:
            lightOn_4();
        break;
        case LIGHT_5:
            lightOn_5();
        break;

    }
}

void View::lightOn_1()
{
    // char buff[30];
    // sprintf(buff, "Light1");
    // lcd->WriteStringXY(0, 0, buff);
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
    
}

void View::lightOn_2()
{
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
    
}
void View::lightOn_3()
{
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
    
}
void View::lightOn_4()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
    
}
void View::lightOn_5()
{
    // char buff[30];
    // sprintf(buff, "Light 5");
    // lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOn();
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
    
}
void View::lightOff()
{
    char buff[30];
    sprintf(buff, "Light Off");
    lcd->WriteStringXY(0, 0, buff);
    lcd->backLightOff();

    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

