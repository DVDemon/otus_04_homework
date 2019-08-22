#include "lib.h"
#include <gtest/gtest.h>


// не знаю как протетсировать данные шаблоны. Будем считать - что если компилируется с заданными типами - то ужн хорошо.
TEST(test_01, basic_test_set)
{
   testing::internal::CaptureStdout();
   homework::print_ip<char>(char(-1));
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="255\n");
}
TEST(test_02, basic_test_set)
{
   testing::internal::CaptureStdout();
   homework::print_ip<short>(short(0));
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="0.0\n");
}
TEST(test_03, basic_test_set)
{
   testing::internal::CaptureStdout();
   homework::print_ip<int>(int(2130706433));
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="127.0.0.1\n");
}
TEST(test_04, basic_test_set)
{
   testing::internal::CaptureStdout();
   homework::print_ip<long>(long(8875824491850138409));
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="123.45.67.89.101.112.131.41\n");
}
TEST(test_05, basic_test_set)
{
   testing::internal::CaptureStdout();
   homework::print_ip<std::string>("www.yandex.ru");
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="www.yandex.ru\n");
}
TEST(test_06, basic_test_set)
{
   testing::internal::CaptureStdout();
   std::vector<int> vector_address {1,2,3,4,5,6,7,8,9};
   homework::print_ip<std::vector<int>>(vector_address);
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="1.2.3.4.5.6.7.8.9\n");
}
TEST(test_07, basic_test_set)
{
   testing::internal::CaptureStdout();
   std::list<int> list_address {100,102,103,104,105,106,107,108,109};
   homework::print_ip<std::list<int>>(list_address);
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="100.102.103.104.105.106.107.108.109\n");
}
TEST(test_08, basic_test_set)
{
   testing::internal::CaptureStdout();
   std::tuple<int,int,int,int> tuple_address {192,168,0,1};
   homework::print_ip<std::tuple<int,int,int,int>>(tuple_address);
   std::string output = testing::internal::GetCapturedStdout();
   ASSERT_TRUE(output=="192.168.0.1\n");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}