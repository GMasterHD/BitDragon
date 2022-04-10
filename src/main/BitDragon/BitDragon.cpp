#include "BitDragon.hpp"
#include <fstream>
#include <iostream>

namespace bd {
	void BitDragon::serialize(const CompoundTag& ctag, std::string path) {
		std::ofstream stream(path, std::ios::binary | std::ios::out);
		ctag.serialize(stream);
	}
	void BitDragon::deSerialize(CompoundTag& tag) {
	}
}
