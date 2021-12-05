#ifndef _HPP_PILHA_DINAMICA_STRING_
#define _HPP_PILHA_DINAMICA_STRING_

#include <iomanip> //biblioteca usada para formatar a impress�o da pilha

struct NoPilhaString
{
    string dado; //informa��o do n�
    NoPilhaString *prox; //pr�ximo elemento
};

struct PilhaString
{
    NoPilhaString *topo;

    PilhaString(){ //Construtor. Inicializa��o da pilha
        topo = nullptr;
    }
};

bool vaziaP(PilhaString *p)
{
    if (!p->topo) //(p->topo == NULL)
        return true;
    else
        return false;
}

//cria método push na pilha
void pushPString(PilhaString *p, string dado)
{
    NoPilhaString *novo = new NoPilhaString; //aloca mem�ria para o novo n�
    novo->dado = dado; //insere o dado no n�
    novo->prox = p->topo; //o pr�ximo elemento � o topo da pilha
    p->topo = novo; //o topo da pilha � o novo n�
}

string popPString(PilhaString *p)
{
    if (vaziaP(p))
        return "";
    else
    {
        string dado = p->topo->dado; //salva o dado do topo da pilha
        NoPilhaString *aux = p->topo; //salva o topo da pilha
        p->topo = p->topo->prox; //o topo da pilha � o pr�ximo elemento
        delete aux; //libera a mem�ria do n�
        return dado; //retorna o dado do topo da pilha
    }
}

int tamanhoP(PilhaString *p)
{
    int cont = 0;
    NoPilhaString *aux = p->topo;
    while (aux)
    {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void mostraPString(PilhaString *p)
{
    cout << "PILHA String:  " << endl;

    if(!vaziaP(p))
    {
        cout << "--------------------------------------------" << endl;
        cout << setfill(' ') << std::setw(13) << "N�" << " | ";
        cout << setfill(' ') << std::setw(13) << "Prox" << " | ";
        cout << setfill(' ') << std::setw(10) << "Dado" << " |" << endl;
        cout << "--------------------------------------------" << endl;
        NoPilhaString *no = p->topo;
        while (no != NULL)
        {
            cout << setfill(' ') << std::setw(13) << no << " | ";
            cout << setfill(' ') << std::setw(13) << no->prox << " | ";
            cout << setfill(' ') << std::setw(10) << no->dado << " |" << endl;

            no = no->prox;
        }
        cout << "--------------------------------------------" << endl;
    }
}

void destroiPString(PilhaString *p)
{
    while (!vaziaP(p))
        popPString(p);
}

#endif // _HPP_PILHA


