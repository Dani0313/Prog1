#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kiir(char* p, int x){
	printf("p is \"%s\" and x is %i\n",p,x);
}

int main(){
	printf("Hello, World!\n");

	char* hello = "Hello";
	char* world = "World!";
    char* hello_world = (char*) malloc(strlen(hello)+strlen(world)+2);
    strcpy(hello_world,hello);
    hello_world[strlen(hello)] = ' ';
    strcpy(hello_world+strlen(hello)+1,world);
    printf("%s\n",hello_world);

    kiir("foo",7);
    kiir("alma",1);
    kiir("körte",2);
    kiir("szilva",3);
    kiir("barack",4);
    kiir("birs",5);

}