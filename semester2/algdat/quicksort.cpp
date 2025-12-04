#include <iostream>
#include <string>


int partition(int a[], int p, int lenght){
    int pivot = a[lenght];
    int i = p - 1;
    for(int j = p; j < lenght; j++){
        if(a[j] <= pivot){
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[lenght], a[i + 1]);
    return i + 1;
}

void quicksort(int a[], int p, int lenght){

    if(p < lenght){
        int q = partition(a, p , lenght);
        quicksort(a, p,     q - 1);
        quicksort(a, q + 1, lenght);
    }
    
    
}



int main(){

    int array[] = {2, 9, 1, 5, 0, 4, 3, 6, 8, 7};
    int lenght = sizeof(array) / sizeof(array[0]);
    
    quicksort(array, 0, lenght - 1);


    for(auto i : array){
        std::cout << array[i] << ", " ;
    }
    std::cout << std::endl;

    return 0;
}


