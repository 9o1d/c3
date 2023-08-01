/*
 * File:  file_struct.h
 * Description: File functions
 * Author: Askar Azhibaev
 * Date: February 2021
 * Copyright (c) 2021-2023  Askar Azhibaev
 * 
 * This file is part of C3 extension.
 * URL: https://azhibaev.com/c3.zip
 * License: CPOL http://www.codeproject.com/info/cpol10.aspx
 */

VAR_POINTER(FILE,f)
VAR_POINTER_INIT(char_string,file_name)
VAR_POINTER_INIT(char_string,options)
VAR_POINTER_FREE(char_string,s)
VAR(size_t,read_chars)
VAR(size_t,write_chars)

