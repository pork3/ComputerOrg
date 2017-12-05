#include <stdio.h>

typedef unsigned char *byte_pointer;


void show_bytes(byte_pointer start, int len) 
{
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
		printf("\n");
}


void show_short(short x) {
		show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
	show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
		show_bytes((byte_pointer) &x, sizeof(double));
}

int main(int argc , char**argv)
{
	short a =0x7000;
	long b = 0x12345678;
	double c =0x12345678;

	show_short(a);
	show_long(b);
	show_double(c);
	return 0;
}