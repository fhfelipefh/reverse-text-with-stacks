#ifndef _HPP_PILHA_DINAMICA_CHAR_
#define _HPP_PILHA_DINAMICA_CHAR_

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha

struct NoPilhaChar
{
    char dado; //informa��o do n�
    NoPilhaChar *prox; //pr�ximo elemento
};

struct PilhaChar
{
    NoPilhaChar *topo;

    PilhaChar(){ //Construtor. Inicializa��o da pilha
        topo = nullptr;
    }
};

bool vaziaP(PilhaChar *p)
{
    if (!p->topo) //(p->topo == NULL)
        return true;
    else
        return false;
}

void pushPChar(PilhaChar *p, char dado)
{
    NoPilhaChar *novo = new NoPilhaChar; //aloca mem�ria para o novo n�
    novo->dado = dado; //insere o dado no n�
    novo->prox = p->topo; //o pr�ximo elemento � o topo da pilha
    p->topo = novo; //o topo da pilha � o novo n�
}

char popPChar(PilhaChar *p)
{
    if (vaziaP(p))
        return '\0';
    else
    {
        char dado = p->topo->dado; //salva o dado do topo da pilha
        NoPilhaChar *aux = p->topo; //salva o topo da pilha
        p->topo = p->topo->prox; //o topo da pilha � o pr�ximo elemento
        delete aux; //libera a mem�ria do n�
        return dado; //retorna o dado do topo da pilha
    }
}

void destroiPChar(PilhaChar *p)
{
    while (!vaziaP(p))
        popPChar(p);
}

#endif // _HPP_PILHA


