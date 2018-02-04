// priority queue
struct T {
    T(int x) : t(x) {}
    int t;
};

struct cmp {
    bool operator()(const T& a, const T& b) {
        return a.t > b.t;
    }
};

int main() {
    priority_queue<T, vector<T>, cmp> q;
    q.emplace(3);
    q.emplace(1);
    q.emplace(5);
    q.emplace(6);
    while (!q.empty()) {
        cout << q.top().t << endl;
        q.pop();
    }
}

// with system provided binary struct
int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(3);
    q.push(1);
    q.push(5);
    q.push(6);
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    }
}