#include <iostream>
#include <string>
#include <stdlib.h>
#include <string>
#include <queue>
#include <ctime>

#include "Foo1.h"
#include "Foo2.h"
#include "Foo3.h"
#include "Foo4.h"
#include "Foo5.h"
#include "Foo6.h"

using namespace std;




void Foo1(int* arr);			//increase by 1
void Foo2(int* arr);			//swap the elements of arr
void Foo3(int* arr);			//print revert
void Foo4(int* arr);			//min value
void Foo5(int* arr);			//bubble sort


void quickSortR(int* arr, 		//quick sort
	int SIZE);

string Words;



struct Node
{
	int data;
	Node* next;
	Node* prev;
};
Node* head, * tail, *cur;

struct Tree
{
	int data;
	Tree* left;
	Tree* right;
};
Tree* head_r;

struct StringTree
{
	string data;
	StringTree* next;
};
StringTree* curSt;

void PrintStruct()
{

	Node* tmp = head;

	while (tmp != NULL)
	{
		cout << tmp->data << "\t";

		tmp = tmp->next;
	}

	cout << endl << endl;

}

void PrintStructRev()
{
	Node* tmp = tail;

	while (tmp != NULL)
	{
		cout << tmp->data << "\t";

		tmp = tmp->prev;
	}

	cout << endl << endl;
}

void AddTail()
{

	int a;

	Node* Four = new Node();

	cout << "set the data: ";

	cin >> a;
	Four->data = a;


	Four->prev = tail;

	tail->next = Four;
	Four->next = NULL;
	tail = Four;

}



int insertTreeValue(Tree* node, int  val, int l)
{
	if (val > node->data)
	{
		if (node->right == NULL)
		{
			node->right = new Tree();
			node->right->data = val;
			return l + 1;
		}
		else
		{
			return insertTreeValue(node->right, val, l + 1);
		}
	}
	else if (val < node->data)
	{
		if (node->left == NULL)
		{
			node->left = new Tree();
			node->left->data = val;
			return l + 1;
		}
		else
		{
			return insertTreeValue(node->left, val, l + 1);
		}
	}
	else
	{
		cout << "\nThe entered number is already present:" << endl;
		return l;
	}
}

int insertTreeValueRand(Tree* node, int val, int l)
{
	if (val > node->data)
	{
		if (node->right == NULL)
		{
			node->right = new Tree();
			node->right->data = val;
			return l + 1;
		}
		else
		{
			return insertTreeValueRand(node->right, val, l + 1);
		}
	}
	else if (val < node->data)
	{
		if (node->left == NULL)
		{
			node->left = new Tree();
			node->left->data = val;
			return l + 1;
		}
		else
		{
			return insertTreeValueRand(node->left, val, l + 1);
		}
	}
	else
	{
		cout << "\nThe entered number is already present:" << endl;
		val = rand() % 10;
		return insertTreeValueRand(head_r, val, l = 0);
	}
}

void addTreeValue()
{
	int chouse;
	cout << "How do you want to enter values?" << endl;
	cout << "On keyboard - 1;" << endl << "Random - 2." << endl;
	cin >> chouse;
	
	switch (chouse)
	{
		int level;
		int val;
	case 1:		
		cout << "Set new value of tree: ";
		cin >> val;

		level = insertTreeValue(head_r, val, 0);
		cout << "On level " << level << endl << endl;
		break;

	case 2:
		int quantity;
		cout << "How many element do you want to ensert?" << endl;
		cin >> quantity;

		int i;

		for (int i = 0; i < quantity; i++)
		{
			val = rand() % 10;
			level = insertTreeValueRand(head_r, val, 0);
			cout << val << endl;
			cout << "On level " << level << endl << endl;
		}		
		break;

	default:
		cout << "Menu item missing";
		return;
		break;
	}	
}

void AddHead()
{
	int a;

	Node* Fst = new Node();

	cout << "set the data: ";

	cin >> a;
	Fst->data = a;


	head->prev = Fst;
	Fst->next = head;
	Fst->prev = NULL;
	head = Fst;

}

