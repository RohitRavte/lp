#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>


int partition(vector<float>&arr,int low,int high){
    float pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;


}


void quciksort(vector<float>&arr,int low,int high){
    if(low<high){
      int pivotindex=partition(arr,low,high);
    
      quciksort(arr,low,pivotindex-1);   
      quciksort(arr,pivotindex+1,high);  
   

    }

    

}



void print(vector<float>&arr){
    for(float num:arr){
        cout<<num<<" ";

    }
}

int main(){

    cout<<"enter the number of elements\n";
    int n;
    cin>>n;

    vector<float>arr(n);

    cout<<"enter the elements\n";

    for(int i=0;i<n;i++){

        cin>>arr[i];


    }



    cout<<"array befor sorting :";

    print(arr);
    cout<<endl;
     
    cout<<"array after sorting :";

    quciksort(arr,0,n-1);
print(arr);
return 0;



}