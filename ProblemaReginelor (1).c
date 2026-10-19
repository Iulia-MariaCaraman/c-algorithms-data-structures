//Se cere să se așeze 8/n regine pe o tablă de șah (8x8/nxn) astfel încît să nu existe
//două regine care să se atace.Trebuie găsite toate posibilitățile de așezare a celor 8 / n
//regine pe tabla de șah.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int valid(int k, int st[])
{
    int i, ok = 1; 
        for (i = 0; i < k; i++)
            if ((st[i] == st[k]) || (abs(i - k) == abs(st[i] - st[k]))) ok = 0; //verificam daca reginele sunt pozitionate pe aceeasi col si daca se pot atinge pe diagonala
                return ok; 
}
void afisare(int n, int st[])
{
    int i; 
        for (i = 0; i < n; i++)
            printf("st[%d]=%d ", i, st[i]); 
            printf("\n");
}
void backtracking(int n)
{
    int st[20], k, nrsol = 0; 
    for (int i = 0; i < n; i++) 
        st[i] = 0;
    k = 0; //plecam de la randul 0
    while (k >= 0)
    {
        if (st[k] < n)
        {
            st[k] = st[k] + 1; //trecem la urm coloana cat mai avem randuri
            if (valid(k, st)) //verif daca reginele nu iti pot atinge pozitia
            {
                if (k == n - 1) //daca ajungem la ultima regina inseamna ca sol este buna
                {
                    nrsol++;
                    printf("Solutia cu nr: %d \n", nrsol); 
                        afisare(n, st); 
                }
                else
                {
                    k++;
                    st[k] = 0; //mergem la randul urmator si resetam coloana
                }
            }
        }
        else
        {
            st[k] = 0;
            k--; //resetam randul inainte de a urca si revenim la randul anterior
        }
    }
}
int main()
{
    int n;
    printf("n=");
        scanf("%d", &n); 
        backtracking(n);
    return 0;
}