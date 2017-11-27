#include <iostream>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element


int main(){

std::vector<float> Xk; //vetor de dos x^(k)
std::vector<float> Xk_1; //vetor de dos x^(k - 1)

Xk = {10, 20.2, 50.4, 30};
Xk_1 = {1, 2, 3, 4.4};

std::vector<float> vector_result_sub; //vetor com os resultados das subtrações
float dk; //distancia d^(k)

for (int i = 0; i < Xk.size() - 1; i++) { 

	float result_i = Xk[i] - Xk_1[i]; // calcula xi^(k) - xi^(k - 1)
	vector_result_sub.push_back(result_i); // armazena resultado no vetor

}

// encontra o maior valor dos resultados, e armazena em dk
dk = *std::max_element(vector_result_sub.begin(), vector_result_sub.end());


std::cout << "A distancia eh: " << dk << std::endl;
// dig din, sou foda;


return 0;
}
