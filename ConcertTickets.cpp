#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int> price; // Khai báo 1 multiset duy nhất
    vector<int> maxprice(m);

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        price.insert(h); // Thêm từng giá tiền vào
    }

    for (auto &t : maxprice)
    {
        cin >> t;
    }

    for (auto t : maxprice)
    {
        if (price.empty())
        {
            cout << "-1" << endl;
            continue;
        }
        auto it = price.upper_bound(t);
        // Tìm vị trí vé đầu tiên có giá > t
        auto it = price.upper_bound(t);

        // Nếu it trỏ ngay đầu tập hợp -> Tất cả vé còn lại đều > t (Không mua được)
        if (it == price.begin())
        {
            cout << -1 << "\n";
        }
        else
        {
            // Lùi lại 1 bước để lấy vé có giá lớn nhất nhưng vẫn <= t
            --it;
            cout << *it << "\n";
            price.erase(it); // Xóa đúng 1 vé vừa bán
        }
    }
}
