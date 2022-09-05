#include <iostream>
#include <string>
#include <binary_tree.hpp>

int main(int, char **) {

	BinaryTree<int> k(5);

	k.append(3);
	k.append(4);
	k.append(1);
	k.append(2);
	k.append(7);
	k.append(6);

	// k.print();
	// printf("\n");

	std::cout << k.find(5)->value << std::endl;
	


	return 0;
}


/*

      5
   3     7
 1   4  6
  2

*/