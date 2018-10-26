#include <iostream>

//This is an implementation on Merge Sort using an integer array.
using namespace std;

//Define prototypes
void mergesort(int*, int, int);
void merge(int*, int, int, int);

//Recursively sorts using mergesort
void mergesort(int *arr,int l,int h){
    int mid = (l+h)/2;          //Virtually divide array into 2 parts
    if(h>l){                    //If passed array has more than one element
        mergesort(arr,l,mid);   //Sort first part of the array
        mergesort(arr,mid+1,h); //Sort second part of the array
        merge(arr,l,mid,h);     //Merge sorted arrays
    }
}

void merge(int *arr,int l,int m,int h){
    int *temp = new int[h-l];          //Create a temporary array. This will hold the sorted array.
    int i=l;                           //Temporary copies of l, m, h. These will be modified, while the originals hold their value.
    int j=m+1;
    int k=l;

    //until we reach the end of the first half or the second half
    while(i<=m && j<=h){

        //put the lesser value in temp
        if(arr[i]<arr[j])
            temp[k]=arr[i++];
        else
            temp[k]=arr[j++];
        k++;
    }

    //Fill the remaining values of the non-empty array in temp
    while(i<=m)
        temp[k++]=arr[i++];
    while(j<=h)
        temp[k++]=arr[j++];

    //copy temp into the original array
    for(int x=l;x<=h;x++)
        arr[x]=temp[x];

    //temp is no longer required. Reclaim ite=s memory.
    delete []temp;
}

int main(){
    cout<<"\nEnter number of elements: ";
    int num;
    cin>>num;
    int *arr = new int[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<"\n";
    mergesort(arr,0,num-1);
    for(int i=0;i<num;i++)
        cout<<arr[i]<<" ";
}
