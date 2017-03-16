#include<stdio.h>
#include<stdlib.h>


struct A {
   int (*Afn)(struct A* this );
};


/* use the return value of method in a class */




int Afn(struct A* this ) {
      return(3);
   }


void constructorA (struct A* this) {
	this->Afn = &Afn;
	}



int main(int argc, char *argv[]) {
struct A myA;
constructorA(&myA);
int retValue;

   retValue = myA.Afn(&myA);
   if (retValue == 3)
      return(0);
   else
      return(1);
}
