# Задание lab_02_05_04
***
## Входные данные
- Количество элементов массива (0 < *N* <= 10)
- Элементы целочисленного статического массива

Тип: **Integer**

## Выходные данные
Количество уникальных чисел в массиве

Тип: **Integer**

## Тесты
### Негативные:
- **neg_01** - длина массива равна нулю
- **neg_02** - длина массива меньше нуля
- **neg_03** - вводимый элемент массива - не целое число
- **neg_04** - длина массива введена некорректно (не число)
- **neg_05** - длина массива больше 10

### Позитивные:
- **pos_01** - все элементы уникальны
- **pos_02** - все элементы одинаковы
- **pos_03** - присутствуют как уникальные, так и повторяющиеся элементы
- **pos_04** - отрицательные числа
- **pos_05** - одно число