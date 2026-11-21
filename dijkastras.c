
#include <stdio.h>
#define INF 9999

int main()
{
    int n, a[10][10], d[10], v[10]={0};
    int i, j, min, u, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter source vertex: ");
    scanf("%d",&s);

    for(i=0;i<n;i++)
        d[i]=INF;

    d[s]=0;

    for(i=0;i<n;i++)
    {
        min=INF;
        u=-1;

        for(j=0;j<n;j++)
            if(!v[j] && d[j]<min)
                min=d[j],u=j;

        if(u==-1) break;

        v[u]=1;

        for(j=0;j<n;j++)
            if(a[u][j]>0 && !v[j] &&
               d[u]+a[u][j]<d[j])
                d[j]=d[u]+a[u][j];
    }

    printf("Shortest distances:\n");
    for(i=0;i<n;i++)
        printf("%d -> %d\n",i,d[i]);

    return 0;
}
