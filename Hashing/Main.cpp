#include <iostream>
#include <vector>
#include "DivisionHashing.h"
#include "MultiplicationHashing.h"
#include "KnuthVariantHashing.h"
#include <time.h>

using namespace std;

vector<int> GetRandomVector(int n, int max) {
	vector<int> vec;

	// set the seed
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; ++i) {
		int random = rand() % max;
		vec.push_back(random);
	}

	return vec;
}


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
	int m = 157;
	int n = 100;

	vector<int> randomData = GetRandomVector(n, 1000);
	vector<int> randomKeys = GetRandomVector(n, 1000);	

#pragma region Método Divisão
	cout << "\n\tMETODO DIVISAO" << endl;
	DivisionHashing* divisionHash = new DivisionHashing();
	divisionHash->Create(m);
	for (int i = 0; i < n; i++)
		divisionHash->Insert(randomKeys.at(i) , randomData.at(i));

	for (int i = 0; i < m; i++)
	{
		cout << "DivisionHash[" << i << "]: " << divisionHash->HashFunction(i) << " --- ";
		divisionHash->hashTable[i]->Imprimir();
	}
	cout << "Numero de colisoes: " << divisionHash->GetNumeroDeColisoes() << endl;
#pragma endregion



#pragma region Método Multiplicação
	cout << "\n\tMETODO MULTIPLICACAO" << endl;
	MultiplicationHashing* multiplicationHash = new MultiplicationHashing();
	multiplicationHash->Create(m);
	for (int i = 0; i < n; i++)
		multiplicationHash->Insert(randomKeys.at(i), randomData.at(i));

	for (int i = 0; i < m; i++)
	{
		cout << "multiplicationHash["<<i<<"]: " << multiplicationHash->HashFunction(i) << " --- ";
		multiplicationHash->hashTable[i]->Imprimir();
	}
	cout << "Numero de colisoes: " << multiplicationHash->GetNumeroDeColisoes() << endl;
#pragma endregion


#pragma region Método Knuth Variant on Division
	cout << "\n\tMETODO KNUTH VARIANT" << endl;
	KnuthVariantHashing* knuthVariantHash = new KnuthVariantHashing();
	knuthVariantHash->Create(m);
	for (int i = 0; i < n; i++)
		knuthVariantHash->Insert(randomKeys.at(i), randomData.at(i));

	for (int i = 0; i < m; i++)
	{
		cout << "knuthVariantHash["<<i<<"]: " << knuthVariantHash->HashFunction(i) << " --- ";
		knuthVariantHash->hashTable[i]->Imprimir();
	}
	cout << "Numero de colisoes: " << knuthVariantHash->GetNumeroDeColisoes() << endl;
#pragma endregion
}

