#include "KnuthVariantHashing.h"

int KnuthVariantHashing::HashFunction(int key)
{
	return (key*(key+3)) % this->tableSize;
}

void KnuthVariantHashing::Create(int m)
{
	hashTable = new ListaEncadeada * [m];
	for (int i = 0; i < m; i++)
	{
		hashTable[i] = new ListaEncadeada();
	}

	this->tableSize = m;
}

void KnuthVariantHashing::Destroy(int m)
{
	for (int i = 0; i < m; i++)
	{
		delete hashTable[i];
	}
	delete hashTable;
}

void KnuthVariantHashing::Insert(int key, int data)
{
	int hashValue = HashFunction(key);
	hashTable[hashValue]->Insere(data);
}

No* KnuthVariantHashing::Lookup(int key, int data)
{
	int hashValue = HashFunction(key);
	return hashTable[hashValue]->GetNoByData(data); //returns pointer to node containing the data or NULL
}

