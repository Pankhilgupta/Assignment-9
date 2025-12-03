#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    int V;
    unordered_map<T, vector<pair<T ,int>>> adj;
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
    vector<pair<pair<T,T>,int>> prims(int source , int n){
    vector<int> key(n);
    vector<T> parent(n);
    vector<bool> mst(n);

    for(int i = 0; i<n ;i++){
        key[i]=99999;
        parent[i]=-1;
        mst[i]=false;
    }

    parent[source]=-1;
    key[source]=0;

    int i;
    for(i=0;i<n;i++){
        int mini=9999999;
        T u;

        for(int v=0 ;v<n ;v++){
            if(mst[v] == false && key[v] < mini){
                u=v;
                mini=key[v];
            }
        }

        mst[u]=true;

        for(auto it: adj[u]){
            T node = it.first;
            int weight = it.second;

            if(mst[node]==false && key[node] > weight ){
                key[node]=weight;
                parent[node]=u;
            }
        }
    }

    vector<pair<pair<T,T>,int>> ans;
    for (int v = 0; v < n; v++) {
        if (parent[v] != -1) {
            ans.push_back({{parent[v], v}, key[v]});
        }
    }

    return ans;
}

    void makeset(vector<int> &parent, int n){
    parent.resize(n);
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
}

void edges_list(vector<tuple<int, T, T>> &edges){
    for(auto &p : adj){
        T u = p.first;
        for(auto &nbr : p.second){
            T v = nbr.first;
            int w = nbr.second;
            edges.push_back({w, u, v});
        }
    }
    sort(edges.begin(), edges.end());
}

int findparent(vector<int> &parent , int node){
    if(parent[node] == node) return node;
    return parent[node] = findparent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findparent(parent, u);
    v = findparent(parent, v);

    if (u == v) return;

    if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else if(rank[v] > rank[u]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

void kruskal(int n){
    vector<int> parent;
    vector<int> rank(n, 0);
    makeset(parent, n);

    vector<tuple<int, T, T>> edges;
    edges_list(edges);

    int minweight = 0;

    for(auto &it : edges){
        int w = get<0>(it);
        int u = get<1>(it);
        int v = get<2>(it);

        int pu = findparent(parent, u);
        int pv = findparent(parent, v);

        if(pu != pv){
            minweight += w;
            unionSet(pu, pv, parent, rank);
        }
    }

    cout << "MST Weight = " << minweight << endl;
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
    vector<int>mst=g.prims(0,n);
    for(auto it: mst){
        cout<<it.first<<","<<it.second.first<<","<<it.second.second;
        cout<<endl;
    }
    g.kruskal(n);

    return 0;
}
