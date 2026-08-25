#include <cstdio>
#include <cstdlib>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// ================= INPUT: mmap thẳng file vào bộ nhớ, không copy qua stdio =================
static char* inBuf;
static int inPos = 0;

inline int readInt() {
    while (inBuf[inPos] < '0' || inBuf[inPos] > '9') inPos++;
    int x = 0;
    while (inBuf[inPos] >= '0' && inBuf[inPos] <= '9') {
        x = x * 10 + (inBuf[inPos] - '0');
        inPos++;
    }
    return x;
}

// ================= OUTPUT: ghi vào buffer RAM, flush 1 lần bằng write() syscall =================
static char outBuf[1 << 21]; // 2MB đủ dùng cho 2x10^5 số
static int outPos = 0;

inline void writeInt(int x) {
    if (x == 0) { outBuf[outPos++] = '0'; }
    else {
        char tmp[10];
        int len = 0;
        while (x) { tmp[len++] = '0' + (x % 10); x /= 10; }
        while (len) outBuf[outPos++] = tmp[--len];
    }
    outBuf[outPos++] = ' ';
}

// ================= BIT =================
static int bit_[200005];
static int n, LOG;

inline void update(int i, int val) {
    for (; i <= n; i += i & (-i)) bit_[i] += val;
}

inline int findKth(int k) {
    int pos = 0;
    for (int pw = LOG; pw >= 0; pw--) {
        int nxt = pos + (1 << pw);
        if (nxt <= n && bit_[nxt] < k) { pos = nxt; k -= bit_[pos]; }
    }
    return pos + 1;
}

int main() {
    // mmap toàn bộ stdin vào bộ nhớ — 0 copy, kernel map thẳng trang bộ nhớ
    struct stat st;
    fstat(0, &st);
    inBuf = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, 0, 0);

    int N = readInt();
    int K = readInt();
    n = N;

    LOG = 0;
    while ((1 << (LOG + 1)) <= n) LOG++;

    for (int i = 1; i <= n; i++) update(i, 1);

    int pos = 0;
    for (int i = 1; i <= n; i++) {
        int remain = n - i + 1;
        pos = (pos + K % remain) % remain;
        int killed = findKth(pos + 1);
        writeInt(killed);
        update(killed, -1);
    }
    outBuf[outPos++] = '\n';

    write(1, outBuf, outPos);  // ghi thẳng ra fd 1 (stdout), không qua stdio buffer
    return 0;
}