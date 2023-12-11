#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int kesimo_menor_recursivo(vector<int>& arr, int low, int high, int k) 
{
    if (low <= high) 
    {
        int pivot_index = partition(arr, low, high);
        if (pivot_index == k - 1) 
        {
            return arr[pivot_index];
        } 
        else if (pivot_index > k - 1) 
        {
            return kesimo_menor_recursivo(arr, low, pivot_index - 1, k);
        } 
        else 
        {
            return kesimo_menor_recursivo(arr, pivot_index + 1, high, k);
        }
    }

    return -1;
}

int kesimo_menor(vector<int>& arr, int k) {
    if (k > 0 && k <= arr.size()) 
    {
        return kesimo_menor_recursivo(arr, 0, arr.size() - 1, k);
    } 
    else 
    {
        return -1;
    }
}

int main() {
    vector<int> vector = {12, 3, 5, 7, 4, 19, 26, 3, 10};
    int k = -1;
    int resultado = kesimo_menor(vector, k);

    if (resultado != -1) 
    {
        cout << "El " << k << "-eimo menor elemento es: " << resultado << endl;
    } else 
    {
        cout << "k fuera de rango." << endl;
    }
    return 0;
}