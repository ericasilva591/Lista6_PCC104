// Exercicio4_CoinCollecting_SemPD.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <algorithm> //para usar o max

int CoinCollecting(int i, int j, std::vector<std::vector<int>>& c) {
    if (i == 0 && j == 0) { //se estivermos na primeira posição do tabuleiro
        return c[i][j];
    }
    else if( i == 0){// se não tiver mais linha para explorar
        return CoinCollecting(i, j - 1, c) + c[i][j]; //chama a função com uma coluna a menos somando o valor de c[i][j]
    }
    else if (j == 0) {// se não tiver mais colunas para explorar
        return CoinCollecting(i - 1, j, c) + c[i][j]; //chama a função com uma linha a menos somando o valor de c[i][j]
    }
    else {
        return std::max(CoinCollecting(i, j - 1, c), CoinCollecting(i - 1, j, c)) + c[i][j];// maximiza a coleta de moedas
    } 
}// Operação básica = soma
//C(n) = 2C(n-1) + 1 = (2^n-1) -1


int main()
{
    /*std::vector<std::vector<int>> CoinColl({ {0,1,0,0},
                                             {1,0,1,0},
                                             {0,0,1,0} });*/

    std::vector<std::vector<int>> CoinColl({{0, 0, 0, 0, 1, 1},
                                            {0, 1, 0, 1, 0, 0},
                                            {0, 0, 0, 1, 0, 1},
                                            {0, 0, 1, 0, 0, 1},
                                            {1, 0, 0, 0, 1, 0} });


    std::cout << CoinCollecting(CoinColl.size() - 1, CoinColl[0].size() - 1, CoinColl); //numéro de linhas, número de colunas, matriz

}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
