#ifndef SERVICE_H
#define SERVICE_H

#include<string>
#include "View.h"
#include "LightState.h"

// enum {LIGHT_OFF, LIGHT_1, LIGHT_2,LIGHT_3,LIGHT_4,LIGHT_5};

class Service
{
private:
    int lightState;
    View *view; //실제 인스턴스 되어있는 주소를 갖자

public:
    Service(View *viewer);
    virtual ~Service();
    void updateState(std::string strState);

};

#endif