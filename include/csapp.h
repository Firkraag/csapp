/*************************************************************************
	> File Name: csapp.h
	> Author: 
	> Mail: 
	> Created Time: Tue 27 Sep 2016 09:14:59 PM CST
 ************************************************************************/

#ifndef _CSAPP_H
#define _CSAPP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define INT_SIZE (sizeof(int) << 3)
#define POS_INFINITY  1 /  0.0 //0x7ff0000000000000
#define NEG_INFINITY  1 / -0.0 //0xfff0000000000000
#define NEG_ZERO     -0.0 //0x8000000000000000

#endif

