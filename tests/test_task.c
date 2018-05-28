//
// Created by cubazis on 25.05.18.
//

#include <check.h>
#include "task.h"


#define TOL_STRICT 1e-9

#ifndef COMPARATOR
#define COMPARATOR(res, c1, c2) do                    \
    {                                             \
        int i = 0;                           \
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

        char *output1 = detab(input1);
        ck_assert_str_eq(output1, answer1);

        //Test 2
        const char input2[] = "abc\t\t\ta";
        const char answer2[] = "abc            a";

        char *output2 = detab(input2);
        ck_assert_str_eq(output2, answer2);
        //Test 3

        const char input3[] = "";
        const char answer3[] = "";

        char *output3 = detab(input3);
        ck_assert_str_eq(output3, answer3);

        //Test 4


        const char input4[] = "abc";
        const char answer4[] = "abc";

        char *output4 = detab(input4);
        ck_assert_str_eq(output4, answer4);

        //Test 5

        const char input5[] = "\t\t\t\t\t\t";
        const char answer5[] = "                        ";

        char *output5 = detab(input5);
        ck_assert_str_eq(output5, answer5);


        //Test 6

        const char input6[] = "I\tam\tvery\tbored\t";
        const char answer6[] = "I    am    very    bored    ";

        char *output6 = detab(input6);
        ck_assert_str_eq(output6, answer6);


        //Test 7

        const char input7[] = "\tThis is very long sentence.\tIt contains four tabs.\tAnd this is very cool.\t";
        const char answer7[] = "    This is very long sentence.    It contains four tabs.    And this is very cool.    ";

        char *output7 = detab(input7);
        ck_assert_str_eq(output7, answer7);

    }
END_TEST

START_TEST (test_entab)
    {
        //Test 1
        const char input1[] = "abc    ";
        const char answer1[] = "abc\t";

        char *output1 = entab(input1);
        ck_assert_str_eq(output1, answer1);

        //Test 2
        const char input2[] = "abc      ";
        const char answer2[] = "abc\t  ";

        char *output2 = entab(input2);
        ck_assert_str_eq(output2, answer2);


        //Test 3
        const char input3[] = "abc            ";
        const char answer3[] = "abc\t\t\t";

        char *output3 = entab(input3);

        ck_assert_str_eq(output3, answer3);

        //Test 4
        const char input4[] = "                        ";
        const char answer4[] = "\t\t\t\t\t\t";

        char *output4 = entab(input4);
        ck_assert_str_eq(output4, answer4);


        //Test 5
        const char input5[] = "";
        const char answer5[] = "";

        char *output5 = entab(input5);
        ck_assert_str_eq(output5, answer5);


        //Test 6
        const char input6[] = "Wow  this sentece  have    difference  size    of   spaces.";
        const char answer6[] = "Wow  this sentece  have\tdifference  size\tof   spaces.";

        char *output6 = entab(input6);
        ck_assert_str_eq(output6, answer6);


        //Test 7
        const char input7[] = "What\tabout\ttabs\there???";
        const char answer7[] = "What\tabout\ttabs\there???";

        char *output7 = entab(input7);
        ck_assert_str_eq(output7, answer7);

        //Test 8
        const char input8[] = "So      Much   Spaces     Around        Here          .     ";
        const char answer8[] = "So\t  Much   Spaces\t Around\t\tHere\t\t  .\t ";

        char *output8 = entab(input8);
        ck_assert_str_eq(output8, answer8);


        //Test 9
        const char input9[] = "     |     |      |     |";
        const char answer9[] = "\t |\t |\t  |\t |";

        char *output9 = entab(input9);
        ck_assert_str_eq(output9, answer9);

    }
END_TEST

