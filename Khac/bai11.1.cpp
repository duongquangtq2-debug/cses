#include <iostream>
#include <vector>

using namespace std;

const int N = 200001;
const int INF = 1e9;

// teleport[x] = hành tinh mà x sẽ đi tới
int teleport[N];

// ĐỒ THỊ ĐẢO:
// Nếu đồ thị gốc có:
//      x -> y
// thì rev_graph[y] sẽ chứa x.
//
// Mục đích:
// Đồ thị gốc có dạng:
//      CÂY -> CYCLE
//
// Sau khi đảo cạnh:
//      CYCLE -> CÂY
//
// Nhờ vậy ta có thể DFS từ cycle ra tất cả các cây.
vector<int> rev_graph[N];

// answer[id] = đáp án của query thứ id
int answer[N];

// queries[x] chứa tất cả query bắt đầu từ x.
//
// Ví dụ input có:
//      3 7
//      3 9
//
// thì:
//      queries[3] = {{7, id1}, {9, id2}}
//
// pair.first  = đích b
// pair.second = id của query
vector<pair<int, int>> queries[N];

// depth là "độ sâu đặc biệt" của lời giải.
//
// Nó KHÔNG hoàn toàn giống depth DFS bình thường.
//
// Với cycle:
//      c1 -> c2 -> c3 -> c1
//
// ta gán:
//      depth[c1] = 0
//      depth[c2] = -1
//      depth[c3] = -2
//
// Còn khi đi từ cycle ra cây:
//      depth tăng lên 1.
//
// Nhờ cách gán này, khoảng cách a -> b có thể tính bằng:
//
//      depth[a] - depth[b]
//
int depth[N];

// visited[x] = x đã được xử lý trong component nào đó chưa
bool visited[N];

// ============================================================
// TÌM CYCLE BẰNG FLOYD
// ============================================================
//
// Vì mỗi đỉnh chỉ có đúng 1 cạnh đi ra:
//
//      x -> teleport[x]
//
// nên chắc chắn từ một đỉnh nào đó ta sẽ đi vào cycle.
//
// Floyd dùng 2 con trỏ:
//
//      a đi 1 bước
//      b đi 2 bước
//
// Khi a == b thì chúng đã gặp nhau trong cycle.
//
vector<int> extract_cycle(int x)
{

    // a đi 1 bước
    int a = x;

    // b đi 2 bước
    int b = teleport[x];

    // Cho đến khi hai con trỏ gặp nhau
    while (a != b)
    {

        // a đi 1 bước
        a = teleport[a];

        // b đi 2 bước
        b = teleport[teleport[b]];
    }

    // Lúc này a và b đang nằm trên cycle.
    //
    // Ta đi quanh cycle một vòng để lấy toàn bộ các đỉnh.
    vector<int> cycle;

    do
    {

        // Sang đỉnh tiếp theo trong cycle
        a = teleport[a];

        // Lưu đỉnh đó
        cycle.push_back(a);

    } while (a != b);

    // Ví dụ có:
    //
    //      2 -> 5 -> 7 -> 2
    //
    // có thể thu được:
    //
    //      cycle = {5, 7, 2}
    //
    // và luôn đảm bảo:
    //
    //      cycle[0] -> cycle[1] -> ...
    //                         -> cycle[0]

    return cycle;
}

