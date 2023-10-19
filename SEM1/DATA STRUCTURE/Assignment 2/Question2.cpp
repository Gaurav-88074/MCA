#include<iostream>
#include<vector>
#include<set>
using namespace std;

void displayArray(vector<int> &nums){
    cout<<"[";
    for(int &i : nums){
        cout<<i<<" ";
    }
    cout<<"]";
    cout<<endl;
}
vector<int> intersection(vector<int> nums1,vector<int> nums2){
    vector<int> res;
    set<int> hashmap;
    for(int &i:nums1){
        hashmap.insert(i);
    }
    for(int &i:nums2){
        if(hashmap.find(i)!=hashmap.end()){
            res.push_back(i);
        }
    }
    return res;
}
int main(){
    vector<int> nums1 = {10,20,30,40};
    vector<int> nums2 = {30,40,50,60};
    displayArray(nums1);
    displayArray(nums2);
    vector<int> nums3 = intersection(nums1,nums2);
    displayArray(nums3);
    return 0;
}