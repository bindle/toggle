/*
 *  Toggle Provisioning System
 *  Copyright (C) 2011 Bindle Binaries <syzdek@bindlebinaries.com>.
 *
 *  @BINDLE_BINARIES_BSD_LICENSE_START@
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Bindle Binaries nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 *  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BINDLE BINARIES BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 *  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 *  SUCH DAMAGE.
 *
 *  @BINDLE_BINARIES_BSD_LICENSE_END@
 */
/**
 *  @file include/toggled.h libtoggled.la API
 */
#ifndef _TOGGLED_H
#define _TOGGLED_H 1

///////////////
//           //
//  Headers  //
//           //
///////////////
#ifdef PMARK
#pragma mark - Headers
#endif

#include <inttypes.h>
#include <stdio.h>
#include <stdarg.h>


//////////////
//          //
//  Macros  //
//          //
//////////////
#ifdef PMARK
#pragma mark - Macros
#endif

/*
 * The macros "BEGIN_C_DECLS" and "END_C_DECLS" are taken verbatim
 * from section 7.1 of the Libtool 1.5.14 manual.
 */
/* BEGIN_C_DECLS should be used at the beginning of your declarations,
   so that C++ compilers don't mangle their names. Use END_C_DECLS at
   the end of C declarations. */
#undef BEGIN_TOGGLED_C_DECLS
#undef END_TOGGLED_C_DECLS
#if defined(__cplusplus) || defined(c_plusplus)
#   define BEGIN_TOGGLED_C_DECLS  extern "C" {    ///< exports as C functions
#   define END_TOGGLED_C_DECLS    }               ///< exports as C functions
#else
#   define BEGIN_TOGGLED_C_DECLS  /* empty */     ///< exports as C functions
#   define END_TOGGLED_C_DECLS    /* empty */     ///< exports as C functions
#endif


///////////////////
//               //
//  Definitions  //
//               //
///////////////////
#ifdef PMARK
#pragma mark - Definitions
#endif

// error codes
#define TOGGLED_EFLAG_FATAL    0x1000
#define TOGGLED_EFLAG_ERROR    0x2000
#define TOGGLED_EFLAG_INFO     0x0000
#define TOGGLED_EMASK_MSG      0x0FFF
#define TOGGLED_EMASK_FLAG     0xF000
#define TOGGLED_ESUCCESS      (0x0000 | TOGGLED_EFLAG_INFO)
#define TOGGLED_ENOMEM        (0x0001 | TOGGLED_EFLAG_FATAL)
#define TOGGLED_EHANDLE       (0x0002 | TOGGLED_EFLAG_FATAL)


/////////////////
//             //
//  Datatypes  //
//             //
/////////////////
#ifdef PMARK
#pragma mark - Datatypes
#endif

// @brief internal state of library handle
typedef struct toggled_library TOGGLED;
struct toggled_library
{
   int      errno_in;    ///< error code used internally
   int      errno_ex;    ///< error code used publicly
};


//////////////////
//              //
//  Prototypes  //
//              //
//////////////////
#ifdef PMARK
#pragma mark - Prototypes
#endif
BEGIN_TOGGLED_C_DECLS

/*
 *  Error API          -- Functions for retrieving error information
 *  Memory API         -- Functions for managing library memory
 */

/***************/
/*  Error API  */
/***************/

// returns error code
int toggled_errno(TOGGLED * td);

// prints error message
void toggled_perror(TOGGLED * td, const char * s);

// returns error message
const char * toggled_strerror(int errnum);

// copies error message into buffer
int toggled_strerror_r(int errnum, char * strerrbuff, size_t bufflen);


/****************/
/*  Memory API  */
/****************/

// initializes library handle
int toggled_initialize(TOGGLED ** tdp);

// closes sessions and frees resources
void toggled_terminate(TOGGLED * td);


END_TOGGLED_C_DECLS
#endif
/* end of header */
