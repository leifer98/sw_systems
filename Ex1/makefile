all: mains maindloop maindrec recursived loopd recursives loops 
	
loops: libclassloops.a
recursives: libclassrec.a
loopd: libclassrec.so
recursived: libclassloops.so

mains: libclassrec.a main.o
	gcc -Wall -g main.o ./libclassrec.a -L. -o mains
	
maindloop: libclassloops.so main.o 
	gcc -Wall -g main.o ./libclassloops.so -L. -o maindloop
	
maindrec: libclassrec.so main.o 
	gcc -Wall -g main.o ./libclassrec.so -L. -o maindrec

libclassloops.a: basicClassification.o advancedClassificationLoop.o NumClass.h
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o 
	
libclassrec.a: basicClassification.o advancedClassificationRecursion.o NumClass.h
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o 
	
libclassrec.so: basicClassification.o advancedClassificationRecursion.o NumClass.h
	gcc -shared -fPIC -o libclassrec.so basicClassification.o advancedClassificationRecursion.o
	
libclassloops.so: basicClassification.o advancedClassificationLoop.o NumClass.h
	gcc -shared -fPIC -o libclassloops.so basicClassification.o advancedClassificationLoop.o

.PHONY: clean all loops recursives loopd recursived

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
