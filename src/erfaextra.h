/*
** Copyright (C) 2016-2019, NumFOCUS Foundation.
**
** Licensed under a 3-clause BSD style license - see LICENSE
**
** This file is NOT derived from SOFA sources.
**
** The functions here provide an interface to ERFA and SOFA version
** information, and for updating the leap second table.
**
** The eraGetLeapSeconds and eraSetLeapSeconds functions are used as an
** experimental interface for getting and setting the leap second table
** starting in astropy 4.0.  They will be supported as long as needed for
** astropy.  Comments and ideas about the best way to keep the leap
** second tables up to date for all users of erfa are welcome
** (https://github.com/liberfa/erfa).
**
*/


#ifndef _ERFA_EXTRA_H
#define _ERFA_EXTRA_H

/* Reference ellipsoids */

/* Moon */
#define ERFA_IAUMOON1988 4
#define ERFA_IAUMOON1979 5

/* Mercury */
#define ERFA_IAUMERCURY2015 6
#define ERFA_IAUMERCURY2009 7
#define ERFA_IAUMERCURY1979 8

/* Venus */
#define ERFA_IAUVENUS1991 9
#define ERFA_IAUVENUS1982 10

/* Mars */
#define ERFA_IAUMARS2000 11
#define ERFA_IAUMARS1979 12

#ifdef __cplusplus
extern "C" {
#endif


/*
** Returns the package version
** as defined in configure.ac
** in string format
*/
const char* eraVersion(void);

/*
** Returns the package major version
** as defined in configure.ac
** as integer
*/
int eraVersionMajor(void);

/*
** Returns the package minor version
** as defined in configure.ac
** as integer
*/
int eraVersionMinor(void);

/*
** Returns the package micro version
** as defined in configure.ac
** as integer
*/
int eraVersionMicro(void);

/*
** Returns the orresponding SOFA version
** as defined in configure.ac
** in string format
*/
const char* eraSofaVersion(void);

/* Astronomy/Planetary/GeodeticGeocentric */
int eraBform(int n, double *a, double *f);

/*
** Get and set leap seconds (not supported by SOFA; EXPERIMENTAL)
*/

typedef struct {
   int iyear, month;
   double delat;
} eraLEAPSECOND;

int eraGetLeapSeconds(eraLEAPSECOND **leapseconds);
void eraSetLeapSeconds(eraLEAPSECOND *leapseconds, int count);

#ifdef __cplusplus
}
#endif

#endif /* _ERFA_EXTRA_H */
