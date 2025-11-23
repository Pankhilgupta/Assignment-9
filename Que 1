#include <iostream>
using namespace std;

class Graph {
    public:
    int adj[100][100];   
    int visited[100];  
    int n; 

    Graph(int size) {
        n = size;

        for(int i=0; i<n; i++){
            visited[i] = 0;
            for(int j=0; j<n; j++){
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, bool direction){
        adj[u][v] = 1;
        if(direction == 0){
            adj[v][u] = 1;
        }
    }

    void printAdj(){
        cout << "Adjacency Matrix:"<<endl;
        for(int i=0; i<n; i++){
            cout << i << " -> ";
            for(int j=0; j<n; j++){
                if(adj[i][j] == 1)
                    cout << j << " ";
            }
            cout << endl;
        }
    }

    void BFS(){
        int queue[100], front = 0, rear = 0;

        for(int i=0; i<n; i++) visited[i] = 0;

        for(int start=0; start<n; start++){
            if(visited[start] == 0){
                queue[rear++] = start;
                visited[start] = 1;

                while(front < rear){
                    int i = queue[front++];
                    cout << i << " ";

                    for(int j=0; j<n; j++){
                        if(adj[i][j] == 1 && visited[j] == 0){
                            queue[rear++] = j;
                            visited[j] = 1;
                        }
                    }
                }
            }
        }
    }

    void DFS_helper(int node){
        cout << node << " ";
        visited[node] = 1;

        for(int j=0; j<n; j++){
            if(adj[node][j] == 1 && visited[j] == 0){
                DFS_helper(j);
            }
        }
    }

    void DFS(){
        
        for(int i=0; i<n; i++) visited[i] = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                DFS_helper(i);
            }
        }
    }
};

int main() {

    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    bool direction;
    cout << "Enter 1 for directed and 0 for undirected graph: ";
    cin >> direction;

    Graph g(n);

    for(int i=0; i<m; i++){
        int u, v;
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v, direction);
    }

    g.printAdj();
    cout<<"BFS: ";
    g.BFS();
    cout<<endl;
    cout<<"DFS: ";
    g.DFS();
    cout<<endl;
    return 0;
}
