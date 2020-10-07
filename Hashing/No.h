#pragma once
class No
{
public:
	No();
	~No();
	No* GetProx();
	void SetProx(No* novoNo);
	int GetValor();
	void SetValor(int valor);

private:
	int valor;
	No* Prox;
};

