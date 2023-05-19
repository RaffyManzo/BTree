all: link

link : list stack btree item_str main
	gcc item_str.o main.o list.o stack.o btree.o -o btree.exe

list:
	gcc -c Stack/list.c

stack:
	gcc -c Stack/stack.c

btree :
	gcc -c btree.c
	
item_str :
	gcc -c item_str.c

main : 
	gcc -c main.c

clean : 
	rm -f *.o *.exe