/**
 * @file lru_cache.hpp
 * @author Mehmet Yusuf Dal (mehmetyusufdal@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <unordered_map>
#include <list>

#include <iostream>//temp
#include <string>//temp

template <class key_T, class val_T>
class LRUCache {
private:
	static constexpr char except_msg[] = "key not found";

	std::size_t capacity{ NULL };
	std::list<key_T> cache{};
	std::unordered_map<key_T, val_T> data{};

    typedef std::pair<key_T, val_T> data_pair;

public:
	LRUCache(std::size_t capacity) : capacity(capacity) {}

	void print() const {//temp
		for (auto t : cache) {
			std::cout << std::to_string(t) << " ";
		}
		printf("\n");
	}//temp

	void set_capacity(std::size_t capacity) noexcept { this->capacity = capacity; }

	void clear() noexcept {
		cache.clear();
		data.clear();
	};

	bool append(key_T const& key, val_T const& val) {
		if (data.find(key) == data.end()) {
			if (data.size() + 1 > capacity) {
				data.erase(data.find(cache.back()));
				cache.pop_back();
			}
			data.emplace(key, val);
			cache.push_front(key);
			print();//temp
			return true;
		}
		//else { } // Note: Maybe throw exception?
		return false;
	}

	bool append(data_pair const& val) {
		return append(val.first, val.second);
	}

	auto find(key_T const& key) -> decltype(data.begin()) {
		auto return_val = data.find(key);
		if (return_val != data.end()) {
			auto t = std::find(cache.begin(), cache.end(), key);
			cache.splice(cache.begin(), cache, t);
			print();//temp
		}
		return return_val;
	}

    bool erase(key_T const& key) {
        auto iter = find(key);
        if(iter != data.end()) {
            data.erase(iter);
            cache.pop_front();
            print();//temp
            return true;
        }
        print();//temp
        return false;
    }

	val_T get_value(key_T const& key) {
		auto iter = find(key);
		[[unlikely]] if (iter == data.end()) throw(std::runtime_error(except_msg));
		return iter->second;
	}

	val_T operator [] (key_T const& key) {
		return get_value(key);
	}
	
};