#pragma once
#include "../Defines.hpp"

namespace bd {
	/// <summary>
	/// Used to store numbers into your binary file (size is always in bytes)
	/// </summary>
	class TagSizeable {
	public:
		TagSizeable(uint16 size, bool floating): size(size), floating(floating) { }

		/// <summary>
		/// Gets the size of this tag
		/// </summary>
		/// <returns>The size in bytes</returns>
		uint16 getSize() const { return size; }
		bool isFloating() const { return floating; }

	private:
		bool floating;
		uint16 size;
	};
}
