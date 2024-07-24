#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

bool isvalid(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m)return true;
    else return false;
}


int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    vector<pair<int,int>> moves={{1,0},{-1,0},{0,1},{0,-1}};
    while(t--){
        int n,m;cin>>n>>m;
        char arr[n][m];
        int vis[n][m];
        int cnt=0;
        memset(vis,0,sizeof(vis));
        REP(i,0,n-1){
            REP(j,0,m-1)cin>>arr[i][j];
        }
        int flag=1;
        REP(i,0,n-1){
            REP(j,0,m-1){
                if(arr[i][j]=='#')vis[i][j]=1;
                if(arr[i][j]=='B'){
                    for(auto it:moves){
                        int x=it.first,y=it.second;
                        if(isvalid(i+x,j+y,n,m) && arr[i+x][j+y]=='.'){arr[i+x][j+y]='#';vis[i+x][j+y]=1;}
                        if(isvalid(i+x,j+y,n,m) && arr[i+x][j+y]=='G'){flag=0;}
                    }
                }
                if(arr[i][j]=='G')cnt++;
            }
        }
        // cout<<arr[n-1][m-1]<<endl;
        if(flag==1 && arr[n-1][m-1]!='#'){
            int tmp=0;
          queue<pair<int,int>> q;
          q.push({n-1,m-1});
          vis[n-1][m-1]=1;
          while(!q.empty()){
            pair<int,int> front;
            front=q.front();
            int i=front.first,j=front.second;
            q.pop();
            for(auto it:moves){
                        int x=it.first,y=it.second;
                        // if(isvalid(i+x,j+y,n,m))cout<<arr[i+x][j+y]<<" "<<vis[i+x][j+y]<<endl;
                        if(isvalid(i+x,j+y,n,m) && arr[i+x][j+y]=='G' && vis[i+x][j+y]==0){vis[i+x][j+y]=1;q.push({i+x,j+y});tmp++;}
                        if(isvalid(i+x,j+y,n,m) && arr[i+x][j+y]=='.' && vis[i+x][j+y]==0){vis[i+x][j+y]=1;q.push({i+x,j+y});}
                    }
          }
         
          if(tmp==cnt)cout<<"Yes"<<endl;
          else cout<<"No"<<endl;


        }
        else {
            if(cnt==0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            }
        
        
    }
}