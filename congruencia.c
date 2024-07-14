#include <stdio.h>

// Função para calcular o calcularMDC e o coeficiente de Bézout
int calcularMdc(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int mdc = calcularMdc(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return mdc;
}

// Função para encontrar o inverso multiplicativo de a em relação a m
int calcularInverso(int a, int m) {
    int x, y;
    int d = calcularMdc(a, m, &x, &y);
    if (d != 1) {
        return -1;  // Inverso multiplicativo não existe
    } else {
        // caso x negativo
        int res = (x % m + m) % m;
        return res;
    }
}

// Função para resolver a condruência linear ax ≡ b (mod m)
void calcularCongruencia(int a, int b, int m) {
    int x, y;
    int d = calcularMdc(a, m, &x, &y);

    // Verifica se a condruência tem solução
    if (b % d != 0) {
        printf("Nenhuma solução\n");
        return;
    }

    // Reduz a, b e m pelo mdc
    a /= d;
    b /= d;
    m /= d;

    int inv = calcularInverso(a, m);
    if (inv == -1) {
        printf("Nenhuma solução\n");
    } else {
        int x0 = (inv * b) % m;
        printf("%d\n", x0);
    }
}

int main() {
    int a, b, m;
    int op = 0;
    printf("=-=-=-= OPERAÇÃO DE CONGRUÊNCIA LINEAR =-=-=-=\n");
    while (op == 0) {
        printf("Didite os valores de a, b e m:\n");
        scanf("%d %d %d", &a, &b, &m);
        calcularCongruencia(a, b, m);
        printf("Deseja encerrar a operação?\n");
        printf("(0)Não (1)Sim\n");
        scanf("%d", &op);
    }

    return 0;
}