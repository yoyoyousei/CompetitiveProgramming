//------UnionFind---------
struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}

    bool unite(int x, int y) {   //併合
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool isSame(int x, int y) {    //同じ集合か判定
        return root(x) == root(y);
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int size(int x) {
        return -data[root(x)];
    }
};
//--------------