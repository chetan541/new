#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
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
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vi v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.pb(x);
        }
        // v.pb(0);
        itn flag=1,c=0,x=0;
        ll sum=0;
        if(n==1)
        cout<<v[0]<<endl;
        else {
        for(int i=0;i<n;i++)
        {
            if(flag==1 && i==0 && v[i]>v[i+1])
            {
                sum+=v[i]; flag=0; c++;
            }
            else if(flag==1 && i==n-1 && v[i]>v[i-1])
            { sum+=v[i]; flag=0; c++;}

            else if( flag==1 && v[i]>v[i-1] && v[i]>v[i+1] )
            {sum=sum+v[i]; flag=0; c++;}
            
            else if(flag==0 && i==n-1 )
            break;

            else if(flag==0 && v[i]<v[i+1] && v[i]<v[i-1])
            {sum-=v[i]; flag=1; x=v[i]; c++; }

            
        }

        // cout<<sum<<endl;        
        if(c%2!=0)
        cout<<sum<<endl;
        else cout<<sum+x<<endl;
        }
    }
}