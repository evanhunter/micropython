/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#pragma once

#include <stdbool.h>
#include <mpconfigport.h>
#include "misc.h"
#include "obj.h"

// Use special typecode to differentiate repr() of bytearray vs array.array('B')
// (underlyingly they're same).
#define BYTEARRAY_TYPECODE 0

int mp_binary_get_size(char struct_type, char val_type, mp_uint_t *palign);
mp_obj_t mp_binary_get_val_array(char typecode, void *p, int index);
void mp_binary_set_val_array(char typecode, void *p, int index, mp_obj_t val_in);
void mp_binary_set_val_array_from_int(char typecode, void *p, int index, mp_int_t val);
mp_obj_t mp_binary_get_val(char struct_type, char val_type, byte **ptr);
void mp_binary_set_val(char struct_type, char val_type, mp_obj_t val_in, byte **ptr);
long long mp_binary_get_int(mp_uint_t size, bool is_signed, bool big_endian, byte *p);
void mp_binary_set_int(mp_uint_t val_sz, bool big_endian, byte *p, byte *val_ptr);
