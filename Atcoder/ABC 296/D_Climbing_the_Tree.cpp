#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// snail class
class Snail {
public:
    int a, b;
    Snail(int a, int b) : a(a), b(b) {}
};

// events
vector<pair<Snail, int>> events;

// maximum possible height of the tree
int h_max = 1e9;

// process events
void process_events() {
    for (auto event : events) {
        // cout<<x<<" ";
        if (event.second != 2) {
            int a = event.first.a, b = event.first.b, n = event.second;
            // check if claimed number of days is consistent with current max height
            if (h_max >= a * (n - 1) - b * (n - 1) && (h_max - a * (n - 1)) % (a - b) == 0) {
                h_max = a * (n - 1) + (h_max - a * (n - 1)) / (a - b) * a;
            }
            cout<<1<<" ";
        } else {
            int a = event.first.a, b = event.first.b;
            // binary search to find minimum number of days required to climb the tree
            int lo = 1, hi = h_max / a + 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (a * (mid - 1) - b * (mid - 1) + a * (h_max - a * (mid - 1)) / (a - b) >= h_max) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            if (a * (lo - 1) - b * (lo - 1) + a * (h_max - a * (lo - 1)) / (a - b) == h_max) {
                cout << lo << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type, a, b, n;
        cin >> type >> a >> b;
        if (type == 1) {
            cin >> n;
            Snail snail(a, b);
            events.push_back(make_pair(snail, n));
        } else {
            Snail snail(a, b);
            events.push_back(make_pair(snail, 2));
        }
    }

    process_events();
    return 0;
}
