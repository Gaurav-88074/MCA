#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include <climits>
typedef long long ll;
using namespace std;
auto pq_comp = [](const vector<ll> a, const vector<ll> b){
    return (a[1]-b[1]) > 0;
};
vector<ll> dijkstra(map<ll,vector<vector<ll>>> &graph,int n){
    vector<ll> res(n,INT_MAX);
    res[0]=0;
    priority_queue<vector<ll>, vector<vector<ll>>, decltype(pq_comp)> pq(pq_comp);
    pq.emplace(vector<ll>{0, 0});//error
    while(pq.size()>0){
        vector<ll> obj = pq.top();
        pq.pop();
        ll node,dist;
        node =obj[0];
        dist =obj[1];
        if(res[node] < dist){
            continue;
        }
        for(vector<ll> &objj : graph[node]){
            ll nei = objj[0];
            ll w = objj[1];
            if(dist + w <  res[nei]){
                res[nei] = dist + w;
                pq.emplace(vector<ll>{nei, res[nei]});//error
            }
        }
    }
    return res;

}
int main(){
    map<ll,vector<vector<ll>>> graph;
    graph[0].push_back({1,9});
    // graph[1].push_back({0,9});

    graph[0].push_back({2,1});
    // graph[2].push_back({0,1});

    graph[0].push_back({3,1});
    // graph[3].push_back({0,1});

    graph[1].push_back({3,3});
    // graph[3].push_back({1,3});

    graph[2].push_back({3,2});
    // graph[3].push_back({2,2});
    int n = 4;
    vector<ll> res = dijkstra(graph,n);
    auto display = [&](auto &arr){
        for(auto &x:arr){
            cout<<x<<" ";
        }
        cout<<endl;
    };
    display(res);
    cout<<"done"<<endl;
    return 0;
}