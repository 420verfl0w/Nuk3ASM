#ifndef NUK3_UTILS_H
#define NUK3_UTILS_H

#include "nuk3_types.h"

////////////////////////////////
//
//   FUNCTIONS READ FILE
//
///////////////////////////////

int			read_file(nuk3_file_t *f);
void		free_file(nuk3_file_t *f);

////////////////////////////////
//
//  	FUNCTIONS LIST
//
///////////////////////////////

nuk3_list_t	*nuke_lst_create(char *filename);
nuk3_list_t	*nuke_lst_get(nuk3_list_t *lst, int idx);
nuk3_list_t	*nuke_lst_get_last(nuk3_list_t *lst);
void		nuke_lst_push(nuk3_list_t **lst, nuk3_list_t *n);
void		nuke_lst_pop(nuk3_list_t **lst);
void		nuke_lst_free(nuk3_list_t **lst);
void		nuke_lst_purge(nuk3_list_t **lst);


#endif