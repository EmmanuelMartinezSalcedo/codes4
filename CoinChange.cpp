#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int MAX_AMOUNT = 7489;
    vector<int> coins = {1, 5, 10, 25, 50};
    vector<int> ways(MAX_AMOUNT + 1, 1);
    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= MAX_AMOUNT; j++)
        {
            ways[j] += ways[j - coins[i]];
        }
    }
    int amount;
    while (cin >> amount)
    {
        cout << ways[amount] << endl;
    }
}