void DelEl()
{
	int a;
	int i = 0;
	Node* current = head;
	Node* currentPrev = NULL;

	cout << "chose the element for delete: ";

	cin >> a;

	if (a == 0)
	{
		head = current->next;
		delete current;
	}
	else
	{

		while (a != i)
		{
			if (current != tail)
			{
				currentPrev = current;
				current = current->next;
			}
			else
			{
				tail = currentPrev;
				currentPrev = NULL;
				delete current;
			}

			i++;
		}

		if (a == i)
		{
			currentPrev->next = current->next;
			delete current;
		}

	}
}

void SortBubbleStruct()
{	
	bool swaped = true;
	int count = 0;

	while (swaped)
	{		
		swaped = false;
		cur = head;
		while (cur->next != NULL)
		{
			if (cur->data > cur->next->data)
			{
				int temp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = temp;
				swaped = true;
			}
			else
			{
				cur = cur->next;
			}
		}
		count++;

		if (swaped)
			PrintStruct();
	}
		
	cout << "Список остортирован за " << count - 1 << " итераций.\n\nИтог:" << endl;
	PrintStruct();
}

void preOrder(Tree* node, StringTree* ValS) {
	if (node == NULL) return;
	ValS->data = ValS->data + " " + to_string(node->data);	

	if ((node->left != NULL)||(node->right != NULL))
	{		
		if (ValS->next == NULL)
		{
			ValS->next = new StringTree();
		}		
	}
	
	if ((node->left != NULL))
	{
		ValS->next->data = ValS->next->data + " (";
		preOrder(node->left, ValS->next);
	}
	if ((node->right != NULL))
	{
		if (node->left == NULL)
		{
			ValS->next->data = ValS->next->data + " (";
		}
		preOrder(node->right, ValS->next);
		ValS->next->data = ValS->next->data + " )";
	}

	/*preOrder(node->left, ValS->next);
	preOrder(node->right, ValS->next);*/
}

void preOrder1(Tree* node, StringTree* ValS) {
	if (node == NULL) return;
	ValS->data = ValS->data + " " + to_string(node->data);

	if ((node->left != NULL) || (node->right != NULL))
	{
		if (ValS->next == NULL)
		{
			ValS->next = new StringTree();
		}
	}	

	preOrder1(node->left, ValS->next);
	preOrder1(node->right, ValS->next);
}


//void levelOrderPrint(Tree* root, StringTree* ValS) {
//	if (root == NULL)
//	{
//		return;
//	}
//	queue<Tree*> q;								// Создаем очередь
//	q.push(root);								// Вставляем корень в очередь
//
//	while (!q.empty())							// пока очередь не пуста
//	{
//		Tree* temp = q.front();					// Берем первый элемент в очереди
//		q.pop();								// Удаляем первый элемент в очереди
//		//cout << temp->data << " ";				// Печатаем значение первого элемента в очереди
//
//		ValS->data = ValS->data + " " + temp->data;
//
//		if (temp->left != NULL)
//			q.push(temp->left);					// Вставляем  в очередь левого потомка
//
//		if (temp->right != NULL)
//			q.push(temp->right);				// Вставляем  в очередь правого потомка
//	}
//}

//string* addTextToTree(Tree* node, StringTree* ValS, int l)
//{
//	ValS->data = node->data;
//
//
//	if (node->left->left != NULL)
//	{
//		ValS->data = node->data;
//		ValS->next = new StringTree();
//		addTextToTree(node->left, ValS->next, l + 1);
//	}
//
//	if (node->left != NULL)
//	{
//		ValS->next = new StringTree();
//		addTextToTree(node->left, ValS->next, l + 1);
//	}
//	else if (node->left == NULL)
//	{
//		ValS->next = new StringTree();
//		addTextToTree(node->right, ValS->next, l + 1);
//	}
//	else
//	{
//
//	}
//
//	s[l] = s[l] + " " + to_string(node->data);
//	if (node->left != NULL)
//	{
//		s = addTextToTree(node->left, s, l + 1);
//	}
//	if (node->right != NULL)
//	{
//		s = addTextToTree(node->right, s, l + 1);
//	}
//	return s;
//}


