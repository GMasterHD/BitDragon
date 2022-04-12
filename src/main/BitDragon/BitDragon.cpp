#include "BitDragon.hpp"
#include <fstream>
#include <iostream>

namespace bd {
	void BitDragon::serialize(const CompoundTag& tag, std::string path) {
		std::ofstream stream(path, std::ios::binary | std::ios::out);
		tag.serialize(stream);
	}
	void BitDragon::deserialize(CompoundTag& tag, std::string path) {
		std::ifstream stream(path, std::ios::binary | std::ios::in);

		uint8 type;
		stream.read((char*) &type, sizeof(uint8));

		tag.deserialize(stream);
	}
}
