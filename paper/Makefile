CC = gcc
CFLAGS = -g -Wall -Wextra -Wno-unused-parameter

build: all

all: paperserver papers.cgi paperinfo.cgi paperview.cgi paperload.cgi

clean:
	rm -f paperserver_clnt.o paperserver_xdr.o paperserver_svc.o \
	paperserver.o paperserver_clnt.c paperserver.h paperserver_xdr.c \
	paperserver_svc.c paperserver ../web/cgi-bin/papers.cgi papers.o ../web/cgi-bin/paperinfo.cgi \
	paperinfo.o ../web/cgi-bin/paperview.cgi paperview.o ../web/cgi-bin/paperload.cgi paperload.o


papers.cgi: papers.o paperserver_clnt.o paperserver_xdr.o 
	$(CC) -o ../web/cgi-bin/papers.cgi papers.o paperserver_clnt.o paperserver_xdr.o -lnsl  

paperview.cgi: paperview.o paperserver_clnt.o paperserver_xdr.o ../ccgi/libccgi.a
	$(CC) -o ../web/cgi-bin/paperview.cgi paperview.o paperserver_clnt.o paperserver_xdr.o -lnsl -lccgi

paperload.cgi: paperload.o paperserver_clnt.o paperserver_xdr.o ../ccgi/libccgi.a
	$(CC) -o ../web/cgi-bin/paperload.cgi paperload.o paperserver_clnt.o paperserver_xdr.o -lnsl -lccgi

paperinfo.cgi: paperinfo.o paperserver_clnt.o paperserver_xdr.o ../ccgi/libccgi.a
	$(CC) -o ../web/cgi-bin/paperinfo.cgi paperinfo.o paperserver_clnt.o paperserver_xdr.o -lnsl -lccgi


paperserver: paperserver.o paperserver_svc.o paperserver_xdr.o
	$(CC) -o paperserver paperserver.o paperserver_svc.o paperserver_xdr.o -lnsl 

paperserver_clnt.c paperserver.h paperserver_xdr.c paperserver_svc.c: paperserver.x
	rpcgen paperserver.x

papers.o: papers.c paperserver.h config.h
	$(CC) $(CFLAGS) -c -o papers.o papers.c

paperinfo.o: paperinfo.c paperserver.h config.h ../ccgi/ccgi.h
	$(CC) $(CFLAGS) -c -o paperinfo.o paperinfo.c

paperload.o: paperload.c paperserver.h config.h ../ccgi/ccgi.h
	$(CC) $(CFLAGS) -c -o paperload.o paperload.c

paperview.o: paperview.c paperserver.h config.h ../ccgi/ccgi.h
	$(CC) $(CFLAGS) -c -o paperview.o paperview.c

paperserver_clnt.o: paperserver_clnt.c paperserver.h
	$(CC) $(CFLAGS) -c -o paperserver_clnt.o paperserver_clnt.c

paperserver_xdr.o: paperserver_xdr.c paperserver.h
	$(CC) $(CFLAGS) -c -o paperserver_xdr.o paperserver_xdr.c

paperserver_svc.o: paperserver_svc.c paperserver.h
	$(CC) $(CFLAGS) -c -o paperserver_svc.o paperserver_svc.c

paperserver.o: paperserver.c paperserver.h
	$(CC) $(CFLAGS) -c -o paperserver.o paperserver.c