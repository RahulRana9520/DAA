#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<pair<int,pair<int,int>>> viii;

// Disjoint Set - Find with path compression
int Find(int x, int parent[]) {
    if (parent[x] < 0)
        return x;
    return parent[x] = Find(parent[x], parent);
}

// Disjoint Set - Union by Weight (or size)
void UnionByWeight(int x, int y, int parent[]) {
    int rootX = Find(x, parent);
    int rootY = Find(y, parent);

    if (rootX == rootY) return;

    // Union by size (more negative = larger tree)
    if (parent[rootX] < parent[rootY]) {
        parent[rootX] += parent[rootY]; // update size
        parent[rootY] = rootX;
    } else {
        parent[rootY] += parent[rootX]; // update size
        parent[rootX] = rootY;
    }
}

viii kruskals(viii g, int V){
    viii res;
    int s,d,w;
    int parent[V];
    for(int i=0;i<V;i++){
        parent[i]=-1;
    }
    sort(g.begin(),g.end());
    int E=g.size();
    for(int i=0;i<E;i++){
        s=g[i].second.first;
        d=g[i].second.second;
        w=g[i].first;

        if(Find(s,parent)!=Find(d,parent)){
            res.push_back(g[i]);
            UnionByWeight(s,d,parent);
        }
    }
    return res;
}

int main(){
    viii g,res;
    int V,E,s,d,w;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        cin>>s>>d>>w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }
    res=kruskals(g,V);
    int sum=0;
    for(int i=0;i<res.size();i++){
        int w=res[i].first;
        cout<<res[i].second.first<<" "<<res[i].second.second<<endl;
        sum+=w;
    }
    cout<<"Sum of weight ="<<sum<<endl;
}
