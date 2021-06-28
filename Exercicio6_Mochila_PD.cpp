// Exercicio6_Mochila_PD.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <algorithm> //para usar o max

void print_matriz(std::vector<std::vector<int>>& m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Knapsack_MemoryFuction(int i, int j, std::vector<int>& w, std::vector<int>& v, std::vector<std::vector<int>>& f) {
    int value;
    if (j == 0) { //preenche a primeira linha e coluna com 0
        f[i][0] = 0;
    }
    if (i == 0){
        f[0][j] = 0;
    }
    else if (f[i][j] < 0){  //se o ultimo elemento for menor que zero (-1) - nenhum item foi adicionado à mochila
        if (j < w[i - 1]) { //se peso_maximo corrente maior que w[i-1]
            value = Knapsack_MemoryFuction(i - 1, j, w, v, f);
        }
        else {
            value = std::max(Knapsack_MemoryFuction(i - 1, j, w, v, f), (v[i - 1] + Knapsack_MemoryFuction(i - 1, j - w[i - 1], w, v, f)));
        }   
        f[i][j] = value;
        //print_matriz(f);
        //std::cout << std::endl;
    }

    return f[i][j];
}

int main()
{
    //Maximizar o valor da mochila considerando que só existe um item de cada
    int max_w = 5;// peso máximo

    std::vector<int> w = {2,1,3,2}; // peso do itens
    std::vector<int> v = {12,10,20,15}; // valor de cada item
    std::vector<std::vector<int>> f(w.size() + 1, std::vector<int>(max_w + 1, -1)); //função de memória - matriz f[num itens+1][pesomax +1]
    

    std::cout << Knapsack_MemoryFuction(w.size(), max_w, w, v, f );
    std::cout << std::endl;

    print_matriz(f);

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
