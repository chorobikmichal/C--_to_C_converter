#include<stdio.h>
#include<stdlib.h>


struct A {
int a, b;
   int (*Afni)(struct A* this ,int i );
   int (*Afnii)(struct A* this ,int i ,int j );
};



/* overloaded methods, comment with the word class in it */




int Afni(struct A* this , int i) {
      this->a = i;
   }
int Afnii(struct A* this , int i,int j) {
      this->b = i + j;
   }


void constructorA (struct A* this) {
	this->Afni = &Afni;
	this->Afnii = &Afnii;
	}



int main(int argc, char *argv[]) {
struct A myA, myB;
constructorA(&myA);
int vali, valj;

   vali = 1;
   valj = 2;

   myA.Afni(&myA, vali);
   myA.Afni(&myA, vali,valj);

   if ((myA.a == 1) && (myA.b == 3))
      return(0);
   else
      return(1);
}
