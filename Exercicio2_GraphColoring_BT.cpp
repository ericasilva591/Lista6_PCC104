#include <iostream>
#include <vector>
#include <functional>

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

bool feasible(int val, std::vector<int> sol, std::vector<int> domain_v, std::vector<std::vector<int>> matrix) {// factível se 
    
}

bool complete(int n_vars, std::vector<int> sol, std::vector<std::vector<int>> matrix) {
    return (sol.size() == n_vars);
}

void backtrack( std::vector<int> domain_c, std::vector<int> domain_v, std::vector<int>& sol, std::vector<std::vector<int>> matrix, int n,
    std::function<bool(int, std::vector<int>, std::vector<int>, std::vector<std::vector<int>>)> feasible, std::function<bool(int, std::vector<int>, std::vector<std::vector<int>>)> complete) {
    
    if (complete(n, sol, matrix)) {
        return;
    }
    else {
        for (auto val : domain_c) {
            if (feasible(val, sol, domain_v, matrix)) {
                sol.push_back(val);

                backtrack(domain_c, domain_v, sol, matrix, n, feasible, complete);

                if (!complete(n, sol, matrix)) {
                    sol.pop_back();
                }
            }
        }
    }
}

int main()
{
    std::vector<int> domain_cores({ 0,1,2});// cores disponíveis
    std::vector<int> domain_vars({ 0,1,2,3,4,5 });// ordem de coloração dos nós
    std::vector<char> domain_l({ 'a','v','l'});// cores disponiveis
    std::vector<int> sol({ 0 }); // solução começando de a = 0
                                                 //a,b,c,d,e,f
    std::vector<std::vector<int>> arc_matrix({ { 0,1,1,1,0,0 },
                                               { 1,0,1,0,0,1 },
                                               { 1,1,0,1,1,0 },
                                               { 1,0,1,0,1,0 },
                                               { 0,0,1,1,0,1 },
                                               { 0,1,0,0,1,0 } });

    int n = arc_matrix[0].size(); 

    std::function<bool(int, std::vector<int>, std::vector<int>, std::vector<std::vector<int>>)> f = [&](int val, std::vector<int> sol, std::vector<int> domain_vars, std::vector<std::vector<int>> matrix) -> bool{
        return feasible(val, sol, domain_vars, matrix);
    };

    std::function<bool(int, std::vector<int>, std::vector<std::vector<int>>)> c = [&](int n_vars, std::vector<int> sol, std::vector<std::vector<int>> matrix) -> bool {
        return complete(n_vars, sol, matrix);
    };

    backtrack(domain_cores, domain_vars, sol, arc_matrix, n, f, c);

    printVector(sol);

}

