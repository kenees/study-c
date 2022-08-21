#include <iostream>
using namespace std;
#include <vector>
// #include <algorithm>

void test01()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i * 1);
        v2.push_back(i * 10);
        v3.push_back(i * 100);
        v4.push_back(i * 1000);
    }

    vector<vector<int>> vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);

    for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); it++)
    {
        for (vector<int>::iterator n = (*it).begin(); n != (*it).end(); n++)
        {
            cout << (*n) << " ";
        }
        cout << endl;
    }
}

int main()
{
    test01();
    return 0;
}