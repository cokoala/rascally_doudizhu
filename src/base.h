#ifndef __BASE_H__
#define __BASE_H__

#define __DEBUG__  
#ifdef __DEBUG__  
#define DEBUG(format,...) printf(""format"", ##__VA_ARGS__)
#define DEBUGPRO(format,...) printf("["__FILE__":%05d]"format"", __LINE__, ##__VA_ARGS__)
#else  
#define DEBUG(format,...)  
#endif  

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
#define byte unsigned char


#endif