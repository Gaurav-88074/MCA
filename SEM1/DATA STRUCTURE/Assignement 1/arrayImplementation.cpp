#include<iostream>
using namespace std;

void displayArray(int array[],int size){
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return;
}
void insertElement(int array[],int &size,int value){
    array[size]=value;
    size+=1;
    return;
}
void insertAtIndex(int array[],int &size,int index,int value){
    int i = size;
    while(i>index){
        array[i] = array[i-1];
        i-=1;
    }
    array[index] = value;
    size+=1;
}
void deleteAtIndex(int array[],int &size,int index){
    int i = index;
    while(i<size){
        array[i] = array[i+1];
        i+=1;
    }
    size-=1;
}
int main(){
    int x = 1e5;
    int array[x] = {10,20,30,40,50};
    int size = 5;
    displayArray(array,size);
    deleteAtIndex(array,size,2);
    displayArray(array,size);
    return 0;
}