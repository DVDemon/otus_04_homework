#ifndef LIB
#define LIB

#define UNUSED(variable)  (void)variable

#include <iostream>
#include <string>
#include <type_traits>
#include <tuple>
/**
 * В данном пространстве имен располагаются функции и шаблоны, необходимые для вывода "виртуального адреса" на экран. 
 */

namespace homework {

/**
 * Функция предназначена для вывода на экран типа char. Функция будет выводить число в диапазоне от 0 до 255
 */

    void print_char(const unsigned char value){
        std::cout << ((int)value);
    }

/**
 * Шаблон функции для печати любого интегрального типа. Функция определяет размер типа и выводит его побайтово через разделитель '.'.
 */
    template <class T> typename std::enable_if<std::is_integral<T>::value,void>::type print_ip(T value){
        size_t size = sizeof(value);
            for(int i=size-1;i>=0;i--){
                print_char(char(value>>(8*i)));
                if(i>0) std::cout << ".";
            }
            std::cout << std::endl;
    }

/**
 * Шаблон функции для печати строк. Сторка выводится на жкран без изменений.
 */
   template <class T> typename std::enable_if<std::is_same<T,std::string>::value,void>::type print_ip(T value){
        std::cout << value << std::endl;
    }

/**
 * Шаблон функции для печати коллекций. Коллекцию отличаем от других типов по второму параметру шаблона.
 */

    template <class T,class ITEM_TYPE> void print_ip(T value){
        for(auto it=value.begin();it!=value.end();){
          std::cout << *it;
          ++it;
          if(it!=value.end()) std::cout<< ".";
        }
        std::cout << std::endl;
        
    }

 
/**
 * Вспомогательный шаблон для печати tuple. Выводим tuple рекурсивно. Данная специализация на случай привышения индекса.
 */
    template <size_t index, class T> typename std::enable_if< (index==std::tuple_size<T>::value),void>::type 
       tuple_print(T & t){
       UNUSED(t);
   } 

 /**
  *  Вспомогательный шаблон для печати tuple. Выводим tuple рекурсивно. 
  *  Данная специализация для случая когда index меньше размера tuple.
  */
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

  
/**
 * Функция для песати tuple. Для определения того что тип является tuple пытаемся определить его размер.
 */
   template <class T> typename std::enable_if<(std::tuple_size<T>::value>0),void>::type print_ip(T value){      
        tuple_print<0,T>(value);
    }
   
}

#endif