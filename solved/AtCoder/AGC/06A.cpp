#include <bits/stdc++.h>
//#include <boost/functional/hash.hpp>
//example: unordered_set< pair<int,int>,boost::hash< std::pair<int, int> > > used;
//priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int> > > > pqueue;    //cost, vertex(行き先)
using namespace std;

#define MODULE 1000000007
#define MP make_pair
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second

template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

typedef pair<int, int> P;
typedef long long LL;
const int INF = INT_MAX / 2;    //int_max->2*e+9 LLの時はLLONG_MAX
const int MAXN = 100001;

/*struct edge {
    edge(int to, int cost) : to(to), cost(cost) {}
    int to, cost;
};
vector<edge> graph[MAXN];*/


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

//-----Template---------
int n;
int minimum=INF;
string s,t;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    cin>>n>>s>>t;
    for (int i = 0; i <= n; ++i) {//食い込む量
        bool flag=true;
        for (int j = 1; j <= i; ++j) {
            if(s[s.length()-j]!=t[i-j]){
                flag=false;
                break;
            }
        }
        if(flag)
            chmin(minimum,(s.length()-i)*2+i);
    }
    cout<<minimum<<endl;
}