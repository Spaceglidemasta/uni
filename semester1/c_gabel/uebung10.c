#include <stdio.h>
#include <stdlib.h>
#include <math.h>


const double pi = 3.141592653589793;


void read_radius(double* pradius){

    printf("Geben Sie einen Radius an: ");
    scanf("%lf", pradius);
}

void circle_circumference_and_area(double radius, double* circumference, double* area){
    
    *circumference = pi*2*radius;

    *area = pi*radius*radius;
}

void kreis(){

    double radius;
    double circumference;
    double area;

    double* pradius = &radius;


    read_radius(pradius);

    circle_circumference_and_area(radius, &circumference, &area);

    printf("Radius: %lf\nCircumferenc: %lf\nArea: %lf\n", radius, circumference, area);
}


void allocator(){

    int n;
    double root;

    printf("Geben Sie die Größe der Felder an: ");
    scanf("%d",&n);

    int* arr1 = (int*)malloc(n * sizeof(int));
    double* arr2 = (double*)malloc(n * sizeof(double));

    if(arr1 == NULL){
        printf("malloc 1 didnt work");
        return;
    }

    if(arr2 == NULL){
        printf("malloc 2 didnt work");
        return;
    }

    for(int i = 0; i < n; i++){
        arr1[i] = i*i;
    }
    for(int i = 0; i < n; i++){

        arr2[i] = sqrt(i);
    }

    for(int i = n-1; i >= 0; i--){
        printf("Array 1, %d: %d, Array 2, %d: %lf\n",i , arr1[i],i ,arr2[i]);
    }

    free(arr1);
    free(arr2);
}





int main(){
    
    kreis();
    return 0;
}

