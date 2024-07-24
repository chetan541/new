#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define For(i,j,n) for(ll i=j;i<n;i++)
#define FOR(itr,V) for(auto itr:V)
#define pb push_back
#define B(V) V.begin()
#define E(V) V.end()
#define Max(V,l,r) *max_element(V.begin()+l,V.begin()+r+1)
#define Min(V,l,r) *min_element(V.begin()+l,V.begin()+r+1)
#define Asort(V) sort(V.begin(),V.end())
#define Dsort(V) sort(V.begin(),V.end(),greater<ll>())
#define Find(V,x) find(V.begin(),V.end(),x)
#define Reverse(V) reverse(V.begin(),V.end())
#define Resize(V) V.resize(distance(V.begin(),unique(V.begin(),V.end())))
#define input(V,n,type) For(i,0,n){type e; cin>>e; V.push_back(e);}
#define print(V) FOR(itr,V){cout<<itr<<' ';}cout<<'\n';
#define ub(V,x) upper_bound(B(V),E(V),x)
#define lb(V,x) lower_bound(B(V),E(V),x)
#define ff first
#define ss second
typedef vector<ll> vl;
typedef map<ll,ll> ml;
typedef map<string,ll> ms;
typedef map<char,ll> mc;
typedef set<ll> sl;
typedef set<string> ss;
typedef set<char> sc;
typedef pair<ll,ll> pl;
typedef pair<string,ll> ps;
typedef pair<char,ll> pc;
typedef vector<pl> vpl;
typedef vector<ps> vps;
typedef vector<pc> vpc;
typedef vector<string> vs;
typedef vector<char> vc;
const ll dx[4]={1,0,-1,0};
const ll dy[4]={0,1,0,-1};
const ll Dx[8]={1,0,-1,0,1,1,-1,-1};
const ll Dy[8]={0,1,0,-1,-1,1,-1,1};
struct point{
    ll x,y;
};
 
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

bool rem(vl &V,ll ind){
    vl temp;
    ll n=V.size();
    For(i,0,n){
        if(i==ind) continue;
        temp.pb(V[i]);
    }
    vl G;
    n=temp.size();
    For(i,0,n-1){
        ll g=__gcd(temp[i],temp[i+1]);
        G.pb(g);
    }
    // cout<<ind<<'\n';
    // print(temp);
    // print(G);
    For(i,0,G.size()-1){
        if(G[i]>G[i+1]) return 0;
    }
    return 1;
}
 
 
void solve(){
    ll n;
    cin>>n;
    vl V;
    input(V,n,ll);
    ll prev=0,f=0;
    vl G;
    For(i,0,n-1){
        // cout<<V[i]<<" "<<V[i+1]<<endl;
        ll g=__gcd(V[i],V[i+1]);
        G.pb(g);
    }
    ll x=G.size();
    // print(V);
    For(i,0,x-1){
        if(G[i]>G[i+1]){
            // if(i-1>=0){
            //     if(rem(V,i-1)){
            //         cout<<"YES\n";
            //         return;
            //     }
            // }
            if(rem(V,i)){
                cout<<"YES\n";
                return;
            }
            if(i+1<n && rem(V,i+1)){
                // cout<<"hello\n";
                cout<<"YES\n";
                return;
            }
            // if(i-2>=0 && rem(V,i-2)){
            //     // cout<<"hello\n";
            //     cout<<"YES\n";
            //     return;
            // }
            if(i+2<n && rem(V,i+2)){
                // cout<<"hello\n";
                cout<<"YES\n";
                return;
            }
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
 
 
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   ll T;
   cin>>T;
   while(T--) solve();
   return 0;
}