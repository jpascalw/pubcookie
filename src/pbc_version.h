/*

    Copyright 1999, University of Washington.  All rights reserved.

     ____        _                     _    _
    |  _ \ _   _| |__   ___ ___   ___ | | _(_) ___
    | |_) | | | | '_ \ / __/ _ \ / _ \| |/ / |/ _ \
    |  __/| |_| | |_) | (_| (_) | (_) |   <| |  __/
    |_|    \__,_|_.__/ \___\___/ \___/|_|\_\_|\___|


    All comments and suggestions to pubcookie@cac.washington.edu
    More info: http://www.washington.edu/computing/pubcookie/
    Written by the Pubcookie Team

    this is simply a header file with the version in it.  do you like that 
       there are more lines of comment then code?

 */

/*
    $Id: pbc_version.h,v 1.43 2002-08-16 21:47:28 jjminer Exp $
 */

#ifndef PUBCOOKIE_VERSION
#define PUBCOOKIE_VERSION

/* The cookie version - Needs to stick around a while */
#define PBC_VERSION "a5"

/*
 * Someday the cookie version will be the major version or something like that.
 */

#define PBC_VERSION_MAJOR "3"
#define PBC_VERSION_MINOR "0"
#define PBC_VERSION_PATCH "0"

/* beta or final, so the code knows what it is, should it care. */
#define PBC_VERSION_RELEASE "beta"

/*
 * Please note that if you change the version string here, you should change it
 * in configure.ac and re-run autoconf and autoheader.
 */

#define PBC_VERSION_STRING "3.0.0 beta1"

#endif /* !PUBCOOKIE_VERSION */