void PrintTree()
{
	/*int a = 10;

	string s[100];
	for (int i = 0; i < 100; i++)
	{
		s[i] = "";
	}	

	string* result = addTextToTree(head_r, s, 0);

	cout << "Tree value: " << endl;

	int i = 0;
	while (s[i] != "")
	{
		cout << "Level " << i << ": " << s[i] << endl;
		i++;
	}*/

	StringTree* ValS = new StringTree();
	preOrder(head_r, ValS);

	cout << "##################################################################################################" << endl << endl;
	cout << "Tree value: " << endl;

	int i = 0;
	while (ValS != NULL)
	{
		cout << "Level " << i << ":" << ValS->data << endl;
		ValS = ValS->next;
		i++;
	}

	cout <<endl;
	cout << "##################################################################################################" << endl << endl;
}

void PrintTree1()
{

	StringTree* ValS = new StringTree();
	preOrder1(head_r, ValS);

	cout << "##################################################################################################" << endl << endl;
	cout << "Tree value: " << endl;

	int i = 0;
	while (ValS != NULL)
	{
		cout << "Level " << i << ":" << ValS->data << endl;
		ValS = ValS->next;
		i++;
	}

	cout << endl;
	cout << "##################################################################################################" << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Node* First = new Node();

	First->data = 10;
	First->next = NULL;
	First->prev = NULL;

	head = First;
	tail = First;	

	Tree* Rood = new Tree();
	Rood->data = 10;
	Rood->left = NULL;
	Rood->right = NULL;

	head_r = Rood;


	Words = "hellomyfriend";



	char a = 'a';

	int ia = (int)a;

	int* array[26];

	int Size[26] = {};

	for (int i = 0; i < 26; i++)
	{
		array[i] = (int*)malloc(sizeof(int) * Words.size());
	}

	for (int j = 0; j < Words.size(); j++)
	{
		int ij = (int)Words[j] - (ia);

		array[ij][Size[ij]] = j;

		Size[ij]++;
		int trt = Size[ij];

	}

	int arr[5] = { 9,6,2,3,4 };

	int command;

	int value;
	int indx;

	while (true)
	{/*
		for(int i = 0; i < 26; i++)
		{
			for(int j = 0; j < Size[i]; j++)
			{
				cout << array[i][j] << " ";
			}

			cout << endl;
		}
		*/
		cout << "0 - Exit\n1 - Read\n2 - Write(not more than 5 elements)\n3 - increase by 1\n4 - swap elem arr\n5 - print arr rev\n6 - min val\n7 - bubble sort\n8 - quick sort\n10 - print struct\n11 - add element at tail\n12 - add element at head\n13 - del element\n14 - print struct rev\n15 - bubble sort struct\n16 - Insert value in tree\n17 - Print tree" << endl << endl << "please, choose a command: ";
		cin >> command;
		system("cls");

		switch (command)
		{
		case 1:
			system("cls");
			for (int i = 0; i < 5; i++)
			{
				cout << arr[i] << "\t";
			}
			cout << endl << endl;
			break;

		case 2:
			cout << "Select the index of the element to fill and its value:";
			cin >> indx >> value;

			arr[indx] = value;
			system("cls");
			break;

		case 3:
			Foo1(arr);
			break;

		case 4:
			Foo2(arr);
			break;

		case 5:
			Foo3(arr);
			break;

		case 6:
			Foo4(arr);
			break;

		case 7:
			Foo5(arr);
			break;

		case 8:
			quickSortR(arr, 5);

		case 9:
			for (int i = 0; i < 5; i++)
			{
				cout << arr[i];
			}
			cout << endl << endl;
			break;

		case 10:
			PrintStruct();
			break;

		case 11:
			AddTail();
			break;

		case 12:
			AddHead();
			break;

		case 13:
			DelEl();
			break;

		case 14:
			PrintStructRev();
			break;	
		
		case 15:
			SortBubbleStruct();
			break;

		case 16:
			addTreeValue();
			break;

		case 17:
			//preOrder(head_r, curSt);
			//levelOrderPrint(head_r);
			PrintTree();
			break;

		case 18:
			PrintTree1();
			break;
		case 0:
			return 0;
			break;

		}
	}

	return 0;
}



//Д/з 09.12.2020:
//1)избавиться от строки в 100 элементов и заменить на список с элементом строки и записывать элементы склеиванием
//2)добавить условие на повторяющиеся значения
//3)организовать корректный вывод
 
//Д/з 14.12.2020:
//Решить проблему с выводо рандомгого дерева