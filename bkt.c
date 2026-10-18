#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int valid(int k,int v[]) {
	int i;
	for (i = 0; i < k - 1; i++) {
		if (v[i] == v[k]) {
			return 0;
		}
		//alte conditii tot aici daca se da ceva din cerinta
		return 1;
	}
}
void afisare(int n, int v[]) {
	for (int i = 0; i < n; i++){

		printf("%d", v[i]);
	}
	printf("\n");
}
void bkt(int k, int n, int v[]) {
	if (k > n) {
		afisare(n, v);
	}
	else {
		for (int i = 0; i < n; i++) {
			v[k] = i;
			if (valid(k, v) == 1) {
				bkt(k + 1, n, v);
			}

		}
	}
}
int main() {
	int n; int v[20];
	printf("Introduceti n:\n ");
	scanf("%d", &n);
	printf("Introduceti elementele vectorului:\n ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);

	}
	bkt(1, n, v);
	return 0;

}

//sa nu fie consecutive la permutari
void valid(int k, int v[]) {
	int i;
	for (i = 0; i < k - 1; i++) {
		if (v[i] == v[k]) {
			return 0;
		}
		if(k>1){
			if (abs(v[k] - v[k - 1] == 1)) {
				return 0;
			}
		}
		return 1;
	}
}
void afisare(int n, int v[]) {
	for (int i = 0; i < n; i++) {
		printf("%d", v[i]);
	}
	printf("\n");
}

void bkt(int k, int n, int v[]) {
	if (k > n) {
		afisare(n, v);
	} else {
		for (int i = 0; i < n; i++) {
			v[k] = i;
			if (valid(k, v) == 1) {
				bkt(k + 1, n, v);
			}
		}
	}
}


int main() {
	int n;
	int v[20];
	printf("Introduceti nr de elemente n:\n");
	scanf("%d", &n);
	//printf introduceti vectorul...
	bkt(1, n, v);
	return 0;
}