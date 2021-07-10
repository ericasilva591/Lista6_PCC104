#include <iostream>
#include <vector>
#include <limits>
#include <functional> // std::function - permite criar uma função para trata-la como um objeto
#include <cmath>

template <typename T>
void printVector(std::vector<T>& v) {
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

bool feasibleHC(int val, std::vector<int> sol, std::vector<std::vector<int>> matrix) {// verifica se a solução é factivel - no caso do circuito Hamiltoniano é se não tem nenhum val repetido na solução e se existe uma aresta entre cada val
    for (int i = 0; i < sol.size(); ++i) {
        if (val == sol[i]) {//verifica se o elemento é repetido
            return false;
        }
    }
    int j = sol.size() - 1;
    if ((matrix[val][sol[j]] == 1)) {// se tiver uma aresta entre val e o ultimo elemento da solução, então ela é factível
        return true;
    }
    return false;
}

bool complete(std::vector<int> sol, int n_vars, std::vector<std::vector<int>> matrix) { // verifica se uma solução é completa
    if (sol.size() == n_vars) {// no caso a solução é completa se ela possui tamanho n_vars e existe uma aresta entre o ultimo elemento da solução e o primeiro
        if (matrix[sol[0]][sol[n_vars - 1]] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
}

void backtrack(std::vector<int>& sol, std::vector<int> domain, std::function<bool(int, std::vector<int>, std::vector<std::vector<int>>)> feasible,
    std::function<bool(std::vector<int>, int, std::vector<std::vector<int>> matrix)> complete, std::vector<std::vector<int>> matrix) {
    int n = domain.size();
    if (complete(sol, n, matrix)) {
        return;   
    }
    else {
        for (auto val : domain) {
            if (feasible(val, sol, matrix)) {
                sol.push_back(val);
                backtrack(sol, domain, feasible, complete, matrix);

                if (!complete(sol, n, matrix)) {
                    sol.pop_back();
                }
            }
        }
    }
}


int main()
{
    //---------------Exemplo 1---------------------------------------
    //------Resposta: c, a, d, b = 2,0,3,1
    
    //std::vector<int> domain({ 0,1,2,3 });// nós do grafo
    //std::vector<char> domain_l({ 'a','b','c','d'});// nós do grafo
    //std::vector<int> sol({ 2 }); // solução começando de c = 2
    
                                               //a,b,c,d
    //std::vector<std::vector<int>> arc_matrix({ { 0,1,1,1 },
    //                                           { 1,0,1,1 },
    //                                           { 1,1,0,0 },
    //                                           { 1,1,0,0 } });

    //---------------Exemplo 2---------------------------------------
    //---para este grafo (igual ao exemplo do livro) resposta: a,b,f,e,c,d = (0,1,5,4,2,3)

    std::vector<int> domain({ 0,1,2,3,4,5 });// nós do grafo
    std::vector<char> domain_l({ 'a','b','c','d','e','f'});// nós do grafo
    std::vector<int> sol({ 0 }); // solução começando de a = 0
                                                 //a,b,c,d,e,f
    std::vector<std::vector<int>> arc_matrix({ { 0,1,1,1,0,0 },
                                               { 1,0,1,0,0,1 },
                                               { 1,1,0,1,1,0 },
                                               { 1,0,1,0,1,0 },
                                               { 0,0,1,1,0,1 },
                                               { 0,1,0,0,1,0 } });

    //----------------------------------------------------------------

    int n = domain.size();
    

    std::function<bool(int, std::vector<int>, std::vector<std::vector<int>>)> f = [&](int val, std::vector<int> sol, std::vector<std::vector<int>> matrix) -> bool //função buleana que recebe um inteiro, um vetor de soluções e a matrix de arestas
    {
        return feasibleHC(val, sol, matrix);
    };

    std::function<bool(std::vector<int>, int, std::vector<std::vector<int>> matrix)> c = [&](std::vector<int> sol, int n, std::vector<std::vector<int>> matrix) -> bool
    {
        return complete(sol, n, matrix);
    };

    backtrack(sol, domain, f, c, arc_matrix);

    for (auto e : sol) { // imprime a solução com o vetor de char
        std::cout << domain_l[e] << ",";
    }
}

