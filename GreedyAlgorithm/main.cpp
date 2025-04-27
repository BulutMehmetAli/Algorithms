#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Greedy Coin Change Algorithm
void greedyCoinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    vector<int> coinsNew;

    for (int i = 0; i < coins.size(); i++) {
        int count = 0;
        while (coins[i] <= amount) {
            amount -= coins[i];
            count++;
        }
        if (count > 0) {
            cout << count << " coin(s) of value " << coins[i] << " used." << endl;
        }
    }

    for (int i = 0; i < coinsNew.size(); i++) {
        cout << coinsNew[i] << " ";
    }

    cout << endl;
}

int main() {
    vector<int> coins = {20, 1, 5, 2, 10};  // Example coin denominations
    int amount = 63;  // Amount to pay

    greedyCoinChange(coins, amount);

    return 0;
}
