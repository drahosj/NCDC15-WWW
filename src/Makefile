LIBOBJECTS=utils.o
BINOBJECTS=create-user.o show-user.o delete-user.o get-access-token.o get-admin-access-token.o make-deposit.o make-withdrawal.o make-payment.o find-user.o landing.o logout.o
BINARIES=create-user show-user delete-user get-access-token get-admin-access-token make-deposit make-withdrawal make-payment find-user landing logout

CFLAGS=-g

all: $(BINARIES) 

install: all
	install create-user ../cgi-bin/actions/
	install delete-user ../cgi-bin/actions/
	install make-deposit ../cgi-bin/actions/
	install make-payment ../cgi-bin/actions/
	install make-withdrawal ../cgi-bin/actions/
	install find-user ../cgi-bin/actions/
	install get-access-token ../cgi-bin/actions/
	install get-admin-access-token ../cgi-bin/actions/
	install logout ../cgi-bin/actions/
	install show-user ../cgi-bin/show/
	install landing ../cgi-bin/show/

uninstall:
	rm -f ../cgi-bin/actions/create-user
	rm -f ../cgi-bin/actions/make-deposit
	rm -f ../cgi-bin/actions/make-payment
	rm -f ../cgi-bin/actions/make-withdrawal
	rm -f ../cgi-bin/actions/delete-user
	rm -f ../cgi-bin/actions/find-user
	rm -f ../cgi-bin/actions/get-access-token
	rm -f ../cgi-bin/actions/get-admin-access-token
	rm -f ../cgi-bin/actions/logout
	rm -f ../cgi-bin/show/show-user
	rm -f ../cgi-bin/show/langing

create-user: $(LIBOBJECTS) create-user.o
	gcc -o create-user $(LIBOBJECTS) create-user.o

logout: $(LIBOBJECTS) logout.o
	gcc -o logout $(LIBOBJECTS) logout.o

make-payment: $(LIBOBJECTS) make-payment.o
	gcc -o make-payment $(LIBOBJECTS) make-payment.o

make-deposit: $(LIBOBJECTS) make-deposit.o
	gcc -o make-deposit $(LIBOBJECTS) make-deposit.o

make-withdrawal: $(LIBOBJECTS) make-withdrawal.o
	gcc -o make-withdrawal $(LIBOBJECTS) make-withdrawal.o

show-user: $(LIBOBJECTS) show-user.o
	gcc -o show-user $(LIBOBJECTS) show-user.o

delete-user: $(LIBOBJECTS) delete-user.o
	gcc -o delete-user $(LIBOBJECTS) delete-user.o

find-user: $(LIBOBJECTS) find-user.o
	gcc -o find-user $(LIBOBJECTS) find-user.o

get-access-token: $(LIBOBJECTS) get-access-token.o
	gcc -o get-access-token $(LIBOBJECTS) get-access-token.o

get-admin-access-token: $(LIBOBJECTS) get-admin-access-token.o
	gcc -o get-admin-access-token $(LIBOBJECTS) get-admin-access-token.o

landing: $(LIBOBJECTS) landing.o
	gcc -o landing $(LIBOBJECTS) landing.o

clean:
	rm $(LIBOBJECTS) $(BINOBJECTS) $(BINARIES) -f
