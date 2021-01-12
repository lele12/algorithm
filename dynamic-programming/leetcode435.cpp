#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[1] < b[1]){
        return true;
    }else if(a[1] == b[1] && a[0] < b[0]){
        return true;
    }
    return false;
}
int eraseOverlapIntervals(vector<vector<int>>& intervals){
    if(intervals.size() <=1){
        return 0;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int count = 0;
    vector<int> s = intervals[0];
    for (int i = 1; i < intervals.size(); i++){
        if (intervals[i][0] < s[1]){
            count++;
        }else{
            s = intervals[i];
        }
    }
    return count;
}

int main(){
    vector<vector<int>> intervals = {{1,2}, {1,2},{1,2}};
    int re = eraseOverlapIntervals(intervals);
    cout << re;
    system("pause");
    return 0;
}