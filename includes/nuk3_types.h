#ifndef NUK3_TYPES_H
#define NUK3_TYPES_H

#include <stddef.h>

////////////////////////////////
//
//        DEFINES
//
///////////////////////////////

////////////////////////////////
//
//        TYPEDEFS
//
///////////////////////////////

typedef	struct	nuk3_file_t	nuk3_file_t;
typedef	struct	nuk3_list_t	nuk3_list_t;
typedef	struct	nuk3_ctx_t	nuk3_ctx_t;

////////////////////////////////
//
//        STRUCT
//
///////////////////////////////


struct nuk3_file_t
{
	char	*buf;
	char	*filename;
	size_t	szfile;
};

struct nuk3_list_t
{
	struct nuk3_list_t	*next;
	struct nuk3_list_t	*prev;
	nuk3_file_t			file;
};

struct	nuk3_ctx_t
{
	nuk3_list_t	*lst;
};

#endif