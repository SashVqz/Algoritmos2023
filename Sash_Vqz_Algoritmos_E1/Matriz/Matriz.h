#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 	private:
  		double **matriz;
  		int n_filas;
  		int n_columnas;
	
	public:

// constructor Default 	
	Matriz();

// constructor por parametros
	Matriz(int n_filas, int n_columnas);

// constructor copia
	Matriz(const Matriz& copia);

// Destructor
    ~Matriz();

/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz con el resultado
	Parámetro: la matriz que se va a asignar
	Retorno: una nueva matriz con la matriz pasada como parámetro.
	Precondicion: Ninguno
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(n_filas*n_columnas)
*/
	Matriz& operator=(const Matriz &m);

/* Suma de matrices
	Parámetro: la matriz que se le suma (b) // (a) es matriz que realiza la llamada al operador (+)
	Retorno: una nueva matriz con la matriz pasada como parámetro.
	Precondicion: a.n_filas == b.n_filas y a.n_columnas == b.n_columnas
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(n_filas*n_columnas)
*/
	Matriz operator+(const Matriz &m);

/* Resta de matrices
	Parámetro: la matriz que se le resta (b) // (a) es matriz que realiza la llamada al operador (-)
	Retorno: una nueva matriz con la matriz pasada como parámetro.
	Precondicion: a.n_filas == b.n_filas y a.n_columnas == b.n_columnas
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(n_filas*n_columnas)
*/
	Matriz operator-(const Matriz &m);

/* Producto de matrices
	Parámetro: la matriz que se le suma (b) // (a) es matriz que realiza la llamada al operador (x)
	Retorno: una nueva matriz con la matriz pasada como parámetro.
	Precondicion: a.n_columnas == b.n_filas
	Complejidad Temporal: O((a.n_filas*b.n_columnas)*a.n_columnas)
	Complejidad Espacial: O((a.n_filas*b.n_columnas)*a.n_columnas)
*/
	Matriz operator*(const Matriz &m);

/* Producto escalar
	Parámetro: double que multiplica a la matriz // (a) es matriz que realiza la llamada al operador (*)
	Retorno: una nueva matriz con la matriz pasada como parámetro.
	Precondicion: Ninguno
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(n_filas*n_columnas)
*/
	Matriz operator*(const double &scalar);

/* Calcular la matriz traspuesta
	Parámetro: Ninguno
	Retorno: una nueva matriz con la matriz pasada como parámetro.
	Precondicion: Ninguno
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(n_filas*n_columnas)
*/
	Matriz calcularTraspuesta();
	
/* Realizar la prueba de que la matriz es simetrica
	Parámetro: Ninguno
	Retorno: booleano
	Precondicion: Ninguno
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(n_filas*n_columnas)
*/
	bool esSimetrica();

/* Calcular el maximo/minimo de la matriz (metodo de la burbuja --> O(n^2))
	Parámetro: Ninguno
	Retorno: double 
	Precondicion: Ninguno
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(n_filas*n_columnas)
*/
	double obtenerMaximo();
	double obtenerMinimo();

/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
	Parámetro: Ninguno
    Retorno: Ninguno
    Precondicion: La matriz no debe estar vacía

	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(1)
*/
  
	void rellenarManual();

/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	Parámetro: semilla que se utiliza para el generador aleatorio
	Retorno: Ninguno
	Precondicion: La matriz no debe estar vacía
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(1)
*/

	void rellenarAleatorio(long seed);

/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	Parámetro: Ninguno
	Retorno: Ninguno
	Precondicion: La matriz no debe estar vacía
	Complejidad Temporal: O(n_filas*n_columnas)
	Complejidad Espacial: O(1)
*/
	void mostrarMatriz();
};

#endif // MATRIZ_H
