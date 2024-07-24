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




int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    clock_t tStart = clock();
    int test=1;
    cin>>test;
   
    while(test--){
        char arr[10][10];

        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cin>>arr[i][j];
            }
        }

        int res=0;

        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(arr[i][j]=='.')
                    continue;
                else
                {
                    if(i==0||i==9)
                    {
                        res+=1;
                        continue;
                    }

                    if(i==1||i==8)
                    {
                        if(j==0||j==9)
                        {
                            res+=1;
                            continue;
                        }
                        else
                        {
                            res+=2;
                            continue;
                        }
                    }

                    if(i==2||i==7)
                    {
                        if(j==0||j==9)
                        {
                            res+=1;
                            continue;
                        }

                        else if(j==1||j==8)
                        {
                            res+=2;
                            continue;
                        }

                        else {
                            res+=3;
                        }
                    }


                    if(i==3||i==6)
                    {
                         if(j==0||j==9)
                        {
                            res+=1;
                            continue;
                        }

                        else if(j==1||j==8)
                        {
                            res+=2;
                            continue;
                        }

                        else if(j==2||j==7)
                        {
                            res+=3;
                            continue;
                        }

                        else 
                        {
                            res+=4;
                        }
                    }

                    if(i==4||i==5)
                    {
                         if(j==0||j==9)
                        {
                            res+=1;
                            continue;
                        }

                        else if(j==1||j==8)
                        {
                            res+=2;
                            continue;
                        }

                        else if(j==2||j==7)
                        {
                            res+=3;
                            continue;
                        }

                        else if(j==3||j==6)
                        {
                            res+=4;
                            continue;
                        }

                        else
                        {
                            res+=5;
                            continue;
                        }

                    }
                }
            }
        }

        cout<<res<<endl;

        
    }
    
   
}     


