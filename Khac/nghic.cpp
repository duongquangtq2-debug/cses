#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;

void wait(int ms)
{
    this_thread::sleep_for(milliseconds(ms));
}

int main()
{
    string s = "Hello World!";

    // Xóa màn hình
    cout << "\033[2J\033[H";

    // =========================
    // Hiệu ứng 1: Gõ từng chữ
    // =========================
    for (char c : s)
    {
        cout << c << flush;
        wait(180);
    }

    wait(800);

    // =========================
    // Hiệu ứng 2: Con trỏ nhấp nháy
    // =========================
    for (int i = 0; i < 8; i++)
    {
        cout << "_" << flush;
        wait(180);
        cout << "\b \b" << flush;
        wait(180);
    }

    // =========================
    // Hiệu ứng 3: Chạy sang phải
    // =========================
    for (int i = 0; i < 30; i++)
    {
        cout << "\r";

        for (int j = 0; j < i; j++)
            cout << ' ';

        cout << s << flush;

        wait(70);
    }

    // =========================
    // Hiệu ứng 4: Chạy sang trái
    // =========================
    for (int i = 30; i >= 0; i--)
    {
        cout << "\r";

        for (int j = 0; j < i; j++)
            cout << ' ';

        cout << s << flush;

        wait(70);
    }

    // =========================
    // Hiệu ứng 5: Nảy qua lại
    // =========================
    for (int k = 0; k < 3; k++)
    {
        for (int i = 0; i < 20; i++)
        {
            cout << "\r";

            for (int j = 0; j < i; j++)
                cout << ' ';

            cout << s << flush;

            wait(40);
        }

        for (int i = 20; i >= 0; i--)
        {
            cout << "\r";

            for (int j = 0; j < i; j++)
                cout << ' ';

            cout << s << flush;

            wait(40);
        }
    }

    // =========================
    // Hiệu ứng 6: Xóa từng chữ
    // =========================
    wait(500);

    for (int len = s.size(); len >= 0; len--)
    {
        cout << "\r";
        cout << string(len, ' ');

        cout << "\r";
        cout << s.substr(0, len) << flush;

        wait(170);
    }

    wait(500);

    // =========================
    // Hiệu ứng 7: Gõ lại
    // =========================
    cout << "\r";

    for (char c : s)
    {
        cout << c << flush;
        wait(150);
    }

    cout << endl;
}