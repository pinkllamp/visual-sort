#include <iostream>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

//функция вывода ответа
void print_answer(int ARRAY[], int size) {
    cout << "Ответ: ";
    for (int i = 0; i < size; ++i) {
        cout << ARRAY[i] << ' ';
    }
    cout << endl;
}

//функция очистки поля вывода
void clear() { 
    this_thread::sleep_for(chrono::seconds(1));     // Пауза на 1 секунду
    cout << "\033[2J\033[H";    // Перемещает курсор в начало и очищает экран
}

//функция визуализации
void visual(int ARRAY[], int size, int color_change1, int color_change2){
    for (int i=0; i < size; ++i) {
        
        if (i==color_change1 or i==color_change2) {
            cout << "\033[96m" << ARRAY[i] << ' ';
            for (int j = 0; j < ARRAY[i]; ++j) {
                cout << "\033[96m□\033[0m"; 
            }
        }
        
        else{
        cout << ARRAY[i] << ' ';
        for (int j = 0; j < ARRAY[i]; ++j) {
            cout << "□"; 
        }
        }
    cout << endl; // Переход на новую строку
    }
}

void comb_sort(int ARRAY[], int size) {
    float factor = 1.247;
    int delta = size/factor;
    do{
        for (int i=0; i + delta < size; i++){
            if (ARRAY[i]>ARRAY[i+delta]){
                swap(ARRAY[i],ARRAY[i+delta]);
                int color_change1 = i, color_change2 = i+delta;
                cout << "Расстояние между сравниваемыми элементами: " << delta - 1 << endl;
                visual(ARRAY, size, color_change1, color_change2);
                clear();
            }
        }
        delta = delta/factor;
    } while (delta >= 1 );
}

int main() {
    const int size = 9;    //количество элементов в массиве
    int ARRAY[size] = {4,2,8,7,1, 3, 5, 9, 6};
    clear();
    //первоначальный массив
    cout << "Первоначальный массив:" << endl;
    visual(ARRAY, size,-1,-1);
    clear();    //очищаем консоль

    // Сортируем массив с помощью функции bubble_sort
    comb_sort(ARRAY, size);

    // Выводим отсортированный массив

    print_answer(ARRAY, size);
    visual(ARRAY, size,-1,-1);
    return 0;
}