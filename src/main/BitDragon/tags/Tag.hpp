#pragma once
#include <ostream>
#include <istream>

#include "../Defines.hpp"

namespace bd {
	class Tag {
	public:
		Tag(std::string key, uint8 id): key(key), id(id) { }
		Tag(): key("") { }

		std::string getKey() const { return key; }
		uint8 getID() const { return id; }

		virtual void serialize(std::ostream& stream) const { }
		virtual void deserialize(std::istream& stream) { }

	protected:
		std::string key;
		uint8 id;
	};
}
