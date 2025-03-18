#include <iostream>
#include <vector>
#include <algorithm> // for the sort() function

using namespace std;

int binarySearch(vector<int>& arr, int value) {

    sort(arr.begin(), arr.end());  // Sort in ascending order (default sorting)

    int lowerValue = 0;
    int upperValue = arr.size() - 1;

    while (lowerValue <= upperValue) {
        int mid = lowerValue + (upperValue - lowerValue) / 2;

        if (arr[mid] == value) {
            return mid;  // Return the index if the value is found
        } else if (arr[mid] < value) {
            lowerValue = mid + 1;
        } else {
            upperValue = mid - 1;
        }
    }

    return -1;  // Return -1 if the value is not found
}

int main() {

    vector<int> arr = {5, 8, 12, 2, 16, 23, 91, 72, 56, 38};

    int result = binarySearch(arr, 56);

    if (result != -1) {
        cout << "Value found, index: " << result << endl;
    } else {
        cout << "Value not found." << endl;
    }
}
