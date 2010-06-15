/* 
 * File:   main.c
 * Author: dbento
 *
 * Created on June 8, 2010, 7:14 PM
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "hotp.h"
#include "hotputil.h"
#include "hmacsha1.h"

#include "mwintype.h"
#include "registry.h"

static char valid_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-+=@";
static int valid_chars_num = 67;

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned char horatexto[8];
    time_t hora = time(NULL);
    hora = hora / 60;
    c2c(hora,horatexto);

    int newSecret = 1; /* FALSE */
    HKEY chave = OpenCreateKey("Software\\bento.eti.br\\Token");
    if(chave != NULL) {
      char valor[21];
      memset((void *)valor,'\0', 21);
      DWORD tam = 21;

      if(!ReadKeyValue(chave, "Segredo", valor, &tam)) {
        srand(time(NULL));
        for(int i = 0; i < 20; i++) {
            valor[i] = valid_chars[rand() % 67];
        }
        tam = 20;
        if(!WriteKeyValue(chave, "Segredo", valor))
          return(EXIT_FAILURE);
        else {
          std::cout << "Segredo: " << valor << std::endl;
          newSecret = 0; /* TRUE */
        }
      }
      CloseKey(chave);

      if(newSecret) {
        BYTE digest[CHMAC_SHA1::SHA1_DIGEST_LENGTH];
        std::cout << test_hotp((BYTE *)horatexto, (BYTE *)valor, (BYTE *)digest, 6) << std::endl;
        //MessageBox(NULL, (char *)test_hotp((BYTE *)horatexto, (BYTE *)valor, (BYTE *)digest, 6), (char *)"Senha", MB_OK+MB_APPLMODAL+MB_ICONINFORMATION);
      }
      return(EXIT_SUCCESS);
    }
    return(EXIT_FAILURE);
}

