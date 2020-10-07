#pragma once
#include "ListaEncadeada.h"

class MultiplicationHashing
{
private:
	int numeroDeColisoes;

public:
	int HashFunction(int key);
	ListaEncadeada** hashTable;
	void Create(int m);
	void Insert(int key, int data);
	No* Lookup(int key, int data);
	void Destroy(int m);
	int tableSize;
};