#include <iostream>
#include "DivisionHashing.h"
#include "MultiplicationHashing.h"
#include "KnuthVariantHashing.h"

using namespace std;

int hashDivisao(int key, int m) {
	return key % m;
}

int hashMultiplicacao(int key, int m)
{
	const float a = 0.618;	//(sqrt(5) - 1)/2
	float aux = fmod(key*a, 1);
	return floor(m * aux);
}


void main()
{
	int m = 5;
	int valores[13] = { 000432545, 111765472, 222464536, 333142613, 444867975, 555741852, 666741852,
		777159842, 888951468, 999741852, 101010654, 111111852, 121212983 };
	int val[13] = { 00, 11, 22, 33, 44, 55, 66,
		77, 88, 99, 10, 11, 12 };
	

#pragma region Método Divisão
	cout << "\n\tMETODO DIVISAO" << endl;
	DivisionHashing* divisionHash = new DivisionHashing();
	divisionHash->Create(m);
	for (int i = 0; i < 13; i++)
		divisionHash->Insert(13245897+i, val[i]);

	for (int i = 0; i < m; i++)
	{
		cout << "DivisionHash[" << i << "]: " << divisionHash->HashFunction(i) << " --- ";
		divisionHash->hashTable[i]->Imprimir();
	}
#pragma endregion



#pragma region Método Multiplicação
	cout << "\n\tMETODO MULTIPLICACAO" << endl;
	MultiplicationHashing* multiplicationHash = new MultiplicationHashing();
	multiplicationHash->Create(m);
	for (int i = 0; i < 13; i++)
		multiplicationHash->Insert(13245897 + i, val[i]);

	for (int i = 0; i < m; i++)
	{
		cout << "multiplicationHash["<<i<<"]: " << multiplicationHash->HashFunction(i) << " --- ";
		multiplicationHash->hashTable[i]->Imprimir();
	}
#pragma endregion


#pragma region Método Knuth Variant on Division
	cout << "\n\tMETODO KNUTH VARIANT" << endl;
	KnuthVariantHashing* knuthVariantHash = new KnuthVariantHashing();
	knuthVariantHash->Create(m);
	for (int i = 0; i < 13; i++)
		knuthVariantHash->Insert(13245897 + i, val[i]);

	for (int i = 0; i < m; i++)
	{
		cout << "knuthVariantHash["<<i<<"]: " << knuthVariantHash->HashFunction(i) << " --- ";
		knuthVariantHash->hashTable[i]->Imprimir();
	}
#pragma endregion
}

