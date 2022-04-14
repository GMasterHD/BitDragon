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
		/// <summary>
		/// Serializes a compound to a stream
		/// </summary>
		/// <param name="tag">The compound</param>
		/// <param name="stream">The ostream</param>
		static void serialize(const CompoundTag& tag, std::ostream& stream);
		/// <summary>
		/// Deserializes a compound from a stream
		/// </summary>
		/// <param name="tag">The compound to save to</param>
		/// <param name="stream">The istream</param>
		static void deserialize(CompoundTag& tag, std::istream& stream);
	private:
	};
}
