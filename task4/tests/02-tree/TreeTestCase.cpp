//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem.hpp>
using boost::filesystem::create_directories;





TEST_F(TreeTestCase,NotExists){
ASSERT_THROW( GetTree("asdasd", true),std::invalid_argument);
}



TEST_F(TreeTestCase,NotDirectory){
boost::filesystem::ofstream( "ForTesting/file.txt" );
EXPECT_THROW( GetTree("ForTesting/file.txt",true),std::invalid_argument);
try{GetTree("ForTesting/file.txt",true);}
catch(std::invalid_argument const & err) {
EXPECT_EQ(err.what(),std::string("Path is not directory"));
}}


TEST_F(TreeTestCase,DirectoryOnly){create_directories("ForTesting/1");
create_directories("ForTesting/1/2");
boost::filesystem::ofstream( "ForTesting/1/file.txt" );

ASSERT_EQ(GetTree("ForTesting/1",true).name,"1");
ASSERT_EQ(GetTree("ForTesting/1",true).children.size(),1);
}

TEST_F(TreeTestCase,DirectoryNotOnly){
create_directories("ForTesting/1");
create_directories("ForTesting/1/2");
boost::filesystem::ofstream( "ForTesting/1/file.txt" );
ASSERT_EQ(GetTree("ForTesting/1",false).name,"1");
ASSERT_EQ(GetTree("ForTesting/1",false).children.size(),2);
ASSERT_EQ(GetTree("ForTesting/1",false).children[0].name,"file.txt");
ASSERT_EQ(GetTree("ForTesting/1",false).children[1].name,"2");
}

TEST_F(TreeTestCase,EmptyNodes1){FileNode node;
ASSERT_NO_THROW(FilterEmptyNodes(node,boost::filesystem::path("ForTesting")));
}

TEST_F(TreeTestCase,EmptyNodes2){
create_directories("ForTesting/1");
create_directories("ForTesting/1/2");
boost::filesystem::ofstream( "ForTesting/1/file.txt" );
auto testing=GetTree("ForTesting/1",false);
ASSERT_EQ(GetTree("ForTesting/1",false).name,"1");
ASSERT_EQ(GetTree("ForTesting/1",false).children.size(),2);
FilterEmptyNodes(GetTree("ForTesting/1",false),boost::filesystem::path("ForTesting/1"));
ASSERT_EQ(GetTree("ForTesting/1",false).name,"1");
ASSERT_EQ(GetTree("ForTesting/1",false).children.size(),1);
}
TEST_F(TreeTestCase,NodesEquality){
create_directories("ForTesting/1");
create_directories("ForTesting/1/2");
boost::filesystem::ofstream( "ForTesting/1/file.txt" );
auto res1=GetTree("ForTesting/1",true);
auto res2=GetTree("ForTesting/1",false);
ASSERT_TRUE(res1==res1);
ASSERT_FALSE(res1==res2);
auto res3=GetTree("ForTesting/1/2",true);
ASSERT_FALSE(res1==res3);
}