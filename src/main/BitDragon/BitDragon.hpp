#pragma once
#include "tags/ArrayTag.hpp"
#include "tags/CompoundTag.hpp"
#include "tags/NumberTag.hpp"
#include "tags/StringTag.hpp"
#include "tags/Tag.hpp"
#include "tags/TagSizeable.hpp"

namespace bd {
	class BitDragon {
	public:
		static void serialize(const CompoundTag& tag, std::string path);
		static void deserialize(CompoundTag& tag, std::string path);

	private:
	};
}
