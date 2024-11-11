#include <iostream>
#include <cmath>
#include <climits> 

using namespace std;

pair<int, int> findCriticalFloor(int floors, int bottles) {
    if (floors <= 0 || bottles <= 0) {
        return {-1, -1}; 
    }
    if (floors == 1) {
        return {1, 1}; 
    }

    int maxTries = 0; 
    int minUnbrokenFloor = 0; 
    int dp[bottles + 1][floors + 1];

    for (int i = 0; i <= bottles; i++) {
        dp[i][0] = 0; 
        dp[i][1] = 1; 
    }
    for (int j = 0; j <= floors; j++) {
        dp[1][j] = j; 
     }

    for (int i = 2; i <= bottles; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX; 
            for (int x = 1; x <= j; x++) {
                int res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                 dp[i][j] = min(dp[i][j], res);
            }
         }
    }

    maxTries = dp[bottles][floors];
    minUnbrokenFloor = floors - maxTries + 1; 

    return {maxTries, minUnbrokenFloor};
}

int main() {
    int floors, bottles;

    cin >> floors;

    cin >> bottles;

    pair<int, int> result = findCriticalFloor(floors, bottles);

    cout << result.first << endl;

    return 0;
}