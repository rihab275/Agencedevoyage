## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = yassinepc

yassinepc_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	ylogin.c ylogin.h \
	TimeDate.c TimeDate.h \
	reclamationclient.c reclamationclient.h 

yassinepc_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

