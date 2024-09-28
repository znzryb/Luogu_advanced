#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 5e5 + 5;

struct Node {
    long long sum, maxSum, prefixSum, suffixSum;
    Node() : sum(0), maxSum(-1e18), prefixSum(-1e18), suffixSum(-1e18) {}
};

Node tree[MAXN * 4];
int arr[MAXN];

Node merge(const Node& left, const Node& right) {
    Node result;
    result.sum = left.sum + right.sum;
    result.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
    result.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
    result.maxSum = max({left.maxSum, right.maxSum, left.suffixSum + right.prefixSum});
    return result;
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].sum = tree[node].maxSum = tree[node].prefixSum = tree[node].suffixSum = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node].sum = tree[node].maxSum = tree[node].prefixSum = tree[node].suffixSum = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) update(node * 2, start, mid, idx, val);
    else update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int start, int end, int l, int r) {
    if (l > end || r < start) return Node();
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return merge(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 1) {
            if (a > b) swap(a, b);
            cout << query(1, 1, n, a, b).maxSum << endl;
        } else {
            update(1, 1, n, a, b);
        }
    }

    return 0;
}