/* 
 * File:   hotp.h
 * Author: dbento
 *
 * Created on June 11, 2010, 12:59 AM
 */

#ifndef _HOTP_H
#define	_HOTP_H

#include "hmacsha1.h"

int test_hotp(BYTE *horatexto, BYTE *segredo, BYTE *md, int len);

#endif	/* _HOTP_H */

