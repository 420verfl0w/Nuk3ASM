#include "nuk3.h"
#include <stdio.h>
#include <stdlib.h>


/////////////////////////////////
//
//	THIS CODE IS IN ALPHA DEV
//  TAKE CARE OF SAFETY
//
////////////////////////////////

int main(int ac, char **av)
{
	nuk3_ctx_t	ctx;
	nuk3_list_t	*fptr;

	if (ac < 2)
		return (fprintf(stderr, "usage : %s --help\n", av[0]));
	
	// PARSE ARGS TO SEARCH OPTIONS

	// PROCED TO BASIC COMPILATION

	for (int i = 1; i < ac; i++) {
		
		if (i == 1) {
			ctx.lst = nuke_lst_create(av[i]);
			read_file(&ctx.lst->file);
			continue;
		}

		fptr = (nuk3_list_t *)nuke_lst_create(av[i]);
		if (!fptr) return (1);
		read_file(&fptr->file);
		nuke_lst_push(&ctx.lst, fptr);
		continue;
	}

	// Free lst
	nuke_lst_purge(&ctx.lst);
	return (0);
}