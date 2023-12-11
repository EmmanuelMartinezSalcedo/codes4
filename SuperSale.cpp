#include <iostream>
#include <vector>
using namespace std;
int main() {
  int Test;
  cin>> Test;
  while(Test > 0) 
  {
    int NumberOfObjects;
    int Price, Weight;
    int Group;
    int MaxWeight;
    int Respuesta = 0;
    vector<int> Solution(31);
    cin >> NumberOfObjects;
    for(int i = 0; i < NumberOfObjects; i++) 
    {
      cin>>Price;
      cin>>Weight;
      for(int j = 30; j >= Weight; j--)
      {
        if(Solution[j] < Solution[j - Weight] + Price)
        {
          Solution[j] = Solution[j - Weight] + Price;
        }
      }
    }
    cin>>Group;
    while(Group--) 
    {
      cin>>MaxWeight;
      Respuesta += Solution[MaxWeight];
    }
    cout<<Respuesta<<endl;
    Test--;
  }
}