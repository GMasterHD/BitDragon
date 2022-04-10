#pragma once
#include "../Defines.hpp"
#include "Tag.hpp"
#include "TagSizeable.hpp"
#include <vector>
#include <sstream>

namespace bd {
	template<typename T>
	class ArrayTag: public Tag, public TagSizeable {
	public:
		ArrayTag(std::string key, uint16 size): Tag(key, BD_TAG_ID_ARRAY), TagSizeable(size) {
		}

		void add(T val) {
			values.push_back(val);
		}
		T& get(uint16 index) {
			return values.at(index);
		}
		uint16 length() {
			return values.size();
		}

		T& operator[](uint16 index) const {
			return get(index);
		}

		void serialize(std::ostream& stream) const override {
			uint16 length = values.size();
			stream.write(reinterpret_cast<const char*>(&length), sizeof(uint16));

			for(T v : values) {
				stream.write(reinterpret_cast<const char*>(&v), sizeof(T));
			}
		}
		void stringify(std::stringstream& ss) const {
			ss << "[";

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
					ss << BD_TAG_DATA_TYPE_INT32 << ";";
					break;
				}
				case 8: {
					ss << BD_TAG_DATA_TYPE_INT64 << ";";
					break;
				}
			}

			bool first = true;
			for(T v : values) {
				if(!first) ss << ",";
				ss << v;
				first = false;
			}
			ss << "]";
		}

		void deSerialize(std::istream& stream) override { }

	private:
		std::vector<T> values;
	};
}
