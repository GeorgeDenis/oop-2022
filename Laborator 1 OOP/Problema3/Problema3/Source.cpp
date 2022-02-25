#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <algorithm>
#include <stdio.h>
int main() {
    char sir[101][101], secventa[101];
    char* p;
    int n = 0;
    int i, j;
    scanf("%[^\n]s", secventa);
    p = strtok(secventa, " ");
    while (p != NULL) {
        strcpy(sir[n], p);
        n++;
        p = strtok(NULL, " ");
    }

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++) {
            if (strlen(sir[i]) < strlen(sir[j]))
                std::swap(sir[i], sir[j]);
            else if (strlen(sir[i]) == strlen(sir[j]))
                if (strcmp(sir[i], sir[j]) < 0)
                    std::swap(sir[i], sir[j]);
        }

    for (j = 0; j < n; j++)
        printf("%s\n", sir[j]);
    return 0;
}