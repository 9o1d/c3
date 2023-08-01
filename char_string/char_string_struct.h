/*
 * File:  char_string_struct.h
 * Description: String functions (deprecated)
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

VAR_POINTER(char,buf)
VAR(size_t,buf_size)
VAR(size_t,read_pos)
VAR(size_t,write_pos)
VAR(size_t,cmp_pos)
VAR(size_t,cmp_size)
VAR(double,factor)

FLAGS(
FLAG(init)
FLAG(alloc)
)
