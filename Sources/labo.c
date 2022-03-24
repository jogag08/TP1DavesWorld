#include "labo.h"

List* NewList() 
{
	List* head = allocate(sizeof(List));
	head->next = NULL;
	head->prev = NULL;
	head->data = NULL;
	return head;
}

Item* CreateItem(char* name, int value)
{
	Item* newItem = allocate(sizeof(Item));
	newItem->Name = name;
	newItem->Value = value;
	
	return newItem;
}

void AddItem(List* head, void* data)
{
	Node* newNode = allocate(sizeof(Node));

	if (head->next == NULL)
	{
		head->next = newNode;
		head->prev = newNode;
		newNode->next = NULL;
		newNode->prev = head->prev;
		newNode->data = data;
		return;
	}

	Node* currNode = head->next;
	while (currNode->next != NULL)
	{
		currNode = currNode->next;
	}

	currNode->next = newNode;
	newNode->prev = currNode;
	newNode->next = NULL;
	newNode->data = data;
	head->prev = newNode;
	head->next->prev = newNode;
}

void RemoveItembyName(List* head, char* itemName)
{
	if (head->next == NULL)
	{
		printf("Votre inventaire est vide.\n");
		return;
	}

	Node* tempNode = head->next;
	Item* item = tempNode->data;

	while (item->Name != itemName)
	{
		tempNode = tempNode->next;
		item = tempNode->data;
		if (tempNode == NULL)
		{
			printf("L'item que vous voulez retirer n'existe pas dans l'inventaire.\n");
			return;
		}
	}
	
	if (item->Name == itemName)
	{
		if (tempNode == head->next) //Si c'est le premier element de la liste
		{
			head->next = tempNode->next;
			tempNode->data = NULL;
			memset(tempNode, 0, sizeof(Item));
			return;
		}

		if (tempNode == head->prev) //Si c'est le dernier element de la liste
		{
			tempNode->prev->next = NULL;
			tempNode->data = NULL;
			memset(tempNode, 0, sizeof(Item));
			return;
		}

		if (tempNode != head->next && tempNode != head->prev) // Si ce n'est pas le premier ou le dernier element de la liste
		{
			tempNode->prev->next = tempNode->next;
			tempNode->data = NULL;
			memset(tempNode, 0, sizeof(Item));
			return;
		}
	}
}

void ShowItem(List* head)
{
	int slotNbr = 1;
	Node* tempNode = head->next;
	if (tempNode == NULL)
	{
		printf("Votre inventaire est vide.");
		printf("\n\n");
		return;
	}
	while (tempNode != NULL)
	{
		Item* item = tempNode->data;
		printf("Slot %d : %s, Value : %d$\n", slotNbr, item->Name, item->Value);
		tempNode = tempNode->next;
		slotNbr++;
	}
	printf("\n\n");
}

void BubbleSortByValue(List* head)
{
	int qty = 0;
	int swap = 0;
	Node* currNode = head->next;

	while (currNode != NULL)
	{
		qty++;
		currNode = currNode->next;
	}
	if (qty <= 1)
	{
		printf("Aucun item a trier dans votre inventaire.\n");
		return;
	}
	
	currNode = head->next;
	
	for (int i = 0; i < qty - 1; i++)
	{
		Item* item1 = currNode->data;
		Item* item2 = currNode->next->data;
		int item1Value = item1->Value;
		int item2Value = item2->Value;
		void* item1Name = item1->Name;
		void* item2Name = item2->Name;
		
		if (item1Value <= item2Value)
		{
			currNode = currNode->next;
		}
		else if (item1Value > item2Value)
		{
			int tempValue = item1Value;
			item1Value = item2Value;
			item2Value = tempValue;
			item1->Value = item1Value;
			item2->Value = item2Value;

			void* tempName = item1Name;
			item1Name = item2Name;
			item2Name = tempName;
			item1->Name = item1Name;
			item2->Name = item2Name;

			swap = 1;
		}
		if (swap == 1)
		{
			swap = 0;
			i = -1;
			currNode = head->next;
		}
	}
}

void AddRandomItems(List* head)
{	
	Item* bottes = CreateItem("Bottes", 25);
	Item* chainmail = CreateItem("Chainmail", 200);
	Item* sword = CreateItem("Sword", 50);
	Item* shield = CreateItem("Shield", 100);
	Item* apple = CreateItem("Apple", 1);
	
	int nbrItems = 4;//(rand() % 7) + 1;
	int tab[5] = { 0 };

	for (int i = 0; i <nbrItems; i++)
	{
		int rdmNum = rand() % 5 + 1;
		if (rdmNum == 1 && tab[0] != rdmNum && tab[1] != rdmNum && tab[2] != rdmNum && tab[3] != rdmNum && tab[4] != rdmNum)
		{
			AddItem(head, bottes);
			tab[i] = rdmNum;
		}
		if (rdmNum == 2 && tab[0] != rdmNum && tab[1] != rdmNum && tab[2] != rdmNum && tab[3] != rdmNum && tab[4] != rdmNum)
		{
			AddItem(head, chainmail);
			tab[i] = rdmNum;
		}
		if (rdmNum == 3 && tab[0] != rdmNum && tab[1] != rdmNum && tab[2] != rdmNum && tab[3] != rdmNum && tab[4] != rdmNum)
		{
			AddItem(head, sword);
			tab[i] = rdmNum;
		}
		if (rdmNum == 4 && tab[0] != rdmNum && tab[1] != rdmNum && tab[2] != rdmNum && tab[3] != rdmNum && tab[4] != rdmNum)
		{
			AddItem(head, shield);
			tab[i] = rdmNum;
		}
		if (rdmNum == 5 && tab[0] != rdmNum && tab[1] != rdmNum && tab[2] != rdmNum && tab[3] != rdmNum && tab[4] != rdmNum)
		{
			AddItem(head, apple);
			tab[i] = rdmNum;
		}
	}
}

int SumItems(List* head)
{
	int sum = 0;
	Node* currNode = head->next;

	while (currNode != NULL)
	{
		sum++;
		currNode = currNode->next;
	}

	return sum;
}