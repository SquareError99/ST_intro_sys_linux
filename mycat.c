#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define RET_STATUS 0



//int main(int argc, char** argv)
int main(int argc, char* argv[])
{

    int fd, num_read, num_write;
    unsigned char buf[100];

    if (argc != 2)
    {
        printf("Usage: %s file_name\n", argv[0]);
	return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
	printf(">> Could not open the file\n");
	return -1;
    }
    printf(">> the file opend with fd = %d\n", fd);


    while ((num_read = read(fd, buf, 100)) != 0) {
	if (num_read < 0) {
	    printf(">> Could not read from the file\n");
	    return -1;
	}
	printf(">> I read %d bytes\n", num_read);

	num_write = write(1, buf, num_read);
	if (num_write < 0) {
	    printf(">> Could not write to stdout\n");
	    return -1;
	}
	printf("\n>> I wrote %d bytes\n", num_write);
    }
    
    close(fd);

    return RET_STATUS;
}
