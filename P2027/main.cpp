#include <iostream>

int main() {

    freopen("../a.in", "r", stdin);
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        if (a >= b) printf("MMM BRAINS\n"); else printf("NO BRAINS\n");
    }
    return 0;
}
