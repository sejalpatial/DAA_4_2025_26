#include <bits/stdc++.h>
using namespace std;

int Depth=0;
int maxDepth = 0;

void complexRec(int n)
{
    Depth++;
    maxDepth = max(maxDepth, Depth);

    if (n <= 2)
    {
        Depth--;
        return;
    }

    int p = n;
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++)
    {
        small[i] = i * i;
    }

    reverse(small.begin(), small.end()); 

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);

    Depth--;
}

int main()
{
    int n;
    cin>>n;
    complexRec(n);
    cout << "Max recursion depth:"<<maxDepth<<endl;
    return 0;
}
//CASE 1 OF MASTER THEOREM
// Recurrence relation: t(N) = 3T(N/2) + O(N logN)
// Time Complexity: O(N^log_2 3)