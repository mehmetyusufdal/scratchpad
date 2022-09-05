/**
 * @file lru_cache.hpp
 * @author Mehmet Yusuf Dal (mehmetyusufdal@gmail.com)
 * @brief LRU Cache Implementation
 * @date 2022-08-25
 */
#pragma once

#include <unordered_map>
#include <list>

template <class key_T, class val_T>
class LRUCache {
private:
	static constexpr char except_msg[] = "key not found";

	std::size_t capacity{ NULL };
	std::list<key_T> cache{};
	std::unordered_map<key_T, val_T> data{};

	typedef std::pair<key_T, val_T> data_pair;

public:
	/**
	 * @brief Construct a new LRUCache object
	 * 
	 * @param capacity Capacity of hashmap
	 */
	LRUCache(std::size_t capacity) : capacity(capacity) {}

	/**
	 * @brief Set the capacity of hashmap
	 * 
	 * @param capacity Capacity of hashmap
	 */
	void set_capacity(std::size_t capacity) noexcept { this->capacity = capacity; }

	/**
	 * @brief Clear LRUCache
	 */
	void clear() noexcept {
		cache.clear();
		data.clear();
	};

	/**
	 * @brief Append new data into hashmap with key & value parameters
	 * 
	 * @param key 
	 * @param val 
	 * @return true if data successfully appended
	 * @return false if data cannot be appended
	 */
	bool append(key_T const& key, val_T const& val) {
		if (data.find(key) == data.end()) {
			if (data.size() + 1 > capacity) {
				data.erase(data.find(cache.back()));
				cache.pop_back();
			}
			data.emplace(key, val);
			cache.push_front(key);
			return true;
		}
		// else { } // Note: Maybe throw exception?
		return false;
	}

	/**
	 * @brief Append new data into hashmap with std::pair<key, value>
	 * 
	 * @param val 
	 * @return true if data successfully appended
	 * @return false if data cannot be appended
	 */
	bool append(data_pair const& val) {
		return append(val.first, val.second);
	}

	/**
	 * @brief Find given key in hashmap
	 * 
	 * @param key 
	 * @return reference to given key in hashmap
	 */
	auto find(key_T const& key) -> decltype(data.begin()) {
		auto return_val = data.find(key);
		if (return_val != data.end()) {
			auto t = std::find(cache.begin(), cache.end(), key);
			cache.splice(cache.begin(), cache, t);
		}
		return return_val;
	}

	/**
	 * @brief Erase given key and its value from hashmap
	 * 
	 * @param key 
	 * @return true if successfully erased
	 * @return false if can not be erased
	 */
	bool erase(key_T const& key) {
		auto iter = find(key);
		if (iter != data.end()) {
			data.erase(iter);
			cache.pop_front();
			return true;
		}
		return false;
	}

	/**
	 * @brief Get the value of given key
	 * 
	 * @param key 
	 * @return value of given key
	 * @exception std::runtime_error key not found in the hashmap
	 */
	val_T get_value(key_T const& key) {
		auto iter = find(key);
		[[unlikely]] if (iter == data.end()) throw(std::runtime_error(except_msg));
		return iter->second;
	}

	/**
	 * @brief Get the value of given key
	 * 
	 * @param key 
	 * @return value of given key
	 * @exception std::runtime_error key not found in the hashmap
	 */
	val_T operator[](key_T const& key) {
		return get_value(key);
	}
};