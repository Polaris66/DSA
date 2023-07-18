#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

bool adjDigits(ll n){
    int prevDigit = -1;
    int currentDigit = 0;

    while(n){
        currentDigit = n % 10;
        if(prevDigit==currentDigit){
            return false;
        }
        prevDigit = currentDigit;
        n /= 10;
    }

    return true;
}

ll countNumbers(ll a, ll b){
    ll res = 0;
    for(ll i = a; i < b + 1; i++){
        if(adjDigits(i)){
            res++;
        }
    }
    return res;
}

ll recursion(ll a, ll b, ll n, int prev_digit){
    if(n > b){
        return 0;
    }

    ll res = 0;
    if(n >= a && n <= b){
        res = 1;
        n *= 10;
        for (int i = 0; i < 10; i++)
        {
            if (i != prev_digit)
            {
                if (!(n == 0 && i == 0))
                    res += (recursion(a, b, n + i, i));
            }
        }
        return res;
    }

    res = 0;
    n *= 10;
    for(int i = 0; i < 10; i++){
        if(i!=prev_digit) 
        {   
            if(!(n==0 && i==0)){
                res += recursion(a, b, n + i, i);
            }
        }
    }

    return res;
}

vector<int> makeArray(ll n){
    vector<int> res;
    while(n){
        res.push_back(n%10);
        n /= 10;
    }
    return res;
}

ll countNumbersRecursion(vector<int> a, int index, int prev_digit, int tight){
    if(index < 0){
        return 1;
    }

    int limit = (tight==1) ? a[index] : 9;

    ll res = 0;
    for(int i = 0; i < limit + 1; i++){
        if(i!=prev_digit){
            if ((tight == 1) && (i == a[index]))
            {
                res += countNumbersRecursion(a, index - 1, i, 1);
            }
            else
            {
                res += countNumbersRecursion(a, index - 1, i, 0);
            }
        }
    }

    return res;
}

ll dp[20][11][2][2];

ll countNumberMemoization(vector<int> a, int index, int prev_digit, int tight, int started)
{
    if (index < 0)
    {
        return 1;
    }

    if(dp[index][prev_digit+1][tight][started]!=-1){
        return dp[index][prev_digit+1][tight][started];
    }

    int limit = (tight == 1) ? a[index] : 9;

    ll res = 0;
    for (int i = 0; i < limit + 1; i++)
    {   
        int new_started = (i==0)? started: 1;
        if (!started || i != prev_digit)
        {
            if ((tight == 1) && (i == a[index]))
            {
                res += countNumberMemoization(a, index - 1, i, 1, new_started);
            }
            else
            {
                res += countNumberMemoization(a, index - 1, i, 0, new_started);
            }
        }
    }
    
    dp[index][prev_digit+1][tight][started] = res;
    
    return res;
}

int main(){
    ll a, b;
    cin>>a>>b;

    // cout<<countNumbers(a,b)<<endl;

    // cout<<recursion(a, b, 0, -1)<<endl;
    // if(b==0){
    //     cout<<1<<endl;
    // }
    // else{
    //     vector<int> arrayB = makeArray(b);
    //     int resB = countNumbersRecursion(arrayB, arrayB.size()-1,-1,1);
    //     if(a==0){
    //         cout<<resB<<endl;
    //     }
    //     else{
    //         vector<int> arrayA = makeArray(a - 1);
    //         int resA = countNumbersRecursion(arrayA, arrayA.size()-1,-1,1);
    //         cout<<resB - resA<<endl;
    //     }
    // }

    if (b == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        vector<int> arrayB = makeArray(b);
        memset(dp, -1, sizeof(dp));
        ll resB = countNumberMemoization(arrayB, arrayB.size() - 1, -1, 1,0);
        if (a == 0)
        {
            cout << resB << endl;
        }
        else
        {
            vector<int> arrayA = makeArray(a - 1);
            memset(dp, -1, sizeof(dp));
            ll resA = countNumberMemoization(arrayA, arrayA.size() - 1, -1, 1,0);
            cout << resB - resA << endl;
        }
    }
}