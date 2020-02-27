#include <assert.h>
#include "trout/util.h"
#include "minunit.h"

int tests_run = 0;

static char *test_tv_sub() {
    struct timeval t1 = {20, 20000000};
    struct timeval t2 = {18, 18000000};

    tv_sub(&t1, &t2);
    char *message = "test1 failed.";
    printf("%d\n", t1.tv_sec);
    mu_assert(message, t1.tv_sec == 1);
    return NULL;
}

int main() {
    mu_run_test(test_tv_sub);
    return 0;
}