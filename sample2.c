#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct A {
int a;
   int (*Asumiii)(struct A* this ,int x ,int y ,int z );
};

struct B {
   float a, b, c;
   void (*Bsetaf)(struct B* this ,float value );
   void (*Bsetbf)(struct B* this ,float value );
   void (*Bsetcf)(struct B* this ,float value );
   float (*Bgeta)(struct B* this );
   float (*Bgetb)(struct B* this );
   float (*Bgetc)(struct B* this );
};




void Bsetaf(struct B* this , float value) {
      this->a = value;
   }
void Bsetbf(struct B* this , float value) {
      this->b = value;
   }
void Bsetcf(struct B* this , float value) {
      this->c = value;
   }
float Bgeta(struct B* this ) {
      return(this->a);
   }
float Bgetb(struct B* this ) {
      return(this->b);
   }
float Bgetc(struct B* this ) {
      return(this->c);
   }


void constructorB (struct B* this) {
	this->Bsetaf = &Bsetaf;
	this->Bsetbf = &Bsetbf;
	this->Bsetcf = &Bsetcf;
	this->Bgeta = &Bgeta;
	this->Bgetb = &Bgetb;
	this->Bgetc = &Bgetc;
	}

int  Asumiii(struct A* this , int x, int y, int z) {
      return(x+ y +z);
   }


void constructorA (struct A* this) {
	this->Asumiii = &Asumiii;
	}



int main(int argc, char *argv[]) {
struct A myA;
constructorA(&myA);
int total;
int a, b, c;
struct B myB;
constructorB(&myB);
float val;

   a = 1;
   b = 2;
   c = 3;

   total = myA.Asumiii(&myA, a, b, c);
   printf("output shoudl be 6: %d\n", total);

   val =1.5;
   myB.Bsetaf(&myB, val);
   printf("output should be 1.50000: %f\n", myB.Bgeta(&myB));

}
