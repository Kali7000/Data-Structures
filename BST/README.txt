Binary Search Tree (BST) and K-th Smallest Element Finder


This program writes a Binary Search Tree (BST) from a list of integers and finds the k-th smallest element in the tree. It uses in-order traversal to collect the elements in sorted order and retrieves the desired element based on user input.

The list of integers is given, and since the given list is sorted the program takes the middle element to create a balanced tree.

then the program askes for k to find the kth element. Then using InOrder traversal, the program stores those elements in an vector. Then using user input the program prints kth smallest element.


To Run using makefile,
	go to the program folder via the command prompt
	type "make.exe"
	then "make run" to run the program
	
	you'll be promted to enter the k

	once the program is done, type "make clean" to delete the compiled files