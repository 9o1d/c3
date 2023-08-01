/*
 * File:  char_string_read_file.h
 * Description: String functions (deprecated)
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef CHAR_STRING_FILE_READ_H
#define CHAR_STRING_FILE_READ_H

FUNCTION_INLINE size_t FUNC(read_file)(T *p,
		FILE *f)
{
	return FUNC(file_read_file_static)(p,
				f);
}

FUNCTION_INLINE T* FUNC(read_line_file)(T *p,
		FILE *f)
{
	if (f)
	{
		if (!p)
		{
			p = FUNC(init)(p,
					0);
		}
		if (FUNC(file_read_line_file_static)(p,
					f))
		{
		}
	}

	return p;
}

#endif	/* CHAR_STRING_FILE_READ_H */

