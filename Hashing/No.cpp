#include "No.h"
#include <iostream>

using namespace std;

No::No()
{
    this->Prox = NULL;
};

No::~No() {};

No* No::GetProx()
{
    return Prox;
}

void No::SetProx(No* prox)
{
    this->Prox = prox;
}

int No::GetValor()
{
    return this->valor;
}

void No::SetValor(int valor)
{
    this->valor = valor;
}