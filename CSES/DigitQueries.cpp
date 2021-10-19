#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


#define mk make_pair
#define pb push_back

typedef unsigned long long lld;
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

lld len_num(lld n)
{
    lld cnt = 0;
    while(n){
        cnt++;
        n/=10;
    }
    return cnt;
}

lld score(lld n)
{
    lld i = 1;
    lld cnt=0;
    lld k = 9;
    lld lgth = len_num(n);
    
    while(i<lgth){
        cnt += i*k;
        i++;
        k = k*10;
    }

    k = k/9;
    n = n - k;

    cnt += i*n;
    return cnt;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld q;
    cin>>q;
    while(q--)
    {
        lld k;
        cin>>k;
        
        lld temp = 9;
        lld cnt = 1;
        while(k > cnt*temp)
        {
            k = k - cnt*temp;
            temp*=10;
            cnt++;
        }

        lld temp2,temp3;

        temp2 = (k-1)%cnt + 1;
        temp3 = (k-1)/cnt;

        lld ans = 1;
        for(lld i=1;i<cnt;i++)
            ans*=10;
        
        ans += temp3;

        for(lld i=1;i<=cnt-temp2;i++)
            ans/=10;
        ans %= 10;
        cout<<ans<<endl;

    }

}
