#include "ArvoreBinaria.h"
#include <iostream>
#include <queue>

ArvoreBinaria::ArvoreBinaria()
{
	raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
	Limpa();
}

void ArvoreBinaria::Insere(TipoItem item){
	InsereRecursivo(raiz,item);
}
void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
	if(p==NULL){
		p = new TipoNo();
		p->item = item;
	}
	else{
		if(item.GetChave() < p->item.GetChave())
			InsereRecursivo(p->esq, item);
		else
			InsereRecursivo(p->dir, item);
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

TipoNo* ArvoreBinaria::getRaiz()
{
	return raiz;
}
