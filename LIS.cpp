#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> encontrarLIS(const vector<int>& s) {
    int n = s.size();
    vector<int> lis(n, 1);
    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (s[i] > s[j] && lis[i] < lis[j] + 1) 
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int longitudMaxima = *max_element(lis.begin(), lis.end());
    vector<int> resultado;
    for (int i = n - 1; i >= 0; --i) 
    {
        if (lis[i] == longitudMaxima) 
        {
            resultado.push_back(s[i]);
            --longitudMaxima;
        }
    }
    reverse(resultado.begin(),resultado.end());
    return resultado;
}

int main() {
    vector<int> s = {11, 17, 5, 8, 6, 4, 7, 12, 3};
    vector<int> lis = encontrarLIS(s);
    for (int i = 0;i < lis.size(); i++)
    {
        cout<<lis[i]<<' ';
    }

    return 0;
}