#ifndef LIB
#define LIB

/**
 ******************************************************************************
 *
 *  \mainpage OTUS Homework 4 Documentation
 *  \see https://github.com/DVDemon/otus_04_homework
 * 
 *  \file      lib.h
 *  \brief     Реализовать функцию печати условного ip-адреса.
 *  Адрес может быть представлен в виде произвольного целочисленного типа.
 *  Представление не зависит от знака типа. Выводить побайтово начиная со
 *  старшего с символом . в качестве разделителя.
 *  Адрес может быть представлен в виде строки. Выводится как есть.
 *  Адрес может быть представлен в виде контейнеров std::list, std::vector.
 *  Выводится содержимое контейнера поэлементно и разделяется ..
 *  Дополнительно адрес может быть представлен в виде std::tuple при
 *  условии, что все типы одинаковы. Выводится содержимое поэлементно и
 *  разделяется . Опционально.
 *  Прикладной код должен содержать следующие вызовы:
 *  • Печать адреса как char(-1)
 *  • Печать адреса как short(0)
 *  • Печать адреса как int(2130706433)
 *  • Печать адреса как long(8875824491850138409)
 *  • Печать адреса как std::string
 *  • Печать адреса как std::vector
 *  • Печать адреса как std::list
 *  • Опционально. Печать адреса как std::tuple
 *  Добавить в .travis.yml на этапе сборки вызов doxygen и публикацию htmlверсии документации на github-pages. Подробное описание на странице:
 *  https://docs.travis-ci.com/user/deployment/pages/
 *  Включить в репозиторий файл Doxyfile с включенными опциями HAVE_DOT
 *  и EXTRACT_ALL.
 *
 ******************************************************************************
 */

#define UNUSED(variable)  (void)variable

#include <iostream>
#include <string>
#include <type_traits>
#include <tuple>
#include <vector>
#include <list>

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
                if(i>0) std::cout << '.';
            }
            std::cout  << std::endl;
    }

/**
 * Шаблон функции для печати строк. Сторка выводится на экран без изменений.
 */
   template <class T> typename std::enable_if<std::is_same<T,std::string>::value,void>::type print_ip(T value){
        std::cout << value << std::endl;
    }

/**
 * Шаблон функции для печати коллекций. Коллекцию отличаем по наличию аллокатора.
 * Но поскольку и у string есть аллокатор (теперь понятно откуда std::string в задании).
 * Делаем вспомогательный шаблон, что бы в enable_if понимать есть ли тип в классе.
 */
   template <class T> struct is_type_exist{
       static const bool value{true};
   };

/**
 * Сам шаблон для опредения того что нам передали коллекцию. Отдельно проверяем что коллекция - не struing.
 */
 
   template <class T> typename std::enable_if<is_type_exist<typename T::allocator_type>::value &&
                                              !(std::is_same<T,std::string>::value),void>::type print_ip(T value){

                for(auto it=value.begin();it!=value.end();){
                        std::cout << *it;
                        ++it;
                        if(it!=value.end()) std::cout << '.';
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
                std::cout << '.';
                tuple_print<index+1,T>(t);
       } else {
            std::cout << std::endl;
       }
   }

  
/**
 * Функция для песати tuple. Для определения того что тип является tuple пытаемся определить его размер.
 */
   template <class T> typename std::enable_if<(std::tuple_size<T>::value>0),void>::type print_ip(T value){      
        tuple_print<0,T>(value);
    }
   
}

#endif