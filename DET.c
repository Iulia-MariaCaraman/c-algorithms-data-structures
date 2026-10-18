#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//SABLON
int det(int v[], int st, int dr) {

	if (st == dr) {
		//in functie de cerinta afisezi de ex return v[st] sau st sau 0...;
	}
	int mij = (st + dr) / 2;
	int stanga=det(v, st, mij);
	int dreapta = det(v, mij + 1, dr);
	//unim rez din stanga cu cel din drepta in fct de cerinta (return stanga+dreapta pt suma ..)

}
int main() {
	int v[100];
	int n;
	printf("Introduceti nr de elemente (n): ");
	scanf("%d", &n);
	printf("dati cele %d elemente ale vectorului:\n ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int rez = det(v, 0, n - 1);
	printf("Rezultatul alg este: %d\n", rez);
	return 0;
}

//ultima aparitie a unui vector
int det(int v[], int st, int dr, int val) {
	if (st == dr) {
		if (v[st] = val) {
			return st;
		}
		return -1;
	}

	int mij = (st + dr) / 2;
	int stanga = det(v, st, mij, val);
	int dreapta = det(v, mij + 1, dr, val);
	//ultima aparitie de obicei ramane in dreapta si daca e dif de -1 adica exista returnam dreapta
	if (dreapta != -1) {
		return dreapta;
	}
	return stanga;
}
// prima aparitie if(stanga!=1){
//return stanga;
//}
//return dreapta;
//}

//numaram de cate ori apare o valoare
int det(int v[], int st, int dr, int val) {
	if (st == dr) {
		if (v[st] == val) {     //daca cere sa fie toate poz v[st]>0 return 1 altfel return 0;
			return 1;
		}
		return 0;
	}
	int mij = (st + dr) / 2;
	int stanga = det(v, st, mij, val);
	int dreapta = det(v, mij + 1, dr, val);
	return stanga = dreapta;
}

//suma elementelor pare
int det(int v[], int st, int dr) {
	if (st == dr) {
		if (v[st] % 2 == 0) {
			return v[st];     //daca cere sa fie min
		}
		return 0;
	}
	int mij = (st + dr) / 2;
	int stanga = det(v, st, mij);
	int dreapta = det(v, mij + 1, dr);     //if stanga<dreapta return stanga el return dreapta;
	return stanga + dreapta;
}