#pragma once
#include "tags/Tag.hpp"
#include "tags/NumberTag.hpp"
#include "tags/CompoundTag.hpp"

namespace bd {
	class BitDragon {
	public:
		static void serialize(const CompoundTag& tag, std::string path);
		static void deSerialize(CompoundTag& tag);

	private:
	};
}
