#include <iostream>
#include <string>
#include <new>



#ifndef LS_H
#define LS_H

class Knoten {
  
	public:
  
	long d; 		//gespeicherte Information
	
	Knoten* next;  	//Pointer auf sich selbst
};


class Stapel {
  
	public:
	Stapel(); 	//NULLpointer wird in C++ einfach mit 0 angegeben
				//wegen der stärkeren Typenprüfung besteht weniger Verwechslungsgefahr zur nummerischen 0
				//in eine bool Abfrage eingesetzt fungiert eine solche 0 wie ein false

	~Stapel(); //Destruktor (löscht nacheinander alle aufgebauten Knoten)

	bool push(long item);/*Legt einen neuen Knoten an, weißt d den Wert von item zu und hängt den Knoten an die verkettete Liste*/

	bool pop(long* item); /*Die Information aus dem obersten Knoten wird an der Adresse von item gespeichert. Der oberste Knoten wird gelöscht*/ 
	
	int get_anz() const { return anz;} /* Informiert über die Anzahl der Knoten in der Liste*/

	long back() const; /*gibt eine Kopie der Information aus dem obersten Knoten aus ohne den Knoten zu löschen.*/
  
	private:
	Knoten* head; //pointer auf den obersten Knoten
	int anz; //anzahl der Knoten
	long default_item; //Hilfsvariable für den Fall, dass leere Knoten gebaut werden sollen.
	};
  
#endif 