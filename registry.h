/* 
 * File:   registry.h
 * Author: dbento
 *
 * Created on June 11, 2010, 2:15 PM
 */

#ifndef _REGISTRY_H
#define	_REGISTRY_H

#ifdef	__cplusplus
extern "C" {
#endif

HKEY OpenCreateKey(const char *key);
int WriteKeyValue(HKEY hKey, const char *key, const char *value);
int ReadKeyValue(HKEY hKey, const char *key, char *value, LPDWORD len);
void CloseKey(HKEY hKey);

#ifdef	__cplusplus
}
#endif

#endif	/* _REGISTRY_H */

