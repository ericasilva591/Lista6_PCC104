// Exercicio2_TSP_BB.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#include <functional>
#include <fstream>
#include <string>
//Branch and bound para o caixeiro viajante

void printv(std::vector<int> v) {
    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void printm(std::vector<std::vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

std::vector<std::vector<int>> getInstance() { //ler aquivo e retornar uma matriz com os dados
    std::ifstream myFile;
    //myFile.open("TSPproblemMatrix.csv");
    myFile.open("test.csv");
    std::string line;
    std::vector<int> v;

    while (myFile.good()) { // Enquanto ainda tiver dados no arquivo ele vai ser lido 
        std::getline(myFile, line); //lê linha por linha
        //std::cout << line << " Size:" << line.size() << std::endl;
        std::string aux;

        for (int i = 0; i < line.size(); i++) {// arquivo precisa ter um zero no final de cada linha
            if (line[i] != ';') {// cada coluna do excel é lida como um ; - lê char por char da linha corrente
                aux.push_back(line[i]);// junta os characteres para formar o número
            }
            else {//se line[i] = ';' então começa um novo número(string)
                v.push_back(std::stoi(aux)); //converte de string para int e armazena em v
                aux.clear(); //limpa a string para armazenar o próximo número
            }
        }

    }

    myFile.close(); // fecha o arquivo

    //std::cout << "Vsize"<< v.size() << std::endl; // max_size() = 1.073.741.823

    int n = std::sqrt(v.size());// matriz quadrada nxn --> v sempre terá n^2 elementos 
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int k = 0;
    for (int i = 0; i < n; i++) { //preenche a matriz de dados linha a linha com n elementos de v, pulando de n em n
        for (int j = 0; j < n; j++) {
            matrix[i][j] = v[j + k];
        }
        k += n;
    }

    return matrix;
}

int h(std::vector<int> sol) {// heuristica negativa melhora artificialmente a solução explorada (custo pior do que o bound e o caminho ainda está sendo explorado), logo sempre positivo e não pode superestimar o custo da solução
    return 0;
}

int cost(std::vector<int> sol, std::vector<std::vector<int>> cost_matrix) {
    int cost = 0;
    for (size_t i = 0; i < sol.size() - 1; i++) {
        cost += cost_matrix[sol[i]][sol[i + 1]];
    }

    cost += cost_matrix[sol[sol.size() - 1]][sol[0]]; // custo do caminho da ultima para a primeira cidade

    return cost;
}

void search(std::vector<int>& sol, std::vector<int>& best_sol, int n, int& bound,
    std::vector<std::vector<int>>& cost_matrix, std::vector<int> domain) {

    if (cost(sol, cost_matrix) + h(sol) < bound) {
        if (sol.size() == n) { //solução completa
            best_sol = sol;
            bound = cost(sol, cost_matrix);
        }
        else {
            for (auto e : domain) {//verificar para cada elemento no dominio se 
                if (std::find(sol.begin(), sol.end(), e) == sol.end()) {//verifica se o elemento está na solução
                    std::vector<int> new_sol(sol);
                    new_sol.push_back(e);

                    search(new_sol, best_sol, n, bound, cost_matrix, domain);
                }
            }
        }
    }
}

std::vector<int> branchAndBound(std::vector<int>& domain, int n, int bound) {
    std::vector<int> best_path({});
    std::vector<int> sol({ 0 });

    std::vector<std::vector<int>> cost_matrix = getInstance();

    search(sol, best_path, n, bound, cost_matrix, domain);

    return best_path;
}


int main()
{
    std::vector<std::vector<int>> cost_matrix = getInstance();
    std::vector<int> domain;

    int n = cost_matrix.size();
    int bound = 50000;

    for (int i = 0; i < n; i++) {
        domain.push_back(i);
    }

    //printv(domain);
    //printm(cost_matrix);

    std::vector<int> best_path = branchAndBound(domain, n, bound);

    printv(best_path);
    std::cout << "Custo otimo: " << cost(best_path, cost_matrix);

    //custo de busca exaustiva = C(n) = (n - 1)!
    //custo de busca branchAndBound pior caso = C(n) = (n - 1)! 
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
