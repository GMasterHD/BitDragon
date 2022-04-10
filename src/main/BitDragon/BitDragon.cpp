#include "BitDragon.hpp"
#include <fstream>
#include <iostream>

namespace bd {
	void BitDragon::serialize(const CompoundTag& ctag, std::string path) {
		uint8 null = 0;
		uint32 sizeofUint16 = sizeof(uint16);
		uint32 sizeofNull = sizeof(null);

		std::ofstream stream(path, std::ios::binary | std::ios::out);
		ctag.serialize(stream);
	}
	void BitDragon::deSerialize(CompoundTag& tag) {
	}
}
