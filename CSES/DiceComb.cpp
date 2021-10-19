#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define mk make_pair
#define pb push_back

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n;
    cin>>n;
    lld dp[n+5]={0};
    lld i,j;
    dp[1] = 1;
    dp[0] = 1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=6;j++)
        {
            if(i-j>=0)
            {
                dp[i] = (dp[i] + dp[i-j])%mod;
            }
        }
    }
    cout<<dp[n]<<endl;

}
