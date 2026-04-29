#ifndef __LIST_H__
#define __LIST_H__

struct Item; //forward declaration
int list_head(struct Item*); //Gibt das erste Element der Liste zurück
struct Item* list_tail(struct Item*); //Gibt die Liste abzüglich des ersten Elementes zurück
struct Item* list_add_front(struct Item*, int); //Fügt ein neues Element am Kopf der Liste ein
void list_delete(struct Item*); //Löscht die Liste

#endif //__LIST_H_