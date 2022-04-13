#pragma once
#include "../Defines.hpp"
#include "Tag.hpp"
#include "TagSizeable.hpp"
#include <vector>
#include <sstream>
#include <functional>

namespace bd {
	template<typename T>
	class ArrayTag: public Tag, public TagSizeable {
	public:
		ArrayTag(std::string key, uint16 size, bool floating): Tag(key, floating ? BD_TAG_ID_ARRAY_FLOAT : BD_TAG_ID_ARRAY), TagSizeable(size, floating) {
		}

		/// <summary>
		/// Adds an array element to this array
		/// </summary>
		/// <param name="val">The value of the element</param>
		void add(T val) {
			values.push_back(val);
		}
		/// <summary>
		/// Gets a element at a index
		/// </summary>
		/// <param name="index">The index</param>
		/// <returns>The element at the index</returns>
		const T& get(uint16 index) {
			return values.at(index);
		}

		/// <summary>
		/// Gets the count of elements in this array
		/// </summary>
		/// <returns>The count</returns>
		uint16 length() {
			return values.size();
		}

		const T& operator[](uint16 index) const {
			return values.at(index);
		}

		/// <summary>
		/// Parses the values
		/// </summary>
		/// <param name="f">Function to receive the values (void(value: T))</param>
		void foreach(std::function<void(T)> f) const {
			for(uint16 i = 0; i < values.size(); ++i) {
				f(values.at(i));
			}
		}
		/// <summary>
		/// Parses the values
		/// </summary>
		/// <param name="f">Function to receive the values (void(value: T, index: uint16)</param>
		void foreach(std::function<void(T, uint16)> f) const {
			for(uint16 i = 0; i < values.size(); ++i) {
				f(values.at(i), i);
			}
		}

		/// <summary>
		/// Writes the array to an ostream
		/// </summary>
		/// <param name="stream">The stream</param>
		void serialize(std::ostream& stream) const override {
			uint16 length = values.size();
			stream.write(reinterpret_cast<const char*>(&length), sizeof(uint16));

			for(uint16 i = 0; i < values.size(); ++i) {
				stream.write(reinterpret_cast<const char*>(&values[i]), sizeof(T));
			}
		}
		/// <summary>
		/// Converts this array into a string
		/// </summary>
		/// <param name="ss">The stream</param>
		/// <param name="tabs">If tabs should be used</param>
		/// <param name="currentIndention">The current indention (needed by other functions)</param>
		void stringify(std::ostream& ss, bool tabs, std::string currentIndention) const {
			bool floating = this->TagSizeable::isFloating();
			currentIndention += "\t";

			ss << "[";
			if(tabs) {
				ss << "\n" << currentIndention;
			}

			switch(this->TagSizeable::getSize()) {
				case 1: {
					ss << BD_TAG_DATA_TYPE_INT8 << ";";
					break;
				}
				case 2: {
					ss << BD_TAG_DATA_TYPE_INT16 << ";";
					break;
				}
				case 4: {
					if(floating) {
						ss << BD_TAG_DATA_TYPE_FLOAT << ";";
					} else {
						ss << BD_TAG_DATA_TYPE_INT32 << ";";
					}
					break;
				}
				case 8: {
					if(floating) {
						ss << BD_TAG_DATA_TYPE_DOUBLE << ";";
					} else {
						ss << BD_TAG_DATA_TYPE_INT64 << ";";
					}
					break;
				}
			}

			if(tabs) {
				ss << " ";
			}

			bool first = true;
			for(uint16 i = 0; i < values.size(); ++i) {
				if(!first) {
					ss << ",";
					if(tabs) {
						ss << " ";
					}
				}

				ss << values.at(i);
				first = false;
			}
			currentIndention = currentIndention.substr(0, currentIndention.size() - 1);

			if(tabs) {
				ss << "\n" << currentIndention;
			}

			ss << "]";
		}

		void deserialize(std::istream& stream) override {
			
		}

	private:
		std::vector<T> values;
	};
}