START_TEST (test_enter)
    {
        //Test 0
        const char s0[] = "qwertyuio";
        int n0 = 3;
        const char answer0[] = "qwe\nrty\nuio";
        char *output0 = enter(n0, s0);
        ck_assert_str_eq(output0, answer0);


        //Test 1
        const char s1[] = "dlinnay stroka";
        int n1 = 4;
        const char answer1[] = "dlin\nnay \nstro\nka";
        char *output1 = enter(n1, s1);
        ck_assert_str_eq(output1, answer1);

        //Test 2
        const char s2[] = "1234567890987654321";
        int n2 = 6;
        const char answer2[] = "123456\n789098\n765432\n1";
        char *output2 = enter(n2, s2);
        ck_assert_str_eq(output2, answer2);


        //Test 3
        const char s3[] = "Hello, world!!!!!!!!!!!!!!!!!!!";
        int n3 = 6;
        const char answer3[] = "Hello,\n world\n!!!!!!\n!!!!!!\n!!!!!!\n!";
        char *output3 = enter(n3, s3);
        ck_assert_str_eq(output3, answer3);


        //Test 4
        const char s4[] = "\tLublu\ttabi\t";
        int n4 = 3;
        const char answer4[] = "\tLu\nblu\n\tta\nbi\t";
        char *output4 = enter(n4, s4);
        ck_assert_str_eq(output4, answer4);

        //Test 5
        const char s5[] = "5 * 5 = 25";
        int n5 = 2;
        const char answer5[] = "5 \n* \n5 \n= \n25";
        char *output5 = enter(n5, s5);
        ck_assert_str_eq(output5, answer5);


        //Test 6
        const char s6[] = "QwertAsdfgZxcvb";
        int n6 = 5;
        const char answer6[] = "Qwert\nAsdfg\nZxcvb";
        char *output6 = enter(n6, s6);
        ck_assert_str_eq(output6, answer6);


    }
END_TEST

START_TEST (test_flush)
    {
        //Test 0
        char *s0 = "// asdasdasd\nNext line for successful people//One more comment";
        char *answer = "Next line for successful people";
        char *res = flush(s0);
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
//        char *s1 = "/**/func\n//comment\n/* asdasdasd \nasdasdasd\nasdasd*/yet another function";
//        answer = "func\nyet another function";
//        res = flush(s1);
//        ck_assert_str_eq(answer, res);
//
//        //Test 4
//        //Test that comments in string is not deleted
//        char s2[] = "//This is normal comment\nchar *bla = \"//however this is not a normal comment\"";
//        answer ="char *bla = \"//however this is not a normal comment\"";
//        res = flush(s2);
        ck_assert_str_eq(answer, res);
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
        ck_assert_str_eq(answer0, res0);


        //Test 1
        char *s1 = "I don't give a hack what I am doing";
        char *r1 = " ";
        char *answer1 = "Idon'tgiveahackwhatIamdoing";
        char *res1 = squeeze(s1, r1);
        ck_assert_str_eq(answer1, res1);


        //Test 2
        char *s2 = "dcba";
        char *r2 = "abcd";
        char *answer2 = "";
        char *res2 = squeeze(s2, r2);
        ck_assert_str_eq(answer2, res2);

        //Test 3
        char *s3 = "dbcA";
        char *r3 = "abcd";
        char *answer3 = "A";
        char *res3 = squeeze(s3, r3);
        ck_assert_str_eq(answer3, res3);


        //Test 4
        char *s4 = "MissIsSiPpi";
        char *r4 = "sp";
        char *answer4 = "MiISiPi";
        char *res4 = squeeze(s4, r4);
        ck_assert_str_eq(answer4, res4);


        //Test 5
        char *s5 = "Nichego ne pomenyalos'";
        char *r5 = "";
        char *answer5 = "Nichego ne pomenyalos'";
        char *res5 = squeeze(s5, r5);
        ck_assert_str_eq(answer5, res5);


        //Test 6
        char *s6 = "Udalyau zapyatie, ibo ne nuzhni";
        char *r6 = ",";
        char *answer6 = "Udalyau zapyatie ibo ne nuzhni";
        char *res6 = squeeze(s6, r6);
        ck_assert_str_eq(answer6, res6);

    }
END_TEST

