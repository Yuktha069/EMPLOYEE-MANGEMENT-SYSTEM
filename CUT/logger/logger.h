#ifndef __LOGGER_H__
#define __LOGGER_H__
#include<stdio.h>
#define LOG_FILE_NAME "log.txt"
#define LOG_FMT "@group4 ||employee management system || %s | %s |%-7s | %-15s |%s:%d|"
#define NEWLINE "\n"
#define INFO_TAG "INFO"
#define LOG_ARGS(LOG TAG) __TIME__,__DATE__,LOG_TAG,__FILE__,__FUCNTION__,__LINE__
#define PRINTFUNCTION(fmt,...)   do{
fprintf(stderr,fmt,__VA_ARGS__);
}while(0)
#define LOG_INFO(message,args...)  PRINTFUNCTION(LOG_FMT message NEWLINE, LOG_ARGS(INFO_TAG),##args)
#endif

