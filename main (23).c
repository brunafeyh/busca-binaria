#include <stdio.h>

int busca_binaria_normal(int vet[], int n, int x) {
    int e, m, d;
    e = -1; d = n;
    while(e < d-1) {
        m = (e+d)/2;
        printf("%d ", d-m-1);
        if (vet[m] < x) e = m;
        else d = m;
    }
    printf("\n");
    return d;
}

int busca_binaria_aux(int vet[], int e, int d, int x) {
    if(e == d-1) return d;
    else {
        int m = (e+d)/2;
        if(vet[m]< x) return busca_binaria_aux(vet,m,d,x);
        else return busca_binaria_aux(vet,e,m,x);
    }
}

int busca_binaria_rec(int vet[], int n, int x) {
    return busca_binaria_aux(vet,-1,n,x);
}

int busca_binaria_menos1(int vet[], int n, int x){
    int e, d, m;
    e = 0;
    d = n-1;
    
    while (e <= d) {
        m = (e + d) / 2;
        if (vet[m] == x) return m;
        else if (vet[m] < x) {
          e = m + 1;
        } else {
          d = m - 1;
        }
  }
  return -1;
}

int busca_binaria_recursiva(int vet[], int e, int d, int x) {
    if (e > d) {
        return -1;
    }

    int m = (e+d) / 2;

    if (vet[m] == x) return m;
    else if (vet[m] < x) return busca_binaria_recursiva(vet, m + 1, d, x);
    else return busca_binaria_recursiva(vet, e, m - 1, x);
    
}

int busca_binaria_rec2(int vet[], int n, int x) {
    return busca_binaria_recursiva(vet,0,n-1,x);
}


int main()
{
    int vetor[10] = {0, 1, 2, 3, 5, 6, 7, 8, 10, 13};
    
    printf("O elemento está no índice: %d\n", busca_binaria_normal(vetor, 10, 4));
    printf("O elemento está no índice: %d\n", busca_binaria_rec(vetor, 10, 4));
    printf("O elemento está no índice: %d\n", busca_binaria_menos1(vetor, 10, 4));
    printf("O elemento está no índice: %d", busca_binaria_rec2(vetor, 10, 4));

    return 0;
}



