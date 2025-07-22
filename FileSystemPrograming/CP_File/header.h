#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <fcntl.h>  
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>

#define ERROR_CHECK(ret, num, msg){if(ret==num){perror(msg); return -1;}}

#endif