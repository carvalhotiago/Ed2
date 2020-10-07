#pragma once
#include "No.h"
class ListaEncadeada
{
public:
	ListaEncadeada();
	~ListaEncadeada();
	bool Insere(int valor);
	int numeroDeComparacoes = 0;
	void Imprimir();
	No* GetNoByData(int data);
private:
	No* primeiro;
};

