#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word)
{
    int s = word.size();
    int max;
    vector<int> wordSize;

    for (int i = 0; i < s; i++)
    {
        char temp = word[i];
        wordSize.push_back(int(temp) - 97);
    }
    max = h[wordSize[0]];

    for (int i = 0; i < s; i++)
    {
        if (max < h[wordSize[i]])
            max = h[wordSize[i]];
    }

    return max * s;
}

int utopianTree(int n)
{
    int result = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
            result++;
        else
            result *= 2;
    }
    return result;
}

string angryProfessor(int k, vector<int> a)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= 0)
            count++;
    }
    if (count >= k)
        return "NO";
    else
        return "YES";
}

// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k)
{
    string str, ret;
    int count = 0;
    int tempNum;
    for (int t = i; t <= j; t++)
    {
        ret = "";
        str = to_string(t);
        for (int k = str.size() - 1; k >= 0; k--)
        {
            ret += str[k];
        }
        stringstream iss(ret);
        iss >> tempNum;
        if ((t - tempNum) % k == 0)
            count++;
    }
    return count;
}

// Complete the viralAdvertising function below.
int viralAdvertising(int n)
{
    vector<int> v1, v2, v3;
    for (int i = 0; i < n; i++)
    {
        i == 0 ? v1.push_back(5) : v1.push_back(v2[i - 1] * 3);
        v2.push_back(v1[i] / 2);
        i == 0 ? v3.push_back(v2[0]) : v3.push_back(v3[i - 1] + v2[i]);
    }
    return v3[v3.size() - 1];
}

// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s)
{
    int a = s + m - 1;
    if (a > n)
    {
        if (a % n == 0)
        {
            return n;
        }
        return a % n;
    }
    return a;
}

// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries)
{
    deque<int> d;
    vector<int> c;
    int temp;
    for (int i = 0; i < a.size(); i++)
    {
        d.push_back(a[i]);
    }
    for (int i = 0; i < k; i++)
    {
        temp = d.back();
        d.pop_back();
        d.push_front(temp);
    }
    for (int i = 0; i < queries.size(); i++)
    {
        c.push_back(d[queries[i]]);
    }

    return c;
}

// Complete the superReducedString function below.
string superReducedString(string s)
{

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            i = -1;
        }
    }

    if (s.empty())
        return "Empty String";
    else
        return s;
}

// Complete the camelcase function below.
int camelcase(string s)
{
    int count = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (int(s[i]) < 97)
            count++;
    }

    return count;
}

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p)
{
    vector<int> result, temp;
    for (int i = 1; i <= p.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] == i)
                temp.push_back(j + 1);
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] == temp[i])
                result.push_back(j + 1);
        }
    }

    return result;
}

int main()
{
    vector<int> v{5, 2, 1, 3, 4};
    // cout<<designerPdfViewer(v,"abc");
    // cout<<utopianTree(9);
    // cout<<angryProfessor(3,v);
    // cout<<beautifulDays(1,2,3);
    // cout<<viralAdvertising(3);
    // cout << saveThePrisoner(7, 19, 2);
    // vector<int>c = circularArrayRotation(v,1,v);
    // cout<<superReducedString("abc");
    // cout << camelcase("saveChangesInTheEditor");
    permutationEquation(v);
    return 0;
}