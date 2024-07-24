#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i,s,n) for(int i=s;i<n;i++)
#define f(i,a,b) for(int i=a;i<b;i++)
typedef int itn;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<long long int> vll;
typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<pair<ll,ll> > vpll;
#define sp '\b' 
#define nl '\n' 
#define F first 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define multi_ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define S second
bool cmp(pair<int,int> a, pair<int,int > b)
{
    // if(a.first !=b.first)
    // {return a.first<b.first;}
    return a.second<b.second;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n; cin>>n;
        vll a,b;
        multi_ordered_set st;
        vector<pair<ll,ll>> v;
        map<int,int> z;
        for(int i=0;i<n;i++)
        {
            ll x; cin>>x;
            a.pb(x);
            z[x]++;
            st.insert(x);
        }
        for(int i=0;i<n;i++)
        {
            ll x; cin>>x;
            b.pb(x);
        }
        for(int i=0;i<n;i++)
        {
            v.pb({a[i],b[i]});
        }
        // sort(all(v),cmp);
        // for(auto it:v)
        // {
        //     cout<<it.F<<" "<<it.S<<endl;
        // }
        ll ans=LONG_LONG_MIN;
        ll s;
        for(itn i=1;i<=n;i++)
        {
            int tmp=st.size();ll x;
            if(i<=tmp)
             {x=*st.find_by_order(i-1);
            if(i*x>ans) {ans=i*x; s=i;}
            // cout<<x<<" " <<i<<endl;
             }
             int k=st.order_of_key(v[v[i-1].S-1].F);
             st.erase(st.find_by_order(k));
             

             
        }
        cout<<ans<<" "<<s<<endl;

         
    }
       return 0;
}