#pragma once
#include "Tag.hpp"
#include "TagSizeable.hpp"
#include <any>

namespace bd {
	//template<typename  T>
	class NumberTag: public Tag, public TagSizeable {
	public:
		NumberTag(std::string key, std::any value, bool floating, uint16 size): Tag(key, floating ? BD_TAG_ID_NUMBER_FLOAT : BD_TAG_ID_NUMBER), TagSizeable(size, floating), value(value) {
		}

		std::any getValue() const { return value; }
		std::string getKey() const { return ((Tag*) this)->getKey(); }
	private:
		std::any value;
	};
}
