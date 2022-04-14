#include <iostream>
#include <fstream>

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
	
	bd::ArrayTag<float>* values = inner->createFloatArray("values");
	values->add(95.732f);

	bd::ArrayTag<uint32>* arr = tag.createUint32Array("arr");
	arr->add(1);
	arr->add(2);
	arr->add(3);
	arr->add(95);

	std::ofstream ofs("./test.bd", std::ios::binary | std::ios::out);
	bd::BitDragon::serialize(tag, ofs);
	ofs.close();

	bd::CompoundTag deserialized;
	std::ifstream ifs("./test.bd", std::ios::binary | std::ios::in);
	bd::BitDragon::deserialize(deserialized, ifs);
	ifs.close();

	std::ofstream fstream("./test.txt", std::ios::out);
	deserialized.stringify(fstream, true);
	fstream.close();

	std::cout << "Array:";
	deserialized.getUint32Array("arr").foreach([](uint32 value) {
		std::cout << " " << value;
	});
	std::cout << std::endl;

	deserialized.keysDeep([](std::string key) {
		std::cout << key << std::endl;
	});

	if(deserialized.isDefined("int")) {
		std::cout << "Key int exists!" << std::endl;
	}
	if(deserialized.isNumber("int")) {
		std::cout << "Key int is a number!" << std::endl;
	}
	if(deserialized.isUint32("int")) {
		std::cout << "Key int is a int32!" << std::endl;
	} else {
		std::cout << "Key int is not a int32!" << std::endl;
	}

	std::cout << "0: " << deserialized.getUint32Array("arr")[0] << std::endl;
}
