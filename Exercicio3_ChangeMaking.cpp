// Exercicio3_ChangeMaking.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <functional>

template <typename T>
void print_vector(std::vector<T>& v) {//função para imprimir um vetor
    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

int changeMaking(int n, const std::vector<int>& c) {
    std::vector<int> f = { 0 };
    int m = c.size();
    
    for (int i = 1; i <= n; i++) {
        int temp = 999999;
        int j = 1;
        while ((j < m) && (i >= c[j])) { 
            temp = std::min(f[i - c[j]], temp);
            j += 1;
            
        }
        f.push_back(temp + 1);
        
    }
    
    return f[n];
}// Operação básica => comparação do min
//TETA(n) --> faz no mínimo n operações com n sendo valor de troco
//O(mn) --> soma(i=1 to i=n)soma(j=1 to j=m-1) = soma(i=1 to i=n)(m-1-1+1) = soma(i=1 to i=n)(m-1) = soma(i=1 to i=n)m - soma(i=1 to i=n)1 = m(n-1+1) - (n-1+1) = (m - 1)n

int main()
{
    std::vector<int> coins = {0,1,5,10,25,50};
    int n = 1010;

    std::cout <<"Total de moedas no troco: " << changeMaking(n, coins);
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
