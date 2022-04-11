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
		ArrayTag(std::string key, uint16 size, bool floating): Tag(key, BD_TAG_ID_ARRAY), TagSizeable(size, floating) {
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

			for(uint16 i = 0; i < values.size(); ++i) {
				stream.write(reinterpret_cast<const char*>(&values[i]), sizeof(T));
			}
		}
		void stringify(std::stringstream& ss) const {
			bool floating = this->TagSizeable::isFloating();
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

			bool first = true;
			for(uint16 i = 0; i < values.size(); ++i) {
				if(!first) ss << ",";

				ss << values.at(i);
				first = false;
			}
			ss << "]";
		}

		void deSerialize(std::istream& stream) override { }

	private:
		std::vector<T> values;
	};
}
