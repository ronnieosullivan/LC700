// Solution 1:
// O(N^2)
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int res = 0;
        ++freq[start];
        --freq[end];
        int cnt = 0;
        for (auto f : freq) {
            cnt += f.second;
            res = max(cnt, res);
        }
        return res;
    }
private:
    map<int, int> freq;
};

// Solution 2:
// O(N^2)
class MyCalendarThree {
public:
    MyCalendarThree() {
        freq[INT_MIN] = 0;
        freq[INT_MAX] = 0;
        maxCnt = 0;
    }
    
    int book(int start, int end) {
        auto l = prev(freq.upper_bound(start));   // l->first < start
        auto r = freq.lower_bound(end);           // r->first >= end
        for (auto curr = l, next = curr; curr != r; curr = next) {
            ++next;
            
            if (next->first > end)
                freq[end] = curr->second;
            
            if (curr->first <= start && next->first > start)
                maxCnt = max(maxCnt, freq[start] = curr->second + 1);            
            else
                maxCnt = max(maxCnt, ++curr->second);
        }
        return maxCnt;
    }
private:
    map<int, int> freq;
    int maxCnt;
};

// Solution 3:
// my version of solution 2
class MyCalendarThree {
public:
    MyCalendarThree() {
        freq[INT_MIN] = 0;
        freq[INT_MAX] = 0;
        maxCnt = 0;
    }
    
    int book(int start, int end) {
        auto l = prev(freq.upper_bound(start)); // l->first < start
        auto it = next(l);
        auto r = freq.lower_bound(end); // r->first >= end
        freq[start] = l->second + 1;
        maxCnt = max(maxCnt, freq[start]);
        for (; it != r; it++) {
            it->second++;
            maxCnt = max(maxCnt, it->second);
        }
        if (end < it->first) {
            auto last = prev(r);
            freq[end] = last->second - 1;
        }
        return maxCnt;
    }
private:
    map<int, int> freq;
    int maxCnt;
};

// Solution 4:
// segment tree
class MyCalendarThree {
public:
    MyCalendarThree(): max_count_(0) {
        root_.reset(new Node(0, 100000000, 0));        
    }
    
    int book(int start, int end) {
        Add(start, end, root_.get());
        return max_count_;
    }
private:
    struct Node {
        Node(int l, int r, int count):l(l), m(-1), r(r), count(count){}
        int l;
        int m; // segment point
        int r;
        int count;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };
    
    void Add(int start, int end, Node* root) {
        if (root->m != -1) {
            if (end <= root->m) 
                Add(start, end, root->left.get());
            else if(start >= root->m)
                Add(start, end, root->right.get());
            else {
                Add(start, root->m, root->left.get());
                Add(root->m, end, root->right.get());
            }
            return;
        }
        
        if (start == root->l && end == root->r)
            max_count_ = max(max_count_, ++root->count);
        else if (start == root->l) {
            root->m = end;
            root->left.reset(new Node(start, root->m, root->count + 1));
            root->right.reset(new Node(root->m, root->r, root->count));
            max_count_ = max(max_count_, root->count + 1);
        } else if(end == root->r) {
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count + 1));
            max_count_ = max(max_count_, root->count + 1);
        } else {
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count));
            Add(start, end, root->right.get());
        }
    }
    
    std::unique_ptr<Node> root_;
    int max_count_;
};