/*
 * File:  char_string_copy.h
 * Description: String functions (deprecated)
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

#ifndef CHAR_STRING_COPY_H
#define CHAR_STRING_COPY_H

#include "char_string_read_char.h"

FUNCTION_INLINE T* FUNC(copy_size_flags)(T *p,
		T *s,
		size_t size,
		unsigned int flags)
{
	if (s)
	{
		if (s->is_init)
		{
			if (s->is_alloc)
			{
				if (s->read_pos < s->write_pos &&
						s->write_pos <= s->buf_size)
				{
					if (size == 0 ||
							size + s->read_pos > s->write_pos)
					{
						size = s->write_pos - s->read_pos;
					}
					p = FUNC(read_char_size_flags)(p, 
							s->buf + s->read_pos, 
							size, 
							flags);
				}
			}
		}
	}

	return p;
}

FUNCTION_INLINE T* FUNC(copy)(T *p,
		T *s)
{
	unsigned int flags = 0;
	size_t size = 0;

	return FUNC(copy_size_flags)(p,
			s,
			size,
			flags);
}

FUNCTION_INLINE T* FUNC(copy_size)(T *p,
		T *s,
		size_t size)
{
	unsigned int flags = 0;

	return FUNC(copy_size_flags)(p,
			s,
			size,
			flags);
}

FUNCTION_INLINE T* FUNC(copy_flags)(T *p,
		T *s,
		unsigned int flags)
{
	size_t size = 0;

	return FUNC(copy_size_flags)(p,
			s,
			size,
			flags);
}

#endif	/* CHAR_STRING_COPY_H */

