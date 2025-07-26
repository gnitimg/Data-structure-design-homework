#include<bits/stdc++.h>
using namespace std;

typedef struct btree
{
    int data;
    struct btree* ltree;
    struct btree* rtree;
} binary_tree;

class tree
{
public:
    btree bt;
    void create(int n);
    void check(int n);

private:
    void dfs(btree* node, int depth, int& wpl);
};

void tree::create(int n)
{
    if (n <= 0) {
        bt.data = 0;
        bt.ltree = NULL;
        bt.rtree = NULL;
        return;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (arr[0] == -1) {
        bt.data = 0;
        bt.ltree = NULL;
        bt.rtree = NULL;
        return;
    }

    bt.data = arr[0];
    bt.ltree = NULL;
    bt.rtree = NULL;

    queue<btree*> q;
    q.push(&bt);
    int i = 1;

    while (!q.empty() && i < n) {
        btree* p = q.front();
        q.pop();

        if (i < n) {
            int left_val = arr[i];
            i++;
            if (left_val != -1) {
                btree* lnode = new btree;
                lnode->data = left_val;
                lnode->ltree = NULL;
                lnode->rtree = NULL;
                p->ltree = lnode;
                q.push(lnode);
            }
        }

        if (i < n) {
            int right_val = arr[i];
            i++;
            if (right_val != -1) {
                btree* rnode = new btree;
                rnode->data = right_val;
                rnode->ltree = NULL;
                rnode->rtree = NULL;
                p->rtree = rnode;
                q.push(rnode);
            }
        }
    }
}

void tree::dfs(btree* node, int depth, int& wpl)
{
    if (node == NULL) {
        return;
    }
    if (node->ltree == NULL && node->rtree == NULL) {
        wpl += node->data * depth;
        return;
    }
    dfs(node->ltree, depth + 1, wpl);
    dfs(node->rtree, depth + 1, wpl);
}

void tree::check(int n)
{
    int wpl = 0;
    dfs(&bt, 0, wpl);
    cout << wpl << endl;
}

int main()
{
    tree t;
    int n;
    cin >> n;
    t.create(n);
    t.check(0);
    return 0;
}