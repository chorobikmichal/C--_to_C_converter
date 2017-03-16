#include<stdio.h>
newline
#include<stdlib.h>
newline
newline
struct
 
mystruct
 
{
newline
 
 
 
float
 
f
;
newline
}
;
newline
newline
class
newline
E
 
{
newline
 
 
 
float
newline
 
 
 
 
 
 
abc
 
=
 
1
.
2
;
newline
 
 
 
struct
 
mystruct
 
*
 
method
(
)
 
{
newline
 
 
 
struct
 
mystruct
 
*
ptr
;
newline
 
 
 
 
 
 
ptr
 
=
 
malloc
(
sizeof
(
struct
 
mystruct
)
)
;
newline
 
 
 
 
 
 
ptr
-
>f
 
=
 
abc
;
newline
 
 
 
 
 
 
return
(
ptr
)
;
newline
 
 
 
}
newline
}
;
newline
newline
newline
newline
/* complex class structure with initialized variable */
newline
newline
int
 
main
(
int
 
argc
,
 
char
 
*
argv
[
]
)
 
{
newline
class
 
E
 
myE
;
newline
struct
 
mystruct
 
*
p
;
newline
 
 
 
newline
 
 
 
p
 
=
 
myE
.
method
(
)
;
newline
 
 
 
if
 
(
p
-
>f
 
=
=
 
1
.
2f
)
newline
 
 
 
 
 
 
return
(
0
)
;
newline
 
 
 
else
newline
 
 
 
 
 
 
return
(
1
)
;
newline
}
newline
newline
