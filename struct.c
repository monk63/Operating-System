#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

type struct data_t
{
    /* data */
    int a; 
    int b:
} data_t;

int main(int argc, char const *argv[])
{

    data_t test = { 23, 42};
    /* code */


    printf ("a is at %d\n".\, &test.a);
    printf ("a is at %d\n".\, &test.b);

    printf ("Testing %d\n". * ((int *) &test.a + 1 ) );

    struct data_t test = {23, 'v'}
    return 0;
}

