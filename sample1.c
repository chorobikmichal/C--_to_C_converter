#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a;

	/* different ways to access variables */

struct A {
int a;
   void (*Aprint1i)(struct A* this ,int a );
   void (*Aprint2)(struct A* this );
   void (*Aprint3)(struct A* this );
};

struct B {
   void (*Bprint4)(struct B* this );
};

	/* simple function outside of a class */
float product(float a, float b) {
   return( a*b );
}





void Bprint4(struct B* this ) {
		/* there is no class variable named a so print global variable*/
      printf("output should be 4: %d\n", a);
   }


void constructorB (struct B* this) {
	this->Bprint4 = &Bprint4;
	}

void Aprint1i(struct A* this , int a) {
		/* print parameter - local to the function*/
      printf("output should be 1: %d\n", a);
   }
void Aprint2(struct A* this ) {
		/* create a local variable*/
      int a = 2;
		/* print local variable*/
      printf("output should be 2: %d\n", a);
   }
void Aprint3(struct A* this ) {
		/* there is a class variable named a so*/
		/* assign value to it and print the class variable*/
      this->a = 3;
      printf("output should be 3: %d\n", this->a);
   }


void constructorA (struct A* this) {
	this->Aprint1i = &Aprint1i;
	this->Aprint2 = &Aprint2;
	this->Aprint3 = &Aprint3;
	}



int main(int argc, char *argv[]) {
struct A myA;
constructorA(&myA);
struct B myB;
constructorB(&myB);
int value;
char str[100];

   printf("Hello \" there\n");
   strcpy(str, "A string containing the word class may be tricky");

   a = 4;
   value = 1;

   myA.Aprint1i(&myA, value);
   myA.Aprint2(&myA);
   myA.Aprint3(&myA);

   myB.Bprint4(&myB);

}
