https://www.luogu.com.cn/problem/P3383

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e8+7;
const double eps=1e-4;
const int mod=998244353;

vector<int>pri;
bitset<maxn>is;

void eular(){
    for(int i=2;i<maxn;i++){
        if(!is[i]){
            pri.push_back(i);
        }
        for(int j=0;1ll*pri[j]*i<maxn;j++){
            is[pri[j]*i]=true;
            if(i%pri[j]==0)break;
        }
    }
}

void solve(){
    eular();
    ll n,q;cin>>n>>q;
    while(q--){
        ll k;cin>>k;
        cout<<pri[k-1]<<'\n';
    }
 
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;//cin>>t;
    while(t--)
    solve();
    return 0;
}
