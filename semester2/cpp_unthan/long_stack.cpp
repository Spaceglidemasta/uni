#include <iostream>
#include <string>
#include "long_stack.hpp"


Stapel::Stapel(){
    head = new Knoten;
    anz = 0;
    default_item = 0;
}

Stapel::~Stapel(){

    Knoten* current = head;

    while (current != nullptr) {
        Knoten* temp = current;
        current = current -> next;
        delete temp;
    }

    anz = 0;
    default_item = 0;
}

bool Stapel::push(long x) {

    Knoten* neu = new Knoten;

    neu -> d = x;

    neu -> next = head;
    head = neu;

    anz++;
    return true;
}

bool Stapel::pop(long* item){

    if(head == nullptr){
        return false;
    }

    *item = head -> d;

    Knoten* temp = head;
    head = head -> next;

    delete temp;

    anz--;

    return true;
}


long Stapel::back() const {
    if(head != nullptr){
        return head -> d;
    }
    return -1;
}



int main() {
    Stapel s;

    std::cout << "Anfangszustand (anz): " << s.get_anz() << std::endl;

    std::cout << "Push 10" << std::endl;
    s.push(10);
    std::cout << "Push 20" << std::endl;
    s.push(20);
    std::cout << "Push 30" << std::endl;
    s.push(30);

    std::cout << "Anzahl Elemente: " << s.get_anz() << std::endl;
    std::cout << "Oberstes Element (back): " << s.back() << std::endl;

    long wert;
    std::cout << "Pop..." << std::endl;
    if (s.pop(&wert)) {
        std::cout << "Entferntes Element: " << wert << std::endl;
    } else {
        std::cout << "Pop fehlgeschlagen (Stapel leer)" << std::endl;
    }

    std::cout << "Anzahl Elemente nach pop: " << s.get_anz() << std::endl;
    std::cout << "Oberstes Element: " << s.back() << std::endl;

    // Leere den Stack vollständig
    while (s.pop(&wert)) {
        std::cout << "Pop: " << wert << std::endl;
    }

    std::cout << "Stapel geleert, Anzahl: " << s.get_anz() << std::endl;

    return 0;
}
