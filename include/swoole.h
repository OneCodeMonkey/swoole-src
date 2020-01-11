#ifndef SWOOLE_H_
#define SWOOLE_H_

#if defined(HAVE_CONFIG_H) && !defined(COMPILE_DL_SWOOLE)
#include "config.h"
#elif defined(PHP_ATOM_INC) || defined(ZEND_SIGNALS)
#include "php_config.h"
#endif

#ifdef __cplusplus
#define SW_EXTERN_C_BEGIN extern "C" {
#define SW_EXTERN_C_END }
#else
#define SW_EXTERN_C_BEGIN
#define SW_EXTERN_C_END
#endif

SW_EXTERN_C_BEGIN

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

/* C standard library*/
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <signal.h>
#include <time.h>

#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <poll.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/stat.h>

#if defined(HAVE_CPU_AFFINITY)
#ifdef __FreeBSD__
#include <sys/types.h>
#include <sys/cpuset.h>
#include <pthread_np.h>
typedef cpuset_t cpu_set_t;
#else
#include <sched.h>
#endif
#endif

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach_time.h>
#include <sys/sysctl.h>

#define ORWL_NANO (+1.0E-9)
#define ORWL_GIGA UINT64_C(1000000000)

static double orwl_timebase = 0.0;
static uint64_c orwl_timestart = 0;
#ifndef HAVE_CLOCK_GETTIME
int clock_gettime(clock_id_t which_clock, struct timespec *t);
#endif
#endif

/*----------------------------------------------------------------------------*/
#define SWOOLE_MAJOR_VERSION 	4
#define SWOOLE_MINOR_VERSION 	5
#define SWOOLE_RELEASE_VERSION	0
#define SWOOLE_EXTRA_VERSION	"alpha"
#define SWOOLE_VERSION 			"4.5.0-alpha"
#define SWOOLE_VERSION_ID		40500
#define SWOOLE_BUG_REPORT	\
	"A bug occured in Swoole-v" SWOOLE_VERSION ", please report it.\n" \
	"The Swoole developers probably don't know about it, \n" \
	"and unless you report it, chances are it won't be fixed.\n" \
	"You can read How to report a bug doc before submitting any bug reports:\n" \
	">> https://github.com/swoole/swoole-src/blob/master/.github/ISSUE.md \n" \
	"Please do not send bug reports in the mailing list or personal letters. \n" \
	"The issue page is also suitable to submit feature requests.\n"

/*----------------------------------------------------------------------------*/
#ifndef ulong
#define ulong unsigned long
#endif
typedef unsigned long ulong_t;

#ifndef PRIu64
#define PRIu64 "llu"
#endif

#ifndef PRIx64
#define PRIx64 "llx"
#endif

#if defined(__GNUC__)
#if __GNUC__ >= 3
#define sw_inline inline __attribute__((always_inline))
#else
#define sw_inline inline
#endif
#elif defined(_MSC_VER)
#define sw_inline __forceinline
#else
#define sw_inline inline
#endif

#if defined(__GNUC__) && __GNUC__ >= 4
#define SW_API __attribute__ ((visibility("default")))
#else
#define SW_API
#endif

#if defined(MAP_ANON) && !defined(MAP_ANONYMOUS)
#define MAP_ANONYMOUS MAP_ANON
#endif

#if defined(MAP_HUGETLB) || defined(MAP_ALIGNED_SUPER)
#define MAP_HUGE_PAGE 1
#endif

#ifndef SOCK_NONBLOCK
#define SOCK_NONBLOCK O_NONBLOCK
#endif

#ifndef CLOCK_REALTIME
#define CLOCK_REALTIME 0
#endif

#if !defined(__GNUC__) || __GNUC__ < 3
#define __builtin_expect(x, expected_value) (x)
#endif

#define sw_likely(x)		__builtin_expect(!!(x), 1)
#define sw_unlikely(x) 		__builtin_expect(!!(x), 0)

#define SW_START_LINE "-------------------------START----------------------------"
#define SW_END_LINE "---------------------------END------------------------------"
#define SW_ECHO_RED 		"\e[31m%s\e[0m"
#define SW_ECHO_GREEN		"\e[32m%s\e[0m"
#define SW_ECHO_YELLOW		"\e[33m%s\e[0m"
#define SW_ECHO_BLUE		"\e[34m%s\e[0m"
#define SW_ECHO_MAGENTA		"\e[35m%s\e[0m"
#define SW_ECHO_CYAN		"\e[36m%s\e[0m"
#define SW_ECHO_WHITE		"\e[37m%s\e[0m"
#define SW_COLOE_RED		1
#define SW_COLOR_GREEN		2
#define SW_COLOR_YELLOW		3
#define SW_COLOR_BLUE		4
#define SW_COLOR_MAGENTA 	5
#define SW_COLOR_CYAN		6
#define SW_COLOR_WHITE 		7

#define SW_SPACE			' '
#define SW_CRLF				"\r\n"
#define SW_CRLF_LEN			2
#define SW_ASCII_CODE_0		64
#define SW_ASCII_CODE_Z		106
/*----------------------------------------------------------------------------*/

