/*
 * File:  chars_pchar.h
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
Write from char *s to (p->buf + p->wpos)
CHARS_FLAG_NOT_NULL_TERMINATED - does not add at the end of the line NULL
CHARS_FLAG_RESET - reset positions and writes from the beginning
*/
FUNCTION_INLINE int FUNC(write_pchar)(T *p,
	const char *s,
	size_t s_size,
	unsigned int flags)
{
	int is_set = 0;
	size_t size = 0;

	if (p)
	{
		if (FUNC(check)(p))
		{
			if (s)
			{
				if (CHARS_FLAG_RESET & flags)
				{
					if (!FUNC(reset)(p))
					{
						/* Error */
					}
				}
				/* Check size */
				size = strlen(s);
				if (!s_size ||
						size < s_size)
				{
					s_size = size;
				}

				/* Check p->size */
				if (p->size - p->wpos < s_size + 1 ||
						!p->is_alloc)
				{
					if (!FUNC(realloc)(p, p->wpos + s_size + 1, CHARS_FLAG_GROWTH_FACTOR))
					{
						/* Error */
					}
				}

				memcpy(p->buf + p->wpos, s, s_size);
				p->wpos += s_size;
				if (!(CHARS_FLAG_NOT_NULL_TERMINATED & flags))
				{
					p->buf[p->wpos] = 0;
				}
				is_set = 1;
			}
		}
	}

	return is_set;
}

/*
Allocate memory, copy from (p->buf + p->rpos) length of s_size
and returns a pointer, after use should call free(),
CHARS_FLAG_POINTER - returns a pointer to (p->buf + p->rpos),
CHARS_FLAG_NOT_NULL_TERMINATED - does not add at the end of the line NULL
CHARS_FLAG_ADVANCE_READ_POS - move reading position to size
CHARS_FLAG_RESET - reads from the beginning
*/
FUNCTION_INLINE char* FUNC(read_pchar)(T *p,
		size_t s_size,
		unsigned int flags)
{
	size_t size = 0;
	char *buf = NULL;

	if (FUNC(check)(p))
	{
		/* Check size */
		size = p->wpos - p->rpos;
		if (!size ||
				size < s_size)
		{
			s_size = size;
		}

		if (CHARS_FLAG_RESET & flags)
		{
			p->rpos = 0;
		}
		if (CHARS_FLAG_POINTER & flags)
		{
			buf = p->buf + p->rpos;
		}
		else
		{
			if (CHARS_FLAG_NOT_NULL_TERMINATED & flags)
			{
				buf = malloc((s_size) * sizeof(char));
				if (buf)
				{
					memcpy(buf, p->buf + p->rpos, s_size);
				}
			}
			else
			{
				buf = malloc((s_size + 2) * sizeof(char));
				if (buf)
				{
					memcpy(buf, p->buf + p->rpos, s_size);
					buf[s_size] = 0;
				}
			}
		}

		if (CHARS_FLAG_ADVANCE_READ_POS & flags)
		{
			p->rpos += s_size;
		}
	}

	return buf;
}

