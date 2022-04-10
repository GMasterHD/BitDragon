#include <iostream>
#include "BitDragon/Defines.hpp"
#include "BitDragon/BitDragon.hpp"

int main(int argc, char** argv) {
	bd::CompoundTag tag;
	tag.setUint16("int", 154);
	tag.setString("string", "String");
	tag.setString("cstring", "CString");
	tag.setFloat("float", 95.732);

	bd::CompoundTag* inner = tag.createCompound("inner");
	inner->setString("tag", "This is inner Tag!");

	bd::BitDragon::serialize(tag, "./test.dat");
	std::cout << tag.stringify() << std::endl;
}
