# RotationMethod
Gives a brief realisation of solving linear systems by rotation method
Для сборки использовать комманду make
Для запуска ввести ./m.e n m k либо ./m.e n m 0 text.txt
Где n - размер матрицы
m - размер выводимой на экран части матрицы
k - номер формулы, по которой инициализируется матрица, или 0, в случае ввода матрицы из файла
text.txt - имя файла с матрицей

head.h и MyException.h - заголовочные файлы, в частности объявлен свой класс-исключение

functions.cpp - реализация вспомогательных функций: вывода и ввода матрицы, применения T_ij(fi) к вектору и матрице, вычисления нормы несвязки

solution.cpp - реализация метода вращения (внимание! первый индекс - номер столбца!!!)

