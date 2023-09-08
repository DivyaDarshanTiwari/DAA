#include <stdio.h>
#include<string.h>

int findSubstring(const char* t, const char* p, int n, int m) {
    for (int i = 0; i < n - m; i++) {
        int j = 0;
        while (j < m && t[i + j] == p[j]) 
        {
            j++;
        }
        if (j == m)
            return i;
    }
    printf("No match found\n");
    return -1;
}

int main() {
    const char* t = "aejbfiaudfjigfadifhdaifjad";
    const char* p = "ad";
    int n = strlen(t);
    int m = strlen(p);

    int index = findSubstring(t, p, n, m);
    printf("Substring found at index: %d\n", index);

    return 0;
}