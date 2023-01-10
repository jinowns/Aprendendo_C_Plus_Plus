﻿#include <iostream>
#include <string> // biblioteca de string
#include <map>
#include "adiciona_palavra.hpp"
#include "chuta.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "le_arquivo.hpp"
#include "letra_existe.hpp"
#include "nao_acertou.hpp"
#include "salva_arquivo.hpp"
#include "sorteia_palavra.hpp"

std :: string palavra_secreta;
std :: map<char, bool> chutou;
std :: vector<char> chutes_errados;//Vector é um vetor com tamanho dinamico conforme é alocaum uma nova informacao

int main() 
{
    imprime_cabecalho();

    palavra_secreta = sorteia_palavra();

    while (nao_acertou(palavra_secreta, chutou) && chutes_errados.size() < 5) {
        imprime_erros();

        imprime_palavra();

        chuta();
    }

    std :: cout << "Fim de jogo!" << std :: endl;
    std :: cout << "A palavra secreta era: " << palavra_secreta << std :: endl;
    if (nao_acertou(palavra_secreta, chutou))
    {
        std :: cout << "Você perdeu! Tente novamente!" << std :: endl;
    }
    else 
    {
        std :: cout << "Parabéns! Você acertou a palavra secreta!" << std :: endl;

        std :: cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        std :: cin >> resposta;
        if (resposta == 'S' || resposta == 's')
        {
            adiciona_palavra();
        }
    }

    std :: cin.get();
}