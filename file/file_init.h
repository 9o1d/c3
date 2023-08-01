/*
 * File:  file_init.h
 * Description: File functions
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

p->file_name = char_string_read_char(p->file_name,
		file_name);
p->options = char_string_read_char(p->options,
		options);
if (!p->s)
{
	p->s = char_string_create_init(1,
			1 KB);
}
if (p->file_name &&
		p->options)
{
	if (p->f)
	{
		fclose(p->f);
	}
	p->f = fopen(p->file_name->buf,
			p->options->buf);
}
