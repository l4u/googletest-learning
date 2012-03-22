#include "TestSuite.h"
#include "libjson.h"
#include "JSONNodeHelper.h"
#include "gtest/gtest.h"
namespace {
  class TestSuite : public ::testing::Test {
    protected:
      TestSuite() {
        // You can do set-up work for each test here.
      }

      virtual ~TestSuite() {
        // You can do clean-up work that doesn't throw exceptions here.
      }

      // If the constructor and destructor are not enough for setting up
      // and cleaning up each test, you can define the following methods:

      virtual void SetUp() {
        jsonNode = libjson::parse("{\"status\": {\"message\":\"this works\"}}");
        // Code here will be called immediately after the constructor (right
        // before each test).
      }

      virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
      }

      JSONNode jsonNode;
      // Objects declared here can be used by all tests in the test case for Foo.
  };

  TEST_F(TestSuite, FindNodeByKeyPositive) {
    JSONNodeHelper jsonNodeHelper(jsonNode);
    JSONNode messageNode = jsonNodeHelper["status"]["message"];
    std::string message= messageNode.as_string();
    EXPECT_EQ("this works", message);
  }

  TEST_F(TestSuite, FindNodeByKeyNegative) {
    // TODO: check return when key is not found
  }
}
int main(int argc, char **argv) { 
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
