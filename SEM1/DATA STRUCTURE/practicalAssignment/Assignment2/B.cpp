#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &array){
    for(int i:array){
        cout<<i<<" ";
    }
    cout<<endl;
}
vector<int> merge(vector<int> &array1,vector<int> &array2){
    vector<int> res;
    int i = 0;
    int j = 0;
    while(i<array1.size() && j<array2.size()){
        if(array1[i]<array2[j]){
            res.push_back(array1[i++]);
        }
        else{
            res.push_back(array2[j++]);
        }
    }
    while(i<array1.size()){
        res.push_back(array1[i++]);
    }
    while(j<array2.size()){
        res.push_back(array2[j++]);
    }
    return res;
}
vector<int> mergeSort(vector<int> &array,int start,int end){
    if(start==end){
        return {array[start]};
    }
    else{
        int mid = start+ (end-start)/2;
        vector<int> left  = mergeSort(array,start,mid);
        vector<int> right = mergeSort(array,mid+1,end);
        return merge(left,right);
    }
}
int main(){
    vector<int> array = {10,20,3,3,1};
    display(array);
    array = mergeSort(array,0,array.size()-1);
    display(array);
    return 0;
}