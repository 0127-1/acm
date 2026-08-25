https://www.luogu.com.cn/problem/P3367

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const int maxn=100;
const int mod=998244353;


struct DSU{
    vector<int>fa,sz;
    DSU (int n):fa(n+1),sz(n+1,1){
        iota(fa.begin(),fa.end(),0);
    }
    int find(int a){
        if(fa[a]==a)return a;
        return fa[a]=find(fa[a]);
    }
    bool merge(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return false;
        if(sz[a]<sz[b])swap(a,b);
        sz[a]+=sz[b];
        fa[b]=a;
        return true;
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
    int size(int a){
        return sz[find(a)];
    }
};

void solve(){
    int n,m;cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int t,x,y;cin>>t>>x>>y;
        if(t==1){
            dsu.merge(x,y);
        }
        else{
            if(dsu.same(x,y))cout<<"Y"<<'\n';
            else  cout<<"N"<<'\n';
        }
    }


}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)
    solve();
}
