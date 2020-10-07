#include <iostream>

#include "ListaEncadeada.h"

using namespace std;

ListaEncadeada::ListaEncadeada() {
    primeiro = NULL;
};

ListaEncadeada::~ListaEncadeada() {
    No* p = primeiro;
    while (p != NULL)
    {
        No* q = p->GetProx();
        delete p;
        p = q;
    }
}

/// <summary>
/// Essa função retorna true quando há colisão (quando não é a primeira inserção na lista)
/// </summary>
/// <param name="valor"></param>
/// <returns></returns>
bool ListaEncadeada::Insere(int valor)
{
    if (this->primeiro == NULL) {
        No* p = new No();
        p->SetValor(valor);
        p->SetProx(NULL);
        this->primeiro = p;
        return false;
    }
    else {
        No* aux = primeiro;
        while (aux->GetProx() != NULL)
            aux = aux->GetProx();

        No* q = new No();
        q->SetValor(valor);
        q->SetProx(NULL);
        aux->SetProx(q);
        return true;
    }
}

void ListaEncadeada::Imprimir() {
    if (this->primeiro == NULL)
    {
        cout << "Lista vazia!" << endl;
    }
    else
    {
        No* aux = primeiro;
        while (aux->GetProx() != NULL)
        {
            cout << aux->GetValor() << " -> ";
            aux = aux->GetProx();
        }
        cout << aux->GetValor() << " -> FIM" << endl;
    }
}

No* ListaEncadeada::GetNoByData(int data)
{
    if (this->primeiro == NULL)
    {
        cout << "Lista vazia!" << endl;
        return NULL;
    }

    No* aux = primeiro;
    while (aux != NULL)
    {
        if (aux->GetValor() == data)
            return aux;
        aux = aux->GetProx();
    }
}