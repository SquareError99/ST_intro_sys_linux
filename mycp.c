#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define RET_STATUS 0



//int main(int argc, char** argv)
int main(int argc, char* argv[])
{

    int fd, fd_dest, num_read, num_write;
    unsigned char buf[100];

    if (argc != 3)
    {
        printf("Usage: %s src dest\n", argv[0]);
	return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
	printf(">> Could not open the file\n");
	return -1;
    }
    printf(">> the file opend with fd = %d\n", fd);

    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest < 0) {
	printf(">> Could not open the dest file\n");
	return -1;
    }
    printf(">> the dest file opend with fd = %d\n", fd_dest);

    while ((num_read = read(fd, buf, 100)) != 0) {
	if (num_read < 0) {
	    printf(">> Could not read from the file\n");
	    return -1;
	}
	printf(">> I read %d bytes\n", num_read);

	num_write = write(fd_dest, buf, num_read);
	if (num_write < 0) {
	    printf(">> Could not write to stdout\n");
	    return -1;
	}
	printf("\n>> I wrote %d bytes\n", num_write);
    }
    
    close(fd);
    close(fd_dest);

    return RET_STATUS;
}
