LIBOBJECTS=utils.o
BINOBJECTS=create-user.o show-user.o delete-user.o get-access-token.o
BINARIES=create-user show-user delete-user get-access-token

CFLAGS=-g

all: $(BINARIES) 

install: all
	install create-user ../cgi-bin/actions/
	install delete-user ../cgi-bin/actions/
	install get-access-token ../cgi-bin/actions/
	install show-user ../cgi-bin/show/

uninstall:
	rm -f ../cgi-bin/actions/create-user
	rm -f ../cgi-bin/actions/delete-user
	rm -f ../cgi-bin/actions/get-access-token
	rm -f ../cgi-bin/show/show-user

create-user: $(LIBOBJECTS) create-user.o
	gcc -o create-user $(LIBOBJECTS) create-user.o

show-user: $(LIBOBJECTS) show-user.o
	gcc -o show-user $(LIBOBJECTS) show-user.o

delete-user: $(LIBOBJECTS) delete-user.o
	gcc -o delete-user $(LIBOBJECTS) delete-user.o

get-access-token: $(LIBOBJECTS) get-access-token.o
	gcc -o get-access-token $(LIBOBJECTS) get-access-token.o

clean:
	rm $(LIBOBJECTS) $(BINOBJECTS) $(BINARIES) -f
