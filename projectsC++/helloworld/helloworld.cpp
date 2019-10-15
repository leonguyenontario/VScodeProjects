#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c, int k)
{
    int count = 100;
    int i = 0;
    do
    {
        count--;
        if (c[i] == 1)
            count -= 2;
        i += k;
    } while (i < c.size());

    return count;
}

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k)
{

    int commonLength = 0;
    int minlength;
    s.size() >= t.size() ? minlength = t.size() : minlength = s.size();

    for (int i = 0; i < minlength; i++)
    {
        if (s[i] == t[i])
            commonLength++;
        else
            break;
    }

    if ((s.length() + t.length() - 2 * commonLength) > k)
    {
        return "No";
    }

    else if ((s.length() + t.length() - 2 * commonLength) <= k)
    {
        return "Yes";
    }

    else
    {
        return "No";
    }
}

int squares(int a, int b)
{
    int range;
    int count = 0;
    for (range = a; range <= b; ++range)
    {

        int temp = sqrt(range);

        if (temp * temp == range)

        {
            count++;
            range += temp * 2;
        }
    }

    return count;
}

// Complete the libraryFine function below.
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int result = 0;
    if (y1 > y2)
    {
        result = 10000;
        return result;
    }
    else if (y2 > y1)
    {
        return result;
    }
    else if (m1 > m2)
    {
        result += (m1 - m2) * 500;
    }
    else if (m1 < m2)
    {
        return result;
    }
    else
    {
        if (d1 > d2)
            result += (d1 - d2) * 15;
    }

    return result;
}

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr)
{
    vector<int> newv;
    vector<int> result;
    int min;
    do
    {
        min = arr[0];
        result.push_back(arr.size());
        for (int i = 1; i < arr.size(); i++)
        {
            if (min > arr[i])
                min = arr[i];
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] - min > 0)
                newv.push_back(arr[i] - min);
        }
        arr.clear();
        for (int i = 0; i < newv.size(); i++)
        {
            arr.push_back(newv[i]);
        }
        newv.clear();

    } while (arr.size() > 0);
    return result;
}

int jumpingOnClouds(vector<int> c)
{
    int i = 0;
    int count = 0;
    do
    {
        count++;
        if (c[i + 2] != 1)
        {
            i += 2;
        }
        else
        {
            i += 1;
        }
    } while (i <= c.size());
    return count - 1;
}

int main()
{
    vector<int> v{1, 2, 3, 3, 3, 4, 4, 4, 5};
    // cout << jumpingOnClouds(v, 2) << endl;
    // cout<<appendAndDelete("abc","abc",7);
    // cout << squares(1, 1000);
    // cout<<libraryFine(2,7,2015,1,1,2015);
    // vector<int> u = cutTheSticks(v);
    // cout << jumpingOnClouds(v);
    // bool a = binary_search(v.begin(),v.end(),1);
    // sort(v.begin(),v.end());
    // vector<int>::iterator it = lower_bound(v.begin(),v.end(),3);  //>=
    // vector<int>::iterator it2 = upper_bound(v.begin(),v.end(),4); //>
    // cout<< *it<<endl;
    // cout<< *it2<<endl;
    // cout<< it2 - it<<endl;
    set<int> set;
    set.insert(5);
    set.insert(4);
    set.insert(3);
    set.insert(2);
    for (int x : set)
    {
        cout << x << " ";
    }
    cout << endl;

    auto it = set.find(5);
    cout << *it << endl;

    auto it2 = set.lower_bound(4);
    auto it3 = set.lower_bound(6);
    if (it3 == set.end()) cout<<"can not find that number"<<endl;
    return 0;
}