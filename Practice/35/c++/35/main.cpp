#include <iostream>

struct IntArray {
  int *data;
  int size;
};

/* Создаёт динамический массив размера size и сохраняет его в поле data переменной arr. Поле size структуры arr становится равным параметру size */
void create(IntArray* arr, int size);
void create(IntArray& arr, int size);
/* Возвращает элемент массива с индексом index, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
int get(IntArray* arr, int index);
int get(IntArray& arr, int index);
/* Изменяет значение элемента массива с индексом index на значение параметра value, при этом проверяет выход за границы массива. Если index лежит за пределами массива, вывести сообщение об ошибке и прервать работу программы */
void set(IntArray* arr, int index, int value);
void set(IntArray& arr, int index, int value);
/* Выводит на экран содержимое массива в формате: [1, 2, 3] */
void print(IntArray* arr);
void print(IntArray& arr);
/* Изменяет размер массива с сохранением элементов. Если новый размер меньше, хвостовые элементы обрезаются, если больше, то дополнительные элементы инициализируются нулём */
void resize(IntArray* arr, int newSize);
void resize(IntArray& arr, int newSize);
/* Освобождает память занятую массивом. Поле data становится равным nullptr, поле size становится равным нулю. Предусмотреть случай попытки удаления уже удалённого массива */
void destroy(IntArray* arr);
void destroy(IntArray& arr);

int main()
{
    IntArray arr;
    create (&arr, 30);
    for (int i = 1; i <= 30; i++){
        set(&arr, i-1, i);
    }
    print (&arr);
    resize (&arr, 50);
    print(&arr);
    resize (&arr, 10);
    print (&arr);
    destroy (&arr);
}

void create(IntArray& arr, int size){
    arr.data = new int [size];
    arr.size = size;
}

void create(IntArray* arr, int size){
    create(*arr, size);
}

int get(IntArray& arr, int index){
    if (index > arr.size - 1 || index < 0){
        std::cout << "index все границ массива";
    }
    else{
        return arr.data[index];
    }
}

int get(IntArray* arr, int index){
    return get(*arr, index);
}

void set(IntArray& arr, int index, int value){
    if (index > arr.size - 1 || index < 0){
        std::cout << "index все границ массива";
        return;
    }
    else{
        arr.data[index] = value;
    }
}

void set(IntArray* arr, int index, int value){
    set (*arr, index, value);
}

void print(IntArray& arr){
    std::cout << "[ ";
    for (int i = 0; i < arr.size; i++){
        std::cout << arr.data[i] << " ";
    }
    std::cout << "]\n";
}

void print(IntArray* arr){
    print (*arr);
}

void resize(IntArray& arr, int newSize){
    int *q = new int [newSize];
    for (int i = 0; i < newSize; i++){
        if (i < arr.size) q[i] = arr.data[i];
        else q[i] = 0;
    }
    delete [] arr.data;
    arr.data = q;
    arr.size = newSize;
    delete [] q;
}

void resize(IntArray* arr, int newSize){
    resize (*arr, newSize);
}

void destroy(IntArray& arr){
    delete [] arr.data;
    arr.data = nullptr;
    arr.size = 0;
}

void destroy(IntArray* arr){
    destroy(*arr);
}

