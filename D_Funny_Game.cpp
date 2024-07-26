#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    int n;
    vector<int> parent, Size;
 
public:
    int cc;
    int find(int v)
    {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
 
    void Union(int a, int b)
    {
        int x = find(a), y = find(b);
        if (x != y) {
            cc--;
            if (Size[x] < Size[y]) swap(x, y);
            parent[y] = x;
            Size[x] += Size[y];
        }
    }
    bool same(int u, int v)  {return (find(u) == find(v));}
    
    DSU(const int N_) {
        n = N_;
        cc = N_;
        parent = vector<int>(n + 1);        
        Size = vector<int>(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);        
    }
};
 
int main(){
    int t ; 
    cin>>t;
    while(t--){
        int n ; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }



    vector<pair<int,int> > res;
    map<pair<int,int> , bool> edges;
    for(int i=n-1;i>=1;i--){
        unordered_map<int,int> mp;
        for(int j=0;j<n;j++){
            if(mp[arr[j]%i]!=0){
                if(edges[{j+1,mp[arr[j]%i]}]==false){
                res.push_back({j+1,mp[arr[j]%i]});
                edges[{j+1,mp[arr[j]%i]}]=true;
                    break;
                }
            }
            mp[arr[j]%i]=j+1;
        }
    }

    cout<<"YES"<<endl;

    for(int i=n-2;i>=0;i--){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }


    }
}