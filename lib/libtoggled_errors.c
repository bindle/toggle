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
 *  @file lib/libtoggled_errors.c error management functions
 */

///////////////
//           //
//  Headers  //
//           //
///////////////
#ifdef PMARK
#pragma mark Headers
#endif

#include "libtoggled.h"

#include <string.h>


/////////////////
//             //
//  Functions  //
//             //
/////////////////
#ifdef PMARK
#pragma mark -
#pragma mark Functions
#endif

/// @brief returns error code
/// @param td      pointer to configuration struct
int toggled_errno(TOGGLED * td)
{
   if (!(td))
      return(-1);
   return(td->errno_ex);
}


/// @brief prints error message
/// @param td      pointer to configuration struct
/// @param s       string to prefix error output
void toggled_perror(TOGGLED * td, const char * s)
{
   const char * msg;
   if (!(td))
   {
      fprintf(stderr, "%s: invalid library handle or pointer\n", s);
      return;
   };
   msg = toggled_strerror(td->errno_ex);
   fprintf(stderr, "%s: %s\n", s, msg);
}


/// @brief returns error message
/// @param errnum   code of the error to return
const char * toggled_strerror(int errnum)
{
   switch(errnum)
   {
      case TOGGLED_ESUCCESS:   return("success");
      case TOGGLED_ENOMEM:     return("out of virtual memory");
      case TOGGLED_EHANDLE:    return("invalid library handle or pointer");
      default:
         break;
   };
   return("unknown error code");
}


/// @brief copies error message into buffer
/// @param td          pointer to configuration struct
/// @param errnum      code of the error to return
/// @param strerrbuf   buffer to store error message
/// @param buflen      length of the buffer
int toggled_strerror_r(int errnum, char * strerrbuff, size_t bufflen)
{
   const char * msg;
   msg = toggled_strerror(errnum);
   strncpy(strerrbuff, msg, bufflen-1);
   strerrbuff[bufflen-1] = '\0';
   return(0);
}


/* end of source code */
