# soap - simple xdg-open replacement with fallback


# install location
PREFIX = /usr/local

# compiler and linker
CC = cc
CFLAGS = -pedantic -Wall -Wextra -O2 ${INCS}
LDFLAGS = -s

SRC = soap.c
OBJ = ${SRC:.c=.o}

all: soap

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h

config.h:
	cp config.def.h $@

soap: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f soap ${OBJ}

install: all
	install -Dm755 soap ${DESTDIR}${PREFIX}/bin
	ln -sf ${DESTDIR}${PREFIX}/bin/soap ${DESTDIR}${PREFIX}/bin/xdg-open

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/soap ${DESTDIR}${PREFIX}/bin/xdg-open
