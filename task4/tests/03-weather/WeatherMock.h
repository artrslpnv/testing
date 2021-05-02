//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

class WeatherMock : public Weather {
public:
WeatherMock(){
    SetApiKey("94775420b8e5674b27495e201f0cb46b");
}
};



