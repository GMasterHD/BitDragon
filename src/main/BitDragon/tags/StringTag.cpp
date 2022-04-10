#include "StringTag.hpp"

namespace bd {
	void StringTag::serialize(std::ostream& stream) const {
	}
	void StringTag::deSerialize(std::istream & stream) {
	}

	std::string StringTag::getValue() const {
		return value;
	}
}
