#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortare(int* pv, int n) {
	int aux;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (pv[i] > pv[j]) {
				aux = pv[i];
				pv[i] = pv[j];
				pv[j] = aux;
			}
		}
	}
}

void greedy(int* pv, int* sol, int* m, int n) {
	int sum = 0;
	*m = 0;
	sortare(pv, n);
	for (int i = 0; i < n; i++) {
		if (sum + pv[i] <= 30) {     // daca e produs <=40 atunci int produs=1 .. produs*pv[i]<=40... produs=produs*pv[i]
			sol[*m] = pv[i];
			sum = sum + pv[i];
			(*m)++;
		}
	}
}

int main() {
	int n = 6;
	int pv[] = { 12, 5, 30, 7, 3, 20 };
	int m = 0;
	int sol[100];
	greedy(pv, sol, &m, n);

	printf("Submultimea este: ");
	for (int i = 0; i < m; i++) {
		printf("%d ", sol[i]);
	}
	printf("\n");
	printf("nr de elemente: %d\n", m);
	return 0;
}




