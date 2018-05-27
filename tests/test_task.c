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

        //Test 9
        const char input9[] = "     |     |      |     |";
        const char answer9[] = "\t |\t |\t  |\t |";

        k = 1;
        char *output9 = entab(input9);
        COMPARATOR(k, output9, answer9);

        ck_assert(1==k);
    }
END_TEST

START_TEST (test_enter)
    {
        //Test 0
        const char s0[] = "qwertyuio";
        int n0 = 3;
        const char answer0[] = "qwe\nrty\nuio";
        int k =1;
        char *output0 = enter(n0, s0);
        COMPARATOR(k, output0, answer0);
        ck_assert(1==k);

        //Test 1
        const char s1[] = "dlinnay stroka";
        int n1 = 4;
        const char answer1[] = "dlin\nnay \nstro\nka";
        k =1;
        char *output1 = enter(n1, s1);
        COMPARATOR(k, output1, answer1);
        ck_assert(1==k);

        //Test 2
        const char s2[] = "1234567890987654321";
        int n2 = 6;
        const char answer2[] = "123456\n789098\n765432\n1";
        k =1;
        char *output2 = enter(n2, s2);
        COMPARATOR(k, output2, answer2);
        ck_assert(1==k);

        //Test 3
        const char s3[] = "Hello, world!!!!!!!!!!!!!!!!!!!";
        int n3 = 6;
        const char answer3[] = "Hello,\n world\n!!!!!!\n!!!!!!\n!!!!!!\n!";
        k =1;
        char *output3 = enter(n3, s3);
        COMPARATOR(k, output3, answer3);
        ck_assert(1==k);

        //Test 4
        const char s4[] = "\tLublu\ttabi\t";
        int n4 = 3;
        const char answer4[] = "\tLu\nblu\n\tta\nbi\t";
        k =1;
        char *output4 = enter(n4, s4);
        COMPARATOR(k, output4, answer4);
        ck_assert(1==k);

        //Test 5
        const char s5[] = "5 * 5 = 25";
        int n5 = 2;
        const char answer5[] = "5 \n* \n5 \n= \n25";
        k =1;
        char *output5 = enter(n5, s5);
        COMPARATOR(k, output5, answer5);
        ck_assert(1==k);

        //Test 6
        const char s6[] = "QwertAsdfgZxcvb";
        int n6 = 5;
        const char answer6[] = "Qwert\nAsdfg\nZxcvb";
        k =1;
        char *output6 = enter(n6, s6);
        COMPARATOR(k, output6, answer6);
        ck_assert(1==k);

    }
END_TEST

START_TEST (test_flush)
    {
        //Test 0
        char* s0 = "// asdasdasd\nNext line for successful people//One more comment";
        char* answer = "Next line for successful people";
        char* res = flush(s0);
        ck_assert_str_eq(answer, res);

        //Test 1
        s0 = "/// // asdasdasd\n/*Next line for */successful people//One more comment";
        answer = "successful people";
        res = flush(s0);
        ck_assert_str_eq(answer, res);

        //Test 2
        s0 = "///**/func\n//";
        answer = "";
        res = flush(s0);
        ck_assert_str_eq(answer, res);

//        //Test 3
//        s0 = "/**/func\n//comment\n/* asdasdasd \nasdasdasd\nasdasd*/yet another function";
//        answer = "func\nyet another function";
//        res = flush(s0);
//        ck_assert_str_eq(answer, res);
    }
END_TEST

START_TEST (test_htoi)
    {
        //Test 0
        char *s0 = "0x123";
        int answer = 291;
        int res = htoi(s0);
        ck_assert_int_eq(answer, res);

        //Test 1
        char *s1 = "123";
        answer = 291;
        res = htoi(s1);
        ck_assert_int_eq(answer, res);

        //Test 2
        char *s2 = "0";
        answer = 0;
        res = htoi(s2);
        ck_assert_int_eq(answer, res);

        //Test 3
        char *s3 = "0xfA3";
        answer = 4003;
        res = htoi(s3);
        ck_assert_int_eq(answer, res);

        //Test 4
        char *s4 = "0XaBcDeF";
        answer = 11259375;
        res = htoi(s4);
        ck_assert_int_eq(answer, res);

        //Test 5
        char *s5 = "fFFf";
        answer = 65535;
        res = htoi(s5);
        ck_assert_int_eq(answer, res);

        //Test 6
        char *s6 = "0x0";
        answer = 0;
        res = htoi(s6);
        ck_assert_int_eq(answer, res);
    }
END_TEST

