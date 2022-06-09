#include <vector>
#include <iostream>
void bubble_sort(std::vector<int> &array){
    int a = 0;
    for (int i = 0; i < array.size(); i++){
        for (int j = 0; j < array.size() - 1; j++){
            if(array[j] > array[j + 1]){
                int value = array[j];
                array[j] = array[j+1];
                array[j+1] = value;
                a++;
            }
        }
    }
    std::cout << a;
}