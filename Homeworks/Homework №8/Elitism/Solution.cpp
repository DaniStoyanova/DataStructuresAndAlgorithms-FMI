#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
      cout << fixed << setprecision(1);
      
    priority_queue<int, vector<int>, greater<int> > minQ;
    priority_queue<int> maxQ;
    int N, a;
    
    cin >> N;
    while (N--) {
        cin >> a; 
        maxQ.push(a);
        if (maxQ.size() > minQ.size() + 1){
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        else if (!minQ.empty() && maxQ.top() > minQ.top()) {
            maxQ.push(minQ.top());
            minQ.pop();
            minQ.push(maxQ.top());
            maxQ.pop();
        }
        
        if (maxQ.size() > minQ.size()) 
            printf("%d.0\n", maxQ.top());
        else {
            a = maxQ.top() + minQ.top();
            printf("%d.%d\n", a / 2, (a & 1) ? 5 : 0);
        }
    }

    return 0;
}
