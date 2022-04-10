#pragma once
#include <ostream>
#include <istream>

#include "../Defines.hpp"

namespace bd {
	class Tag {
	public:
		Tag(std::string key, uint8 id): key(key), id(id) { }
		Tag(): key("") { }

		virtual void serialize(std::ostream& stream) const = 0;
		virtual void deSerialize(std::istream& stream) = 0;

		std::string getKey() const { return key; }
		uint8 getID() const { return id; }

	protected:
		std::string key;
		uint8 id;
	};
}
