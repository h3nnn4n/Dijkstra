#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char * argv[]) {
    int ** m, a, b, i, n, w;

    if (argc == 1)
        scanf("%d", &n);
    m = (int**)malloc(sizeof(int*) * n);
    for(i=0; i<n; i++){
        m[i] = (int*)malloc(sizeof(int) * n);
    }
    if (argc == 1){
        w = 1;
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
