//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"
#include <stdexcept>
#include <Functions.h>
#include <vector>

TEST_F(LeapTestCase,NegativeYear){
    ASSERT_THROW(IsLeap(0),std::invalid_argument);
    ASSERT_NO_THROW(IsLeap(400));
}

TEST_F(LeapTestCase,NegativeYear2){
EXPECT_THROW(IsLeap(0),std::invalid_argument);
    try{IsLeap(0);}
catch(std::invalid_argument const & err) {
EXPECT_EQ(err.what(),std::string("Year must be greater than 0"));
    }
}
TEST_F(LeapTestCase,NegativeYear4){
try{IsLeap(-3);}
catch(std::invalid_argument const & err) {
EXPECT_EQ(err.what(),std::string("Year must be greater than 0"));
}
}
TEST_F(LeapTestCase,NegativeYear5){
try{IsLeap(100);}
catch(std::invalid_argument const & err) {
EXPECT_EQ(err.what(),std::string("Year must be greater than 0"));
}
}

TEST_F(LeapTestCase,NegativeYear1){
ASSERT_THROW(IsLeap(-2),std::invalid_argument);
}

TEST_F(LeapTestCase,YearDividableBy4_100_400){
ASSERT_NO_THROW(IsLeap(400));
ASSERT_EQ(IsLeap(400),true);
}
TEST_F(LeapTestCase,YearDividableBy4_100_not_by_400){
ASSERT_EQ(IsLeap(300),false);
}
TEST_F(LeapTestCase,YearDividableBy4_not_by_100_400){
ASSERT_EQ(IsLeap(96),true);
}
TEST_F(LeapTestCase,YearDividableNotBy4){
ASSERT_EQ(IsLeap(3),false);
}
TEST_F(LeapTestCase,Month2){
ASSERT_EQ(GetMonthDays(400,2),29);
}
TEST_F(LeapTestCase,Month20){
ASSERT_EQ(GetMonthDays(300,2),28);
}
TEST_F(LeapTestCase,MonthBigger12){
ASSERT_THROW(GetMonthDays(300,13),std::invalid_argument);
}
TEST_F(LeapTestCase,MonthLower0){
ASSERT_THROW(GetMonthDays(300,0),std::invalid_argument);
}
TEST_F(LeapTestCase,Month04){
ASSERT_EQ(GetMonthDays(300,4),30);
}
TEST_F(LeapTestCase,Month06){
ASSERT_EQ(GetMonthDays(300,6),30);
}
TEST_F(LeapTestCase,Month9){
ASSERT_EQ(GetMonthDays(300,9),30);
}
TEST_F(LeapTestCase,Month11){
ASSERT_EQ(GetMonthDays(300,11),30);
}
TEST_F(LeapTestCase,Month3){
int a[7]={1,3,5,7,8,10,12};
for (auto v: a){
ASSERT_EQ(GetMonthDays(300,v),31);
}
}
