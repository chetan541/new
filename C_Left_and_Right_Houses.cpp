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
#define S second
bool cmp(pair<int,int> a, pair<int,int > b)
{
    if(a.first !=b.first)
    {return a.first<b.first;}
    return a.second>b.second;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin>>n;
        string s;cin>>s;
        vi v;
        ll sum=0;
        v.pb(0);
        for(int i=0;i<n;i++)
        {
            
            int x; x=(s[i])-48;
            sum+=x;
            v.pb(sum);
        }
        double mn=INT_MAX;
        double ans=0;
        for(int i=0;i<=n;i++)
        {
            int tmp=ceil((i/2.0));
            int a=ceil((n-i)/2.0);
            int c=i-v[i];
            int b=v[n]-v[i];
            if(c>=tmp && b>=a)
            {
                if(abs(n/2.0 - i)<mn)
                {
                    mn=abs(n/2.0 - i);
                    ans=i;
                }
            }

        }
        cout<<int(ans)<<endl;
         
    }
       return 0;
}