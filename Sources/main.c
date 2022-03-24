#include "labo.h"

uint8_t* heap = NULL;
size_t heap_top = 0;

static size_t getline(char** lineptr, size_t* n, FILE* stream) {
	char* bufptr = NULL;
	char* p = bufptr;
	size_t size;
	int c;

	if (lineptr == NULL) {
		return -1;
	}
	if (stream == NULL) {
		return -1;
	}
	if (n == NULL) {
		return -1;
	}
	bufptr = *lineptr;
	size = *n;

	c = fgetc(stream);
	if (c == EOF) {
		return -1;
	}
	if (bufptr == NULL) {
		bufptr = malloc(128);
		if (bufptr == NULL) {
			return -1;
		}
		size = 128;
	}
	p = bufptr;
	while (c != EOF) {
		if ((p - bufptr) > (size - 1)) {
			size = size + 128;
			bufptr = realloc(bufptr, size);
			if (bufptr == NULL) {
				return -1;
			}
		}
		*p++ = c;
		if (c == '\n') {
			break;
		}
		c = fgetc(stream);
	}

	*p++ = '\0';
	*lineptr = bufptr;
	*n = size;

	return p - bufptr - 1;
}


int main() {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);
	srand(time(0));

	//Creation de la liste d'items
	List* head = NewList();
	
	
	//Peupler la liste d'items
	Item* potion = CreateItem("Potion", 10);
	
	
	//Ajout de l'item fiole dans l'inventaire
	AddItem(head, potion);
	//Montrer le nombre d'items
	int sum = SumItems(head);
	printf("Nombre d'items dans l'inventaire : %d\n", sum);
	//Montrer les items
	ShowItem(head);
	

	//Ajouter un nombre aleatoire d'items
	AddRandomItems(head);
	//Montrer le nombre d'items
	sum = SumItems(head);
	printf("Nombre d'items dans l'inventaire : %d\n", sum);
	//Montrer les items
	ShowItem(head);
	

	//Trier les items
	BubbleSortByValue(head);
	//Montrer le nombre d'items
	sum = SumItems(head);
	printf("Nombre d'items dans l'inventaire : %d\n", sum);
	//Montrer les items
	ShowItem(head);


	//Supprimer un item par son nom
	RemoveItembyName(head, "Potion");
	//Montrer le nombre d'items
	sum = SumItems(head);
	printf("Nombre d'items dans l'inventaire : %d\n", sum);
	//Montrer les items
	ShowItem(head);
	return 0;
}