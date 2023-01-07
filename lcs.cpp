#include <iostream>
#include<vector>
using namespace std;
int topDown(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 or m == 0)
        return dp[0][0] = 0;

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = 1 + topDown(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        return dp[n][m] = max(topDown(s1, s2, n, m - 1, dp), topDown(s1, s2, n - 1, m, dp));
    }
}
int main()
{
    string s1 = "abcd";
    string s2 = "abdc";
    vector<vector<int>> dp;
    cout << topDown(s1, s2, 4, 4, dp);
}