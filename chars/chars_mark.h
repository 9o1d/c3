/*
 * File:  chars_mark.h
 * Description: Chars string functions
 * Author: Askar Azhibaev
 * Date: June 2023
 * Copyright (c) 2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

/*
Return read position
*/
FUNCTION_INLINE size_t FUNC(get_mark)(T *p)
{
	int is_set = 0;

	if (p)
	{
		return p->rpos;
	}

	return is_set;
}

/*
Set read position
*/
FUNCTION_INLINE int FUNC(set_mark)(T *p,
		size_t read_mark)
{
	int is_set = 0;

	if (FUNC(check)(p))
	{
		if (read_mark < p->wpos)
		{
			p->rpos = read_mark;
			is_set = 1;
		}
	}

	return is_set;
}

