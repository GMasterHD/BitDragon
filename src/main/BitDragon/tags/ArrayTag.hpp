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

		void add(T val) {
			values.push_back(val);
		}
		const T& get(uint16 index) {
			return values.at(index);
		}

		uint16 length() {
			return values.size();
		}

		const T& operator[](uint16 index) const {
			return values.at(index);
		}

		void foreach(std::function<void(T)> f) const {
			for(uint16 i = 0; i < values.size(); ++i) {
				f(values.at(i));
			}
		}
		void foreach(std::function<void(T, uint16)> f) const {
			for(uint16 i = 0; i < values.size(); ++i) {
				f(values.at(i), i);
			}
		}

		void serialize(std::ostream& stream) const override {
			uint16 length = values.size();
			stream.write(reinterpret_cast<const char*>(&length), sizeof(uint16));

			for(uint16 i = 0; i < values.size(); ++i) {
				stream.write(reinterpret_cast<const char*>(&values[i]), sizeof(T));
			}
		}
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
