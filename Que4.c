#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Graph {
    int V;
    unordered_map<T, vector<pair<T,int>>> adj;
public:
    Graph(int n){
       V=n;
    }
    void addEdge(T u, T v, int w, bool directed) {
        adj[u].push_back({v,w});
        if (!directed) adj[v].push_back({u,w});
    }

    void printAdjList() {
        for (auto p : adj) {
            cout << p.first << " -> ";
            for (auto j : p.second) {
                    cout << "[ "<<j.first<<","<<j.second<<" ]";
            }
            cout << '\n';
        }
            cout << '\n';
    }
    
    void dijkstra(T source){
        int max=99999;
        set<pair<int,T>> s; //make set
        map<T,int> dist; //make dist
        for(auto it: adj){
            dist[it.first]=max; //initialise to max distance
        }
        // to start insert source in set and dist
        dist[source]=0;
        s.insert({0,source});  
        while(!s.empty()){
            auto min=*s.begin(); // find min and remove
            s.erase(min);
            //traverse for neighbours of node found
            for(auto p: adj[min.second]){
                if( (min.first+ p.second) < dist[p.first]){
                    auto record = s.find({dist[p.first],p.first});
                    if(record !=s.end()){ // if such record exists del
                        s.erase(record);
                    }
                    dist[p.first]=min.first+ p.second; // update dist if smaller
                    s.insert({dist[p.first] , p.first});
                    
                }
            }
        }
        for(auto it: dist){ //print shortest distance 
            cout<<it.second<<" ";
        }
        
    }
   
};

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    Graph<int> g(n);

    bool dir;
    cout << "Enter 1 for directed and 0 for undirected graph: ";
    cin >> dir;

    int u, v , w;
    for (int i = 0; i < m; ++i) {
        cout << "Enter the first and second vertice and the weight of edge: ";
        cin >> u >> v>>w;
        g.addEdge(u, v,w, dir);
    }

    cout << "Adjacency List:\n";
    g.printAdjList();

    int s;
    cout<<"Enter source node: ";
    cin>>s;
    g.dijkstra(s);
    cout<<"\n";
   
    return 0;
}
