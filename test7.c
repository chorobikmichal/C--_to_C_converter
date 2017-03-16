#include<stdio.h>
#include<stdlib.h>


struct A {
int a;
   int (*Afn)(struct A* this );
};

struct B {
int b;
   int (*Bfn)(struct B* this );
};


/* two classes which contain the same method name */




int Bfn(struct B* this ) {
      this->b = 4;
   }


void constructorB (struct B* this) {
	this->Bfn = &Bfn;
	}

int Afn(struct A* this ) {
      this->a = 3;
   }


void constructorA (struct A* this) {
	this->Afn = &Afn;
	}



int main(int argc, char *argv[]) {
struct A myA;
constructorA(&myA);
struct B myB;
constructorB(&myB);

   myA.Afn(&myA);
   myB.Bfn(&myB);
   if ((myA.a == 3) && (myB.b == 4))
      return(0);
   else
      return(1);
}
