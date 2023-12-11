#include <iostream>
#include <vector>

using namespace std;

vector<int> combinar(vector<int> a, vector<int> b) 
{
    vector<int> c;
    int i = 0;
    int j = 0;
    while (a.size() > i && b.size() > j)
    {
        if (a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    while (a.size() > i)
    {
        c.push_back(a[i]);
        i++;
    }
    while (b.size() > j)
    {
        c.push_back(b[j]);
        j++;
    }
    return c;
}

vector<int> mergeSort(vector<int> V)
{
    int size = V.size();
    if (size == 1)
    {
        return V;
    }
    int mid = size / 2;
    vector<int> izq(V.begin(), V.begin() + mid);
    vector<int> der(V.begin() + mid, V.end());
    izq = mergeSort(izq);
    der = mergeSort(der);
    return combinar(izq, der);
}
int main()
{
    vector<int> V2 = { 10, 2, 3, 1, 6, 8, 4, 5, 7, 9 };
    vector<int> sol2 = mergeSort(V2);
    for (int i = 0; i < sol2.size(); i++)
    {
        cout << sol2[i] << ' ';
    }
}