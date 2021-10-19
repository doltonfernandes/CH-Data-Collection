#include<bits/stdc++.h>
using namespace std;

#define mk make_pair
#define pb push_back

typedef long long lld;

lld cnt = 0;
vector <pair<lld,lld>> steps;

void movePile(lld n, lld start, lld end, lld middle)
{
    if(n==0)
        return;
    
    movePile(n-1,start,middle,end);
    steps.push_back(mk(start,end));
    cnt++;
    movePile(n-1,middle,end,start);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld n;
    cin>>n;

    movePile(n,1,3,2);
    cout<<cnt<<endl;

    for(auto x:steps){
        cout<<x.first<<' '<<x.second<<endl;
    }

}
