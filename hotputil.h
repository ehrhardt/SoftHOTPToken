/* 
 * File:   hotputil.h
 * Author: dbento
 *
 * Created on June 10, 2010, 11:59 PM
 */

#ifndef _HOTPUTIL_H
#define	_HOTPUTIL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>

void c2c(uint64_t counter, unsigned char challenge[]);

#ifdef	__cplusplus
}
#endif


#endif	/* _HOTPUTIL_H */

