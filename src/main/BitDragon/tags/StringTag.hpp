#pragma once
#include "Tag.hpp"
#include "StringTag.hpp"
#include "TagSizeable.hpp"

namespace bd {
	class StringTag: public Tag, public TagSizeable {
	public:
		StringTag(std::string key, std::string value): Tag(key, BD_TAG_ID_STRING), TagSizeable(value.length(), false), value(value) {
		}

		void serialize(std::ostream& stream) const override;
		void deSerialize(std::istream& stream) override;

		std::string getValue() const;

	private:
		std::string value;
	};
}
