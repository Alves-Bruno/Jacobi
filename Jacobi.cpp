/*
 * Jacobi.cpp
 *
 *  Created on: 27 de nov de 2017
 *      Author: alves
 */


#include <iostream>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element
#include <limits>


float calcula_dk (std::vector<float> Xk, std::vector<float> Xk_1){

	// Xk -->> vetor de dos x^(k)
	// xk_1 -->> vetor de dos x^(k - 1)

	std::vector<float> vector_result_sub; //vetor com os resultados das subtrações
		float dk; //distancia d^(k)

		for (int i = 0; i < Xk.size() - 1; i++) {

			float result_i = Xk[i] - Xk_1[i]; // calcula xi^(k) - xi^(k - 1)
			vector_result_sub.push_back(result_i); // armazena resultado no vetor

		}

		// encontra o maior valor dos resultados, e armazena em dk
		dk = *std::max_element(vector_result_sub.begin(), vector_result_sub.end());

		return dk;

}

std::vector<float> Met_Jacobi(std::vector<float> X0, std::vector<std::vector<float>> Matriz, double Erro, int num_max_iteracoes){

	double dk = std::numeric_limits<double>::max(); // dk recebe mais infinito

	std::vector<float> Xk = {0, 0, 0};
	std::vector<float> Xk_1 = X0;

	int iteracao = 0;
	while(dk > Erro || num_max_iteracoes == iteracao){

		for(int i = 0; i < Matriz.size(); i++){

			float soma_linha = 0;
			for(int j = 0; j < Matriz[i].size(); j++){

				if(j == i){
					soma_linha += Matriz[i][j];
				}else{
					soma_linha += Matriz[i][j] * Xk_1[j];
				}
			}
			Xk[i] = soma_linha;
		}

		iteracao++;
		std::cout << "X^" << iteracao << " = {";
		for(auto& value : Xk){
			std::cout << value << ", ";
		}
		std::cout << "}" << std::endl;

		dk = calcula_dk(Xk, Xk_1);
		std::cout << "Erro = " << dk << std::endl;
		Xk_1 = Xk;

	}

	return Xk;

}

int main(){

	std::vector<float> X0; // Vetor que contem X^(0)
	std::vector<std::vector<float>> Matriz; // Matriz com os X1, X2, X3, ..., Xn isolados
	double Erro;

	std::vector<float> Xk = {0, 0, 0};
	std::vector<float> Xk_1;

	Erro = 0.001;

	X0 = {0, 0, 0};
	Xk_1 = X0;

	Matriz = {
		{ 0.7, -0.2, -0.1},
		{-0.2, -1.6, -0.2},
		{-0.2, -0.3,  0.6},
	};


	Met_Jacobi(X0, Matriz, Erro, 10);



	return 0;
}



