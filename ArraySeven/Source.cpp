#include <iostream>
using namespace std;

int main() {
    int n, k, karman = 0;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k; // числа кратные k

    for (int i = 0; i < n; ++i) {
        if (arr[i] % k == 0) {
            karman += arr[i];
        }
    }
    cout << karman;
    return 0;
}