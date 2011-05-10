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
 *  @file include/toggled_module.h API for toggled modules
 */
#ifndef _TOGGLED_MODULE_H
#define _TOGGLED_MODULE_H 1

///////////////
//           //
//  Headers  //
//           //
///////////////
#ifdef PMARK
#pragma mark -
#pragma mark Headers
#endif

#include <toggled.h>
#include <inttypes.h>


///////////////////
//               //
//  Definitions  //
//               //
///////////////////
#ifdef PMARK
#pragma mark -
#pragma mark Definitions & Macros
#endif

// toggled module API version info
#define TOGGLED_MODULE_VERSION_CURRENT    0x00L
#define TOGGLED_MODULE_VERSION_REVISION   0x00L
#define TOGGLED_MODULE_VERSION_AGE        0x00L


/////////////////
//             //
//  Datatypes  //
//             //
/////////////////
#ifdef PMARK
#pragma mark -
#pragma mark Datatypes
#endif

/// @brief toggled module information
///
/// Version Info for Modules/Library:
///    Current    -- the current version number of this API
///    Revision   -- the revision of the implementation of the API version
///    Age        -- How many seqential past API versions is supported by
///                  this implementation
typedef struct toggled_module_info ToggledModuleInfo;
struct toggled_module_info
{
   uint64_t      toggled_current;    ///< current version of libtoggled_module.la
   uint64_t      toggled_revision;   ///< revision of libtoggled_module.la
   uint64_t      toggled_age;        ///< age of libtoggled_module.la
   uint64_t      module_current;     ///< current version of module's config API
   uint64_t      module_revision;    ///< revision of module's config API
   uint64_t      module_age;         ///< age of module's config API
   const char  * module_name;        ///< name of module
   const char  * module_description; ///< description of module
};


#endif
/* end of header */