START_TEST (test_squeeze)
    {
        //Test 0
        char *s0 = "abracadabra";
        char *r0 = "abcd";
        char *answer0 = "rr";
        char *res0 = squeeze(s0, r0);
        int k = 1;
        COMPARATOR(k, answer0, res0);
        ck_assert_int_eq(k, 1);

        //Test 1
        char *s1 = "I don't give a hack what I am doing";
        char *r1 = " ";
        char *answer1 = "Idon'tgiveahackwhatIamdoing";
        char *res1 = squeeze(s1, r1);
        k = 1;
        COMPARATOR(k, answer1, res1);
        ck_assert_int_eq(k, 1);

        //Test 2
        char *s2 = "dcba";
        char *r2 = "abcd";
        char *answer2 = "";
        char *res2 = squeeze(s2, r2);
        k = 1;
        COMPARATOR(k, answer2, res2);
        ck_assert_int_eq(k, 1);

        //Test 3
        char *s3 = "dbcA";
        char *r3 = "abcd";
        char *answer3 = "A";
        char *res3 = squeeze(s3, r3);
        k = 1;
        COMPARATOR(k, answer3, res3);
        ck_assert_int_eq(k, 1);

        //Test 4
        char *s4 = "MissIsSiPpi";
        char *r4 = "sp";
        char *answer4 = "MiISiPi";
        char *res4 = squeeze(s4, r4);
        k = 1;
        COMPARATOR(k, answer4, res4);
        ck_assert_int_eq(k, 1);

        //Test 5
        char *s5 = "Nichego ne pomenyalos'";
        char *r5 = "";
        char *answer5 = "Nichego ne pomenyalos'";
        char *res5 = squeeze(s5, r5);
        k = 1;
        COMPARATOR(k, answer5, res5);
        ck_assert_int_eq(k, 1);

        //Test 6
        char *s6 = "Udalyau zapyatie, ibo ne nuzhni";
        char *r6 = ",";
        char *answer6 = "Udalyau zapyatie ibo ne nuzhni";
        char *res6 = squeeze(s6, r6);
        k = 1;
        COMPARATOR(k, answer6, res6);
        ck_assert_int_eq(k, 1);
    }
END_TEST

START_TEST (test_any)
    {
        //Test 0
        const char s1[] = "abcd";
        const char t1[] = "c";
        int answer = 2;
        int res = strrindex(s1, t1);
        ck_assert_int_eq(answer, res);

        //Test 1
        const char s2[] = "abracadabra";
        const char t2[] = "brac";
        answer = 1;
        res = strrindex(s2, t2);
        ck_assert_int_eq(answer, res);

        //Test 2
        const char s3[] = "lolkeklolkek";
        const char t3[] = "kek";
        answer = 9;
        res = strrindex(s3, t3);
        ck_assert_int_eq(answer, res);

        //Test 3
        const char s4[] = "1223452";
        const char t4[] = "23";
        answer = 2;
        res = strrindex(s4, t4);
        ck_assert_int_eq(answer, res);

        //Test 4
        const char s5[] = "Stroka s probelom";
        const char t5[] = " ";
        answer = 8;
        res = strrindex(s5, t5);
        ck_assert_int_eq(answer, res);

        //Test 5
        const char s6[] = "Stroka \t s \t tabami";
        const char t6[] = "\t";
        answer = 11;
        res = strrindex(s6, t6);
        ck_assert_int_eq(answer, res);

        //Test 6
        const char s7[] = "13sr65 3h95 24 5";
        const char t7[] = "5 ";
        answer = 10;
        res = strrindex(s7, t7);
        ck_assert_int_eq(answer, res);
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
        //Test 0
        int n = 100;
        int b = 16;
        char* answer0 = "64";
        char* res0 = itob(n, b);
        int k = 1;
        COMPARATOR(k, answer0, res0);
        ck_assert(1==k);

        //Test 1
        n = 12453;
        b = 8;
        char* answer1 = "30245";
        char* res1 = itob(n, b);
        k = 1;
        COMPARATOR(k, answer1, res1);
        ck_assert(1==k);

        //Test 2
        n = 234;
        b = 5;
        char* answer2 = "1414";
        char* res2 = itob(n, b);
        k = 1;
        COMPARATOR(k, answer2, res2);
        ck_assert(1==k);

        //Test 3
        n = 890;
        b = 12;
        char* answer3 = "622";
        char* res3 = itob(n, b);
        k = 1;
        COMPARATOR(k, answer3, res3);
        ck_assert(1==k);

        //Test 4
        n = -5;
        b = 2;
        char* answer4 = "-101";
        char* res4 = itob(n, b);
        k = 1;
        COMPARATOR(k, answer4, res4);
        ck_assert(1==k);

        //Test 5
        n = 15;
        b = -1;
        char* answer5 = "Base must be > 1";
        char* res5 = itob(n, b);
        k = 1;
        COMPARATOR(k, answer5, res5);
        ck_assert(1==k);

        //Test 6
        n = 300000000;
        b = 2;
        char* answer6 = "10001111000011010001100000000";
        char* res6 = itob(n, b);
        k = 1;
        COMPARATOR(k, answer6, res6);
        ck_assert(1==k);


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