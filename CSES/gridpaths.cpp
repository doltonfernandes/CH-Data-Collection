#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long lld;
typedef pair<lld,lld> pr;
typedef priority_queue <lld> max_heap;
typedef priority_queue <lld, vector<lld>, greater<lld> > min_heap;
lld const mod = 1e9+7;
lld const N = 1e5+5;
#define ordered_set tree<lld, null_type,less<lld>, rb_tree_tag,tree_order_statistics_node_update>

lld fact[N], ifact[N];

lld power(lld x, lld y)
{
    lld res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

lld power_mod(lld base, lld y)
{
    lld t = 1;
    while (y > 0)
    {

        if (y % 2 != 0)
            t = (t * base) % mod;
        base = (base * base) % mod;
        y /= 2;
    }
    return t % mod;
}

void findFact() {
    fact[0] = 1;
    for(lld i = 1; i <= N; i++)
        fact[i] = 1ll * fact[i - 1] * i % mod;
    ifact[N] = power_mod(fact[N], mod - 2);
    for(lld i = N - 1; i >= 0; i--)
        ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
}

lld comb(lld n, lld r) {
    return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}


lld gcd(lld a, lld b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}

lld cnt = 0;
string s;

lld path[10][10]={0};

void fun(lld itr, lld i, lld j)
{
    
    if(i==6 && j==0 && itr==48)
    {
        cout<<"s = "<<s<<endl;
        cnt++;
        return;
    }
    if(i==6 && j==0)
        return;
    if(itr==48)
    {
        return;
    }

    cout<<"itr = "<<itr<<" s[itr] = "<<s[itr]<<endl;
    switch (s[itr])
    {
        case 'U':
            if(i==0 || path[i-1][j]==1)
                return;
            path[i-1][j] = 1;
            fun(itr+1,i-1,j);
            path[i-1][j] = 0;
            break;
        
        case 'D':
            if(i==6 || path[i+1][j]==1)
                return;
            path[i+1][j] = 1;
            fun(itr+1,i+1,j);
            path[i+1][j] = 0;
            break;
        
        case 'L':
            if(j==0 || path[i][j-1]==1)
                return;
            path[i][j-1] = 1;
            fun(itr+1,i,j-1);
            path[i][j-1] = 0;
            break;
        
        case 'R':
            if(j==6 || path[i][j+1]==1)
                return;
            path[i][j+1] = 1;
            fun(itr+1,i,j+1);
            path[i][j+1] = 0;
            break;

        case '?':
            s[itr]='U';
            fun(itr,i,j);
            
            s[itr]='D';
            fun(itr,i,j);
            
            s[itr]='L';
            fun(itr,i,j);
            
            s[itr]='R';
            fun(itr,i,j);

            s[itr]='?';

            break;

        default:
            break;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    cin>>s;
    path[0][0]=1;
    fun(0,0,0);
    cout<<cnt<<endl;
}
