#include<iostream>

using namespace std;
int main() {
    int s, l1, r1, l2, r2, x1 = 0, x2 = 0, q = 0;
    cin >> s >> l1 >> r1 >> l2 >> r2;
    if ((s > (r1 + r2)) || (s < (l1 + l2))) {
        cout << -1;
    }
    else {
        if ((s - l1) >= l2) {
            if (s <= (l1 + r2)) {
                cout << l1 << " " << s - l1;
            }
            else {
                q = abs(s - (l1 + r2));
                if ((l1 + q) < r1 && (r2 - q) > l2) {
                    cout << l1 + q << " " << s - (l1 + q);
                }
                else {
                    cout << -1;
                }
            }
        }
        else {
            cout << -1;
        }
    }
}