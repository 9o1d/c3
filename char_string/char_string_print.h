/*
 * File:  char_string_print.h
 * Description: String functions (deprecated)
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef CHAR_STRING_PRINT_H
#define CHAR_STRING_PRINT_H

FUNCTION_INLINE int FUNC(print)(T *p)
{
	int is_set = 0;

	if (p)
	{
		if (FUNC(check(p)))
		{
			printf("%s\n",
					p->buf + p->read_pos);
			is_set = 1;
		}
	}

	return is_set;
}

#endif	/* CHAR_STRING_PRINT_H */

