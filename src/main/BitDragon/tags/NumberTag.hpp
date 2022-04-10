#pragma once
#include "Tag.hpp"
#include "TagSizeable.hpp"
#include <any>

namespace bd {
	//template<typename  T>
	class NumberTag: public Tag, public TagSizeable {
	public:
		NumberTag(std::string key, std::any value, bool floating, uint16 size): Tag(key, BD_TAG_ID_NUMBER), TagSizeable(size), value(value), floating(floating) {
		}

		void serialize(std::ostream& stream) const override { }
		void deSerialize(std::istream& stream) override { }

		std::any getValue() const { return value; }
		std::string getKey() const { return ((Tag*) this)->getKey(); }
		bool isFloating() const { return floating; }
	private:
		std::any value;
		bool floating;
	};
}
