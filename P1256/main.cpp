#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 15

char st[MAX_N], path[MAX_N];
bool visit[MAX_N];

char tolower(char a) {
    return a < 'a' ? char(a + 32) : a;
}

bool cmp(char a, char b) {
    if (tolower(a) != tolower(b)) {
        return tolower(a) < tolower(b);
    }
    return a < b;
}

void dfs(int step, int n) {
    if (step == n) {
        path[n] = '\0';
        printf("%s\n", path);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            path[step] = st[i];
            dfs(step + 1, n);
            visit[i] = false;
            while (i + 1 < n && st[i + 1] == st[i]) i++;
        }
    }
}

int main() {

    freopen("../a.in", "r", stdin);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", st);
        int len = strlen(st);
        sort(st, st + len, cmp);
        memset(visit, false, sizeof visit);
        dfs(0, len);
    }

    return 0;
}
