#include "DivisionHashing.h"

int DivisionHashing::HashFunction(int key)
{
	return key % this->tableSize;
}

void DivisionHashing::Create(int m)
{
	hashTable = new ListaEncadeada*[m];
	for (int i = 0; i < m; i++)
	{
		hashTable[i] = new ListaEncadeada();
	}

	this->tableSize = m;
}

void DivisionHashing::Destroy(int m)
{
	for (int i = 0; i < m; i++)
	{
		delete hashTable[i];
	}
	delete hashTable;
}

void DivisionHashing::Insert(int key, int data)
{
	int hashValue = HashFunction(key);
	if (hashTable[hashValue]->Insere(data))
		numeroDeColisoes++;
}

No* DivisionHashing::Lookup(int key, int data)
{
	int hashValue = HashFunction(key);
	return hashTable[hashValue]->GetNoByData(data); //returns pointer to node containing the data or NULL
}

int DivisionHashing::GetNumeroDeColisoes()
{
	return this->numeroDeColisoes;
}
