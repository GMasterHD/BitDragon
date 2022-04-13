#include "BitDragon.hpp"
#include <fstream>
#include <iostream>

namespace bd {
	void BitDragon::serialize(const CompoundTag& tag, std::ostream& stream) {
		tag.serialize(stream);
	}
	void BitDragon::deserialize(CompoundTag& tag, std::istream& stream) {
		uint8 type;
		// Used to skip the first currently unused start tag
		stream.read((char*) &type, sizeof(uint8));

		tag.deserialize(stream);
	}
}
