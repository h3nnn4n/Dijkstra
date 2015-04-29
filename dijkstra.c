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

int isEmpty(int Q[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(Q[i] == 1) return 1;
    }
    return 0;
}

int smallest(int Q[], int d[], int n) {
    int small = INT_MAX, smallI, i;

    for(i = 0; i < n; i++) {
        if(d[i] < small) {
            small = d[i];
            smallI = i;
        }
    }
    Q[smallI] = -1;
}

void doDijkstra(int ** m, int n, int s) {
    int Q[n], p[n], d[n];
    initDijkstra(Q, p, d, n, s);

    while(isEmpty(Q, n) != 0) {

    }
}

int main(int argc, char * argv[]) {
    int ** m, a, b, i, n, w = 1, s;

    if (argc == 1)
        scanf("%d %d", &n, &s);
    m = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++){
        m[i] = (int*)malloc(sizeof(int) * n);
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

return 0;
}
