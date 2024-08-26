#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
//bstrlib.h
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
//bstrlib.c
//#include <stdio.h>
#include <stddef.h>
//#include <stdarg.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <limits.h>

#include <sys/mman.h>
#include <unistd.h>

//ringbuffer_posix
#include <fcntl.h>
// #include <stdio.h>
#include <sys/stat.h>
// #include <string.h>
// #include <errno.h>
// #include <assert.h>
#include <stdint.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#endif