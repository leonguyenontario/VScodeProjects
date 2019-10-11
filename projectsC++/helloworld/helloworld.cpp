#include <iostream>
#include <vector>
#include <string>

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

int main()
{
    vector<int> v{1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7};
    // cout<<dayOfProgrammer(2016);
    cout << designerPdfViewer(v, "zaba");
    return 0;
}