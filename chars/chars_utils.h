/*
 * File:  chars_utils.h
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
Checks that the pointer p has been created,
done initialization,
buffer p->buf created,
read position <= write position,
write position <= p->size
*/
FUNCTION_INLINE int FUNC(check)(T *p)
{
    int is_set = 0;

    if (p)
    {
        if (p->is_init &&
                p->buf &&
                p->rpos <= p->wpos &&
                p->wpos <= p->size)
        {
            is_set = 1;
        }
    }

    return is_set;
}

/*
Checks that the pointer p has been created,
done initialization,
buffer p->buf created,
read position < write position,
there is data to read,
write position <= p->size
*/
FUNCTION_INLINE int FUNC(check_read)(T *p)
{
    int is_set = 0;

    if (p)
    {
        if (p->is_init &&
                p->buf &&
                p->rpos < p->wpos &&
                p->wpos <= p->size)
        {
            is_set = 1;
        }
    }

    return is_set;
}

/*
Allocates a new buffer if there is not enough space
CHARS_FLAG_GROWTH_FACTOR - uses factor
*/
FUNCTION_INLINE int FUNC(realloc)(T *p,
		size_t size,
		unsigned int flags)
{
	int is_set = 0;
	char *buf = NULL;
	size_t s_size = 0;

	if (FUNC(check)(p))
	{
		if (CHARS_FLAG_GROWTH_FACTOR & flags)
		{
			s_size = p->size * p->factor;
			if (size < s_size)
			{
				size = s_size;
			}
		}
		if (size)
		{
			if (size > p->size)
			{
				buf = malloc(size * sizeof(char));
				if (buf)
				{
					if (p->buf)
					{
						memcpy(buf, p->buf, p->wpos);
						if (p->wpos < size)
						{
							buf[p->wpos] = 0;
						}
						if (p->is_alloc)
						{
							free(p->buf);
						}
					}
					p->buf = buf;
					p->size = size;
					p->is_alloc = 1;
				}
			}
		}
	}

	return is_set;
}

/*
Prints a line from the buffer
CHARS_FLAG_PRINT_NEWLINE - adds a new line
CHARS_FLAG_PRINT_HEX - character values
CHARS_FLAG_PRINT_ALL - prints from the beginning
CHARS_FLAG_PRINT_SPACE - prints spaces
*/
FUNCTION_INLINE int FUNC(print)(T *p,
		unsigned int flags)
{
	int is_set = 0;
	char *s = NULL;
	size_t i = 0;
	char *s_format = NULL;
	char c = 0;

	if (FUNC(check)(p))
	{
		s = p->buf;
		if (!(CHARS_FLAG_PRINT_ALL & flags))
		{
			s += p->rpos;
		}
		if (CHARS_FLAG_PRINT_HEX & flags)
		{
			if (CHARS_FLAG_PRINT_SPACE & flags)
			{
				s_format = "%2x ";
			}
			else
			{
				s_format = "%2x";
			}
			for (i = 0; i < p->wpos && *s; i++)
			{
				printf(s_format, (unsigned char)*s++);
			}
		}
		else
		{
			for (i = 0; i < p->wpos && *s; i++)
			{
				c = *s++;
				if (c < 0x20 || c == 0x7f)
				{
					c = '.';
				}
				putchar(c);
			}
		}
		if (CHARS_FLAG_PRINT_SPACE & flags &&
				!(CHARS_FLAG_PRINT_HEX & flags))
		{
			putchar(' ');
		}
		if (CHARS_FLAG_PRINT_NEWLINE & flags)
		{
			putchar('\n');
		}
	}

	return is_set;
}

/*
Clears a string, resets read and write positions
*/
FUNCTION_INLINE int FUNC(reset)(T *p)
{
	int is_set = 0;

	if (p)
	{
		p->rpos = 0;
		p->wpos = 0;
		is_set = 1;
	}

	return is_set;
}
/*
Returns the format string for printf by type
CHARS_FLAG_POINTER - format for pointer address
*/
FUNCTION_INLINE const char* FUNC(get_type_format)(int type,
		unsigned int flags)
{
	char *s_format = NULL;

	switch (type)
	{
		case T_PREFIX_NAME(info_type,int):
			s_format = "%d";
			break;
		case T_PREFIX_NAME(info_type,size_t):
			s_format = "%ld";
			break;
		case T_PREFIX_NAME(info_type,char):
			if (CHARS_FLAG_POINTER & flags)
			{
				s_format = "%lx";
			}
			else
			{
				s_format = "%d";
			}
			break;
		case T_PREFIX_NAME(info_type,float):
		case T_PREFIX_NAME(info_type,double):
			s_format = "%f";
			break;
		default:
			s_format = "%ld";
	}

	return s_format;
}

/*
Prints the values of a structure
CHARS_FLAG_PRINT_NEWLINE - move to a new line
*/
FUNCTION_INLINE int FUNC(print_info)(T *p,
unsigned int flags)
{
	int is_set = 0;

	if (p)
	{
#define VAR(t,s) \
		printf(#s "="); \
		printf(FUNC(get_type_format)(T_PREFIX_NAME(info_type, t), 0), p->s); \
		putchar(' ');
#define VAR_POINTER(t,s) \
		printf(#s "="); \
		printf(FUNC(get_type_format)(T_PREFIX_NAME(info_type, t), CHARS_FLAG_POINTER), p->s); \
		putchar(' ');
		#define FLAGS(s)
		#define FLAG(s)
#include STR(T_NAME(struct.h))
#undef FLAG
#undef FLAGS
#undef VAR_POINTER
#undef VAR
	if (CHARS_FLAG_PRINT_NEWLINE & flags)
	{
		putchar('\n');
	}
	}

	return is_set;
}

