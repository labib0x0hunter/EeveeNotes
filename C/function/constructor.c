#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<unistd.h>
#include<stdint.h>
#include<stddef.h>

// runs before main().
__attribute__((constructor)) void init() {
	printf("Hello From init()\n");
}

int main() {

	printf("Hello From main()\n");

	return 0;
}