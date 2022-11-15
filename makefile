all: loops recursives recursived loopd mains maindloop maindrec

loops: basicClassification.o advancedClassificationLoop.o
	ar -rc libclassloops.a basicClassification.o advancedClassificationLoop.o 
	
recursives: basicClassification.o advancedClassificationRecursion.o
	ar -rc libclassrec.a basicClassification.o advancedClassificationRecursion.o 
	
recursived: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.c advancedClassificationRecursion.c 
	
loopd: basicClassification.c advancedClassificationLoop.c
	gcc -shared -o libclassloops.so basicClassification.c advancedClassificationLoop.c




	
mains: main.c recursives 
	gcc -Wall main.c ./libclassrec.a -L. -o mains
	
maindloop: main.c loopd 
	gcc -Wall -fPIC main.c ./libclassloops.so -o maindloop
	
maindrec: main.c recursived 
	gcc -Wall -fPIC main.c ./libclassrec.so -o maindrec

.PHONY: clean

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
