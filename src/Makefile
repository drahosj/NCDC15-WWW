LIBOBJECTS=utils.o
BINOBJECTS=create-user.o show-user.o delete-user.o get-access-token.o get-admin-access-token.o make-deposit.o make-withdrawal.o make-payment
BINARIES=create-user show-user delete-user get-access-token get-admin-access-token make-deposit make-withdrawal make-payment

CFLAGS=-g

all: $(BINARIES) 

install: all
	install create-user ../cgi-bin/actions/
	install delete-user ../cgi-bin/actions/
	install make-deposit ../cgi-bin/actions/
	install make-payment ../cgi-bin/actions/
	install make-withdrawal ../cgi-bin/actions/
	install get-access-token ../cgi-bin/actions/
	install get-admin-access-token ../cgi-bin/actions/
	install show-user ../cgi-bin/show/

uninstall:
	rm -f ../cgi-bin/actions/create-user
	rm -f ../cgi-bin/actions/make-deposit
	rm -f ../cgi-bin/actions/make-payment
	rm -f ../cgi-bin/actions/make-withdrawal
	rm -f ../cgi-bin/actions/delete-user
	rm -f ../cgi-bin/actions/get-access-token
	rm -f ../cgi-bin/actions/get-admin-access-token
	rm -f ../cgi-bin/show/show-user

create-user: $(LIBOBJECTS) create-user.o
	gcc -o create-user $(LIBOBJECTS) create-user.o

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

get-access-token: $(LIBOBJECTS) get-access-token.o
	gcc -o get-access-token $(LIBOBJECTS) get-access-token.o

get-admin-access-token: $(LIBOBJECTS) get-admin-access-token.o
	gcc -o get-admin-access-token $(LIBOBJECTS) get-admin-access-token.o

clean:
	rm $(LIBOBJECTS) $(BINOBJECTS) $(BINARIES) -f
