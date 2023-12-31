/*
 * File:  utopia_parse_init.h
 * Description: Utopia preprocessor of the 'mod.h' files
 * Author: Askar Azhibaev
 * Date:  December 2022
 * Copyright (c) 2022-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

p->section_index = -1;
p->is_module = 0;
p->s_path_out = char_string_read_char(p->s_path_out,
		path_out);
file_init(p->f_in,
		f_in,
		"r");
