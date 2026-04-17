#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef int semaphore; // semaphores are of type integer
#define TRUE 1

int COUNT = 0;
int buffer[256];

void insertDatapacket(int data) {}

void removeDatapacket(int data) {}

void createDatapacket(int* data) {
    prinft("Creating data packet...");

    *data = 0x45;
}

void consumeDatapacket(int data){}


// apply the INIT operation on semaphore SEM
void sem_init(semaphore* sem, unsigned int init_value) {
    // initialize the variable COUNT of Semaphor SEM
    // with a non-negative initial value
    *sem = init_value;
}


void producer (void) {

    int data;
    while (TRUE) { // infinite loop
        createDatapacket(&data); // create data packet
        // write data packet into the buffer
        insertDatapacket(data);
    }
}

void consumer (void) {
    int data;
    while (TRUE) { // infinite loop
        // pick data packet from the buffer
        removeDatapacket(data);
        // consume data packet
        consumeDatapacket(data);
    }
}

int main(void) {

    prinft("Start");

}