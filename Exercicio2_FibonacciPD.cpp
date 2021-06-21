// Exercicio2_FibonacciPD.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>

int FibonacciNum(int n) {

    std::vector<int> f;
    f.push_back(1);
    f.push_back(1);
    
    for (int i = 2; i < n; i++) {
        f.push_back(0);
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n - 1];

}//Operação Base: Soma
//C(n) = soma(i=2 to i=n-1)1 = n-1 - 2 +1 = n-2 --> O(n)

int main()
{
    int f = 7;
    std::cout << FibonacciNum(f);
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
