#ifndef LIB
#define LIB

#define UNUSED(variable)  (void)variable

#include <iostream>
#include <string>
#include <type_traits>


namespace homework {

    void print_char(const unsigned char value){
        std::cout << ((int)value);
    }

    // печатаем целочисленные типы
    template <class T> typename std::enable_if<std::is_integral<T>::value,void>::type print_ip(T value){
        size_t size = sizeof(value);
            for(int i=size-1;i>=0;i--){
                print_char(char(value>>(8*i)));
                if(i>0) std::cout << ".";
            }
            std::cout << std::endl;
    }

   // печатаем строки
   template <class T> typename std::enable_if<std::is_same<T,std::string>::value,void>::type print_ip(T value){
        std::cout << value << std::endl;
    }

    // печатаем коллекции
    template <class T,class ITEM_TYPE> void print_ip(T value){
        for(auto it=value.begin();it!=value.end();){
          std::cout << *it;
          ++it;
          if(it!=value.end()) std::cout<< ".";
        }
        std::cout << std::endl;
        
    }

 
    // helper для печати tuple - случай привышения индекса
    template <size_t index, class T> typename std::enable_if< (index==std::tuple_size<T>::value),void>::type 
       tuple_print(T & t){
       UNUSED(t);
   } 

 // helper для печати tuple - итерируем от 0 до размера tuple
   template <size_t index, class T> typename std::enable_if< (index<std::tuple_size<T>::value),void>::type 
       tuple_print(T & t){
       std::cout << std::get<index>(t);
       if((index+1)<std::tuple_size<T>::value){
                std::cout << ".";
                tuple_print<index+1,T>(t);
       } else {
            std::cout << std::endl;
       }
   };

  
    // печатаем tuple
   template <class T> typename std::enable_if<(std::tuple_size<T>::value>0),void>::type print_ip(T value){
        
        tuple_print<0,T>(value);
    }
   
}

#endif