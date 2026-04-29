#include <iostream>
#include <string> 



void insertsort(int *arr, int size){

    int i, key;

    for(int j = 1; j <= size - 1; j++){

        key = arr[j];
        i = j - 1;

        while(i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        } 

        arr[i + 1] = key;
    }

    std::cout << "{";
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << "}" << std::endl;

}

int main()
{
    int arr[] = {3, 2 , 9, 1, 4, 5, 8, 7, 6};

    int size = (sizeof(arr) / sizeof(arr[0]));

    insertsort(arr, size);

    return 0;
}
