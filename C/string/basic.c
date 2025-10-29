#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    // string array -> stores at stack -> modifiable
    char s[] = "Hello";
    s[0] = 'X';
    printf("%s\n", s);
    printf("%lu\n", sizeof(s)); // 6 = strlen + '\0'
    printf("%lu\n", strlen(s)); // 5

    // string literal -> stores at read-only section -> non modifiable
    char *ss = "vauvau";
    // ss[0] = 'V'; // bus error
    printf("%s\n", ss); // no change
    printf("%lu\n", sizeof(ss));  // 8 = sizeof(pointer)
    printf("%lu\n", sizeof(*ss)); // 1 = s[0] -> one char
    printf("%lu\n", strlen(ss));  // 5

    ss = "but i can !"; // can assign another string..
    printf("%s\n", ss);

    ss = s;
    printf("%s\n", ss);


    /* */
    // c string always ends with '\0' -> null terminator
    char sss[4] = "abc";
    sss[3] = '\0';
    printf("%s\n", sss);

    // strncpy() doesn't copy null-terminator. you must do it your own.
    strncpy(sss, "xyz", sizeof(sss));
    sss[3] = '\0';
    printf("%s\n", sss);

    /* find index of delimeter char */
    char s8[8] = "abcd\0efg";
    printf("%s\n", s8);

    // IMPORTANT TO NOTEEE......., give the index from where the iteration begins.
    size_t idx = strcspn(s8, "\0"); // 4
    printf("%zu\n", idx);

    size_t idx = strcspn(s8 + 5, "f"); // 2
    printf("%zu\n", idx);

    /* */
    char s3[3], s6[6];

    // strcpy(s6, s3);
    // strncpy(s3, s6, 3);

    // strcat(s3, s6);
    // strncat(s3, s6, 3);

    // strcmp(s3, s6);
    // strncmp(s3, s6, 3);

    // strpbrk()

    // strspn()
    // strcspn()

    // strdup()

    // memset();
    // memmem();
    // memcpy();
    // memcmp();
    // memchr();


    /// strcpy vs memcpy ///
    // strcpy -> copies until found NULL terminator('\0)
    // memcpy -> you tell how many should be copied ..

    /* input from stdin */
    char buffer[1024];
    fgets(buffer, sizeof(buffer) - 1, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    char *newStr;
    newStr = malloc(strlen(buffer) + 1);    // reserve one room for '\0', must must free() later
    strcpy(newStr, buffer);

    printf("%s\n", newStr);

    /* seperate through delimeter */
    // strtok() modifies the original string ...
    char msg[] = "hello world";
    char *token = strtok(msg, " "); // token, msg is same
    printf("%s %s\n", token, msg);

    token = strtok(NULL, " ");
    printf("%s\n", token);

    token = strtok(NULL, " ");
    printf("%s\n", token);

    if (token == NULL) {
        printf("No more token\n");
    }

    // toknize from newStr
    token = strtok(newStr, " ");    // newStr from 'input from stdin' section
    printf("%s\n", token);

    free(newStr);

    /* */
    // sprintf();
    // snprintf();

    return 0;
}