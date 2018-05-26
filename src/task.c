//
// Created by cubazis on 25.05.18.
//

#include <math.h>
#include "task.h"
#include <string.h>

#define TAB_SIZE 4
/** The stub function
 *  just to demonstrate how to work with ck_assert
 *  please look for test case for stub function in test_task.c
 */

int stub(void) {
    return 42;
}

/** The array_changer function
 *  just to demonstrate how to work with returning of array from function
 *
 *  1) C language doesn't have strings
 *  2) array in a C language is just a segment of memory
 *  3) C lang doesn't have ability to pass array as parameter in a function
 *  4) we suppose that you don't know about memory allocation through pointers
 *
 *  so, we provide you simple demo function which change 'c' char in input array
 *  	input parameter: constant array of chars
 *  	output: pointer to memory segment in which resulting array starts
 *
 *  	extra stuff: we provide you three define macros in task.h.
 *  		you can use them in your solutions
 *  		if you don't want to use them please, don't delete them - somebody may use it
 *
 *  please look for test case for array_changer function in test_task.c
 */

char *array_changer(const char c[]) {
    char j = 0;
    int size = 0;
    STRING_LEN(size, c);
    char *b = ALLOCATE(size);

    for (; j < size;) {
        if (c[j] == 'c')
            b[j] = 'b';
        else
            b[j] = c[j];
        j++;
    }
    return b;
}

/** YOUR SOLUTIONS */

char *detab(const char input[]) {
    char i = 0;
    int j = 0;
    STRING_LEN(i, input);
    char *to_return = ALLOCATE(i);
    j = i;
    int k2 = 0;
    for (int k1 = 0; k1 < i; ++k1) {
        if (input[k1] == '\t') {
            j = j + TAB_SIZE;
            realloc(to_return, j * sizeof(char));
            for (int c = 0; c < TAB_SIZE; ++c) {
                to_return[k2] = ' ';
                k2++;
            }
        } else {
            to_return[k2] = input[k1];
            k2++;
        }
    }
    to_return[k2] = '\0';

    return to_return;
}

char *entab(const char input[]) {
    char i = 0;
    STRING_LEN(i, input);
    char *to_return = ALLOCATE(i);
    int j = i;

    int k2 = 0;

    int current_spaces = 0;

    for (int k1 = 0; k1 < i; ++k1) {
        if (input[k1] == ' ') {
            current_spaces++;
            if (current_spaces == 4) {
                current_spaces = 0;
                to_return[k2] = '\t';
                k2++;
            }
        } else {
            while (current_spaces > 0) {
                to_return[k2] = ' ';
                k2++;
                current_spaces--;
            }
            to_return[k2] = input[k1];
            k2++;
        }
    }

    to_return[k2] = '\0';
    return to_return;
}

char *enter(int n, const char input[]){
    int length = strlen(input);
    int count = 0;
    char* output = ALLOCATE(length + log2(length) + 1);
    if (length > n){
        for(int i = 0; i < length; i++){
            output[i+count] = input[i];
            if (i % n == n-1 && i != 0 && i != length - 1){
                output[i+count + 1] = '\n';
                count++;
            }
        }
    }
    int bound = length + count + 1;
    char* to = ALLOCATE(bound);
    for (int j = 0; j < bound - 1; j++) {
        to[j] = output[j];
    }
    to[bound - 1] = '\0';
    return to;
}

/** GET FROM task.h */

int htoi(const char s[]) {
    int l = 0;
    int res = 0;
    int start = 0;
    STRING_LEN(l, s);
    if (s[1] == 'x' || s[1] == 'X') {
        start = 2;
    }
    int power = 0;
    for (int i = l - 1; i >= start; i--) {
        char j = s[i];
        if (j >= 'a' && j <= 'f') {
            res += (j - 'a' + 10) * pow(16, power);
        } else if (j >= 'A' && j <= 'F') {
            res += (j - 'A' + 10) * pow(16, power);
        } else if (j >= '0' && j <= '9') {
            res += (j - '0') * pow(16, power);
        }
        power++;
    }
    return res;
}

char *squeeze(const char s1[], const char s2[]) {
    int l1 = 0, l2 = 0;
    STRING_LEN(l1, s1);
    STRING_LEN(l2, s2);
    char *res = ALLOCATE(l1);
    int flag;
    int res_i = 0;
    for (int i = 0; i < l1; i++) {
        flag = 0;
        for (int j = 0; j < l2; j++) {
            if (s1[i] == s2[j]) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            res[res_i] = s1[i];
            res_i++;
        }
    }
    res[res_i] = '\0';
    return res;
}

int any(const char s1[], const char s2[]){
    for (int i = 0; i < strlen(s1); i++ ){
        for (int j = 0; j < strlen(s2); j++ ){
            if (s1[i] == s2[j]){
                return i;
            }
        }
    }
    return -1;
}

int strrindex(const char source[], const char target[]) {
    int s_len = strlen(source);
    int t_len = strlen(target);
    int index = -1;
    for (int i = s_len - t_len + 1; i >= 0; i--) {
        if (source[i] == target[0]) {
            index = i;
            break;
        }
    }

    if (index > -1) {
        for (int i = index; i < t_len + index; i++) {
            char a = source[i];
            char b = target[i - index];
            if (a == b && i - index == t_len) return index;
            if (a != b) {
                char* to = (char*) malloc((index + 1) * sizeof(char));
                for (int j = 0; j < index; j++) {
                    to[j] = source[j];
                }
                to[index] = '\0';
                return strrindex(to, target);
            }
        }
        return index;
    }
    return index;
}