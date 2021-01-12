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

int findMinArrowShots(vector<vector<int>>& points){
    if(points.size() == 0){
        return 0;
    }
    sort(points.begin(), points.end(), cmp);
    vector<int> s = points[0];
    int count = 0;
    for (int i = 1; i < points.size(); i++){
        if (points[i][0] <= s[1]){
            count++;
        }else{
            s = points[i];
        }
    }
    return points.size() - count;
}

int main(){
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int re = findMinArrowShots(points);
    cout << re;
    system("pause");
    return 0;
}