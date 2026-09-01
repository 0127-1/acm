https://ac.nowcoder.com/acm/contest/120564/D

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using i128=__int128_t;
const int inf=0x3f3f3f3f;
const int maxn=1<<12;
const int mod=100000000;

i128 exgcd(i128 a,i128 b,i128 &x,i128 &y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    i128 d=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return d;
}

i128 ceil_(i128 a,i128 b){
    i128 q=a/b;
    i128 r=a%b;
    if(r!=0&&a>0)q++;
    return q;
}

i128 floor_(i128 a,i128 b){
    i128 q=a/b;
    i128 r=a%b;
    if(r!=0&&a<0)q--;
    return q;
}


void solve(){
    ll x,a,s;cin>>x>>a>>s;
    i128 u,v;
    i128 g=exgcd(a,s,u,v);
    if(x%g!=0){
        cout<<"No"<<'\n';
        return ;
    }
    u*=x/g;v*=x/g;
    i128 k=floor_((v-u),(s/g+a/g));
    i128 l=ceil_((-u),(s/g)),r=floor_(v,(a/g));
    if(l>r){
        cout<<"No"<<'\n';
        return ;
    }
    k=max(k,l);
    k=min(k,r);
    cout<<"Yes"<<'\n';
    ll x1=u+s/g*k,y1=v-a/g*k;
    if(k+1<=r){
        ll x2=u+s/g*(k+1),y2=v-a/g*(k+1);
        if(max(x1,y1)<=max(x2,y2)){
            cout<<x1<<' '<<y1<<'\n';
        }
        else{
            cout<<x2<<' '<<y2<<'\n';
        }
    }
    else{
        cout<<x1<<' '<<y1<<'\n';
    }


}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
}
