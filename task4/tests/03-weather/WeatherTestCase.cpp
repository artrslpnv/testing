//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST_F(WeatherTestCase,TodayTemperature){
WeatherMock weather;
ASSERT_EQ(ceil(static_cast <float> (weather.GetTemperature("London"))),10);}
// from
//curl --location --request GET
//'http://api.openweathermap.org/data/2.5/weather?q=London&appid=94775420b8e5674b27495e201f0cb46b&units=metric'
//response['main']['temp']

TEST_F(WeatherTestCase,TommorowTemperatureTestCase){
WeatherMock weather;
ASSERT_EQ(round(weather.GetTomorrowTemperature("London")),9);}
// from
//curl --location --request GET
// 'http://api.openweathermap.org/data/2.5/forecast/?q=London&appid=94775420b8e5674b27495e201f0cb46b&units=metric'
//response['list'][7]['main']['tmp']

TEST_F(WeatherTestCase,TommorowDiffTestCase){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Moscow"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseL){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("London"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseK){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Kazan"));
}

TEST_F(WeatherTestCase,WrongAPI){
WeatherMock weather;
weather.SetApiKey("asdasd");
ASSERT_THROW(weather.GetTomorrowDiff("Kazan"),std::invalid_argument);
}

TEST_F(WeatherTestCase,DiffBetweenCities){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetDifferenceString("Moscow","London"));
ASSERT_NO_THROW(weather.GetDifferenceString("London","Moscow"));
}


TEST_F(WeatherTestCase,TommorowDiffTestCaseZ){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Zagreb"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseW){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Wellington"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseT){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Tokyo"));
}


TEST_F(WeatherTestCase,TommorowDiffTestCaseLA){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Los Angeles"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseNY){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("New York"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseN){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Novosibirsk"));
}


TEST_F(WeatherTestCase,TommorowDiffTestCasePek){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Beijing"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseLagos){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Lagos"));
}
TEST_F(WeatherTestCase,TommorowDiffTestCaseBangkok){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Bangkok"));
}

TEST_F(WeatherTestCase,TommorowDiffTestCaseBerl){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Berlin"));
}
TEST_F(WeatherTestCase,Bern){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Bern"));
}
TEST_F(WeatherTestCase,Brasilia){
WeatherMock weather;
ASSERT_NO_THROW(weather.GetTomorrowDiff("Brasilia"));
}