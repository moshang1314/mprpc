#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec( n );
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort( vec.begin() , vec.end() , greater<int>() );
    int result = vec[0];
    int a = vec[0];
    int right = vec.size() - 1;
    int left = 1;
    int index = 1;
    while (left <= right) {
        if (index == 1) {
            a = vec[right--];
            index = 0;
        }
        else {
            result += vec[left] - a;
            a = vec[left++];
            index = 1;
        }
    }
    cout << result << endl;
    return 0;
}