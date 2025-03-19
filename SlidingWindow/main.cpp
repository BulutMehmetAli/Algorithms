#include <iostream>
#include <climits>

using namespace std;

int slidingWindow(int arr[] , int wSize , int n){

//    int maxSum = INT_MIN;
//    for(int i=0;i<n-wSize+1;i++){
//        int currentSum=0;
//        for(int j=0;j<wSize;j++){
//            currentSum = currentSum + arr[j+i];
//        }
//        maxSum = max(currentSum,maxSum);
//    }
//    return maxSum;

    if(n<=wSize){
        cout << "Overlengt window size" << endl;
        return -1;
    }

    int max_sum = 0;
    for(int i=0;i<wSize;i++){
        max_sum += arr[i];
    }
    int windowSum = max_sum;
    for(int i=wSize;i<n;i++){
        windowSum += arr[i] - arr[i-wSize];
        max_sum = max(windowSum , max_sum);
    }
    return max_sum;

}


int main()
{

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result =slidingWindow(arr , 2 , n);
    cout << result << endl;
    return 0;
}
