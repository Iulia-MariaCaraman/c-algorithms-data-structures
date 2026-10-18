#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//citire matrice dintr un fisier text
void citire(int *nv, int *nm, int a[20][20]) {
	FILE* f;
	int x, y;
	f=fopen("fisier.txt", "r");
	if (f != NULL) {
		fscanf(f, "%d", nv);
		fscanf(f, "%d", nm);
		for (int i = 0; i < *nv; i++) {
			for (int j = 0; j < *nv; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < *nm; i++){
			fscanf(f, "%d", &x);
		fscanf(f, "%d", &y);
		a[x - 1][y - 1] = 1;
		a[y - 1][x - 1] = 1;
	}
			fclose(f);
		}

	else
		printf("\nFisierul nu poate fi deschis");
}
//afisare matrice dintr un fisiser
void afisare(int a[][20], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}

}
//gradul unui nod
void grad_nod(int n, int nod, int a[20][20]) {
	int grad = 0;
	for (int i = 0; i < n; i++) {
		if (a[nod - 1][i] == 1) {
			grad++;
		}
	}
	return grad;
}
//grad exterior la noduri
void gradex(int n, int a[20][20]) {
	for (int i = 0; i < n; i++) {     //pt grad interior e la fel doar ca avem for (j.... ) primu dp for(i......)
		int grad = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1)
				grad++;
		}
		printf("Nr gradului exterior al nodului %d este %d:\n ", i + 1, grad);
	}
}
//verif daca graf e complet daca are 1 peste tot si vf dif

int complet(int a[20][20], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && a[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

//bfs parcurgere in latime
void bfs(int a[20][20], int n, int start) {
	int coada[20];
	int vizat[20] = { 0 };
	int prim = 1;
	int ultim = 1;
	int nod_curent;
	coada[ultim] = start;
	vizat[start] = 1;
	while (prim <= ultim) {
		nod_curent = coada[prim];
		prim++;
		printf("%d", nod_curent);
		for (int i = 1; i <= n; i++) {
			if (a[nod_curent][i] == 1 && vizat[i] == 0) {
				ultim++;
				coada[ultim] = i;
				vizat[i] = 1;
			}
		}
	}
	printf("\n");
}

//dfs parcurgere in lungime fara coada
void dfs(int start, int a[20][20], int n) {
	int ultim = 1;
	int vizat[20] = { 0 };
	int stiva[20];
	int nod_curent;
	stiva[ultim] = start;
	vizat[start] = 1;
	while (ultim >= 1) {
		nod_curent = stiva[ultim];
		ultim--;
		printf("%d", nod_curent);
		for (int i = 1; i <= n; i++) {
			if (a[nod_curent][i] == 1 && vizat[i] == 0)
				ultim++;
			stiva[ultim] = i;
			vizat[i] = 1;


		}
	}
}
printf("\n");
}

//nr componente conexe
void componente_conexe( int a[20][20], int n){
	int vizat[20] = {0};
	int nr = 0;
	for (int i = 0; i < n; i++) {
		if (vizat[i] == 0) { //daca nu l am vizat prin dfs inseamna ca e o noua insula
			nr++;
			dfs(i, a, n); //mergem mai departe in cautarea componentelor nevizate
		}
	}
	printf("nr de componente conexe este: %d\n", nr);
}

int main() {
	int nv;
	int nm;
	int a[20][20];
	citire(&nv, &nm, a);
	printf("Matricea de adiacenta (cu %d noduri si %d muchii): ", nv, nm);
	afisare(a, nv);
	return 0;
	
}