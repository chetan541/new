#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef int itn;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef vector<pair<ll, ll>> vpll;
#define sp '\b'
#define nl '\n'
#define F first
#define S second
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{

    int n;
    cin >> n;
    while(n--){
    string s;
    cin>>s;
    int flag;
    for (int i = 0; i< s.size(); i++)
    {
       if(s[i]=='.')
       {flag=0; break;}
       if(s[i]=='/')
       flag=1;
    }
    string date,mon,year;
    int i=0;
    if(flag==0)
    {
        while(s[i]!='.')
        {
            date.push_back(s[i]);
            i++;
        } i++;
        while(s[i]!='.')
        {
            mon.push_back(s[i]);
            i++;
        }i++;
        while(i!=s.size())
        {
            year.push_back(s[i]);
            i++;
        }
    }
    else
    {
        while(s[i]!='/')
        {
            mon.push_back(s[i]);
            i++;
        } i++;
        while(s[i]!='/')
        {
            date.push_back(s[i]);
            i++;
        } i++;
        while(i!=s.size())
        {
            year.push_back(s[i]);
            i++;
        } i++;
    }
    
    if(date.size()!=2)
    {
        date.insert(0,"0");
    }
    if(mon.size()!=2)
    mon.insert(0,"0");
    if(year.size()!=4)
    {
        while(year.size()!=4){
            year.insert(0,"0");
        }

    }
    cout<<date<<"."<<mon<<"."<<year<<" ";
    cout<<mon<<"/"<<date<<"/"<<year<<endl;}
    




    


}