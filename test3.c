#include<stdio.h>
#include<stdlib.h>


struct A {
int a;
   int (*Afn)(struct A* this );
};


/* set the value of a class variable from a method within the class */




int Afn(struct A* this ) {
      this->a = 3;
   }


void constructorA (struct A* this) {
	this->Afn = &Afn;
	}



int main(int argc, char *argv[]) {
struct A myA;
constructorA(&myA);

   myA.Afn(&myA);
   if (myA.a == 3)
      return(0);
   else
      return(1);
}
