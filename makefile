BASIC = basicClassification
LOOP = advancedClassificationLoop
RECUR = advancedClassificationRecursion

all: mains maindloop maindrec loops

loops: libclassloops.a
	
recursives: libclassrec.a
	
recursived:  libclassrec.so
	
loopd:  libclassloops.so
	
mains: libclassrec.a
	gcc -o mains main.c libclassrec.a
	
maindloop: libclassloops.so
	gcc -Wall -o maindloop main.c libclassloops.so
	
maindrec: libclassrec.so
	gcc -Wall -o maindrec main.c libclassrec.so
	
libclassrec.so: $(BASIC).c $(RECUR).c
	gcc -c -Wall -Werror -fpic $(BASIC).c $(RECUR).c
	gcc -shared -Wall $(BASIC).o $(RECUR).o -o libclassrec.so

libclassloops.so: $(BASIC).c $(LOOP).c
	gcc -c -Wall -Werror -fpic $(BASIC).c $(LOOP).c
	gcc -shared -Wall $(BASIC).o $(LOOP).o -o libclassloops.so

libclassrec.a: $(BASIC).o $(RECUR).o
	ar -rc libclassrec.a $(BASIC).o $(RECUR).o

libclassloops.a: $(BASIC).o $(LOOP).o
	ar -rc libclassloops.a $(BASIC).o $(LOOP).o

basicClassification.o: $(BASIC).c
	gcc -Wall -c $(BASIC).c
	
advancedClassificationLoop.o: $(LOOP).c
	gcc -Wall -c $(LOOP).c
	
advancedClassificationRecursion.o: $(RECUR).c
	gcc -Wall -c $(RECUR).c
	
clean:
	
