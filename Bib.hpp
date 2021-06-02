#ifndef BIB_HPP_INCLUDED
#define BIB_HPP_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <locale.h>
#include <time.h>

using namespace std;

void limpaTela();

char menuPrincipal();

int jogarSozinho();

string retornaPalavraAleatoria();

string retornaPalavraComMascara(string, int);

void exibeStatus(string, int, int, string, string);


#endif // BIB_HPP_INCLUDED