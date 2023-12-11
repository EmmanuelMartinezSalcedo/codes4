#include <iostream>
#include <vector>

using namespace std;

int findIndex(const vector<int>& X, int start, int end) {
    if (start > end) 
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (X[mid] == mid) 
    {
        return mid;
    }
    int leftResult = findIndex(X, start, min(mid - 1, X[mid]));
    if (leftResult != -1) {
        return leftResult;
    }
    return findIndex(X, max(mid + 1, X[mid]), end);
}

int main() {
    vector<int> X = {-10, 0, 1, 2, 3, 5, 5, 10};
    int index = findIndex(X, 0, X.size() - 1);
    if (index != -1) {
        cout << "Indice " << index << " es X[i] == i." << endl;
    } else {
        cout << "No existe tal indice" << endl;
    }

    return 0;
}