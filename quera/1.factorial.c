#include<stdio.h>

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

int
main() {
    int n;

    int matched = scanf("%d", &n);

    if (matched != 1) {
        return 1;
    }

    printf("%d\n", fact(n));
}
