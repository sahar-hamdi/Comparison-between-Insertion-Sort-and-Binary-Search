#include<bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <time.h>

using namespace std;
using namespace std::chrono;

//Original Insertion Sort.
void InsertionSort(int arr[] , int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while(j>=0 && temp <= arr[j])  /* Move the elements greater than temp to one position ahead from their current position*/
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp;
    }
}
//Binary Search.
int BinarySearch(int arr[], int item, int low, int high)
{
    while (high <= low){
        if(item > arr[low])
            return low + 1;
        else
            return low;
    }


    int mid = (low + high)/2;
    if(item == arr[mid])
        return mid+1;
    if(item > arr[mid])
        return BinarySearch(arr, item, mid+1, high);
    return BinarySearch(arr, item, low, mid-1);
}
//Binary Insertion Sort.
void BinaryInsertionSort(int arr[] , int size)
{
        int i, loc, j, k, selected;
        for (i = 1; i < size ; ++i) {
            j = i - 1;
            selected = arr[i];
            loc = BinarySearch(arr, selected, 0, j);
            while (j >= loc) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = selected;
        }

}
int main(){
    for (int i = 0; i < 5 ; ++i) {

        int num; cin>>num;
        int a[num];
        for(int i = 0 ; i < num ; i++){
            a[i]=rand()%10000;
        }
        auto begin= high_resolution_clock::now();
        InsertionSort(a,num);
        auto End= high_resolution_clock::now();
        auto DurationTime=duration_cast<microseconds>(End-begin);
        cout<<"The running time in insertion sort is : "<<DurationTime.count()<<" microseconds"<<endl;
        cout<<"______________________________________________________________________________________"<<endl;
        auto Start= high_resolution_clock::now();
        BinaryInsertionSort(a,num);
        auto End_= high_resolution_clock::now();
        auto durationtime=duration_cast<microseconds>(End_-Start);
        cout<<"The running time in binary insertion sort is : "<<durationtime.count()<<" microseconds"<<endl;
        cout<<"______________________________________________________________________________________"<<endl;
    }
}