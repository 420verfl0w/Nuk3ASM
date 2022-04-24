#include "nuk3_utils.h"


////////////////////////////////
//
//       INCLUDES
//
///////////////////////////////

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////
//
//     FUNCTIONS LST
//
///////////////////////////////


nuk3_list_t	*nuke_lst_create(char *filename)
{
    nuk3_list_t *ptr = (nuk3_list_t *)malloc(sizeof(nuk3_list_t));
    if (!ptr)
		return (NULL);
    ptr->file.filename = filename;
	ptr->file.buf = NULL;
	ptr->file.szfile = 0;
	ptr->next = NULL;
	ptr->prev = NULL;
    return (ptr);
}

nuk3_list_t	*nuke_lst_get(nuk3_list_t *lst, int idx)
{
    for (int i = 0; lst && i < idx; i++, lst = lst->next);
    return (lst);
}

nuk3_list_t	*nuke_lst_get_last(nuk3_list_t *lst)
{
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void		nuke_lst_push(nuk3_list_t **lst, nuk3_list_t *n)
{
	if (!n)
		return;
	(*lst)->prev = n;
	n->prev = NULL;
	n->next = *lst;
	*lst = n;
}

void		nuke_lst_pop(nuk3_list_t **lst)
{
	if (!*lst)
		return;
	nuk3_list_t	*next = (*lst)->next;
	next->prev = NULL;
	free(*lst);
	*lst = next;
}

void		nuke_lst_free(nuk3_list_t **lst)
{
	(*lst)->next = NULL;
	(*lst)->prev = NULL;
	if (*lst)
		free(*lst);
	*lst = NULL;
}

void		nuke_lst_purge(nuk3_list_t **lst)
{
	nuk3_list_t	*next = NULL;

	while (*lst) {
		next = (*lst)->next;
		free_file(&(*lst)->file);
		free(*lst);
		*lst = next;
	}
}

void		nuke_lst_show(nuk3_list_t	*lst)
{
	for (; lst; lst = lst->next) {
		printf(
			"%s (%lu): \n%s\n", 
			lst->file.filename, 
			lst->file.szfile,
			lst->file.buf
		);
	}
}