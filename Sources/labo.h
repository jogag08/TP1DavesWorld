#include <stdint.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HEAP_SIZE 1024 * 1024
extern uint8_t* heap;
extern size_t heap_top;

static void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

typedef struct Node_t Node;
struct Node_t
{
	Node* next;
	Node* prev;
	void* data;
};
typedef Node List;

typedef struct Item_t Item;
struct Item_t
{
	void* Value;
	void* Name;
};

List* NewList();

void AddItem(List* head, void* data);

void RemoveItembyName(List* head, char* itemName);

void ShowItem(List* head);

void BubbleSortByValue(List* head);

void AddRandomItems(List* head);

int SumItems(List* head);

Item* CreateItem(char* name, int value);