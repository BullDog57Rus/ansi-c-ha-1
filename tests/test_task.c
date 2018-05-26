//
// Created by cubazis on 25.05.18.
//

#include <check.h>
#include "task.h"

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

START_TEST (test_stub)
    {
        ck_assert(42 == stub());
    }
END_TEST

START_TEST (test_array_changer)
    {
        const char input[] = "abcba";
        const char pattern[] = "abbba";

        /** change 'c' to 'b' */

        char *output = array_changer(input);

        /** initialise k because ck_assert need's it to be sure
         *  that he compare something initialised with 1
         *  because if COMPARATOR will not change it value, k will not have any value
         *  */
        int k = 1;

        /** get k, k, output, pattern
         *  compare output array with pattern array by elements
         *  return 0 if they are not equal
         * */
        COMPARATOR(k, output, pattern);

        /** check statement is true */
        ck_assert(1 == k);

    }
END_TEST

/** YOUT TEST CASES HERE
 *
 *  please use 'test_fname' format for naming tcases
 *  fname is function name
 *
 *  if function name is 'detab' then test case is 'test_detab'
 * */

START_TEST (test_detab)
    {
        //Test 1 detab
        const char input1[] = "abc\ta";
        const char answer1[] = "abc    a";

        int k = 1;
        char *output1 = detab(input1);
        COMPARATOR(k, output1, answer1);

        ck_assert(1==k);

        //Test 2
        const char input2[] = "abc\t\t\ta";
        const char answer2[] = "abc            a";

        k = 1;
        char *output2 = detab(input2);
        COMPARATOR(k, output2, answer2);

        ck_assert(1==k);

        //Test 3

        const char input3[] = "";
        const char answer3[] = "";

        k = 1;
        char *output3 = detab(input3);
        COMPARATOR(k, output3, answer3);

        ck_assert(1==k);

        //Test 4


        const char input4[] = "abc";
        const char answer4[] = "abc";

        k = 1;
        char *output4 = detab(input4);
        COMPARATOR(k, output4, answer4);

        ck_assert(1==k);

        //Test 5

        const char input5[] = "\t\t\t\t\t\t";
        const char answer5[] = "                        ";

        k = 1;
        char *output5 = detab(input5);
        COMPARATOR(k, output5, answer5);

        ck_assert(1==k);

        //Test 6

        const char input6[] = "I\tam\tvery\tbored\t";
        const char answer6[] = "I    am    very    bored    ";

        k = 1;
        char *output6 = detab(input6);
        COMPARATOR(k, output6, answer6);

        ck_assert(1==k);

        //Test 7

        const char input7[] = "\tThis is very long sentence.\tIt contains four tabs.\tAnd this is very cool.\t";
        const char answer7[] = "    This is very long sentence.    It contains four tabs.    And this is very cool.    ";

        k = 1;
        char *output7 = detab(input7);
        COMPARATOR(k, output7, answer7);

        ck_assert(1==k);
    }
END_TEST

START_TEST (test_entab)
    {
        //Test 1
        const char input1[] = "abc    ";
        const char answer1[] = "abc\t";

        int k = 1;
        char *output1 = entab(input1);
        COMPARATOR(k, output1, answer1);
        ck_assert(1==k);

        //Test 2
        const char input2[] = "abc      ";
        const char answer2[] = "abc\t  ";

        k = 1;
        char *output2 = entab(input2);
        COMPARATOR(k, output2, answer2);
        ck_assert(1==k);

        //Test 3
        const char input3[] = "abc            ";
        const char answer3[] = "abc\t\t\t";

        k = 1;
        char *output3 = entab(input3);
        COMPARATOR(k, output3, answer3);

        ck_assert(1==k);

        //Test 4
        const char input4[] = "                        ";
        const char answer4[] = "\t\t\t\t\t\t";

        k = 1;
        char *output4 = entab(input4);
        COMPARATOR(k, output4, answer4);

        //Test 5
        const char input5[] = "";
        const char answer5[] = "";

        k = 1;
        char *output5 = entab(input5);
        COMPARATOR(k, output5, answer5);

        ck_assert(1==k);

        //Test 6
        const char input6[] = "Wow  this sentece  have    difference  size    of   spaces.";
        const char answer6[] = "Wow  this sentece  have\tdifference  size\tof   spaces.";

        k = 1;
        char *output6 = entab(input6);
        COMPARATOR(k, output6, answer6);

        ck_assert(1==k);

        //Test 7
        const char input7[] = "What\tabout\ttabs\there???";
        const char answer7[] = "What\tabout\ttabs\there???";

        k = 1;
        char *output7 = entab(input7);
        COMPARATOR(k, output7, answer7);

        ck_assert(1==k);
        //Test 8
        const char input8[] = "So      Much   Spaces     Around        Here          .     ";
        const char answer8[] = "So\t  Much   Spaces\t Around\t\tHere\t\t  .\t ";

        k = 1;
        char *output8 = entab(input8);
        COMPARATOR(k, output8, answer8);

        ck_assert(1==k);
    }
END_TEST

START_TEST (test_enter)
    {

    }
END_TEST

START_TEST (test_flush)
    {

    }
END_TEST

START_TEST (test_htoi)
    {

    }
END_TEST

START_TEST (test_squeeze)
    {

    }
END_TEST

START_TEST (test_any)
    {

    }
END_TEST

START_TEST (test_setbits)
    {

    }
END_TEST

START_TEST (test_binsearch)
    {

    }
END_TEST

START_TEST (test_escape)
    {

    }
END_TEST

START_TEST (test_expand)
    {

    }
END_TEST

START_TEST (test_itoa)
    {

    }
END_TEST

START_TEST (test_itob)
    {

    }
END_TEST

START_TEST (test_strrindex)
    {

    }
END_TEST

START_TEST (test_atofe)
    {

    }
END_TEST


Suite *str_suite(void) {
    Suite *suite = suite_create("Home assignment 1");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_stub);
    tcase_add_test(tcase, test_array_changer);

    tcase_add_test(tcase, test_detab);
    tcase_add_test(tcase, test_entab);
    tcase_add_test(tcase, test_enter);
    tcase_add_test(tcase, test_flush);
    tcase_add_test(tcase, test_htoi);
    tcase_add_test(tcase, test_squeeze);
    tcase_add_test(tcase, test_any);
    tcase_add_test(tcase, test_setbits);
    tcase_add_test(tcase, test_binsearch);
    tcase_add_test(tcase, test_escape);
    tcase_add_test(tcase, test_expand);
    tcase_add_test(tcase, test_itoa);
    tcase_add_test(tcase, test_itob);
    tcase_add_test(tcase, test_strrindex);
    tcase_add_test(tcase, test_atofe);
    /** YOUT TEST CASES HERE */

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