/*
 * File:  prime1.c
 * Description: Prime module test program
 * Author: Askar Azhibaev
 * Date:  July 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prime.h"

int main(int argc, const char *argv[])
{
	prime *p = NULL;
	unsigned long long i = 0;
	unsigned long long j = 0;
	unsigned long long m = 0;

	p = prime_create(1);

	if (argc < 2)
	{
		printf("Usage: %s n\n", argv[0]);
		return 1;
	}

	m = atoll(argv[1]);
	prime_init(p, 0, m < 100 ? 0 : m);
	for (i = 0; i <= m; i++)
	{
		j = prime_get_i(p, i);
		printf("p[%lld]=%lld ", i, j);
	}
	printf("\n");

	return 0;
}
