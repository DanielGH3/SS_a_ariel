BASIC = basicClassification
LOOP = advancedClassificationLoop
RECUR = advancedClassificationRecursion

all:
	gcc -Wall -c $(BASIC).c
	gcc -Wall -c $(LOOP).c
	gcc -Wall -c $(RECUR).c
	ar -rc libclassloops.a $(BASIC).o $(LOOP).o
	ar -rc libclassrec.a $(BASIC).o $(RECUR).o
	
	gcc -c -Wall -Werror -fpic $(BASIC).c $(RECUR).c
	gcc -c -Wall -Werror -fpic $(BASIC).c $(LOOP).c
	gcc -shared -o libclassrec.so $(BASIC).o $(RECUR).o
	gcc -shared -o libclassloops.so $(BASIC).o $(LOOP).o
	gcc -o mains main.c libclassloops.a
	gcc -o maindloop main.c libclassloops.so
	gcc -o maindrec main.c libclassrec.so

loops:
	gcc -Wall -c $(BASIC).c $(LOOP).c
	ar -rc libclassloops.a $(BASIC).o $(LOOP).o

recursives:
	gcc -Wall -c $(BASIC).c $(RECUR).c
	ar -rc libclassrec.a $(BASIC).o $(RECUR).o

recursived:
	gcc -c -Wall -Werror -fpic $(BASIC).c $(RECUR).c
	gcc -shared -o libclassrec.so $(BASIC).o $(RECUR).o
	
loopd:
	gcc -c -Wall -Werror -fpic $(BASIC).c $(LOOP).c
	gcc -shared -o libclassloops.so $(BASIC).o $(LOOP).o

mains:
	make loops
	gcc -o mains main.c libclassloops.a

maindloop:
	make loopd
	gcc -o maindloop main.c libclassloops.so

maindrec:
	make recursived
	gcc -o maindrec main.c libclassrec.so

clean:
	rm -v !(*.c|*.h|*.txt)
