#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

// class LRU {
// public:
//     LRU( int capacity ) : m_capacity( capacity ) {}
//     void set( int key , int value ) {
//         if (m_map.find( key ) == m_map.end()) {
//             if (m_map.size() < m_capacity) {
//                 m_map.insert( { key, value } );
//                 m_list.push_front( key );
//             }
//             else {
//                 int tmp = m_list.back();
//                 m_map.erase( tmp );
//                 m_list.pop_back();
//             }
//         }
//         else {
//             m_map[key] = value;
//             auto it = find( m_list.begin() , m_list.end() , key );
//             m_list.erase( it );
//             m_list.push_front( key );
//         }
//     }
//     int get( int key ) {
//         if (m_map.find( key ) == m_map.end()) {
//             return -1;
//         }
//         else {
//             int tmp = m_map[key];
//             auto it = find( m_list.begin() , m_list.end() , key );
//             m_list.erase( it );
//             m_list.push_front( key );
//             return tmp;
//         }
//     }
// private:
//     int m_capacity;
//     unordered_map<int , int> m_map;
//     list<int> m_list;
// };

// int main() {
//     int n , l;
//     cin >> n >> l;
//     LRU vl( n );
//     for (int i = 0; i < l; i++) {
//         char c;
//         cin >> c;
//         if (c == 's') {
//             int a , b;
//             cin >> a >> b;
//             vl.set( a , b );
//         }
//         else if (c == 'g') {
//             int a;
//             cin >> a;
//             cout << vl.get( a );
//         }
//         else {
//             cout << "error input!" << endl;
//         }
//     }
// }

// int main() {
//     int k , m , n;
//     cin >> k >> m >> n;
//     m += 1;
//     n += 1;
//     if (k < ( m + n - 2 )) {
//         cout << -1 << endl;
//         return 0;
//     }
//     vector<int> dp( m );
//      for (int i = 0; i < m; i++) {
//         dp[i] = 1;
//      }
//      for (int i = 1; i < n; i++) {
//          for (int j = 1; j < m; j++) {
//              dp[j] = dp[j - 1] + dp[j];
//          }
//      }
//      cout << dp[m - 1];
// }