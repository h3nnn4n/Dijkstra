#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void initDijkstra(int Q[], int p[], int d[], int n, int s) {
    int i;

    for(i = 0; i < n; i++) {
        d[i] = INT_MAX;
        p[i] = -1;
        Q[i] = 1;
    }

    d[s] = 0;
}

int notEmpty(int Q[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(Q[i] == 1) return 1;
    }
    return 0;
}

int smallest(int Q[], int d[], int n) {
    int small = INT_MAX, smallI, i;

    for(i = 0; i < n; i++) {
        if(d[i] < small && Q[i] == 1) {
            small = d[i];
            smallI = i;
        }
    }
    Q[smallI] = -1;
    return smallI;
}

void doDijkstra(int ** m, int n, int s) {
    int Q[n], p[n], d[n], v, u, alt;
    initDijkstra(Q, p, d, n, s);
    int i = n;
    while(i--) {  // O(|V|)
        u = smallest(Q, d, n);  // melhor caso O(1) e pior O(|V|)
        for(v = 0; v < n; v++) {
            if(Q[v] != -1 && u != v && m[u][v] != -1) {
                alt = d[u] + m[u][v];
                if(alt < d[v]) {
                    d[v] = alt;
                    p[v] = u;
                }
            }
        }
    }

    i = n - 1;
    do{
        printf("%d <- ", i);
        i  = p[i];
    }while(i > 0);
    printf("%d\n\n", i);

    for(v = 0; v < n; v++) {
        printf("No: %d, Relaxamento:%d, No anterior:%d\n", v, d[v], p[v]);
    }
}

int main(int argc, char * argv[]) {
    int ** m, a, b, i, j, n, w = 1, s;

    if (argc == 1)
        scanf("%d %d", &n, &s);
    m = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++){
        m[i] = (int*)malloc(sizeof(int) * n);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            m[i][j] = -1;
        }
    }
    if (argc == 1){
        while(w > 0){
            scanf("%d %d %d", &a, &b, &w);
            if(a < n && b < n && w > 0){
                m[a][b] = w;
            }
        }
    }
    else
        return 1;

    doDijkstra(m, n, s);

    return 0;
}
