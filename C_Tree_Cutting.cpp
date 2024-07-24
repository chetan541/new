#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
bool dfs(vector<int> arr[], int app[], int node,int m,int k,int par,int &cnt) {
   app[node]=1;
   for(auto it:arr[node]){
     if(it!=par){
        dfs(arr,app,it,m,k,node,cnt);
        app[node]+=app[it];
     }
   }
//    cout<<app[node]<<" "<<node<<" "<<cnt<<endl;
   if(app[node]>=m && cnt<k && par!=0 ){
    cnt++;
    app[node]=0;
   }
   if(cnt==k && app[node]>=m)return true;
   else return false;
   }



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr[n + 1];
        int app[n + 1] = {0}; // Initialize app array with zeros
        for (int i = 0; i < n - 1; i++) {
            int c, l;
            cin >> c >> l;
            arr[c].push_back(l);
            arr[l].push_back(c);
           
        }
        int x = 1, z = n;
        int cnt=0;
        while (z - x > 1) {
            int m = (x + z) / 2;
            memset(app,0,sizeof(app));
            cnt=0;
            if (dfs(arr,app,1,m,k,0,cnt))
                x = m;
            else
                z = m - 1;
        }
        cnt=0;
        if (dfs(arr,app,1,z,k,0,cnt))
            cout << z << endl;
        else
            cout << x << endl;
    }
    return 0;
}
