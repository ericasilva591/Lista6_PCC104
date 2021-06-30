#include <iostream>
#include <vector>
#include <limits>
#include <functional> // std::function - permite criar uma função para trata-la como um objeto
#include <cmath>

template <typename T>
void printVector(std::vector<T>& v){

    std::cout << "[";
    for (auto e : v) {
        if (e == v[v.size() - 1]) {
            std::cout << e;
        }
        else std::cout << e << ", ";
    }
    std::cout << "]";
    std::cout << std::endl;
}


bool feasibleNqueens(int val, std::vector<int> sol){// verifica se a solução para o problema das N rainha é factivel 
    for (int i = 0; i < sol.size(); ++i){
        if (val == sol[i]){
            return false;
        }

        int delx = std::abs(sol[i] - val);
        int dely = std::abs(i - (int)sol.size());

        if (delx == dely){
            return false;
        }
    }

    return true;
}

bool complete(std::vector<int> sol, int n_vars){ // verifica se uma solução é completa
    return (sol.size() == n_vars); // no caso das n-rainha a solução é completa se ela possui tamanho n_vars e a função complete retorna true
}

void backtrack(std::vector<int>& sol, std::vector<int> domain, std::function<bool(int, std::vector<int>)> feasible,
    std::function<bool(std::vector<int>)> complete){
   
    if (complete(sol)){ // se a solução for completa eu retorno ela (poassagem por referência)
        return;
    }
    else{ // se a solução não for completa 
        for (int val : domain) { // para cada valor do pertecente ao dominio 
            if (feasible(val, sol)){ // verificar se é factível ( se não existe uma rainha na mesma coluna), se sim
                sol.push_back(val);// adiciona val na solução
                backtrack(sol, domain, feasible, complete);// chama a função backtrack com a solução atualizada

                if (!complete(sol)){ // se o ramo foi explorado e ainda assim a solução não é completa, o ultimo valor adicionado à solução é retirado (backtracking)
                    sol.pop_back();
                }
            }
        }
    }
}

int main()
{
    
    std::vector<int> domain({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});// número de colunas do tabuleiro, já que só pode haver uma rainha por linha
    int n = domain.size();
    std::vector<int> sol({}); // solução vazia

    std::function<bool(int, std::vector<int>)> f = [&](int val, std::vector<int> sol) -> bool //função buleana que recebe um inteiro e um vetor de soluções
    {
        return feasibleNqueens(val, sol);
    };

    std::function<bool(std::vector<int>)> c = [&](std::vector<int> sol) -> bool
    {
        return complete(sol, n);
    };

    backtrack(sol, domain, f, c);

    std::cout << "Solucao para o problema da N-Rainha com um tabuleiro " << n << "x" << n << ":";
    printVector(sol);

    return 0;
}
