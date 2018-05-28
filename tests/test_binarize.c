//
// Created by cubazis on 24.05.18.
//
#include <check.h>
#include "binarize.h"

#ifndef COMPARATOR
#define COMPARATOR(res, c1, c2) do                    \
    {                                             \
        char i = 0;                           \
        for (;'\0' != (c1)[i];i++)            \
        {                                     \
            if((c1)[i] != (c2)[i])        \
                {                     \
                                        (res) = 0;    \
                }                     \
        }                                     \
    } while(0)
#endif

START_TEST (test_bin_u)
    {
        //Test 1
        unsigned long x = 1608637542;
        char *output = binarize_u(x);
        char *pattern = "01011111111000011101110001100110";
        ck_assert_str_eq(pattern, output);

        //Test 2
        unsigned long x1 = 3;
        char *output1 = binarize_u(x1);
        char *pattern1 = "0000000000000011";
        ck_assert_str_eq(pattern1, output1);

        //Test 3
        unsigned long x2 = 111;
        char *output2 = binarize_u(x2);
        char *pattern2 = "0000000001101111";
        ck_assert_str_eq(pattern2, output2);

        //Test 4
        unsigned long x3 = 32767;
        char *output3 = binarize_u(x3);
        char *pattern3 = "0111111111111111";
        ck_assert_str_eq(pattern3, output3);

        //Test 5
        unsigned long x4 = 32768;
        char *output4 = binarize_u(x4);
        char *pattern4 = "1000000000000000";
        ck_assert_str_eq(pattern4, output4);

        //Test 6
        unsigned long x5 = 65535;
        char *output5 = binarize_u(x5);
        char *pattern5 = "1111111111111111";
        ck_assert_str_eq(pattern5, output5);

        //Test 7
        unsigned long x6 = 65536;
        char *output6 = binarize_u(x6);
        char *pattern6 = "00000000000000010000000000000000";
        ck_assert_str_eq(pattern6, output6);

        //Test 8
        unsigned long x7 = 4294967296;
        char *output7 = binarize_u(x7);
        char *pattern7 = "0000000000000000000000000000000100000000000000000000000000000000";
        ck_assert_str_eq(pattern7, output7);

    }
END_TEST

START_TEST (test_bin_s)
    {
        signed long x = -1608637542;
        char *output = binarize_s(x);
        char *pattern = "10100000000111100010001110011010";
        ck_assert_str_eq(pattern, output);
    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("binarize");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_bin_u);
    tcase_add_test(tcase, test_bin_s);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}