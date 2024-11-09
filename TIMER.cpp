#include <iostream>
#include <ctime>
using namespace std;

int Partition(int ARRAY[], int l, int r) {
  int pivot = ARRAY[r];
  int less = l;
  for (int i = l; i < r; ++i) {
    if (ARRAY[i] <= pivot) {
      swap(ARRAY[i], ARRAY[less]);
      ++less;
    }
  }
  swap(ARRAY[less], ARRAY[r]);
  
  return less;
}
void quick_sort(int ARRAY[], int l, int r) {
    if (l < r){
        int q = Partition(ARRAY, l, r);
        quick_sort(ARRAY, l, q - 1);
        quick_sort(ARRAY, q + 1, r);
    }
}

int main() { 
    int const size = 10;
    int i, ARRAY[size];
    //генерируем целый случайный массив из size эелментов от 1 до size
    for (i = 0; i < size; i++)
        ARRAY[i] = 1 + rand() % size;

    unsigned int start_time =  clock(); // начальное время
    quick_sort(ARRAY, 0, size-1);
    unsigned int end_time = clock(); // конечное время
    unsigned int search_time = end_time - start_time; // искомое время
    cout << "Время исполнения = " << search_time << " мс"<<endl; // время работы программы   

    return 0;
}