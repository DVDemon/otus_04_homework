#include "lib.h"
#include <vector>
#include <list>
#include <tuple>


int main(int argc, char* argv[]){

// Печать адреса как char(-1)
homework::print_ip<char>(char(-1));
// Печать адреса как short(0)
homework::print_ip<short>(short(0));
// Печать адреса как int(2130706433)
homework::print_ip<int>(int(2130706433));
// Печать адреса как long(8875824491850138409)
homework::print_ip<long>(long(8875824491850138409));
// Печать адреса как std::string
homework::print_ip<std::string>("www.yandex.ru");
// Печать адреса как std::vector
std::vector<int> vector_address {1,2,3,4,5,6,7,8,9};
homework::print_ip<std::vector<int>,int>(vector_address);
// Печать адреса как std::list
std::list<int> list_address {100,102,103,104,105,106,107,108,109};
homework::print_ip<std::list<int>,int>(list_address);
// Опционально. Печать адреса как std::tuple
std::tuple<int,int,int,int> tuple_address {192,168,0,1};
homework::print_ip<std::tuple<int,int,int,int>>(tuple_address);


 UNUSED(argc);
 UNUSED(argv);
 return 0;
}