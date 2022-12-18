#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    stack<pair<char, int> > mystack;
    string str;
    int len, max;
    pair<int, int> tempindex, maxindex;
    pair<int, int> info[100000];
    for (int i = 0; i < 100000; i++) {
        info[i].first = -1;
        info[i].second = 0;
    }

    cin >> str;
    len = str.length();
    max = 0;
    for (int i = 0; i < len; i++) {
        if (!mystack.empty()) {
            if (((mystack.top().first == '(') && (str[i] == ')')) || ((mystack.top().first == '[') && (str[i] == ']'))) {
                tempindex = { mystack.top().second, i };
                if ((tempindex.first > 0) && (info[(tempindex.first) - 1].first != -1)) {

                    info[i].second += info[(tempindex.first) - 1].second;
                    tempindex.first = info[(tempindex.first) - 1].first;
                }
                if (info[i - 1].first != -1) {

                    info[i].second += info[i - 1].second;
                }
                if (str[i] == ']') {
                    info[i].second = info[i].second + 1;
                }

                if (max < info[i].second) {
                    max = info[i].second;
                    maxindex.first = tempindex.first;
                    maxindex.second = tempindex.second;
                }
                info[i].first = tempindex.first;
                mystack.pop();
            }

            else
                mystack.push(make_pair(str[i], i));
        }
        else
            mystack.push(make_pair(str[i], i));
    }
    cout << max << endl;
    if (max == 0) {
        cout << "";
        return 0;
    }
}

