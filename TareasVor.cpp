#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compararTuplas(const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
    if (get<2>(a) != get<2>(b))
    {
        return get<2>(a) < get<2>(b);
    }
    return get<0>(a) > get<0>(b);
}

vector<int> tareas(vector<int> b, vector<int> d)
{
    vector<int> X;
    for (int i = 0; i < b.size(); i++)
    {
        X.push_back(0);
    }
    vector<tuple<int, int, int>> coleccion;

    for (int i = 0; i < b.size(); i++) {
        coleccion.emplace_back(b[i], i, d[i]);
    }
    sort(coleccion.begin(), coleccion.end(), compararTuplas);
    int currentTime = 1;
    for (int i=0;i<coleccion.size();i++)
    {
        if (currentTime <= get<2>(coleccion[i]))
        {
            X[get<1>(coleccion[i])]=1;
            currentTime++;
        }
    }
    return X;
}
int main()
{
    vector<int> b = {50,10,15,30,60,20};
    vector<int> d = {3, 3, 3, 3, 3, 3};
    vector<int> sol = tareas(b,d);
    for (int i=0;i<b.size();i++)
    {
        cout<<b[i]<<' ';
    }
    cout<<endl;
    for (int i=0;i<d.size();i++)
    {
        cout<<d[i]<<' ';
    }
    cout<<endl<<endl;
    for (int i=0;i<sol.size();i++)
    {
        cout<<sol[i]<<' ';
    }

    return 0;
}
