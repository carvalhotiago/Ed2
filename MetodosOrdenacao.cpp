// MetodosOrdenacao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>

using namespace std;

//Variaveis globais para contadores
int numeroDeComparacoes;
int numeroDeTrocas;

void PrintVector(vector<int> vec)
{
	int n = vec.size();
	for (int i = 0; i < n; i++)
	{
		cout << vec.at(i) << " ";
	}
	cout << endl;
}

vector<int> GetRandomVector(int n) {
	vector<int> vec;

	// set the seed
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; ++i) {
		int random = rand() % 10000;
		vec.push_back(random);
	}

	return vec;
}

void BubbleSort(vector<int>& vec, int n)
{
	const clock_t t0 = clock();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			numeroDeComparacoes++;
			if (vec.at(j) > vec.at(j + 1))
			{
				numeroDeTrocas++;
				int aux = vec.at(j);
				vec.at(j) = vec.at(j + 1);
				vec.at(j + 1) = aux;
			}

		}
	}

	cout << "Tempo BubblerSort: " << float(clock() - t0) / CLOCKS_PER_SEC << endl;
}

void Merge(vector<int>& vec, int low, int mid, int high)
{
	int helper[5000];
	for (int a = low; a <= high; a++)
	{
		helper[a] = vec.at(a);
	}

	int i = low;
	int j = mid + 1;
	int k = low;

	while (i <= mid && j <= high)
	{
		numeroDeComparacoes++;
		if (helper[i] <= helper[j])
		{
			vec.at(k) = helper[i];
			i++;
		}
		else
		{
			numeroDeTrocas++;
			vec.at(k) = helper[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		vec.at(k) = helper[i];
		k++;
		i += 1;
	}
}

void MergeSort(vector<int>& vec, int low, int high)
{
	if (low < high)
	{
		int mid = (high - low) / 2 + low;
		MergeSort(vec, low, mid);
		MergeSort(vec, mid + 1, high);
		Merge(vec, low, mid, high);
	}
}

void ShellSort(vector<int>& vec, int n)
{
	const clock_t t0 = clock();

	for (int passo = n / 2; passo > 0; passo /= 2)
	{
		for (int i = passo; i < n; i++)
		{
			int aux = vec.at(i);
			int j;

			for (j = i; j >= passo && vec.at(j - passo) > aux; j -= passo, numeroDeComparacoes++)
			{
				numeroDeTrocas++;
				vec.at(j) = vec.at(j - passo);
			}

			vec.at(j) = aux;
		}
	}

	cout << "Tempo ShellSort: " << float(clock() - t0) / CLOCKS_PER_SEC << endl;
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}


int main(int argc, char* argv[])
{
	numeroDeComparacoes = 0;
	numeroDeTrocas = 0;

	srand(time(NULL));
	int n = atoi(argv[1]);
	vector<int> vec = GetRandomVector(n);
	PrintVector(vec);

	int arr[5000];
	copy(vec.begin(), vec.end(), arr);

	double t0_qsort = double(clock());
	qsort(arr, vec.size(), sizeof(int), compare);
	cout << "Tempo qsort: " << float(clock() - t0_qsort) / CLOCKS_PER_SEC << endl;

	// BubbleSort(vec, n);

	const clock_t t0 = clock();
	MergeSort(vec, 0, n - 1);
	cout << "Tempo MergeSort: " << float(clock() - t0) / CLOCKS_PER_SEC << endl;

	//ShellSort(vec, n);

	PrintVector(vec);

	cout << "\nNumero de comparacoes: " << numeroDeComparacoes << "\nNumero de trocas: " << numeroDeTrocas << endl;
	cout << endl;
}
