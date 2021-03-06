#include <bits/stdc++.h>

using namespace std;

vector<int> A;

void printLIS(vector<int> &prev, int pos) {
    if (prev[pos] != -1) {
        printLIS(prev, prev[pos]);
    }
    cout << A[pos] << endl;
}

int main() {
    int tt;
    cin >> tt;
    cin.ignore();
    cin.ignore();
    while (tt--) {
        int tmp, pre;
        string s;
        while (getline(cin, s) && s != "") {
            stringstream ss(s);
            ss >> tmp;
            A.push_back(tmp);
        }
        int n = A.size();
        vector<int> LIS(n);
        vector<int> prev(n);
        for (int i = 0; i < n; ++i) {
            tmp = 0, pre = -1;
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i] && LIS[j] > tmp) {
                    tmp = LIS[j];
                    pre = j;
                }
            }
            LIS[i] = 1 + tmp;
            prev[i] = pre;
        }
        int pos = distance(LIS.begin(), max_element(LIS.begin(), LIS.end()));
        cout << "Max hits: " << LIS[pos] << endl;
        printLIS(prev, pos);
        if (tt)
            cout << endl;
        A.clear();
    }
    return 0;
}

/*
Author: bumpy (-_-)
date: 2-Dec-2016
*/
