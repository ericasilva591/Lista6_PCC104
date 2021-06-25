// Exercicio2_FibonacciPD.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>

int Fibonacci_PD_BottomUp_var(int n) { //economia de memória, armazana somente os dois ultimo números - abordagem Bottom_UP
    int num1 = 0;
    int num2 = 1;
    int numaux = 0;

    for (int i = 0; i < n - 1; i++) {
        numaux = num2;
        num2 = num2 + num1;
        num1 = numaux;
    }

    return num2;

}//Operação Base: Soma
//C(n) = soma(i=2 to i=n-1)1 = n-1 - 2 +1 = n-2 --> O(n)

int Fibonacci_PD_BottomUp_vector(int n) {

    std::vector<int> cache(n + 1, -1);
    for (int i = 0; i < cache.size(); i++) {
        if (i <= 1) {
            cache[i] = i;
        }
        else {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
    }
    return cache[n];
}//Operação Base: comparação
//C(n) = soma(i=0 to i=n)1 = n - 0 +1 = n+1 --> O(n)


int Fibonacci_PD_TopDown(int n, std::vector<int>& cache) { //armazena na memória (vector) o fibonacci(n) - Abordagem Top_Down
    if (cache[n] != -1) {// se ele já foi calculado, já retorna a a posição do vetor e recupera o valor armazenado 
        return cache[n];
    }
    else{
        if (n <= 1) {
            cache[n] = n;
        }
        else {
            cache[n] = Fibonacci_PD_TopDown(n - 1, cache) + Fibonacci_PD_TopDown(n - 2, cache);
        }

        return cache[n];
    }
}//Operação Base: soma
//C(n) = C(n-1) + C(n-2) + 1

int Fibonacci_PD_TopDown(int n) {
    std::vector<int> cache(n + 1, -1);
    return Fibonacci_PD_TopDown(n, cache);
}

int main()
{
    int f = 11;
    
   std::cout << "Fibonacci de " << f << " Programacao dinamica BottomUP usando var:" << Fibonacci_PD_BottomUp_var(f);

    std::cout << std::endl;

    std::cout << "Fibonacci de " << f << " Programacao dinamica BottomUP usando vector:" << Fibonacci_PD_BottomUp_vector(f);

    std::cout << std::endl;

    std::cout << "Fibonacci de " << f << " Programacao dinamica TopDown:" << Fibonacci_PD_TopDown(f);

    std::cout << std::endl;

   
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
