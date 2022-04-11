#pragma once
#include "Tag.hpp"
#include "TagSizeable.hpp"
#include <any>

namespace bd {
	//template<typename  T>
	class NumberTag: public Tag, public TagSizeable {
	public:
		NumberTag(std::string key, std::any value, bool floating, uint16 size): Tag(key, BD_TAG_ID_NUMBER), TagSizeable(size, floating), value(value) {
		}

		void serialize(std::ostream& stream) const override { }
		void deSerialize(std::istream& stream) override { }

		std::any getValue() const { return value; }
		std::string getKey() const { return ((Tag*) this)->getKey(); }
	private:
		std::any value;
	};
}
