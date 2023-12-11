#include<iostream>
#include<vector>
#include<tuple>

using namespace std;
void intercambiar(tuple<vector<int>,vector<float>,vector<int>>& A, int i, int j) {
    int temp1 = get<0>(A)[i];
    int temp2 = get<1>(A)[i];
    int temp3 = get<2>(A)[i];
    get<0>(A)[i] = get<0>(A)[j];
    get<0>(A)[j] = temp1;
    get<1>(A)[i] = get<1>(A)[j];
    get<1>(A)[j] = temp2;
    get<2>(A)[i] = get<2>(A)[j];
    get<2>(A)[j] = temp3;
}

int pivot(tuple<vector<int>,vector<float>,vector<int>>& V, int start, int end) {
    int i = start;
    int pivote = get<1>(V)[end];
    for (int j = start; j < end; j++) {
        if (get<1>(V)[j] >= pivote) 
        {
            intercambiar(V, i, j);
            i++;
        }
    }
    intercambiar(V, i, end);
    return i;
}

void quickSort(tuple<vector<int>,vector<float>,vector<int>>& V, int start, int end) {
    end--;
    if (start < end) 
    {
        int pivot_index = pivot(V, start, end);
        quickSort(V, start, pivot_index - 1);
        quickSort(V, pivot_index + 1, end);
    }
}

vector<int> Mochila(int M, vector<int> b, vector<int> p)
{
    vector<int> Sol(p.size(),0);
    vector<float> divs;
    for (size_t i = 0; i < p.size(); ++i) 
    {
        divs.push_back(static_cast<float>(b[i]) / p[i]);
    }
    tuple<vector<int>,vector<float>,vector<int>> aux;
    for (int i = 0; i < divs.size(); i++)
    {
        get<0>(aux).push_back(i);
        get<1>(aux).push_back(divs[i]);
        get<2>(aux).push_back(p[i]);
    }
    quickSort(aux,0, get<0>(aux).size());
    float current = 0;
    for (int i=0;i<divs.size();i++)
    {
        if(current + get<2>(aux)[i] <= M)
        {
            current = current + get<2>(aux)[i];
            Sol[get<0>(aux)[i]] = 1;
        }
    }
    return Sol;
}
int main()
{
    vector<int> p = {2, 5, 10, 5};
    vector<int> b = {20, 30, 50, 10};
    int M = 10;
    vector<int> solution = Mochila(M, b, p);
    cout << "M: " << M << endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << p[i] << ' ';
    }
    cout<<" p"<<endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << b[i] << ' ';
    }
    cout<<" b"<<endl;
    for (size_t i = 0; i < solution.size(); ++i) {
        cout << solution[i] << ' ';
    }

}