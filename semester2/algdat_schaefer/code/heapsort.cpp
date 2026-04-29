#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>


#define LEN(x) (sizeof(x) / sizeof(x[0]))



void heapify(std::vector<int>& a, int heapsize, int pivot){
    int l = 2*pivot + 1;
    int r = 2*pivot + 2;
    int maximum = pivot;

    if(l < heapsize && a[l] > a[pivot]){
        maximum = l;
    }

    if(r < heapsize && a[r] > a[maximum]){
        maximum = r;
    }

    if(maximum != pivot){
        std::swap(a[pivot], a[maximum]);
        heapify(a, heapsize, maximum);
    }

}

void build_heap(std::vector<int>& a){
    
    for (int i = a.size() / 2; i > 0; i--){
        heapify(a, a.size(), i - 1);
    }
}

void heapsort(std::vector<int>& a){
    build_heap(a);
    for(int i = a.size() - 1 ; i > 0; i--){
        std::swap(a[0], a[i]);
        heapify(a, i, 0);
    }

}


int main(){

    std::vector<int> a = {4,1,3,2,16,9,10,14,8,7};

    heapsort(a);

    for(int i : a){
        std::cout << i << " ";
    }

    return 0;
}