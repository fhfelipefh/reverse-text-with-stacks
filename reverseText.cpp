#include <iostream>
using namespace std;

#include "pilhaString.hpp"
#include "pilhaChar.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    PilhaString pilhaString;
    PilhaChar pilhaChar;
    string fraseInvertida;
    string palavraEmOrdemInversa;
    cout << "Digite uma frase: ";
    string frase;
    getline(cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        pushPChar(&pilhaChar, frase[i]);
    }

    for (int i = 0; i < frase.length(); i++)
    {
        fraseInvertida += popPChar(&pilhaChar);
    }

    bool temEspaco = false;
    for (int i = 0; i < fraseInvertida.length(); i++)
    {
        if (fraseInvertida[i] == ' ')
        {
            temEspaco = true;
        }
    }

    string aux, aux2;
    int contador = 0;
    fraseInvertida += ' ';
    int tamFraseInvertida = fraseInvertida.length();
    //cout << "Frase Invertida: " << fraseInvertida << endl;
    //cout << "Tamanho da frase: " << tamFraseInvertida << endl;
     int qtdPalavras = 0;
    for (int i = 0; i < fraseInvertida.length(); i++)
    {
        if (fraseInvertida[i] == ' ')
        {
            qtdPalavras++;
        }
    }
    string *vetorDePalavras = new string[qtdPalavras];
    for (int i = 0; i < tamFraseInvertida; i++)
    {
        if (fraseInvertida[i] == ' ')
        {
            vetorDePalavras[contador] = aux;
            aux = "";
            contador++;
        }
        else
        {
            aux += fraseInvertida[i];
        }
    }

    for (int i = 0; i < qtdPalavras; i++)
    {
        pushPString(&pilhaString, vetorDePalavras[i]);
    }

    for (int i = 0; i < qtdPalavras; i++)
    {
        palavraEmOrdemInversa += popPString(&pilhaString);
        palavraEmOrdemInversa += " ";
    }

    cout << "Frase em Ordem Inversa: " << palavraEmOrdemInversa << endl;

    destroiPString(&pilhaString);
    destroiPChar(&pilhaChar);
    delete[] vetorDePalavras;
    return 0;
}
