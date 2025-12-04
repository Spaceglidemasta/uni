#include <iostream>
#include <string>
#include <new>

/*
a) Sehen Sie sich die Datei leak.cpp an. Was tut die Klasse Person, was tut die Klasse Kunde, was soll in der main Funktion passieren? 

b) Schreiben Sie an die Initialisierungslisten, die Sie im Code finden, einen Kommentar. Wenn Sie nicht mit C++11 arbeiten wollten, schreiben Sie den Code entsprechend um.

c) Kennzeichnen Sie alle dafür geeigneten Methoden mit dem Schluesselwort const

d) Statten Sie den Personen Konstruktor mit dem Indikatorsatz 'cout <<  "Personen Objekt "  << vorname << " "  << nachname  << " erstellt." << endl; ' aus. Schreiben Sie einen Personen Destruktor,
   der lediglich den Indikatorsatz 'cout <<  "Personen Objekt "  << vorname << " "  << nachname << " zerstört." << endl; '.  enthält.
   Kompilieren Sie und führen Sie das Programm aus. Vergleichen Sie  die Nachrichten, die Sie vom Konstruktor erhalten, mit den Nachrichten,
	die Sie vom Destruktor erhalten. Wie lassen sich die Unterschiede erklären?

e) Ergänzen Sie den Destruktor von Person so, dass er den allokierten Speicher des Objekts wieder freigibt und beobachten Sie was geschieht. Warum können hier schwere Fehlermeldungen auftreten?

f) Reparieren Sie den Code mit einem geeigneten Copy Konstruktor und einem geeigneten Zuweisungoperator wo nötig.

g) Ändern Sie den Code so, dass die Kundennummer der Objekte konstant bleibt.

*/

using namespace std;

/**
*Person
*----------
*Defieniert eine Klasse "Person", die die Attribute Vorname, Vorname-länge,
*nachname und nachname-länge hat.
*
*Diese hat ausserdem die Methoden n_ausgabe, welche den vor- und nachnamen ausgibt,
*sowie den initialiser Person, welche durch console inputs den vor- und nachnamen
*durch memory allocation setzt.
*/
class Person {


    public: 
    Person();
    void n_ausgabe() const;
    
    
    private:  
    char* vorname;
    int vlaenge;
    char* nachname;
    int nlaenge;
    
    friend class Kunde;
};


Person::Person() {
 
  string v;
  string n;
  cout << "Vorname: ";
  getline(cin,v);
  cout << "Nachname: ";
  getline(cin,n);
  int i;
  
  vlaenge = v.length()+1; 
  nlaenge = n.length()+1;
  
  vorname = new char [vlaenge]; 
  
  for(i=0; i<v.length();i++){
   
    vorname[i] = v[i];
    
  }
  
  vorname[i]='\0';
  
  nachname = new char [nlaenge];
  
  for(i=0; i<n.length();i++){
   
    nachname[i] = n[i];
    
  }
  
  nachname[i]='\0';

  cout <<  "Personen Objekt "  << vorname << " "  << nachname  << " erstellt." << endl;
  
}


void Person::n_ausgabe() const {
	cout << "Name: " << vorname << " " << nachname << endl; 
}

/**
*Kunde
*------------
*Die Klasse Kunde hat die privaten Attribute kunde, welcher vom typ Person ist,
*sowie den long int kundennummer
*
*Außerdem verfügt sie über die public zweifach geoverloadete Methode Kunde,
*welche bei mitgabe von der nummer die nummer eines bereits bestehenden Kunden
*setzt, und im falle von 2 parametern Person und long int einen neuen Kunden
*erstellt und diesem eine kundennummer zuteilt.
*Zudem verfügt sie über die methode print, welche die Kundennummer sowie den
*vor- und nachnamen eines Kunden ausgibt.
*
*---
*Person kunde
*long kundennummer
*
*Kunde(long nummer);
*Kunde(Person neukunde, long nummer);
*void print();
*/
class Kunde{
  
    Person kunde;
    
    long kundennummer;
    
    
    public:
    
    Kunde(long nummer);
    Kunde(Person neukunde, long nummer);
    void print() const;
  
};

//Konstruktor für Kunde ohne ggb. Person
Kunde::Kunde(long nummer) : kundennummer(nummer){}

//Konstrukot für Kunde mit ggb. Person
Kunde::Kunde(Person neukunde, long nummer) : kunde(neukunde), kundennummer(nummer) { 
}

void Kunde::print() const {
 
  	cout << "Die Kundennummer des Kunden " << kunde.vorname << " " << kunde.nachname << " lautet: " << kundennummer << endl;
  
}

Kunde kunde_anlegen(){
 
	long nr;
	cout << "Neuen Kunden anlegen!" << endl;
	Person neu;
	cout << "Bitte geben Sie die Kundennummer ein: ";
	cin >> nr;
	cin.ignore();
	
	Kunde k{neu,nr};


	return k;
  
}


int main(){
  
	Kunde neuer{kunde_anlegen()}; 
	
	Kunde dagobert{9999};
	
	neuer.print();
	dagobert.print();
	
	dagobert = neuer;
	
	neuer.print();
	dagobert.print();
  
}