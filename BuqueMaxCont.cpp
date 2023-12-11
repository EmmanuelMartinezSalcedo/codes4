#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
void intercambiar(pair<vector<int>, vector<int>>& A, int i, int j)
{
    int temp1 = A.first[i];
    int temp2 = A.second[i];
    A.first[i] = A.first[j];
    A.first[j] = temp1;
    A.second[i] = A.second[j];
    A.second[j] = temp2;
}

int pivot(pair<vector<int>, vector<int>>& V, int start, int end)
{
    int i = start;
    int pivote = V.second[end];
    for (int j = start; j < end; j++) {
        if (V.second[j] <= pivote) {
            intercambiar(V, i, j);
            i++;
        }
    }
    intercambiar(V, i, end);
    return i;
}

void quickSort(pair<vector<int>, vector<int>>& V, int start, int end)
{
    end--;
    if (start < end) {
        int pivot_index = pivot(V, start, end);
        quickSort(V, start, pivot_index - 1);
        quickSort(V, pivot_index + 1, end);
    }
}

vector<int> MaxCont(vector<int> &V, int capacidad)
{
    vector<int> Sol(V.size(),0);
    pair<vector<int>,vector<int>> aux;
    for (int i = 0; i < V.size(); i++)
    {
        aux.first.push_back(i);
        aux.second.push_back(V[i]);
    }
    quickSort(aux,0,aux.first.size());
    int current = 0;
    for (int i=0;i<V.size();i++)
    {
        if(current + aux.second[i] <= capacidad)
        {
            current = current + aux.second[i];
            Sol[aux.first[i]] = 1;
        }
    }
    return Sol;
}
int main()
{
    vector<int> pesos={1,5,3,2,11,10,4};
    vector<int> sol =MaxCont(pesos,25);
    for (int i=0;i<pesos.size();i++)
    {
        cout<<pesos[i]<<' ';
    }
    cout<<endl;
    for (int i=0;i<sol.size();i++)
    {
        cout<<sol[i]<<' ';
    }
}