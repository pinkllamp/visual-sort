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

//функция визуализации сортировки пузырьком
void visual(int ARRAY[], int size, int color_change1, int color_change2){
    for (int i=0; i < size; ++i) {
        
        if (i==color_change1 or i==color_change2) {
            cout << "\033[33m" << ARRAY[i] << ' ';
            for (int j = 0; j < ARRAY[i]; ++j) {
                cout << "\033[33m□\033[0m"; 
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

// Сортировка пузырьком
void bubble_sort(int ARRAY[], int size) {
    bool have_change;   // флаг изменения массива
    int k = 0;  // количество проходов
    do{
        k++;
        have_change = false ;   // перед пробегом по массиву изменений нет
        for (int i=0; i<size-1; i++){
            if (ARRAY[i]>ARRAY[i+1]){   //если левый элемент больше правого, то меняем местами
                swap(ARRAY[i],ARRAY[i+1]);
                have_change = true; //произошло изменение
                int color_change1 = i, color_change2 = i+1;
                cout << k << " проход по массиву" << endl;
                visual(ARRAY, size, color_change1, color_change2);
                clear();
            }
        }
    } while (have_change == true);  // пока прошли изменения, пробегаем массив заново
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
    bubble_sort(ARRAY, size);

    // Выводим отсортированный массив
    print_answer(ARRAY, size);
    visual (ARRAY, size,-1,-1);
    return 0;
}