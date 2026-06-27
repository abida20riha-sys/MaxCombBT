#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int CoinChange(int n, vector<int> &coins, int amount)
{
    vector<vector<int>> CC(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; i++){
        CC[i][0]=1;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=amount; j++ )
        {
            if (j>=coins[i-1])
            {
                CC[i][j]=(CC[i-1][j]+CC[i][j-coins[i-1]]);
            }
            else
            {
                CC[i][j]=CC[i-1][j];
            }
        }
    }

    cout << "Actual combinations found:" << endl;
    int i = n;
    int j = amount;
    vector<int> current_combination;

    while (i > 0 && j > 0) {
        if (j >= coins[i-1] && CC[i][j - coins[i-1]] > 0) {
            current_combination.push_back(coins[i-1]);
            j = j - coins[i-1];
        } else {
            i--;
        }
    }

    for (int k = 0; k < current_combination.size(); k++) {
        cout << current_combination[k] << " ";
    }
    cout << endl;

    return CC[n] [amount];
}

int main()
{
    int n;
    cout <<"Enter the number of coins: ";
    cin >> n;

    vector <int> coins(n);
    for (int i=0; i<n; i++)
    {
        cout <<"Enter the value of coins "<<i+1<<": ";
        cin >> coins[i];
    }
    cout <<"Enter the amount: ";
    int amount;
    cin >> amount;
    int result=CoinChange (n, coins, amount);
    cout <<"Maximum no of combination: "<<result<<endl;
}
