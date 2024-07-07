# Задание lab_01_07_02
***
## Входные данные

- *x* (|x| <= 1)
- *еps* (0 < *eps* <= 1)

Тип: **Double**
 
## Выходные данные
- Вычисленное с точностью *еps* приближённое значение *s(x)* и 
- Точное значение *f(x)* функции *f*, 
- Абсолютная дельта погрешности
- Относительная дельта погрешности:

Тип: **Double**

## Тесты
### Негативные:
- **neg_01** - значение *x* выходит за область допустимых значений
- **neg_02** - значение *еps* выходит за область допустимых значений
- **neg_03** - чрезвычайно малое значение *x*, провоцирующее деление на 0
- **neg_04** - чрезвычайно малое значение *еps*
- **neg_05** - не число при вводе *х*
- **neg_06** - не число при вводе *eps*

### Позитивные:
- **pos_01** - числа с плавающей точкой
- **pos_02** - *eps* - малое число с плавающей точкой
- **pos_03** - все единицы
- **pos_04** - числа в экспоненциальной форме
- **pos_05** - *x* - малое число с плавающей точкой