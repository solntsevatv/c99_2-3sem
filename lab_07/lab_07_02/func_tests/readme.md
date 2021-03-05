# Тесты для лабораторной работы №7

## Входные данные
Файл f_in, содержащий целочисленный массива; 

## Выходные данные
Файл f_out, в который будет выводиться результат работы программы

## Позитивные тесты
### аргументы командной строки: app.exe f_in f_out
- 01 - массив состоит из одного элемента
- 02 - массив состоит из нулей
- 03 - массив, не требующий сортировки
- 04 - обычный тест
### аргументы командной строки: app.exe f_in f_out f
- 05 - массив из единиц (без отрицательных чисел)
- 06 - обычный тест
- 07 - обычный тест, содержащий нуль перед отрицательным числом

## Негативные тесты
### проверка аргументов (здесь под номерами тестов указываются посылаемые ошибочные аргументы)
- 01 - 2 аргумента (мало)
- 02 - 5 аргументов (много)
- 03 - пустой файл (без указания выполнения фильтрации)
- 04 - пустой файл (с указанием выполнения фильтрации)
- 05 - 4 аргумент в виде "d" (принимается только "f")
- 06 - первый элемент - отрицательный (с указанием выполнения фильтрации)