#include <stdio.h>

int bellman(int g[40][40], int v, int E, int edge[40][2]);

void main(){
    int g[40][40], edge[40][2], i, j, k=0, v;

    printf("enter the number of vertices\n");
    scanf("%d", &v);

    printf("Enter the graph\n");
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            scanf("%d", &g[i][j]);
            if(g[i][j]!=0){
                edge[k][0]=i;
                edge[k++][1]=j;
            }
        }
    }

    if(bellman(g, v, k, edge)){
        printf("No negative weight cycle exist");
    }
    else{
        printf("Negative weight cycle exists");
    }
}

int bellman(int g[40][40], int V, int E, int edge[40][2]){
    int distance[40], parent[40], flag=1, i, k, j,u, v, source;
    
    for(int i=0; i<V; i++){
        distance[i]=1000;
        parent[i]=-1;
    }

    printf("Enter the source\n");
    scanf("%d", &source);
    distance[source-1]=0;

    for(int i=0;i<V-1;i++){
        for(int j=0; j<E; j++){
            u = edge[j][0];
            v = edge[j][1];
            if(distance[v]>distance[u]+g[u][v]){
                distance[v] = distance[u]+g[u][v];
                parent[v] = u;
            }
                
        }
    }

    for(int j=0; j<E; j++){
        u = edge[j][0];
        v = edge[j][1];
        if(distance[v]>distance[u]+g[u][v])
            flag = 0;
    }

    if(flag){
        for(int i=0;i<V;i++){
            printf("Vertex->%d cost ->%d parent ->%d\n", i+1, distance[i], parent[i]+1);
        }
    }

    return flag;
}

/*
0 6 4 5 0 0
0 0 0 0 -1 0
0 -2 0 0 3 0
0 0 -2 0 0 -1
0 0 0 0 0 3
0 0 0 0 0 0
*/
