#include "nuk3_utils.h"

////////////////////////////////
//
//        INCLUDES
//
///////////////////////////////

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

////////////////////////////////
//
//        FUNCTIONS
//
///////////////////////////////

int	read_file(nuk3_file_t *f)
{
	int fd;

	if (!f || !f->filename)
		return (0);

	fd = open(f->filename, 444);

	if (fd < 0)
		return (0);

	f->szfile = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	f->buf = (char *)malloc(f->szfile + 1);	
	
	if (!f->buf) {
		close(fd);
		return (0);
	}

	if ((size_t)read(fd, f->buf, f->szfile) < f->szfile) {
		free(f->buf);
		f->buf = NULL;
		return (0);
	}

	close(fd);

	return (f->szfile);
}

void	free_file(nuk3_file_t *f)
{
	if (f->buf)
		free(f->buf);
	f->buf = NULL;
	f->filename = NULL;
	f->szfile = 0;
}
