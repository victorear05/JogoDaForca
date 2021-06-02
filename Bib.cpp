#include "Bib.hpp"

void limpaTela(){
    system("CLS");
}

char menuPrincipal(){
    char opcao;

    cout << "Menu Principal\nDigite a opção desejada:\n";
    cout << "1 - Jogar \n";
    cout << "2 - Sobre\n";
    cout << "0 - Sair\n";

    cin >> opcao;

    return opcao;
}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasUsadas, string mensagem){
    cout << mensagem <<'\n';
    cout << palavraComMascara << " - (" << tamanhoDaPalavra << ")\n";
    cout << "Letras já usadas: ";

    for(int i = 0;i<(int)letrasUsadas.size();i++){
        cout << letrasUsadas[i] << ", ";
    }

    cout << "\nTentativas Restantes: " << tentativasRestantes;
}


int jogarSozinho(){

    string palavraAleatoria = retornaPalavraAleatoria();
    int tamanhoDaPalavra = palavraAleatoria.size();
    string palavraComMascara = retornaPalavraComMascara(palavraAleatoria, tamanhoDaPalavra);
    int tentativas = 0, maximoDeTentativas = tamanhoDaPalavra + 3;
    char letra;
    string letrasUsadas;
    string mensagem = "Começou o jogo!";
    int reiniciar;
    bool palpiteDePalavra = false;

    while( (palavraAleatoria != palavraComMascara) && (maximoDeTentativas - tentativas > 0) && (palpiteDePalavra == false) ){

        bool letraJaDigitada = false;

        limpaTela();

        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasUsadas, mensagem);

        cout << "\nDigite uma letra, ou 1 para adivinhar a palavra: ";
        cin >> letra;

        if(letra == '1'){
            cout << "Digite a palavra que você acha que é: \n";
            string palpitePalavra;
            cin >> palpitePalavra;
            limpaTela();
            if(palpitePalavra == palavraAleatoria)
                cout << "Parabéns você acertou a palavra!\n";
            else
                cout << "Você errou!\nA palavra era: " << palavraAleatoria << "Mais sorte na próxima vez!\n";
            palpiteDePalavra = true;
        }

        else{
            for(int i = 0;i < (int)letrasUsadas.size(); i++){
                if(letra == letrasUsadas[i]){
                    mensagem = "Essa letra já foi digitada!";
                    letraJaDigitada = true;
                }
            }

            bool acertouLetra = false;

            letraJaDigitada = false;

            if(letraJaDigitada == false){
                letrasUsadas += tolower(letra);
                for(int i = 0;i < tamanhoDaPalavra;i++){
                    if(palavraAleatoria[i] == tolower(letra) ){
                        palavraComMascara[i] = tolower(letra);
                        acertouLetra = true;
                    }
                }
                if(acertouLetra == true)
                    mensagem = "Você acertou uma letra!";
                else
                    mensagem = "A palavra não possui essa letra!";
                tentativas++;
            }

            if(palavraAleatoria == palavraComMascara){
                limpaTela();
                cout << "Você ganhou, parabéns!\nA palavra era: " << palavraAleatoria << '\n';
            }else{
                limpaTela();
                cout << "Acabaram as tentativas, você perdeu! Mais sorte na próxima vez!\nA palavra era: " << palavraAleatoria << '\n';
            }
        }
    }
    cout << "Deseja jogar novamente?\n1 - Sim\n2 - Não\n";
    cin >> reiniciar;
    return reiniciar;
}

string retornaPalavraComMascara(string palavraAleatoria, int tamanhoDaPalavra){

    int cont = 0;
    string palavraComMascara;

    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;
}


string retornaPalavraAleatoria(){

    string palavras[8] = {"abacaxi", "manga", "morango", "uva", "banana", "pera", "laranja"}; //Banco de palavras a ser sorteado

    srand(time(NULL)); //Função de gerar número aleatório

    int indiceAleatorio = rand() % 8;

    return palavras[indiceAleatorio];
}