START_TEST (test_any)
    {
        //Test 0
        const char s1[] = "a";
        const char s2[] = "a";
        int answer = 0;
        int res = any(s1, s2);
        ck_assert_int_eq(answer, res);

        //Test 1
        const char s3[] = "se";
        const char s4[] = "e";
        answer = 1;
        res = any(s3, s4);
        ck_assert_int_eq(answer, res);

        //Test 2
        const char s5[] = "blablabla";
        const char s6[] = "kek";
        answer = -1;
        res = any(s5, s6);
        ck_assert_int_eq(answer, res);

        //Test 3
        const char s7[] = "  ";
        const char s8[] = " lol";
        answer = 0;
        res = any(s7, s8);
        ck_assert_int_eq(answer, res);

        //Test 4
        const char s9[] = " stroka s probelami";
        const char s10[] = " i eta stroka ";
        answer = 0;
        res = any(s9, s10);
        ck_assert_int_eq(answer, res);

        //Test 5
        const char s11[] = "stroka s tabom\t";
        const char s12[] = "\t";
        answer = 14;
        res = any(s11, s12);
        ck_assert_int_eq(answer, res);

        //Test 6
        const char s13[] = "123";
        const char s14[] = "321";
        answer = 0;
        res = any(s13, s14);
        ck_assert_int_eq(answer, res);

        //Test 7
        const char s15[] = "'*4$";
        const char s16[] = "\t$";
        answer = 3;
        res = any(s15, s16);
        ck_assert_int_eq(answer, res);

    }
END_TEST

START_TEST (test_setbits)
    {
        //Test 1
        unsigned int x = 138;
        unsigned int y = 503;
        int p = 4;
        int n = 3;
        unsigned int answer = 158;
        unsigned res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        //Test 2
        x = 74;
        y = 503;
        p = 3;
        n = 3;
        answer = 78;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        //Test 3
        x = 14;
        y = 42;
        p = 2;
        n = 0;
        answer = 14;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        //Test 4
        x = 14;
        y = 42;
        p = 3;
        n = 3;
        answer = 4;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        //Test 5
        x = 13234;
        y = 43222;
        p = 3;
        n = 0;
        answer = x;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        //Test 6
        x = 14;
        y = 42;
        p = 2;
        n = 3;
        answer = 10;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        //Test 7
        x = 74;
        y = 503;
        p = 3;
        n = 4;
        answer = 71;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);


        //Test 8
        x = 74;
        y = 503;
        p = 0;
        n = 1;
        answer = 75;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);

        //Test 9
        x = 503;
        y = 74;
        p = 8;
        n = 9;
        answer = 74;
        res = setbits(x, p, n, y);
        ck_assert_int_eq(answer, res);
    }
END_TEST

START_TEST (test_binsearch)
    {
        //Test 0
        int v0[] = {1, 4, 7, 8, 34, 55};
        int x = 7;
        int answer = 2;
        int res = binsearch(x, v0, 6);
        ck_assert_int_eq(answer, res);

        //Test 1
        x = 3;
        answer = -1;
        res = binsearch(x, v0, 6);
        ck_assert_int_eq(answer, res);

        //Test 2
        int v2[] = {34};
        x = 7;
        answer = -1;
        res = binsearch(x, v2, 1);
        ck_assert_int_eq(answer, res);

        //Test 3
        x = 34;
        answer = 0;
        res = binsearch(x, v2, 1);
        ck_assert_int_eq(answer, res);

        //Test 4
        int v4[] = {};
        x = 100;
        answer = -1;
        res = binsearch(x, v4, 0);
        ck_assert_int_eq(answer, res);
    }
END_TEST

START_TEST (test_escape)
    {
        //Test 1
        const char input1[] = "abc\t";
        const char answer1[] = "abc\\t";

        char *output1 = escape(input1);
        ck_assert_str_eq(answer1, output1);

        //Test 2
        const char input2[] = "";
        const char answer2[] = "";

        char *output2 = escape(input2);
        ck_assert_str_eq(answer2, output2);

        //Test 3
        const char input3[] = "This\bis\bsome\breally\blong\btext.\nI\breally\blike\those.\nYou\bcan\bdo\bwhatever\byou\bwant\bwith\bthis.\nFor\bexample:\bspam\btabs\t\t\t\t\t\t\t\t";
        const char answer3[] = "This\\bis\\bsome\\breally\\blong\\btext.\\nI\\breally\\blike\\those.\\nYou\\bcan\\bdo\\bwhatever\\byou\\bwant\\bwith\\bthis.\\nFor\\bexample:\\bspam\\btabs\\t\\t\\t\\t\\t\\t\\t\\t";

        char *output3 = escape(input3);
        ck_assert_str_eq(answer3, output3);

        //Test 4
        const char input4[] = "Let's test all the escapes, right?\a\b\f\n\r\t\v\\\'\"\?";
        const char answer4[] = "Let\\\'s test all the escapes, right\\?\\a\\b\\f\\n\\r\\t\\v\\\\\\\'\\\"\\?";

        char *output4 = escape(input4);
        ck_assert_str_eq(answer4, output4);


    }
