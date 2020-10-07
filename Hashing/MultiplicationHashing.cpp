#include "MultiplicationHashing.h"
#include <math.h>

int MultiplicationHashing::HashFunction(int key)
{
	const float a = (sqrt(5)-1)/2;	//(sqrt(5) - 1)/2
	double ka = (double)key * a;
	float aux = fmod(ka, 1);
	int hash = floor(this->tableSize * aux);
	return hash;
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
	if (hashTable[hashValue]->Insere(data))
		numeroDeColisoes++;
}

No* MultiplicationHashing::Lookup(int key, int data)
{
	int hashValue = HashFunction(key);
	return hashTable[hashValue]->GetNoByData(data); //returns pointer to node containing the data (or NULL)
}

int MultiplicationHashing::GetNumeroDeColisoes()
{
	return this->numeroDeColisoes;
}