#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void myMerge(vector<int>& arr, vector<int>& res,int start,int end) {
    if (start >= end) {
        return;
    }

    int len = end - start;
    //+的优先级为2，要高于>>为6的优先级，因此会先计算加法，所以要加括号
    int mid = (len >> 1) + start;
    int start1 = start;
    int start2 = mid + 1;
    int end1 = mid;
    int end2 = end;
    myMerge(arr, res, start1, end1);
    myMerge(arr, res, start2, end2);

    int k = start;
    while (start1 <= end1 && start2 <= end2) {
        res[k++] = arr[start1] > arr[start2] ? arr[start2++] : arr[start1++];
    }
    while (start1 <= end1) {
        res[k++] = arr[start1++];
    }
    while (start2 <= end2) {
        res[k++] = arr[start2++];
    }

    for (k = start; k <= end; k++) {
        arr[k] = res[k];
    }
}

void myMergeSort(vector<int> &arr,vector<int> &res) {
    int len = arr.size();
    myMerge(arr, res, 0, len - 1);
}

int main() {
    vector<int> arr = { 1,3,5,7,8,6,4,2 };
    vector<int> res(arr.size());

    myMergeSort(arr, res);
}