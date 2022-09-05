#include <iostream>
#include <string>
#include <binary_tree.hpp>

int main(int, char **) {

	BinaryTree<float> k(5.2);

	k.append(3);
	k.append(4.65);
	k.append(1.255);
	k.append(2);
	k.append(6);

	k.print();

	return 0;
}