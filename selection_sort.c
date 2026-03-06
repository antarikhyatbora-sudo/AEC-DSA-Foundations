#include <stdio.h>
#include <string.h>
int main() {
    char str[100], temp;
    int i, j, n, max;
    printf("Enter string: ");
    gets(str);
    n = strlen(str);

    for(i=0; i<n-1; i++) {
        max = i;
        for(j=i+1; j<n; j++)
            if(str[j] > str[max])
                max = j;
        temp = str[i];
        str[i] = str[max];
        str[max] = temp;
    }

    printf("Sorted in Descending order: %s", str);
    return 0;
}
