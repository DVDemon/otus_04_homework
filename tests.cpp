#include "lib.h"
#include <gtest/gtest.h>


// не знаю как протетсировать данные шаблоны. Будем считать - что если компилируется с заданными типами - то ужн хорошо.
TEST(test_01, basic_test_set)
{
   homework::print_ip<char>(char(-1));

   homework::print_ip<short>(short(0));

   homework::print_ip<int>(int(2130706433));
   
   homework::print_ip<long>(long(8875824491850138409));

   homework::print_ip<std::string>("www.yandex.ru");

   std::vector<int> vector_address {1,2,3,4,5,6,7,8,9};
   homework::print_ip<std::vector<int>,int>(vector_address);

   std::list<int> list_address {100,102,103,104,105,106,107,108,109};
   homework::print_ip<std::list<int>,int>(list_address);

   std::tuple<int,int,int,int> tuple_address {192,168,0,1};
   homework::print_ip<std::tuple<int,int,int,int>>(tuple_address);
   ASSERT_TRUE(true);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}