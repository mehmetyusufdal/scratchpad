#include <iostream>
#include <string>
#include <lru_cache.hpp>

int main(int, char **) {

  /*LRU Cache Tests*/
	LRUCache<std::uint8_t, std::string> l(5);

	l.append(std::make_pair(0, "test_0"));
	l.append(std::make_pair(1, "test_1"));
	l.append(std::make_pair(1, "test_1"));
	l.append(std::make_pair(2, "test_2"));
	l.append(std::make_pair(3, "test_3"));
	l.append(std::make_pair(4, "test_4"));
	l.append(std::make_pair(5, "test_5"));
	l.append(std::make_pair(6, "test_6"));


	std::cout << l.find(2)->second << std::endl;
	std::cout << l.get_value(5) << std::endl;
	l.append(std::make_pair(7, "test_7"));
	std::cout << l[7] << std::endl;
	l.append(8, "test_8");
	l.append(0, "test_0");
	l.append(0, "test_0");

	try {
		l[15];
	}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; }

  std::cout << l.erase(7) << std::endl;
  std::cout << l.erase(7) << std::endl;
  /*LRU Cache Tests*/

	return 0;
}