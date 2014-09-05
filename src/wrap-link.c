/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** wrap-link.c
** Wrapping write and puts system call by relying on 'ld --wrap=symbol'.
** 
**
** Author: Saman Barghi <saman.b@gmail.com>
** -------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

/* create pointers for real glibc functions */
ssize_t __real_write(int fd, const void *buf, size_t count);
int __real_puts(const char* str);


/* wrapping write function */


ssize_t __wrap_write (int fd, const void *buf, size_t count)
{
    /* printing out the number of characters */
    printf("write:chars#:%lu\n", count);

    /* call the real glibc function and return the result */
    ssize_t result = __real_write(fd, buf, count);
    return result;
}

/* wrapping puts function */
int __wrap_puts (const char* str)
{
    /* printing out the number of characters */
    printf("puts:chars#:%lu\n", strlen(str));

    /* call the real glibc function and return the result */
    int result = __real_puts(str);
    return result;
}
