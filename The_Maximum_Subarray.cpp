#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


pair<int, int> maxSubarray(const vector<int>& arr) {
    int n = arr.size();
    
    
    int maxSubarraySum = arr[0];
    int currentSum = arr[0];
    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSubarraySum = max(maxSubarraySum, currentSum);
    }
    
    
    int maxSubsequenceSum = 0;
    int maxElement = arr[0];
    bool hasPositive = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            maxSubsequenceSum += arr[i];
            hasPositive = true;
        }
        maxElement = max(maxElement, arr[i]);
    }
    if (!hasPositive) {
        maxSubsequenceSum = maxElement; 
    }
    
    return {maxSubarraySum, maxSubsequenceSum};
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        
        pair<int, int> result = maxSubarray(arr);
        
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
