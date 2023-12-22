#include <bits/stdc++.h>
using namespace std;

int check_incorrectphone(string phone){
    if (phone.size()!=10) return 1;
    for (int i=0; i<phone.size(); i++)
        if (phone[i] < '0' || phone[i] > '9') return 1;
    return 0;
}

map<string, int> numbercall, timecall;

int count_time_call(string start, string end){
    int start_time = (start[0]- '0')*36000 + (start[1]- '0')*3600 + (start[3]- '0')*600 + (start[4]- '0')*60 + (start[6]- '0')*10 + (start[7]- '0');
    int end_time = (end[0]- '0')*36000 + (end[1]- '0')*3600 + (end[3]- '0')*600 + (end[4]- '0')*60 + (end[6]- '0')*10 + (end[7]- '0');
    return end_time - start_time;
}

int main(){
    int total_calls = 0, incorrect_phone_calls = 0;
    string type, from_num, to_num, date, stime, etime;
    do {
        cin >> type;
        if (type == "#") break;
        cin >> from_num >> to_num >> date >> stime >> etime;
        if (check_incorrectphone(from_num) || check_incorrectphone(to_num)) 
            incorrect_phone_calls++;
        numbercall[from_num]++;
        timecall[from_num] += count_time_call(stime, etime);
        total_calls++;
    } while (type != "#");

    int check_phone_call = incorrect_phone_calls == 0 ? 1 : 0;

    do {
        cin >> type;
        if (type == "#") break;
        
        if (type == "?check_phone_number")
            cout << check_phone_call << endl;
        else if (type == "?number_total_calls")
            cout << total_calls << endl;
        else if (type == "?number_calls_from"){
            cin >> from_num;
            cout << numbercall[from_num] << endl;
        }
        else if (type == "?count_time_calls_from"){
            cin >> from_num;
            cout << timecall[from_num] << endl;
        }
    } while (type != "#");
}