#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll cnt = 0, sum = 0, flag = 1, tmp = 0;

        REP(i, 0, 63)
        {
            // cout<<i<<" "<<(n&(1<<i))<<" "<<(x&(1<<i))<<" "<<endl;
            if ((n & (1LL << i)) == (1LL << i) && (x & (1LL << i)) == (1LL << i))
            {
                tmp++;
            }
            else if ((n & (1LL << i)) == (1LL << i) && (x & (1LL << i)) != (1LL << i))
            {
                if (tmp > 0)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    cnt = i;
                    sum+=(1LL<<i);
                }
            }
            else if ((n & (1LL << i)) != (1LL << i) && (x & (1LL << i)) == (1LL << i))
            {
                flag = 0;
                break;
            }
        }

        // cout << flag << " " << cnt << " " << tmp << endl;
        if((n&(1LL << (cnt+1)))==(1LL << (cnt+1)) && sum!=0)flag=0;
        if(flag==0)cout<<-1<<endl;
        else{
            if(sum==0)cout<<n<<endl;
            else cout<<n+(1LL<<(cnt+1))-sum<<endl;
        }
    }

    return 0;
}
