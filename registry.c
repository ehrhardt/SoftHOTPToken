// Source code accompanied with the "Working with Windows Registry in C++" article/tutorial
// Author: Barzan "Tony" Antal

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winreg.h>

#include "registry.h"

HKEY OpenCreateKey(const char *key) {
  HKEY hKey;
  DWORD dwDisposition;
  DWORD result;

  result = RegCreateKeyEx(HKEY_CURRENT_USER, TEXT(key), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition);

  if ((result == ERROR_SUCCESS) && (dwDisposition == REG_CREATED_NEW_KEY || dwDisposition == REG_OPENED_EXISTING_KEY))
    return hKey;
  else
    return (HKEY)NULL;
}

int WriteKeyValue(HKEY hKey, const char *key, const char *value) {
  DWORD a = RegSetValueEx(hKey, TEXT(key), 0, REG_SZ, value, strlen(value)+1);
  return a == ERROR_SUCCESS;
}

int ReadKeyValue(HKEY hKey, const char *key, char *value, LPDWORD len) {
  DWORD type;
  int ret = RegQueryValueEx(hKey, TEXT(key), NULL, &type, value, len) == ERROR_SUCCESS;
  ret = ret && (type == REG_SZ);
  ret = ret && ((*len) > 0);

  return ret;
}

void CloseKey(HKEY hKey) {
  RegCloseKey(hKey);
}
