#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <climits>
using namespace std;
class DSU{
    public:
        int n;
        vector<int> tempSize;
        vector<int> leader;
        DSU(int _){
            this->n=_;
            tempSize.resize(n, 1); // Initialize class member vectors
            leader.resize(n);
            for(int i=0;i<n;i++){
                leader[i]=i;
            }
        }
        int getLeader(int x){
            if(leader[x]==x)return x;
            return leader[x] = getLeader(leader[x]);
        }
        void merge(int x,int y){
            x = getLeader(x);
            y = getLeader(y);
            if(tempSize[x]==tempSize[y]){
                leader[x]=leader[y];
                tempSize[y]+=1;
            }
            else if(tempSize[x] < tempSize[y]){
                leader[x]=leader[y];
            }
            else{
                leader[y]=leader[x];
            }
        }
        
};
int main()
{
    
    return 0;
}