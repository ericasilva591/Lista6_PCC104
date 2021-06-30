// Exercicio1_TSP_BB.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

void printm(std::vector<std::vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void printv(std::vector<int>& v) {
    for (auto e : v) {
        std::cout << e << " ";
    }

    std::cout << std::endl;
}

int fat(int n) { //retorna o fatorial de um número
    int fat = 1;
    for (int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}

int main()
{
    std::ifstream myFile;
    myFile.open("TSPproblemMatrix.csv");
    //myFile.open("test.csv");
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
    
    printm(matrix);

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
