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

int main(){
    int a, b;
    cin>>a>>b;

    // cout<<countNumbers(a,b)<<endl;

    cout<<recursion(a, b, 0, -1)<<endl;
}