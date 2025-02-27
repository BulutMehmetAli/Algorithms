#include <iostream>
#include <vector>
using namespace std;

int kadensAlgorithm(vector<int> &arr){

    int currentSum = arr[0];
    int maxSum = arr[0];
    for(int i=1;i<arr.size();i++){
                maxSum = max(maxSum+arr[i], arr[i]);
                currentSum = max(maxSum,currentSum);

    }
    return currentSum;
    cout << endl;
}
int main()
{
    vector<int> arr = {2, 333, -8, -7, -1, 2, 3};
    int result = kadensAlgorithm(arr);
    cout << result << endl;
    return 0;
}
