#
#   Toggle Provisioning System
#   Copyright (C) 2011 Bindle Binaries <syzdek@bindlebinaries.com>.
#
#   @BINDLE_BINARIES_BSD_LICENSE_START@
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are
#   met:
#
#      * Redistributions of source code must retain the above copyright
#        notice, this list of conditions and the following disclaimer.
#      * Redistributions in binary form must reproduce the above copyright
#        notice, this list of conditions and the following disclaimer in the
#        documentation and/or other materials provided with the distribution.
#      * Neither the name of Bindle Binaries nor the
#        names of its contributors may be used to endorse or promote products
#        derived from this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
#   IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#   THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BINDLE BINARIES BE LIABLE FOR
#   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
#   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
#   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
#   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
#   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
#   SUCH DAMAGE.
#
#   @BINDLE_BINARIES_BSD_LICENSE_END@
#
#   @configure_input@
#
#   Makefile.am - automate compiling on a unix platform
#

# Sub directories
SUBDIRS					=
DIST_SUBDIRS				=

# Global flags
AM_LIBS					=
AM_LDFLAGS				=
AM_CFLAGS				= -O2 $(CFLAGS_WARNINGS)
AM_CXXFLAGS				= -O2 @AM_CXXFLAGS@
AM_OBJCFLAGS				= -O2 @AM_OBJCFLAGS@
AM_CPPFLAGS				= -O2 -UPMARK -DHAVE_CONFIG_H=1 -I$(top_builddir)/include -I$(top_srcdir)/include -DSYSCONFDIR="\"$(sysconfdir)\""
ACLOCAL_AMFLAGS				= -I m4 -I contrib/bindletools/m4 -W all -W error
AM_MAKEINFOFLAGS                        = --no-split
DEFS					=


# automake targets
check_PROGRAMS				=
doc_DATA				=
include_HEADERS				= include/toggled.h include/toggled_module.h
lib_LTLIBRARIES				= lib/libtoggled.la
man_MANS				=
info_TEXINFOS				=
noinst_LTLIBRARIES			=
noinst_HEADERS				=
noinst_PROGRAMS				=
bin_PROGRAMS				=


# macros for lib/libtoggled.la
lib_libtoggled_la_DEPENDENCIES		= Makefile lib/libtoggled.sym
lib_libtoggled_la_CFLAGS		= $(AM_CFLAGS)
lib_libtoggled_la_LIBADD		= $(AM_LIBS)
lib_libtoggled_la_LDFLAGS		= -rpath '$(libdir)' \
					  -version-info $(LIB_VERSION_INFO) \
					  $(AM_LDFLAGS) \
					  -pthread \
					  -export-symbols $(srcdir)/lib/libtoggled.sym
lib_libtoggled_la_SOURCES		= include/toggled.h \
					  lib/libtoggled.h \
					  lib/libtoggled_errors.c


# lists
BUILT_SOURCES				= include/git-package-version
TESTS					=
XFAIL_TESTS				=
EXTRA_MANS				=
EXTRA_DIST				= build-aux/git-tar-name.txt  \
					  contrib/bindletools/COPYING \
					  contrib/bindletools/README \
					  contrib/bindletools/build-aux/autogen.sh \
					  contrib/bindletools/build-aux/git-package-version.sh \
					  contrib/bindletools/m4/bindle.m4 \
					  include/git-package-version.txt \
					  lib/libtoggled.sym
CLEANFILES				= \
					  $(builddir)/a.out   $(srcdir)/a.out \
					  $(builddir)/*/a.out $(srcdir)/*/a.out \
					  config.h.in~ $(srcdir)/config.h.in~ \
					  $(man_MANS) \
					  @PACKAGE_TARNAME@-*.tar.* \
					  @PACKAGE_TARNAME@-*.zip
DISTCHECK_CONFIGURE_FLAGS		= --enable-strictwarnings


# Makefile includes
GIT_PACKAGE_VERSION_DIR=include
SUBST_EXPRESSIONS = 
include $(srcdir)/contrib/bindletools/build-aux/makefile-autotools.am
include $(srcdir)/contrib/bindletools/build-aux/makefile-subst.am
include $(srcdir)/contrib/bindletools/build-aux/makefile-version.am


# custom targets
.PHONY: update gitclean include/git-package-version

include/git-package-version:
	@@GIT_VERSION_SCRIPT@ $(top_srcdir) > /dev/null 2>&1

gitclean:
	$(MAKE) -f Makefile distclean
	rm -f  $(top_srcdir)/INSTALL
	rm -f  $(top_srcdir)/Makefile.in
	rm -f  $(top_srcdir)/aclocal.m4
	rm -f  $(top_srcdir)/config.h.in
	rm -f  $(top_srcdir)/configure
	rm -f  $(top_srcdir)/include/git-package-version


# local targets
install-exec-local:

install-data-local:

uninstall-local:

clean-local:

distclean-local:
	rm -fR $(srcdir)/autom4te.cache

# end of automake file
