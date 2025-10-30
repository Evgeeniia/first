#include <stdio.h>

#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) != 1) {
        printf("n/a");
        return 0;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 0 || *n > NMAX) {
        return 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            return 0;
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    return 1;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max_v;
    for (int i = 0; i < n; i++) {
        if (a[i] > max_v) {
            max_v = a[i];
        }
    }
    return max_v;
}

int min(int *a, int n) {
    int min_v;
    for (int i = 0; i < n; i++) {
        if (a[i] < min_v) {
            min_v = a[i];
        }
    }
    return min_v;
}

double mean(int *a, int n) {
    double mean_v = 0;
    for (int i = 0; i < n; i++) {
        mean_v += a[i];
    }
    return mean_v / n;
}

double variance(int *a, int n) {
    double variance_v = 0;
    double m = mean(a, n);
    for (int i = 0; i < n; i++) {
        variance_v += (a[i] - m) * (a[i] - m);
    }
    return variance_v / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}
