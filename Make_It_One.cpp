#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int  long long
#define all(x) (x).begin(), (x).end()
void printDivisors(int n,set<int>&st); 
#define nl "\n"
typedef long long ll;
#define sz(v)   ((int)(v).size())
#define fill(a,x)   memset(a,x,sizeof(a))
void solve(){
     int l,r;cin>>l>>r;
     if(__gcd(l,r)==1){
        int x=l+1;
        for(int i=1;i<=(r-l);i++){
            cout<<x<<" ";++x;
        }
        cout<<l;
        cout<<endl;
        return;
     } 
     int flag=0;int i;
     for(i=l;i<=r;i++){
        // cout<<i<<" "<<l<<" "<<i+1<<" "<<r<<endl;
        if(__gcd(i,l)==1 && __gcd(i+1,r)==1){
            flag=1;break;
        }
     }
    //  cout<<i<<endl;
     if(flag){
        for(int j=l;j<=r;j++){
            if(j==i) cout<<l<<" ";
            else if(j==r) cout<<i+1<<" ";
            else cout<<j+1<<" ";
        }
        cout<<endl;
     }
     else cout<<-1<<endl;






}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
    return 0;
}
void printDivisors(int n,set<int>&st) 
{ 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i)   st.insert(i);
            else st.insert(i),st.insert(n/i);
        } 
    } 
}