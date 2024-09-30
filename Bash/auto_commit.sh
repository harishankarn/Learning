#!/bin/bash

# This file can be run to automatically 
# add, commit and push a file to git

git add .
echo "enter message : " 

# 'read' stores the user input into 
# the variable "message"

read message

# To print out the text in the variable,
# we put '$' in front of the variable.

#generally we us it inside the quotes
# of ' echo" " '

git commit -m $message 
git push
