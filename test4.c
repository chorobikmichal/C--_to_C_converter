#include<stdio.h>
#include<stdlib.h>


struct A {
int a;
   void (*Afni)(struct A* this ,int value );
};


/* set the value of a class variable using a method parameter */




void Afni(struct A* this , int value) {
      this->a = value;
   }


void constructorA (struct A* this) {
	this->Afni = &Afni;
	}



int main(int argc, char *argv[]) {
struct A myA;
constructorA(&myA);
int i;

   i = 3;
   myA.Afni(&myA, i);
   if (myA.a == 3)
      return(0);
   else
      return(1);
}
