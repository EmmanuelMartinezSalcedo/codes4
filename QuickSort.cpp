#include <iostream>
#include <vector>

using namespace std;

void intercambiar(vector<int>& A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int pivot(vector<int>& V, int start, int end) 
{
    int i = start;
    int pivote = V[end];
    for (int j = start; j < end; j++)
    {
        if (V[j] <= pivote)
        {
            intercambiar(V, i, j);
            i++;
        }
    }
    intercambiar(V, i, end);
    return i;
}

void quickSort(vector<int>& V , int start, int end)
{
    if (start < end)
    {
        int pivot_index = pivot(V, start, end);
        quickSort(V, start, pivot_index - 1);
        quickSort(V, pivot_index, end);
    }
}
int main()
{
    vector<int> V = { 10, 2, 3, 1, 6, 8, 4, 5, 7, 9 };
    quickSort(V, 0, V.size()-1);
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << ' ';
    }
}