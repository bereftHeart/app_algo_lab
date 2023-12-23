#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    int n = 9, s[9];
    int arr[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int sum = 0, k = 3;
    s[-1] = 0;
    for (int i=0; i<n; i++) s[i] = s[i-1] + arr[i];
    int curr_st = 0, best_start, bets_end;
    float curr_avg, new_avg, avg_k, best_avg = (float)INT_MIN;

    for (int i = 0; i < n-k; i++) {
        avg_k = (float) (s[i+k-1] - s[i-1]) / k; // tbc cua k phan tu i den i+k
        new_avg = (float) (s[i+k-1-curr_st] - s[curr_st-1]) / (i+k-curr_st); // tbc cua i+k-curr_st phan tu

        if (new_avg < avg_k){
            curr_avg = avg_k;
            curr_st = i;
        } else 
            curr_avg = new_avg;
            
        if (curr_avg > best_avg){ // cap nhat tbc tot nhat
            best_avg = curr_avg;
            best_start = curr_st;
            bets_end = i+k-1;
        }

        // cout << curr_avg << " start at " << curr_st << " end at " << i+k-1 << endl;

    }

    cout << "Max avg =" << best_avg << " from a" << best_start << " to a" << bets_end ;
    
}