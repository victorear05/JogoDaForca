#include "Bib.cpp"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    cout << "Bem vindo ao jogo!\n\n";
    char opcao = '0';
    do{
        opcao = menuPrincipal();
        switch(opcao){
        case '1': {
            int reiniciarJogo = 1;
            while(reiniciarJogo == 1){
                reiniciarJogo = jogarSozinho();
            }
            break;
        }

        case '2': {
            limpaTela();
            cout << "Jogo da forca desenvolvido por Victor Eduardo em 2021\n";
            cout << "Digite a opção desejada: \n1 - para voltar ao menu \n2 - para sair do programa\n";

            char auxiliar;
            cin >> auxiliar;
            if(auxiliar == '1')
                limpaTela();
            else
                opcao = '0';
        }

        case '0':{
            break;
        }

        default:
            cout << "Opção inválida, selecione uma opção válida!\n";
            break;
        }
    }while(opcao != '0');

    limpaTela();
    cout << "Até mais!\n";
    cout << "\n\n-----------------------------------JOGO ENCERRADO-----------------------------------\n\n";


    return 0;
}