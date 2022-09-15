#ifndef TEMPHUMIDSERVICE_H
#define TEMPHUMIDSERVICE_H

#include "DHT_Data.h"
#include "TempHumidView.h"

#pragma once

class TempHumidService
{
private:
    TempHumidView *tempHumidView;
public:
    TempHumidService(TempHumidView *tempHumidView);
    virtual ~TempHumidService();
    void updateEvent(DHT_Data dhtData);



};

#endif