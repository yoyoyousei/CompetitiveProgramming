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

const LL INF = LONG_MAX / 2;    //int_max->2*e+9
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
LL tmpS,tmpC;
set<pair<LL,LL>> memo;
vector<LL> ans;
int main(){
    ios::sync_with_stdio(false); //cout<< fixed << setprecision(10);
    scanf("%ld",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld%ld",&tmpS,&tmpC);
        while (tmpC){
            auto it=memo.lower_bound(MP(tmpS,-1));//tmp以上で終わる最小の範囲を返す
            if(it==memo.end()){
                memo.insert(MP(tmpS+tmpC,tmpS));
                cout<<tmpS+tmpC-1<<endl;
                tmpS+=tmpC;
                tmpC=0; //ans.push_back(tmpS+tmpC);
                break;
            }
            //first:区間の終わり,second：区間の始まり　 [second,first)
            if(it->second<=tmpS){   //始まりがtmpSよりまえ
                auto it2=it;
                it2++; //it2がend
               /* cout<<it2->first;
                cout<<",";
                cout<<it2->second<<endl;*/
                if(it2!=memo.end() && it->first+tmpC>it2->second){
                    LL dist=it2->second-it->first;
                    tmpC-=dist;
                    tmpS=it2->second;
                    pair<LL,LL> p=MP(it2->first,it->second);
                    memo.insert(p);
                    memo.erase(MP(it->first,it->second)); //イテレータを渡して削除してもいいけど，
                    memo.erase(MP(it2->first,it2->second));
                }else if(it2!=memo.end() && it->first+tmpC == it2->second){
                    cout<<it->first+tmpC-1<<endl;

                    tmpS=it->first+tmpC;
                    tmpC=0;
                    pair<LL,LL> p=MP(it2->first,it->second);
                    memo.insert(p);
                    memo.erase(MP(it->first,it->second));
                    memo.erase(MP(it2->first,it2->second));
                }else{
                    cout<<it->first+tmpC-1<<endl;

                    tmpS=it->first+tmpC;
                    tmpC=0;
                    memo.insert(MP(tmpS,it->second));
                    memo.erase(MP(it->first,it->second));
                }
            }else { //あと
                LL dist=it->second-tmpS;
                if(tmpC>dist){
                    pair<LL,LL> p=MP(it->first,tmpS);
                    memo.insert(p);
                    memo.erase(MP(it->first,it->second));
                    tmpC-=dist;
                    tmpS=it->second;
                }else if(tmpC==dist){
                    cout<<tmpS+tmpC-1<<endl;

                    pair<LL,LL> p=MP(it->first,tmpS);
                    memo.insert(p);
                    memo.erase(MP(it->first,it->second));
                    tmpS=it->second;
                    tmpC=0;
                }else{
                    cout<< tmpS+tmpC-1<<endl;

                    memo.insert(MP(tmpS+tmpC,tmpS));
                    tmpS+=tmpC;
                    tmpC=0;
                }
            }
        }
        //ans.push_back(tmpS-1);

    }
    /*for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<endl;
    }*/
}