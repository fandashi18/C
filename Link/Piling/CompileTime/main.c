#include <malloc.h>

int main() {
    void *ptr = malloc(100);
    free(ptr);
    return 0;
}
