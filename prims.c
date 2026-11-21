
#include <stdio.h>
#define INF 9999

int main()
{
    int a[10][10], visited[10]={0};
    int n, i, j, u, v, min, cost=0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    visited[0]=1;

    printf("Minimum Spanning Tree:\n");

    for(i=0;i<n-1;i++)
    {
        min=INF;

        for(j=0;j<n;j++)
            if(visited[j])
                for(int k=0;k<n;k++)
                    if(!visited[k] && a[j][k]>0 &&
                       a[j][k]<min)
                    {
                        min=a[j][k];
                        u=j;
                        v=k;
                    }

        visited[v]=1;
        cost+=min;

        printf("%d - %d : %d\n",u,v,min);
    }

    printf("Minimum cost = %d",cost);

    return 0;
}
