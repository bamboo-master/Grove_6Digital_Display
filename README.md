Теперь можно использовать не только 4 разрядные готовые модули, но и 6 разрядные (они также продаются). Но в данном случае больше подходит для различных самодельных часов (с двоеточитем), с дробной точкой пока нет, но с эти тоже можно разобратся когда-нибудь.
Как получить дополнительные 2 цифры?
На микросхеме tm1637 6 выходов на разряды, в модуле задействованы только 4, также сегменты (аноды) нового индикатора должны быть соединины с остальными общими. 
![2022-12-25_13-01-22](https://user-images.githubusercontent.com/81521477/209463923-76b26f25-d92f-4432-aa68-b6b4d74f403f.png)
Как сделать свой собственный модуль?
Покупаем часовой индикатор с общим анодом и разбираемся согласно datasheet.
![2022-12-25_13-03-32](https://user-images.githubusercontent.com/81521477/209464051-f042b0d3-ae64-43eb-b0d4-d7bc29f3e2e8.png)
Как работать?
По скольку библиотека заточена под esp8266 (но работает со всем остальным) убраны примеры с использованием TimerOne, оставлен NumberFlow и создан пример Watch.
Разобраться не сложно, в случае можно подставить переменные часов из rtc или gps, в случае с esp8266 еще проще взять часы из интернета, в примере точка не мигает.
Что можно вывести на дополнительные разряды?
Можно выводить секунды, можно градусы полученные от датчика lm75a или что-то другое.
