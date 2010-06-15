/* 
 * File:   mwintype.h
 * Author: dbento
 *
 * Created on June 11, 2010, 3:02 PM
 */

#ifndef _MWINTYPE_H
#define	_MWINTYPE_H

#define CONST const
#ifndef VOID
#define VOID void
#endif
typedef char CHAR;
typedef short SHORT;
typedef long LONG;
typedef char CCHAR, *PCCHAR;
typedef unsigned char UCHAR,*PUCHAR;
typedef unsigned short USHORT,*PUSHORT;
typedef unsigned long ULONG,*PULONG;
typedef char *PSZ;

typedef void *PVOID,*LPVOID;

typedef int                                    *LPLONG;
typedef unsigned int    DWORD,      *PDWORD,   *LPDWORD;
typedef unsigned short int    WORD,      *PWORD;

#define ANSI_NULL '\0'
#define UNICODE_NULL L'\0'
typedef BYTE BOOLEAN,*PBOOLEAN;

typedef BYTE FCHAR;
typedef WORD FSHORT;
typedef DWORD FLONG;

#ifdef UNICODE
/*
 * __TEXT is a private macro whose specific use is to force the expansion of a
 * macro passed as an argument to the macro TEXT.  DO NOT use this
 * macro within your programs.  It's name and function could change without
 * notice.
 */
#define __TEXT(q) L##q
#else
#define __TEXT(q) q
#endif
/*
 * UNICODE a constant string when UNICODE is defined, else returns the string
 * unmodified.
 * The corresponding macros  _TEXT() and _T() for mapping _UNICODE strings
 * passed to C runtime functions are defined in mingw/tchar.h
 */
#define TEXT(q) __TEXT(q)
typedef SHORT *PSHORT;
typedef LONG *PLONG;
#ifdef STRICT
typedef void *HANDLE;
#define DECLARE_HANDLE(n) typedef struct n##__{int i;}*n
#else
typedef PVOID HANDLE;
#define DECLARE_HANDLE(n) typedef HANDLE n
#endif
typedef HANDLE *PHANDLE,*LPHANDLE;
typedef DWORD LCID;
typedef PDWORD PLCID;
typedef WORD LANGID;
DECLARE_HANDLE(HKEY);
typedef HKEY *PHKEY;

#define MB_OK                   0x00000000
#define MB_OKCANCEL             0x00000001
#define MB_ABORTRETRYIGNORE     0x00000002
#define MB_YESNOCANCEL          0x00000003
#define MB_YESNO                0x00000004
#define MB_RETRYCANCEL          0x00000005
#define MB_CANCELTRYCONTINUE    0x00000006
#define MB_TYPEMASK             0x0000000F

#define MB_ICONHAND             0x00000010
#define MB_ICONQUESTION         0x00000020
#define MB_ICONEXCLAMATION      0x00000030
#define MB_ICONASTERISK         0x00000040
#define MB_USERICON             0x00000080
#define MB_ICONMASK             0x000000F0

#define MB_ICONINFORMATION      MB_ICONASTERISK
#define MB_ICONSTOP             MB_ICONHAND
#define MB_ICONWARNING          MB_ICONEXCLAMATION
#define MB_ICONERROR            MB_ICONHAND

#define MB_DEFBUTTON1           0x00000000
#define MB_DEFBUTTON2           0x00000100
#define MB_DEFBUTTON3           0x00000200
#define MB_DEFBUTTON4           0x00000300
#define MB_DEFMASK              0x00000F00

#define MB_APPLMODAL            0x00000000
#define MB_SYSTEMMODAL          0x00001000
#define MB_TASKMODAL            0x00002000
#define MB_MODEMASK             0x00003000

#define MB_HELP                 0x00004000
#define MB_NOFOCUS              0x00008000
#define MB_MISCMASK             0x0000C000

#define MB_SETFOREGROUND        0x00010000
#define MB_DEFAULT_DESKTOP_ONLY 0x00020000
#define MB_SERVICE_NOTIFICATION 0x00040000
#define MB_TOPMOST              0x00040000
#define MB_RIGHT                0x00080000
#define MB_RTLREADING           0x00100000

#define HELPINFO_WINDOW         0x0001
#define HELPINFO_MENUITEM       0x0002

int MessageBox(PDWORD hWnd, PCCHAR lpText, PCCHAR lpCaption, DWORD uType);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _MWINTYPE_H */

