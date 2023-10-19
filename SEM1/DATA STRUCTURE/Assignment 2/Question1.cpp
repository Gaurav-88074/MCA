#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a=b;
    b=temp;
}
void reverseArray(vector<int> &nums){
    int n = nums.size();
    for (int i = 0; i < n/2; i++){
        swap(nums[i],nums[n-i-1]);
    }
}
void displayArray(vector<int> &nums){
    for(int &i : nums){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> nums = {10,20,30,40};
    displayArray(nums);
    reverseArray(nums);
    displayArray(nums);
    return 0;
}