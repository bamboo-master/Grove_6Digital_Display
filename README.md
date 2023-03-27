Теперь можно использовать не только 4 разрядные готовые модули, но и 6 разрядные (они также продаются). Но в данном случае больше подходит для различных самодельных часов (с двоеточитем).

Как получить дополнительные 2 цифры?

На микросхеме tm1637 6 выходов на разряды, в модуле задействованы только 4, также сегменты (аноды) нового индикатора должны быть соединины с остальными общими. 


![2022-12-25_13-01-22](https://user-images.githubusercontent.com/81521477/209463923-76b26f25-d92f-4432-aa68-b6b4d74f403f.png)


Как сделать свой собственный модуль?

Покупаем часовой индикатор с общим анодом, покупаем tm1637 и разбираемся согласно datasheet.

![2022-12-25_13-03-32](https://user-images.githubusercontent.com/81521477/209464051-f042b0d3-ae64-43eb-b0d4-d7bc29f3e2e8.png)

Особенности:

Если симисегмент с 2 или более двоеточиями, то можно как вариант соединить между собой (может это уже сделано). Програмно не реализовано.

Есть пример для esp8266 (часы), установите недостающие библиотеки: https://github.com/arduino-libraries/NTPClient/

Если нужо выводить флоат то попробуйте это https://github.com/bamboo-master/TM1637_6D_float
