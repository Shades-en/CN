#include <stdio.h>

void dijikstras();

int cost[20][20], n, i,j, min, source, distance[20], visited[20], u, w;
void main(){
    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix");
    for(int i=1; i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source\n");
    scanf("%d", &source);

    dijikstras();

    for(int i=1;i<=n;i++){
        if(i!=source){
            printf("from %d to %d cost is %d\n", source, i, distance[i]);
        }
    }
}

void dijikstras(){
    for(int i=1;i<=n;i++){
        visited[i]=0;
        distance[i] = cost[source][i];
    }

    distance[source]=0;
    visited[source]=1;

    for(int i=2; i<=n;i++){
        min = 999;
        for(int j=1;j<=n;j++){
            if(!visited[j]){
                if(min>distance[j]){
                    min = distance[j];
                    u = j;
                }
            }
        }

        visited[u]=1;

        for(w=1;w<=n;w++){
            if(cost[u][w]!=999 && !visited[w]){
                if(distance[w]>distance[u]+cost[u][w]){
                    distance[w] = distance[u]+cost[u][w];
                }
            }
        }
    }
}

/*
0 10 999 30 100
10 0 50 999 999
999 50 0 20 10
30 999 20 0 60
100 999 10 60 0
*/