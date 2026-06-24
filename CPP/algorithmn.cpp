//                        Linear search

// int arr [] = {3,5,1,12,36,32,4}; key =12
// find they key in array using linear search,
// if the key is found and value of key is >10,
// then return double the value of key,
// otherwise return the half value of key


// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {3, 5, 1, 12, 36, 32, 4};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int key = 12;

//     bool found = false;

//     for (int i = 0; i < n; i++) {
//         if (arr[i] == key) {
//             found = true;

//             if (key > 10)
//                 cout << "Result = " << key * 2 << endl;
//             else
//                 cout << "Result = " << key / 2.0 << endl;

//             break;
//         }
//     }

//     if (!found)
//         cout << "Key not found" << endl;

//     return 0;
// }


//                        Binary search

// if  arr[mid]== key ->return key,
// if key>mid -> search in right -> s= mid+1,
// if key<mid -> search in left -> s = mid -1; 



#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int size){
    int s=0; 
    int e = size-1;

    while(s<=e){
        int mid =(s+e)/2;

        if(arr[mid]== key) return mid;

        else if(arr[mid]<key )s=mid+1;

        else e=mid-1;
    }
    return -1;
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8,9,10};

} 