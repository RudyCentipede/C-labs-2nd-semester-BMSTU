# Задание lab_03_06_02
***
## Входные данные
- Количество строк и столбцов матрицы

Тип: **size_t**

## Выходные данные
Заполненная "ходом быка" целочисленная матрица так, чтобы минимальное число находилось в правом нижнем углу матрицы

Тип: **Integer**

## Тесты
### Негативные:
- **neg_01** - количество строк не является числом
- **neg_02** - количество строк - отрицательное число
- **neg_03** - количество строк равно нулю
- **neg_04** - количество строк больше максимально дозволенного 
- **neg_05** - количество столбцов не является числом
- **neg_06** - количество столбцов - отрицательное число
- **neg_07** - количество столбцов равно нулю
- **neg_08** - количество столбцов больше максимально дозволенного

### Позитивные:
- **pos_01** - матрица размерности 3x4
- **pos_02** - матрица размерности 3х5
- **pos_03** - матрица размерности 1х1
- **pos_04** - матрица размерности 1х5
- **pos_05** - матрица размерности 5х3