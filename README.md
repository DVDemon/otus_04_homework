# otus_04_homework
# Условие

Реализовать функцию печати условного ip-адреса.
Адрес может быть представлен в виде произвольного целочисленного типа.
Представление не зависит от знака типа. Выводить побайтово начиная со
старшего с символом . в качестве разделителя.
Адрес может быть представлен в виде строки. Выводится как есть.
Адрес может быть представлен в виде контейнеров std::list, std::vector.
Выводится содержимое контейнера поэлементно и разделяется ..
Дополнительно адрес может быть представлен в виде std::tuple при
условии, что все типы одинаковы. Выводится содержимое поэлементно и
разделяется .. Опционально.


Прикладной код должен содержать следующие вызовы:

• Печать адреса как char(-1)

• Печать адреса как short(0)

• Печать адреса как int(2130706433)

• Печать адреса как long(8875824491850138409)

• Печать адреса как std::string

• Печать адреса как std::vector

• Печать адреса как std::list

• Опционально. Печать адреса как std::tuple

Добавить в .travis.yml на этапе сборки вызов doxygen и публикацию html-
версии документации на github-pages. Подробное описание на странице:

https://docs.travis-ci.com/user/deployment/pages/

Включить в репозиторий файл Doxyfile с включенными опциями HAVE_DOT
и EXTRACT_ALL.

# Требования к реализации

Бинарный файл и пакет должны называться print_ip. Результат
опубликовать в своём репозитории на bintray.
Функция печати должна быть одной шаблонной функцией с частичной
специализацией. 
Специализация для целочисленного представления
должна быть единственная. Специализация для контейнеров должна быть
единственная.
Выслать на адрес электронной почты адрес репозитория.


# Проверка
Задание считается выполненным успешно, если после просмотра кода,
подключения репозитория, установки пакета и запуска бинарного файла
командой:

print_ip

будут выведены адреса

255

0.0

127.0.0.1

123.45.67.89.101.112.131.41

вслед за которыми будут выведены адреса из строки, контейнеров и
опционально из кортежа.
Будет отмечена скорость выполнения задания. Возможность печати адреса
в виде tuple идентичных типов.
