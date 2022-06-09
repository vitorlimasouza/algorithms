#include <vector>
#include <iostream>

void insertion_sort(std::vector<int> &array){
    int a = 0;
    for(int i = 1; i < array.size(); i++){
        int value = array[i];
        int element = i - 1;
        while (element >= 0 && array[element] > value)
        {
            array[element+1] = array[element];
            element--;
            a++;
        }
        array[element + 1] = value;
    }
    std::cout << a << std::endl;
}