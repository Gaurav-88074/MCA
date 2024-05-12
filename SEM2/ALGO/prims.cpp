#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <climits>
typedef long long ll;
using namespace std;
auto pq_comp = [](const vector<ll> a, const vector<ll> b)
{
    return (a[1] - b[1]) > 0;
};
vector<ll> prims(map<ll, vector<vector<ll>>> &graph, int n)
{
    vector<ll> res(n, INT_MAX);
    res[0] = 0;
    priority_queue<vector<ll>, vector<vector<ll>>, decltype(pq_comp)> pq(pq_comp);
    pq.emplace(vector<ll>{0, 0}); // error
    vector<ll> vis(n, 0);

    while (pq.size() > 0)
    {
        vector<ll> obj = pq.top();
        pq.pop();
        ll node, dist;
        node = obj[0];
        dist = obj[1];
        vis[node]=1;
        // Update distances to adjacent nodes
        for (vector<ll>& objj : graph[node]){
            ll nei = objj[0];
            ll w = objj[1];
            if (vis[nei]==0 && w < res[nei]){
                res[nei] = w;
                pq.push({nei, w}); // Push the updated distance and node to the priority queue
            }
        }
    }
    return res;
}
int main()
{
    map<ll, vector<vector<ll>>> graph;
    graph[1].push_back({0,2});
    graph[0].push_back({1,2});

    graph[1].push_back({2,4});
    graph[2].push_back({1,4});
    
    graph[2].push_back({1,4});
    graph[1].push_back({2,4});
    
    graph[2].push_back({3,6});
    graph[3].push_back({2,6});
    
    graph[3].push_back({2,6});
    graph[2].push_back({3,6});
    
    graph[3].push_back({4,8});
    graph[4].push_back({3,8});
    
    graph[4].push_back({3,8});
    graph[3].push_back({4,8});
    int n = 5;
    vector<ll> res = prims(graph, n);
    auto display = [&](auto &arr)
    {
        for (auto &x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    };
    display(res);
    cout << "done" << endl;
    return 0;
}