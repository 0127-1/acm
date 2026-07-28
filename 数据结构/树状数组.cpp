https://www.luogu.com.cn/problem/P3374
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+7;
const double eps=1e-4;
const int mod=998244353;

struct Fenwick{
    vector<ll>v;
    Fenwick(int n):v(n+1){};
    void update(ll k,ll val){
        for(int i=k;i<v.size();i+=i&(-i)){
            v[i]+=val;
        }
    }
    ll query(int t){
        ll len=0;
        for(int i=t;i>=1;i-=i&(-i)){
            len+=v[i];
        }
        return len;
    }
    ll range(int l,int r){
        return query(r)-query(l-1);
    }
};

void solve() {
    ll n,m;cin>>n>>m;
    vector<ll>v(n);
    Fenwick tr(n);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        tr.update(i,x);
    }
    for(int i=0;i<m;i++){
        ll op,x,y;cin>>op>>x>>y;
        if(op==1){
            tr.update(x,y);
        }
        else{
            cout<<tr.range(x,y)<<'\n';
        }
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
