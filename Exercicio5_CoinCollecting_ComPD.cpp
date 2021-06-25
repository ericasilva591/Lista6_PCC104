// Exercicio5_CoinCollecting_ComPD.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <algorithm> //para usar o max

int CoinCollecting(std::vector<std::vector<int>>& C) {
    
    int n = C[0].size(); //número de colunas
    int m = C.size();//número de linhas

    std::vector<std::vector<int>> F(m, std::vector<int> (n,0)); //inicializa a matriz F[m][n] com zero
        
    F[0][0] = C[0][0];
    for (int j = 1; j < n; j++) { 
        F[0][j] = F[0][j - 1] + C[0][j]; //preenche a primeira coluna de F com a soma do anterior com o atual
    }
    for (int i = 1; i < m; i++) {
        F[i][0] = F[i-1][0] + C[i][0];
        for (int j = 1; j < n; j++) {
            F[i][j] = std::max(F[i - 1][j], F[i][j - 1]) + C[i][j];
        }
    }
    return F[m -1][n-1];

}// Operação básica = soma
//C(n) = 2C(n-1) + 1 = (2^n-1) -1


int main()
{
    /*std::vector<std::vector<int>> CoinColl({ {0,1,0,0},
                                             {1,0,1,0},
                                             {0,0,1,0} });*/

    std::vector<std::vector<int>> CoinColl({ {0, 0, 0, 0, 1, 10},
                                            {0, 1, 0, 1, 0, 0},
                                            {0, 0, 0, 1, 0, 1},
                                            {0, 0, 1, 0, 0, 1},
                                            {1, 0, 0, 0, 1, 0} });


    std::cout << CoinCollecting(CoinColl);

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
