#include <stdio.h>
#include <stdlib.h> //For malloc() and free()

//This is an implementation on Merge Sort using an integer array.

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
    int *temp = malloc((h-l)*sizeof(int));          //Create a temporary array. This will hold the sorted array.
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
    free(temp);
}

int main(){
    printf("\nEnter number of elements: ");
    int num;
    scanf("%d", &num);
    int *arr = malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        scanf("%d", &arr[i]);
    }
    printf("\n");
    mergesort(arr,0,num-1);
    for(int i=0;i<num;i++)
        printf("%d ", arr[i]);
}
