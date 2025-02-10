#pragma once

#include "SolucionParcial.h" 

class Polinomio{
 	private:
 		int n; 
		float *coeficientes; 
		float obtenerAleatorioNormalEstandar();
		float obtenerRaizRecursivo(SolucionParcial solucionParcialInicial);

	public:
		Polinomio(int n, float *coeficientes);
		float evaluar (float x);
		float obtenerRaiz();
		~Polinomio();
};

