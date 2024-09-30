!/bin/bash

function C {
	 echo  function_C
	 }
C

function B {
echo  $1 $2
} 

B "function_B" "hello"
B "function_B" "hello"
