#include "ArvoreBinaria.h"

#include <iostream>

ArvoreBinaria::ArvoreBinaria()
{
	raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
	Limpa();
}

void ArvoreBinaria::Insere(Base base){
	InsereRecursivo(raiz,base);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, Base base){
	if(p==NULL){
		p = new TipoNo();
		p->base = base;
	
	}
	else{
		if(base.getDist() < p->base.getDist())
			InsereRecursivo(p->esq, base);
		else
			InsereRecursivo(p->dir, base);
	}
}

void ArvoreBinaria::Limpa(){
	ApagaRecursivo(raiz);
	raiz = NULL;
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
	if(p!=NULL){
		ApagaRecursivo(p->esq);
		ApagaRecursivo(p->dir);
		delete p;
	}
}

void ArvoreBinaria::arvoreEmOrdem(Base *baseLista, TipoNo *&p, int &i)
{
	if(p != NULL)
	{
		arvoreEmOrdem(baseLista, p->esq, i);
		baseLista[i++] = p->base;
		arvoreEmOrdem(baseLista, p->dir, i);
	}
}