END_TEST

START_TEST (test_expand)
    {
        //Test 0
        char s0[] = "a-d";
        char answer0[] = "abcd";
        char *res0 = expand(s0);
        ck_assert_str_eq(answer0, res0);


        //Test 1
        char s1[] = "a-d0-9";
        char answer1[] = "abcd0123456789";
        char *res1 = expand(s1);
        ck_assert_str_eq(answer1, res1);

        //Test 2
        char s2[] = "-a-d";
        char answer2[] = "-abcd";
        char *res2 = expand(s2);
        ck_assert_str_eq(answer2, res2);

        //Test 3
        char s3[] = "-a-d-";
        char answer3[] = "-abcd-";
        char *res3 = expand(s3);
        ck_assert_str_eq(answer3, res3);

        //Test 4
        char s4[] = "a-d-e";
        char answer4[] = "abcde";
        char *res4 = expand(s4);
        ck_assert_str_eq(answer4, res4);


        //Test 5
        char s5[] = "";
        char answer5[] = "";
        char *res5 = expand(s5);
        ck_assert_str_eq(answer5, res5);


        //Test 6
        char s6[] = "a-z0-c";
        char answer6[] = "abcdefghijklmnopqrstuvwxyz0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abc";
        char *res6 = expand(s6);
        ck_assert_str_eq(answer6, res6);


    }
END_TEST

START_TEST (test_itoa)
    {
        //Test 0
        int x = 123;
        char *res0 = itoa(x);
        char *answer0 = "123";
        ck_assert_str_eq(res0, answer0);

        //Test 1
        x = -2147483648;
        char *res1 = itoa(x);
        char *answer1 = "-2147483648";
        ck_assert_str_eq(res1, answer1);

        //Test 2
        x = -2000000000;
        char *res2 = itoa(x);
        char *answer2 = "-2000000000";
        ck_assert_str_eq(res2, answer2);

        //Test 3
        x = 6124224;
        char *res3 = itoa(x);
        char *answer3 = "6124224";
        ck_assert_str_eq(res3, answer3);
    }
END_TEST

START_TEST (test_itob)
    {
        //Test 0
        int n = 100;
        int b = 16;
        char *answer0 = "64";
        char *res0 = itob(n, b);
        ck_assert_str_eq(answer0, res0);


        //Test 1
        n = 12453;
        b = 8;
        char *answer1 = "30245";
        char *res1 = itob(n, b);
        ck_assert_str_eq(answer1, res1);

        //Test 2
        n = 234;
        b = 5;
        char *answer2 = "1414";
        char *res2 = itob(n, b);
        ck_assert_str_eq(answer2, res2);


        //Test 3
        n = 890;
        b = 12;
        char *answer3 = "622";
        char *res3 = itob(n, b);
        ck_assert_str_eq(answer3, res3);


        //Test 4
        n = -5;
        b = 2;
        char *answer4 = "-101";
        char *res4 = itob(n, b);
        ck_assert_str_eq(answer4, res4);


        //Test 5
        n = 15;
        b = -1;
        char *answer5 = "Base must be > 1";
        char *res5 = itob(n, b);
        ck_assert_str_eq(answer5, res5);


        //Test 6
        n = 300000000;
        b = 2;
        char *answer6 = "10001111000011010001100000000";
        char *res6 = itob(n, b);
        ck_assert_str_eq(answer6, res6);


    }
END_TEST

START_TEST (test_strrindex)
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

START_TEST (test_atofe)
    {
        //Test 0
        char s0[] = "5.5e2";
        double res = atofe(s0);
        double answer = 550;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        //Test 1
        char s1[] = "-5.5e-2";
        res = atofe(s1);
        answer = -0.0550;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        //Test 2
        char s2[] = "-5.565";
        res = atofe(s2);
        answer = -5.565;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        //Test 3
        char s3[] = "-555.5651e4";
        res = atofe(s3);
        answer = -5555651;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        //Test 4
        char s4[] = "555e-4";
        res = atofe(s4);
        answer = 0.0555;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        //Test 5
        char s5[] = "111";
        res = atofe(s5);
        answer = 111;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);

        //Test 6
        char s6[] = "-111111";
        res = atofe(s6);
        answer = -111111;
        ck_assert_double_eq_tol(res, answer, TOL_STRICT);
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