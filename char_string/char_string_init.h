/*
 * File:  char_string_init.h
 * Description: String functions (deprecated)
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

if (buf_size == 0)
{
	buf_size = CHAR_STRING_DEFAULT_BUFFER_SIZE;
}
else
{
	buf_size += 2;
}
p->buf_size = buf_size;
p->buf = (char*) malloc(sizeof(char) * p->buf_size);
if (p->buf)
{
	memset(p->buf, 0, sizeof(char) * p->buf_size);
	p->is_init = 1;
	p->is_alloc = 1;
}
p->read_pos = 0;
p->write_pos = 0;
p->factor = CHAR_STRING_DEFAULT_GROWTH_FACTOR;
