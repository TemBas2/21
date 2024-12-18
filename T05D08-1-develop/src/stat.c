#include <math.h>
#include <stdio.h>

#define NMAX 10

int input(int *a, int *n) {
    char pop;
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 0;
    }
    for (int i = 0; i < *n; i++) {
        if (scanf("%d%c", &a[i], &pop) != 2 || (i == *n - 1 && pop != '\n')) {
            return 0;
        }
    }
    return 1;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    if (n == 0) {
        return 0;
    }
    int max_v = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_v) {
            max_v = a[i];
        }
    }
    return max_v;
}

int min(int *a, int n) {
    if (n == 0) {
        return 0;
    }
    int min_v = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_v) {
            min_v = a[i];
        }
    }
    return min_v;
}

double mean(int *a, int n) {
    if (n == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    if (n == 0) {
        return 0;
    }
    double mean_v = mean(a, n);
    double sum_sq_diff = 0;
    for (int i = 0; i < n; i++) {
        sum_sq_diff += pow(a[i] - mean_v, 2);
    }
    return sum_sq_diff / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f\n", max_v, min_v, mean_v, variance_v);
}

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        printf("n/a\n");
        return 1;
    }
    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

    return 0;
}
