#include<stdio.h>
#include<stdlib.h>


struct A {
int a, b;
   int (*Afnif)(struct A* this ,int i ,float * );
   int (*Afniflk)(struct A* this ,int i ,float j ,long long ,k );
};



/* overloaded methods with multiple types */




int Afnif(struct A* this , int i, float *pj) {
      this->a = i + (int) *pj;
   }
int Afniflk(struct A* this , int i,float j,long long k) {
      this->b = i + (int) j + (int) k;
   }


void constructorA (struct A* this) {
	this->Afnif = &Afnif;
	this->Afniflk = &Afniflk;
	}



int main(int argc, char *argv[]) {
struct A myA;
constructorA(&myA);
int vali;
float valj;
long long valk;
float *pj;

   vali = 1;
   valj = 2.5;
   valk = 10;
   pj = &valj;

   myA.Afnif(&myA, vali,pj);
   myA.Afnif(&myA, vali,valj,valk);

   if ((myA.a == 3) && (myA.b == 13))
      return(0);
   else
      return(1);
}
