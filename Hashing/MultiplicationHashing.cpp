#include "MultiplicationHashing.h"
#include <math.h>

int MultiplicationHashing::HashFunction(int key)
{
	const float a = 0.618;	//(sqrt(5) - 1)/2
	float aux = fmod(key * a, 1);
	return floor(this->tableSize * aux);
}

void MultiplicationHashing::Create(int m)
{
	hashTable = new ListaEncadeada * [m];
	for (int i = 0; i < m; i++)
	{
		hashTable[i] = new ListaEncadeada();
	}

	this->tableSize = m;
}

void MultiplicationHashing::Destroy(int m)
{
	for (int i = 0; i < m; i++)
	{
		delete hashTable[i];
	}
	delete hashTable;
}

void MultiplicationHashing::Insert(int key, int data)
{
	int hashValue = HashFunction(key);
	hashTable[hashValue]->Insere(data);
}

No* MultiplicationHashing::Lookup(int key, int data)
{
	int hashValue = HashFunction(key);
	return hashTable[hashValue]->GetNoByData(data); //returns pointer to node containing the data (or NULL)
}

