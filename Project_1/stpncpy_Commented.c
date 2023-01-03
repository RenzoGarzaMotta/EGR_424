/*
FUNCTION
	<<stpncpy>>---counted copy string returning a pointer to its end

INDEX
	stpncpy

ANSI_SYNOPSIS
	#include <string.h>
	char *stpncpy(char *<[dst]>, const char *<[src]>, size_t <[length]>);

TRAD_SYNOPSIS
	#include <string.h>
	char *stpncpy(<[dst]>, <[src]>, <[length]>)
	char *<[dst]>;
	char *<[src]>;
	size_t <[length]>;

DESCRIPTION
	<<stpncpy>> copies not more than <[length]> characters from the
	the string pointed to by <[src]> (including the terminating
	null character) to the array pointed to by <[dst]>.  If the
	string pointed to by <[src]> is shorter than <[length]>
	characters, null characters are appended to the destination
	array until a total of <[length]> characters have been
	written.

RETURNS
	This function returns a pointer to the end of the destination string,
	thus pointing to the trailing '\0', or, if the destination string is
	not null-terminated, pointing to dst + n.

PORTABILITY
<<stpncpy>> is a GNU extension, candidate for inclusion into POSIX/SUSv4.

<<stpncpy>> requires no supporting OS subroutines.

QUICKREF
	stpncpy gnu
*/

#include <string.h>
#include <limits.h>

/*SUPPRESS 560*/
/*SUPPRESS 530*/

/* Nonzero if either X or Y is not aligned on a "long" boundary.
 * src(const char) and dst(char) are the inputs to this macro
 */
#define UNALIGNED(X, Y) \
  (((long)X & (sizeof (long) - 1)) | ((long)Y & (sizeof (long) - 1)))

/*This snippet of code defined DETECTNULL(X) depending on whether a long int is 32 or 64 bits.
 * LONG_MAX
 *   -From limit.h
 *   -This macro defines the maximum value for a long int to accommodate 32 or 64 bits
 */
#if LONG_MAX == 2147483647L
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)
#else
#if LONG_MAX == 9223372036854775807L
/* Nonzero if X (a long int) contains a NULL byte. */
#define DETECTNULL(X) (((X) - 0x0101010101010101) & ~(X) & 0x8080808080808080)
#else
#error long int is not a 32bit or 64bit type.
#endif
#endif

/*If DETECTNULL is not defined, print an error.
 *
 */
#ifndef DETECTNULL
#error long int is not a 32bit or 64bit byte
#endif

/* Define the TOO_SMALL macro function. This serves to determine if the length
 * of the passed variable is less than the size of a long int data type.
 * count(size_t) is the input for this macro.
 */
#define TOO_SMALL(LEN) ((LEN) < sizeof (long))

char *
_DEFUN (stpncpy, (dst, src), char *dst _AND _CONST char *src _AND size_t count){
	char *ret = NULL;

#if !defined(PREFER_SIZE_OVER_SPEED) && !defined(__OPTIMIZE_SIZE__)
	long *aligned_dst;
	_CONST long *aligned_src;

	/* If SRC and DEST are aligned and count large enough, then copy words.  */
	if (!UNALIGNED (src, dst) && !TOO_SMALL (count)){
		aligned_dst = (long*)dst; //Indicate that the destination is long-aligned
		aligned_src = (long*)src; //Indicate that the source is long-aligned

		/* SRC and DEST are both "long int" aligned, try to do "long int"
		sized copies.*/
		while (count >= sizeof (long int) && !DETECTNULL(*aligned_src)){
			count -= sizeof (long int);
			*aligned_dst++ = *aligned_src++;
		}

		dst = (char*)aligned_dst;
		src = (char*)aligned_src;
	}
#endif /* not PREFER_SIZE_OVER_SPEED */

/* Check if the requested count was larger than the src length. If so, 
 *
 */
	while (count > 0){
		--count;
		if ((*dst++ = *src++) == '\0'){
			ret = dst - 1;
			break;
		}
	}

/* If src is smaller than dst and count is larger than src. When there are is no
 * more data to copy from src, fill in the rest (of count) with NULL characters.
 */
	while (count-- > 0)
		*dst++ = '\0';

	return ret ? ret : dst;
}
