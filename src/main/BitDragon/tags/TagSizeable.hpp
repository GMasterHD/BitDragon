#pragma once
#include "../Defines.hpp"

namespace bd {
	/// <summary>
	/// Used to store numbers into your binary file (size is always in bytes)
	/// </summary>
	class TagSizeable {
	public:
		TagSizeable(uint16 size): size(size) { }

		uint16 getSize() const { return size; }

	private:
		uint16 size;
	};
}
