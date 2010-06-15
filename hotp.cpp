#include <math.h>

#include "hmacsha1.h"

int test_hotp(BYTE *horatexto, BYTE *segredo, BYTE *md, int len)
{
  CHMAC_SHA1 hmac_sha1;
  hmac_sha1.HMAC_SHA1(horatexto, 8, segredo, 20, md);
  UINT_32 dbc; /* "dynamic binary code" from HOTP draft */

  /* 2. the truncate step is unnecessarily complex */
  {
    int offset;

    offset = md[19] & 0x0F;
    /* we can't just cast md[offset] because of alignment and endianness */
    dbc = (md[offset] & 0x7F) << 24 |
    md[offset + 1] << 16 | md[offset + 2] << 8 | md[offset + 3];
  }

  /* 3. apply the size limit */
  {
      UINT_32 limit = (UINT_32) pow(10, len);
      dbc = dbc % limit;
  }

  return dbc;
}