// ============================================================
// DFS TỪ CYCLE RA CÁC CÂY
// ============================================================
//
// x = đỉnh hiện tại
// d = depth của x trên đường DFS hiện tại
//
void dfs(int x, int d)
{

    // Đánh dấu x đã được duyệt
    visited[x] = true;

    // --------------------------------------------------------
    // LƯU depth CŨ
    // --------------------------------------------------------
    //
    // depth của cycle đã được gán từ trước.
    //
    // Ví dụ:
    //
    //      cycle = {2, 3, 4}
    //
    // thì:
    //
    //      depth[2] = 0
    //      depth[3] = -1
    //      depth[4] = -2
    //
    // Khi DFS đến 2, ta tạm thời gán:
    //
    //      depth[2] = 0
    //
    // Sau khi DFS xong sẽ khôi phục lại.
    //
    int previous_depth = depth[x];

    // Gán depth theo đường DFS hiện tại
    depth[x] = d;

    // ========================================================
    // XỬ LÝ TẤT CẢ QUERY BẮT ĐẦU TỪ x
    // ========================================================
    //
    // Ví dụ:
    //
    //      query: x -> b
    //
    // Nếu b nằm trên phần mà x có thể đi tới:
    //
    //      answer = depth[x] - depth[b]
    //
    // Nếu b không nằm ở đó:
    //
    //      answer = -1
    //
    for (auto [b, id] : queries[x])
    {

        // depth[b] == -INF nghĩa là b chưa nằm
        // trong đường/cycle mà x có thể đi tới.
        //
        // Nếu depth[b] > -INF:
        //      b tồn tại trong phần đang xét.
        if (depth[b] > -INF)
        {

            // Số bước từ x -> b
            answer[id] = d - depth[b];
        }
        else
        {

            // Không thể đi từ x tới b
            answer[id] = -1;
        }
    }

    // ========================================================
    // ĐI TỪ x RA CÁC CÂY
    // ========================================================
    //
    // rev_graph là đồ thị ĐẢO.
    //
    // Ví dụ đồ thị gốc:
    //
    //      6 -> 2
    //      7 -> 6
    //
    // thì đồ thị đảo:
    //
    //      2 -> 6 -> 7
    //
    // Vì vậy từ cycle 2 ta có thể DFS:
    //
    //      2
    //      |
    //      6
    //      |
    //      7
    //
    for (int y : rev_graph[x])
    {

        // Nếu y chưa được duyệt
        if (!visited[y])
        {

            // Đi xuống cây
            //
            // Vì đi thêm 1 cạnh nên depth tăng 1.
            dfs(y, d + 1);
        }
    }

    // ========================================================
    // BACKTRACK
    // ========================================================
    //
    // depth chỉ có ý nghĩa trên đường DFS hiện tại.
    //
    // Khi DFS xong x, phải trả depth[x] về trạng thái cũ.
    //
    // Ví dụ:
    //
    //      2
    //      |
    //      6
    //      |
    //      7
    //
    // Khi đang ở 7:
    //
    //      depth[2] = 0
    //      depth[6] = 1
    //      depth[7] = 2
    //
    // DFS xong 7:
    //
    //      depth[7] phải trở lại -INF.
    //
    depth[x] = previous_depth;
}

int main()
{

    int n, q;
    cin >> n >> q;

    // ========================================================
    // ĐỌC ĐỒ THỊ
    // ========================================================
    for (int i = 1; i <= n; ++i)
    {

        int t;
        cin >> t;

        // Cạnh gốc:
        //
        //      i -> t
        //
        teleport[i] = t;

        // Đồng thời tạo cạnh ĐẢO:
        //
        //      t -> i
        //
        // để sau này DFS từ cycle ra cây.
        rev_graph[t].push_back(i);

        // Ban đầu chưa có depth
        depth[i] = -INF;
    }

    // ========================================================
    // ĐỌC QUERY
    // ========================================================
    for (int i = 1; i <= q; ++i)
    {

        int a, b;
        cin >> a >> b;

        // Query:
        //
        //      a -> b
        //
        // được lưu tại a.
        //
        // i là ID của query để sau này in đúng
        // thứ tự input.
        queries[a].emplace_back(b, i);
    }

    // ========================================================
    // DUYỆT TỪNG COMPONENT
    // ========================================================
    for (int i = 1; i <= n; ++i)
    {

        // Nếu component này chưa được xử lý
        if (!visited[i])
        {

            // ------------------------------------------------
            // BƯỚC 1: TÌM CYCLE
            // ------------------------------------------------
            auto cycle = extract_cycle(i);

            // ------------------------------------------------
            // BƯỚC 2: GÁN depth CHO CYCLE
            // ------------------------------------------------
            //
            // Ví dụ:
            //
            //      cycle = {2, 5, 7, 9}
            //
            // ta gán:
            //
            //      2 :  0
            //      5 : -1
            //      7 : -2
            //      9 : -3
            //
            // cycle[0] không cần gán ở đây vì
            // DFS sẽ gán nó = 0.
            //
            for (int j = 1; j < cycle.size(); ++j)
            {
                depth[cycle[j]] = -j;
            }

            // ------------------------------------------------
            // BƯỚC 3: DFS TỪ cycle[0]
            // ------------------------------------------------
            //
            // cycle[0] được coi là depth = 0.
            //
            // DFS trên rev_graph để đi từ cycle
            // ra các cây.
            //
            dfs(cycle[0], 0);

            // ------------------------------------------------
            // BƯỚC 4: XÓA depth CỦA CYCLE
            // ------------------------------------------------
            //
            // Các giá trị:
            //
            //      -1, -2, -3, ...
            //
            // chỉ dùng cho component hiện tại.
            //
            // Sau khi xử lý xong thì xóa đi.
            //
            for (int j = 1; j < cycle.size(); ++j)
            {
                depth[cycle[j]] = -INF;
            }
        }
    }

    // ========================================================
    // IN ĐÁP ÁN
    // ========================================================
    //
    // answer được lưu theo ID query ban đầu,
    // nên dù các query được xử lý theo DFS,
    // ta vẫn in đúng thứ tự input.
    //
    for (int i = 1; i <= q; ++i)
    {
        cout << answer[i] << '\n';
    }
}