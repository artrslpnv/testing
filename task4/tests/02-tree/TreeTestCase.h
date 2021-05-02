//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
using boost::filesystem::create_directories;
class TreeTestCase : public ::testing::Test {
    void SetUp(){create_directories("ForTesting");}
    void TearDown(){remove("ForTesting");}
};


