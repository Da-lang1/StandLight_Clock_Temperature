#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;

}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState); //서비스가 view쪽에 상태변경된 것을 알려주고 있음 setState로
            }
        break;

        case LIGHT_1:
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;   
            }
            view->setState(lightState); 
        break;

        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;   
            }
            view->setState(lightState); 
        break;

        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;   
            }
            view->setState(lightState); 
        break;

        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;   
            }
            view->setState(lightState); 
        break;

        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
                view->setState(lightState);
            }
        break;
    }
}