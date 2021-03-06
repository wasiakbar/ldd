#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/echo"

int main()
{
   int fd;
   char buf[100];

   fd = open(DEVICE_NAME, O_RDWR);
   if (fd == -1)
     {
        fprintf(stderr, "failed to open device\n");
        perror("file open:");
        return -1;
     }
   sprintf(buf, "Hello from userspace: %d", 100);
   printf("writing to kernel from userspace:\n==> %s\n\n", buf);

   write(fd, buf, sizeof(buf));

   memset(buf, 0, sizeof(buf));
   read(fd, buf, sizeof(buf));

   printf("Read from kernel space:\n==> %s\n", buf);

   close(fd);

   return 0;
}
