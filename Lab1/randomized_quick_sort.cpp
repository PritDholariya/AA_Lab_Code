#include<bits/stdc++.h>
using namespace std;

int comparision = 0;

int partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p-1;
    int j;

    for(j=p; j<=r-1; j++){
        comparision++;
        if(arr[j] <= x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

int randomized_partition(int arr[], int p, int r){
    srand(5);
    int random = p + rand() % (r-p+1);
    swap(arr[random], arr[r-1]);
    return partition(arr,p,r);
}

void randomized_quick_sort(int arr[], int p, int r){
    if(p < r){
        int q = randomized_partition(arr,p,r);
        randomized_quick_sort(arr,p,q-1);
        randomized_quick_sort(arr,q+1,r);
    }
}



int main(){
    int size;
    cout << "Please enter the size of array: ";
    cin >> size;
    int arr[size];
    cout << "Please enter the elements of the array: ";
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    randomized_quick_sort(arr,0,size-1);

    cout << "Sorted array: ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl << "The number of comparisions: " << comparision;
    return 0;
}
