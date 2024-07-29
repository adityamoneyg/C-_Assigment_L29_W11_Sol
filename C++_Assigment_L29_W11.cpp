#include<iostream>
using namespace std;
int minRec(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int minVal = minRec(arr + 1, n - 1);
    return arr[0] < minVal ? arr[0] : minVal;
}
int main() {
    int arr[] = { 10, 5, 7, 3, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int minElement = minRec(arr, n);
    cout << "Minimum element is: " << minElement;
}

//                                      2 Solution

#include<iostream>
using namespace std;
int sumRec(int arr[], int n, int sum = 0) {
    if (n == 0) {
        return sum;
    }
    return sumRec(arr + 1, n - 1, sum + arr[0]);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = sumRec(arr, n);
    cout << "Sum of elements: " << sum;
}

//                                    3 Solution

#include<iostream>
using namespace std;
int indexOfRec(int arr[], int n, int element, int index = 0) {
    if (n == 0) {
        return -1;
    }
    if (arr[0] == element) {
        return index;
    }
    return indexOfRec(arr + 1, n - 1, element, index + 1);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = 7;
    int index = indexOfRec(arr, n, element);
    cout << "Index of " << element << " is: " << index;
}

//                                  4 Solution

#include<iostream>
using namespace std;
void printReverseRec(int arr[], int n) {
    if (n == 0) {
        return;
    }
    printReverseRec(arr + 1, n - 1);
    cout << arr[0] << " ";
}
int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printReverseRec(arr, n);  
}

//                                       5 Solution

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int start) {
    result.push_back(subset);
    for (int i = start; i < nums.size(); i++) {
        // Skip duplicates
        if (i > start && nums[i] == nums[i - 1]) continue;
        subset.push_back(nums[i]);
        backtrack(nums, result, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    backtrack(nums, result, subset, 0);
    return result;
}

int main() {
    // Example input
    vector<int> nums = {0, 2, 2};

    // Generate all subsets
    vector<vector<int>> result = subsetsWithDup(nums);

    // Print the result
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}

