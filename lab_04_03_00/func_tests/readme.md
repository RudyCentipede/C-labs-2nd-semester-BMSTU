# Задание lab_04_03_00
***
## Входные данные
Cтрока

Тип: **char[]**

## Выходные данные
Новая строка из слов, отличных от последнего, с удаленными последующими вхождениями первой буквы, в обратном порядке

Тип: **char[]**

## Тесты
### Негативные:
- **neg_01** - длина введенной строки больше максимума
- **neg_02** - ввод пустой строки
- **neg_03** - в введенной строке одно слово
- **neg_04** - в введенной строке нет слов
- **neg_05** - длина слова больше максимума
- **neg_06** - введены одинаковые слова

### Позитивные:
- **pos_01** - все слова введенной строки уникальны
- **pos_02** - строка содержит слова, равные последнему
- **pos_03** - строка содержит слова, имеющие последующие вхождения первой буквы (одно начертание)
- **pos_04** - строка содержит слова, имеющие последующие вхождения первой буквы (разные начертания)
- **pos_05** - разделители слов не являются пробелами