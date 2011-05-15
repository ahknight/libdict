/*
 * hashtable.h -- hash-value sorted, chained hash-table interface.
 *
 * Copyright (c) 2001-2011, Farooq Mela
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    This product includes software developed by Farooq Mela.
 * 4. Neither the name of the Farooq Mela nor the
 *    names of contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY FAROOQ MELA ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL FAROOQ MELA BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "dict.h"

BEGIN_DECL

typedef struct hashtable
			hashtable;

hashtable*	hashtable_new(dict_compare_func cmp_func, dict_hash_func hash_func,
						  dict_delete_func del_func, unsigned size);
dict*		hashtable_dict_new(dict_compare_func cmp_func,
							   dict_hash_func hash_func,
							   dict_delete_func del_func, unsigned size);
unsigned	hashtable_free(hashtable *table);

int			hashtable_insert(hashtable *table, void *key, void *datum,
							 int overwrite);
int			hashtable_probe(hashtable *table, void *key, void **datum);
void*		hashtable_search(hashtable *table, const void *key);
int			hashtable_remove(hashtable *table, const void *key);
unsigned	hashtable_clear(hashtable *table);
unsigned	hashtable_traverse(hashtable *table, dict_visit_func visit);
unsigned	hashtable_count(const hashtable *table);
unsigned	hashtable_size(const hashtable *table);
unsigned	hashtable_slots_used(const hashtable *table);
int			hashtable_resize(hashtable *table, unsigned size);

typedef struct hashtable_itor
			hashtable_itor;

hashtable_itor*
			hashtable_itor_new(hashtable *table);
dict_itor*	hashtable_dict_itor_new(hashtable *table);
void		hashtable_itor_free(hashtable_itor *);

int			hashtable_itor_valid(const hashtable_itor *itor);
void		hashtable_itor_invalidate(hashtable_itor *itor);
int			hashtable_itor_next(hashtable_itor *itor);
int			hashtable_itor_prev(hashtable_itor *itor);
int			hashtable_itor_nextn(hashtable_itor *itor, unsigned count);
int			hashtable_itor_prevn(hashtable_itor *itor, unsigned count);
int			hashtable_itor_first(hashtable_itor *itor);
int			hashtable_itor_last(hashtable_itor *itor);
int			hashtable_itor_search(hashtable_itor *itor, const void *key);
const void*	hashtable_itor_key(const hashtable_itor *itor);
void*		hashtable_itor_data(hashtable_itor *itor);
const void*	hashtable_itor_cdata(const hashtable_itor *itor);
int			hashtable_itor_set_data(hashtable_itor *itor,
									void *datum, void **prev_datum);
int			hashtable_itor_remove(hashtable_itor *itor, int del);

END_DECL

#endif /* !_HASHTABLE_H_ */
