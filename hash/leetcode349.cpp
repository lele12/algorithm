#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    set<int> ss;
    for (int i = 0; i < nums1.size(); i++){
        ss.insert(nums1[i]);
    }

    set<int> re;
    // vector<int> re;
    for (int i = 0; i < nums2.size(); i++){
        if(ss.count(nums2[i])){
            re.insert(nums2[i]);
        }
    }
    return vector<int>(re.begin(), re.end());
}

int main(){
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9};
    vector<int> re = intersection(nums1, nums2);
    for (int i = 0; i < re.size(); i++){
        cout << re[i] << ' ';
    }
    system("pause");
    return 0;
}