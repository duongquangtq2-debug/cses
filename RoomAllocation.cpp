#include <iostream>
#include <algorithm>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range
{
    int l, r, id;

    bool operator<(const Range &other) const
    {
        if (l != other.l)
            return l < other.l;
        if (r != other.r)
            return r > other.r;
        return id < other.id; // bắt buộc để phân biệt các phần tử
    }
};

int main()
{
    int n;
    cin >> n;

    indexed_set<Range> ranges;

    for (int i = 0; i < n; i++)
    {
        Range x;
        cin >> x.l >> x.r;
        x.id = i;
        ranges.insert(x);
    }

    // Xuất theo chỉ số
    for (int i = 0; i < n; i++)
    {
        auto x = *ranges.find_by_order(i);
        cout << x.id << " " << x.l << " " << x.r << '\n';
    }
}