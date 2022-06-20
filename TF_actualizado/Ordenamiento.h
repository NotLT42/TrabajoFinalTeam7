#ifndef __ORDENAMIENTOS_HPP__ //Esta es una macro, sirve para crear una biblioteca, ya que son las primeras en ser leidas por el compilador
#define	__ORDENAMIENTOS_HPP__

#include <vector>
#define endl "\n";

using namespace std;

template <class G>
class Ordenamiento {

private:
	vector<G> valores;
	void swap(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

public:
	Ordenamiento(vector<G>& v) {
		valores = v;
	}

	void intercambio() {
		for (int i = 0; i < valores.size() - 1; ++i) {
			for (int j = i + 1; j < valores.size(); ++j) {
				if (valores[i] > valores[j]) {
					swap(&valores[i], &valores[j]);
				}
			}
		}
	}

	void burbuja() {
		for (size_t i = 0; i < valores.size() - 1; i++) {
			bool ordenado = true;
			for (size_t j = 0; j < valores.size() - 1 - i; ++j) {
				if (valores[j] > valores[j + 1]) {
					ordenado = false;
					swap(&valores[i], &valores[j]);
				}
				if (ordenado) break;
			}
		}
	}

	void insercion() {
		for (size_t i = 1; i < valores.size(); i++) {
			G auxValor = valores[i];
			size_t auxPos = i;
			while (valores[auxPos] > 0 && valores[auxPos - 1] > auxValor) {
				//valores[auxPos--] = valores[]
			}
		}
	}

	void seleccion() {
		for (int i = 0; i < valores.size() - 1; i++)
		{
			size_t posmenor = i;//asumo que el primero es el menor, hasta que encuentre lo contrario
			for (int j = 0; j < valores.size(); j++)
			{
				if (valores[j] < valores[posmenor])
					posmenor = j;
			}
			if (posmenor != i) {
				swap(valores[i], valores[i--]);
			}
		}
	}
	void imprimir() {
		/*for (int i = 0; i < valores.size(); i++)
		{
			std::cout << "- " << valores.at() << endl;
		}*/
	}
};

#endif