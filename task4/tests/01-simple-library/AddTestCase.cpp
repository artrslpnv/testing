//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"
TEST_F(AddTestCase,Positive){
    ASSERT_EQ(6,Add(3,3));
}