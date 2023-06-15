#include <iostream>
 using namespace std;
int main()
{
    int matrix[10][10],i,j,k,qu[10],stack[10],front=0,rear=0,top=-1, visited[10],n,m,v,visited1[10];
    char type;
    cout<<"Enter D for directed and U for undirected : ";
    cin>>type;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    cout<<"Enter the number of edges : ";
    cin>>m;
    cout<<"Enter the edges: "<<endl;
    for(k = 1 ; k <= m ; k++)
    {
        cin>>i>>j;
        matrix[i][j]=1;
        if(type=='u' || type=='U')
        {
            matrix[j][i]=1;
        }
    }
    //display
    cout<<"Adjacency matrix is: "<<endl;
    for(i=1 ; i <= n ; i++)
    {
        for(j = 1 ; j<=n;j++)
        {
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Adjacency list is: "<<endl;
    for(i=1;i<=n;i++)
    {
           cout<<i<<" ---> ";
           for(j=1;j<=n;j++)
           {
              if(matrix[i][j]==1)
              {
                     cout<<j<<"  ";
              }
              
           }
           cout<<endl;
    }
    //bfs
    cout<<"Enter the vertex to start: ";
    cin>>v;
    cout<<"BFS is: "<<endl;
    qu[rear++]=v;
    visited[v]=1;
    while(front!=rear)
    {
           v=qu[front++];
           cout<<v<<" --> ";
           for(j=1;j<=n;j++)
           {
                  if(matrix[v][j]==1 && visited[j]==0)
                  {
                         visited[j]=1;
                         qu[rear++]=j;
                  }
           }
    }
    //dfs
    cout<<endl;
    cout<<"Enter the vertex to start: ";
    cin>>v;
    cout<<"DFS is: "<<endl;
    stack[++top]=v;
    while(top!=-1)
    {
           v=stack[top--];
           if(visited1[v]==0)
           {
               visited1[v]=1;
               cout<<v<<" --> ";
           }
           for(j=1;j<=n;j++)
           {
                  if(matrix[v][j]==1 && visited1[j]==0)
                  {
                         stack[++top]=j;
                  }
           }
    }
    
    return 0;
}
