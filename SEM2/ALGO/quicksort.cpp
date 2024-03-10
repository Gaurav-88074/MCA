#include<iostream>
#include<vector>
using namespace std;
void displayArray(vector<int> &array){
    cout<<"Displaying Your Array..."<<endl;
    for (int i = 0; i < array.size(); i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void swap(vector<int> &array,int a,int b){
    int temp = array[a];
    array[a]  = array[b];
    array[b]  = temp;
}

int partition(vector<int> &array,int start,int end){
    int index = start-1;
    int pivot = end;
    while (start<end){
        if (array[start]<=array[pivot]){
            index+=1;
            swap(array,index,start);
        }
        start+=1;
    }
    index+=1;
    swap(array,index,pivot);
    return index;
}
void quickSort(vector<int> &array,int start,int end){
    if (start<end){
        int partion = partition(array,start,end);
        quickSort(array,start,partion-1);
        quickSort(array,partion+1,end);
    }
}

int main(){
    vector<int> array = {10,9,8,7,6,5,4,3,2,1};
    
    displayArray(array);
    quickSort(array,0,array.size()-1);
    displayArray(array);

    return 0;
}