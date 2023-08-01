/*
 * File:  char_string_free.h
 * Description: String functions (deprecated)
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

if (p->is_init)
{
	if (p->is_alloc &&
			p->buf)
	{
		free(p->buf);
	}
	is_free = 1;
}
