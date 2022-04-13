#include "CompoundTag.hpp"
#include "NumberTag.hpp"
#include "StringTag.hpp"
#include <iostream>
#include <sstream>

namespace bd {
	void CompoundTag::add(Tag& tag) {
		tags[tag.getKey()] = &tag;
	}
	Tag* CompoundTag::get(std::string key) const {
		return tags.at(key);
	}

	void CompoundTag::setUint8(std::string key, uint8 value) {
		tags[key] = new NumberTag(key, value, false, (uint16) 1);
		tagTypes[key] = BD_TAG_TYPE_UINT8;
	}
	void CompoundTag::setUint16(std::string key, uint16 value) {
		tags[key] = new NumberTag(key, value, false, (uint16) 2);
		tagTypes[key] = BD_TAG_TYPE_UINT16;
	}
	void CompoundTag::setUint32(std::string key, uint32 value) {
		tags[key] = new NumberTag(key, value, false, (uint16) 4);
		tagTypes[key] = BD_TAG_TYPE_UINT32;
	}
	void CompoundTag::setUint64(std::string key, uint64 value) {
		tags[key] = new NumberTag(key, value, false, (uint16) 8);
		tagTypes[key] = BD_TAG_TYPE_UINT64;
	}
	void CompoundTag::setFloat(std::string key, float value) {
		tags[key] = new NumberTag(key, value, true, (uint16) 4);
		tagTypes[key] = BD_TAG_TYPE_FLOAT;
	}
	void CompoundTag::setDouble(std::string key, double value) {
		tags[key] = new NumberTag(key, value, true, (uint16) 8);
		tagTypes[key] = BD_TAG_TYPE_DOUBLE;
	}
	void CompoundTag::setBool(std::string key, bool value) {
		tags[key] = new NumberTag(key, value ? 1 : 0, false, (uint16) 1);
		tagTypes[key] = BD_TAG_TYPE_BOOL;
	}
	void CompoundTag::setString(std::string key, std::string value) {
		tags[key] = new StringTag(key, value);
		tagTypes[key] = BD_TAG_TYPE_STRING;
	}
	CompoundTag* CompoundTag::createCompound(std::string key) {
		tags.insert(std::pair<std::string, Tag*>(key, (Tag*) new CompoundTag()));
		tagTypes[key] = BD_TAG_TYPE_COMPOUND;
		return (CompoundTag*) tags.at(key);
	}

	ArrayTag<uint8>* CompoundTag::createUint8Array(std::string key) {
		tags.insert(std::pair<std::string, Tag*>(key, (Tag*) new ArrayTag<uint8>(key, 1, false)));
		tagTypes[key] = BD_TAG_TYPE_ARRAY_UINT8;
		return (ArrayTag<uint8>*) tags.at(key);
	}
	ArrayTag<uint16>* CompoundTag::createUint16Array(std::string key) {
		tags.insert(std::pair<std::string, Tag*>(key, (Tag*) new ArrayTag<uint16>(key, 2, false)));
		tagTypes[key] = BD_TAG_TYPE_ARRAY_UINT16;
		return (ArrayTag<uint16>*) tags.at(key);
	}
	ArrayTag<uint32>* CompoundTag::createUint32Array(std::string key) {
		tags.insert(std::pair<std::string, Tag*>(key, (Tag*) new ArrayTag<uint32>(key, 4, false)));
		tagTypes[key] = BD_TAG_TYPE_ARRAY_UINT32;
		return (ArrayTag<uint32>*) tags.at(key);
	}
	ArrayTag<uint64>* CompoundTag::createUint64Array(std::string key) {
		tags.insert(std::pair<std::string, Tag*>(key, (Tag*) new ArrayTag<uint64>(key, 8, false)));
		tagTypes[key] = BD_TAG_TYPE_ARRAY_UINT64;
		return (ArrayTag<uint64>*) tags.at(key);
	}
	ArrayTag<float>* CompoundTag::createFloatArray(std::string key) {
		tags.insert(std::pair<std::string, Tag*>(key, (Tag*) new ArrayTag<float>(key, 4, true)));
		tagTypes[key] = BD_TAG_TYPE_ARRAY_FLOAT;
		return (ArrayTag<float>*) tags.at(key);
	}
	ArrayTag<double>* CompoundTag::createDoubleArray(std::string key) {
		tags.insert(std::pair<std::string, Tag*>(key, (Tag*) new ArrayTag<double>(key, 8, true)));
		tagTypes[key] = BD_TAG_TYPE_ARRAY_DOUBLE;
		return (ArrayTag<double>*) tags.at(key);
	}

	uint8 CompoundTag::getUint8(std::string key) const {
		NumberTag* tag = (NumberTag*) tags.at(key);
		return std::any_cast<uint8>(tag->getValue());
	}
	uint16 CompoundTag::getUint16(std::string key) const {
		NumberTag* tag = (NumberTag*) tags.at(key);
		return std::any_cast<uint16>(tag->getValue());
	}
	uint32 CompoundTag::getUint32(std::string key) const {
		NumberTag* tag = (NumberTag*) tags.at(key);
		return std::any_cast<uint32>(tag->getValue());
	}
	uint64 CompoundTag::getUint64(std::string key) const {
		NumberTag* tag = (NumberTag*) tags.at(key);
		return std::any_cast<uint64>(tag->getValue());
	}
	float CompoundTag::getFloat(std::string key) const {
		NumberTag* tag = (NumberTag*) tags.at(key);
		return std::any_cast<float>(tag->getValue());
	}
	double CompoundTag::getDouble(std::string key) const {
		NumberTag* tag = (NumberTag*) tags.at(key);
		return std::any_cast<double>(tag->getValue());
	}
	bool CompoundTag::getBool(std::string key) const {
		NumberTag* tag = (NumberTag*) tags.at(key);
		return std::any_cast<uint8>(tag->getValue()) == 1;
	}
	std::string CompoundTag::getString(std::string key) const {
		return ((StringTag*) tags.at(key))->getValue();
	}
	CompoundTag& CompoundTag::getCompound(std::string key) const {
		return *(((CompoundTag*) tags.at(key)));
	}

	ArrayTag<uint8>& CompoundTag::getUint8Array(std::string key) {
		return *((ArrayTag<uint8>*) tags.at(key));
	}
	ArrayTag<uint16>& CompoundTag::getUint16Array(std::string key) {
		return *((ArrayTag<uint16>*) tags.at(key));
	}
	ArrayTag<uint32>& CompoundTag::getUint32Array(std::string key) {
		return *((ArrayTag<uint32>*) tags.at(key));
	}
	ArrayTag<uint64>& CompoundTag::getUint64Array(std::string key) {
		return *((ArrayTag<uint64>*) tags.at(key));
	}
	ArrayTag<float>& CompoundTag::getFloatArray(std::string key) {
		return *((ArrayTag<float>*) tags.at(key));
	}
	ArrayTag<double>& CompoundTag::getDoubleArray(std::string key) {
		return *((ArrayTag<double>*) tags.at(key));
	}

	bool CompoundTag::isDefined(std::string key) {
		return tagTypes.find(key) != tagTypes.end();
	}
	bool CompoundTag::isNumber(std::string key) {
		if(!isDefined(key)) return false;
		switch(tagTypes.at(key)) {
			case BD_TAG_TYPE_UINT8: case BD_TAG_TYPE_UINT16: case BD_TAG_TYPE_UINT32: case BD_TAG_TYPE_UINT64: case BD_TAG_TYPE_FLOAT: case BD_TAG_TYPE_DOUBLE:
				return true;
		}
		return false;
	}
	bool CompoundTag::isUint8(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_UINT8;
	}
	bool CompoundTag::isUint16(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_UINT16;
	}
	bool CompoundTag::isUint32(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_UINT32;
	}
	bool CompoundTag::isUint64(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_UINT64;
	}
	bool CompoundTag::isFloat(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_FLOAT;
	}
	bool CompoundTag::isDouble(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_DOUBLE;
	}
	bool CompoundTag::isArray(std::string key) {
		if(!isDefined(key)) return false;
		switch(tagTypes.at(key)) {
			case BD_TAG_TYPE_ARRAY_UINT8: case BD_TAG_TYPE_ARRAY_UINT16: case BD_TAG_TYPE_ARRAY_UINT32: case BD_TAG_TYPE_ARRAY_UINT64: case BD_TAG_TYPE_ARRAY_FLOAT: case BD_TAG_TYPE_ARRAY_DOUBLE:
				return true;
		}
		return false;
	}
	bool CompoundTag::isUint8Array(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_ARRAY_UINT8;
	}
	bool CompoundTag::isUint16Array(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_ARRAY_UINT16;
	}
	bool CompoundTag::isUint32Array(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_ARRAY_UINT32;
	}
	bool CompoundTag::isUint64Array(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_ARRAY_UINT64;
	}
	bool CompoundTag::isFloatArray(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_ARRAY_FLOAT;
	}
	bool CompoundTag::isDoubleArray(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_ARRAY_DOUBLE;
	}
	bool CompoundTag::isString(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_STRING;
	}
	bool CompoundTag::isCompound(std::string key) {
		if(!isDefined(key)) return false;
		return tagTypes.at(key) == BD_TAG_TYPE_COMPOUND;
	}

	void CompoundTag::keys(std::function<void(std::string)> f) {
		for(auto it = tags.begin(); it != tags.end(); ++it) {
			f(it->first);
		}
	}
	void CompoundTag::keysDeep(std::function<void(std::string)> f) {
		keysDeep("", f);
	}
	void CompoundTag::keysDeep(std::string key, std::function<void(std::string)> f) {
		std::stack<std::string> keys;
		for(auto it = tags.begin(); it != tags.end(); ++it) {
			keys.push(it->first);

			switch(it->second->getID()) {
				case BD_TAG_ID_ARRAY: case BD_TAG_ID_ARRAY_FLOAT: {
					switch(dynamic_cast<TagSizeable*>(it->second)->getSize()) {
						case 1: {
							for(uint16 i = 0; i < ((ArrayTag<uint8>*) it->second)->length(); ++i) {
								std::stringstream ss;
								keyFromStack(keys, ss);
								ss << "." << i;
								f(ss.str());
							}
							break;
						}
						case 2: {
							for(uint16 i = 0; i < ((ArrayTag<uint16>*) it->second)->length(); ++i) {
								std::stringstream ss;
								keyFromStack(keys, ss);
								ss << "." << i;
								f(ss.str());
							}
							break;
						}
						case 4: {
							for(uint16 i = 0; i < ((ArrayTag<uint32>*) it->second)->length(); ++i) {
								std::stringstream ss;
								keyFromStack(keys, ss);
								ss << "." << i;
								f(ss.str());
							}
							break;
						}
						case 8: {
							for(uint16 i = 0; i < ((ArrayTag<uint64>*) it->second)->length(); ++i) {
								std::stringstream ss;
								keyFromStack(keys, ss);
								ss << "." << i;
								f(ss.str());
							}
							break;
						}
					}

					break;
				}
				case BD_TAG_ID_COMPOUND: {
					((CompoundTag*) it->second)->keysDeep(key, f);
					break;
				}
				default: {
					std::stringstream ss;
					keyFromStack(keys, ss);
					f(ss.str());
				}
			}

			keys.pop();
		}
	}
	void CompoundTag::keyFromStack(std::stack<std::string>& stack, std::stringstream& ss) {
		if(stack.empty()) return;
		std::string s = stack.top();
		stack.pop();
		keyFromStack(stack, ss);
		if(stack.size() < 2) ss << s;
		else ss << "." << s;
		stack.push(s);
	}

	void CompoundTag::serialize(std::ostream& stream) const {
		#ifdef _DEBUG
		std::cout << "Writing new compound Tag!" << std::endl;
		#endif

		uint8 startID = BD_TAG_ID_CTAG_START;
		uint8 endID = BD_TAG_ID_CTAG_END;
		uint8 null = 0;

		stream.write(reinterpret_cast<const char*>(&startID), sizeof(uint8));

		for(auto it = tags.begin(); it != tags.end(); ++it) {
			std::string key = it->first + ";";
			Tag* tag = it->second;
			uint8 tagID = tag->getID();

			stream.write(reinterpret_cast<const char*>(&tagID), sizeof(uint8));
			stream.write(key.c_str(), key.size());
			if(TagSizeable* tagS = dynamic_cast<TagSizeable*>(tag)) {
				uint16 size = tagS->getSize();
				bool floating = tagS->isFloating();
				stream.write(reinterpret_cast<const char*>(&size), sizeof(uint16));
				
				if(tag->getID() == BD_TAG_ID_NUMBER || tag->getID() == BD_TAG_ID_NUMBER_FLOAT) {
					NumberTag* tagN =  (NumberTag*) tag;
					std::any number = tagN->getValue();

					switch(size) {
						case 1: {
							uint8 num8 = std::any_cast<uint8>(number);
							stream.write(reinterpret_cast<const char*>(&num8), sizeof(uint8));
							break;
						}
						case 2: {
							uint16 num16 = std::any_cast<uint16>(number);
							stream.write(reinterpret_cast<const char*>(&num16), sizeof(uint16));
							break;
						}
						case 4: {
							if(floating) {
								float num32 = std::any_cast<float>(number);
								stream.write(reinterpret_cast<const char*>(&num32), sizeof(float));
							} else {
								uint32 num32 = std::any_cast<uint32>(number);
								stream.write(reinterpret_cast<const char*>(&num32), sizeof(uint32));
							}
							break;
						}
						case 8: {
							if(floating) {
								double num64 = std::any_cast<double>(number);
								stream.write(reinterpret_cast<const char*>(&num64), sizeof(double));
							} else {
								uint64 num64 = std::any_cast<double>(number);
								stream.write(reinterpret_cast<const char*>(&num64), sizeof(uint64));
							}
							break;
						}
					}
				} else if(tag->getID() == BD_TAG_ID_STRING) {
					std::string value = ((StringTag*) tag)->getValue();
					stream.write(value.c_str(), value.size());
				} else if(tag->getID() == BD_TAG_ID_ARRAY || tag->getID() == BD_TAG_ID_ARRAY_FLOAT) {
					switch(size) {
						case 1: {
							ArrayTag<uint8>* arr = ((ArrayTag<uint8>*) tag);
							arr->serialize(stream);
							break;
						}
						case 2: {
							ArrayTag<uint16>* arr = ((ArrayTag<uint16>*) tag);
							arr->serialize(stream);
							break;
						}
						case 4: {
							if(floating) {
								ArrayTag<float>* arr = ((ArrayTag<float>*) tag);
								arr->serialize(stream);
							} else {
								ArrayTag<uint32>* arr = ((ArrayTag<uint32>*) tag);
								arr->serialize(stream);
							}
							break;
						}
						case 8: {
							if(floating) {
								ArrayTag<double>* arr = ((ArrayTag<double>*) tag);
								arr->serialize(stream);
							} else {
								ArrayTag<uint64>* arr = ((ArrayTag<uint64>*) tag);
								arr->serialize(stream);
							}
							break;
						}
					}
				}
			}
			if(tag->getID() == BD_TAG_ID_COMPOUND) {
				((CompoundTag*) tag)->serialize(stream);
			}
		}

		stream.write(reinterpret_cast<const char*>(&endID), sizeof(uint8));
	}

	void CompoundTag::stringify(std::ostream& ss, bool tabs, std::string currentIndention) const {
		currentIndention += "\t";

		ss << "{";
		if(tabs) {
			ss << "\n" << currentIndention;
		}

		bool first = true;
		for(auto it = tags.begin(); it != tags.end(); ++it) {
			if(!first) {
				ss << ",";
				if(tabs) {
					ss << "\n" << currentIndention;
				}
			}

			std::string key = it->first;
			Tag* tag = it->second;
			uint8 tagID = tag->getID();


			ss << key;
			if(tabs) {
				ss << ": ";
			} else {
				ss << ":";
			}
			if(tagID == BD_TAG_ID_NUMBER || tagID == BD_TAG_ID_NUMBER_FLOAT) {
				NumberTag* tagN = dynamic_cast<NumberTag*>(tag);
				std::any num = tagN->getValue();
				bool floating = tagN->isFloating();
				uint16 size = dynamic_cast<TagSizeable*>(tag)->getSize();

				switch(size) {
					case 1: {
						uint8 num8 = std::any_cast<uint8>(num);
						ss << num8 << BD_TAG_DATA_TYPE_INT8;
						break;
					}
					case 2: {
						uint16 num16 = std::any_cast<uint16>(num);
						ss << num16 << BD_TAG_DATA_TYPE_INT16;
						break;
					}
					case 4: {
						if(floating) {
							float num32 = std::any_cast<float>(num);
							ss << num32 << BD_TAG_DATA_TYPE_FLOAT;
						} else {
							uint32 num32 = std::any_cast<uint32>(num);
							ss << num32 << BD_TAG_DATA_TYPE_INT32;
						}
						break;
					}
					case 8: {
						if(floating) {
							double num64 = std::any_cast<double>(num);
							ss << num64 << BD_TAG_DATA_TYPE_DOUBLE;
						} else {
							uint64 num64 = std::any_cast<uint64>(num);
							ss << num64 << BD_TAG_DATA_TYPE_INT64;
						}
						break;
					}
				}
			} else if(tagID == BD_TAG_ID_STRING) {
				ss << "\"" << ((StringTag*) tag)->getValue() << "\"";
			} else if(tagID == BD_TAG_ID_COMPOUND) {
				((CompoundTag*) tag)->stringify(ss, tabs, currentIndention);
			} else if(tagID == BD_TAG_ID_ARRAY || tagID == BD_TAG_ID_ARRAY_FLOAT) {
				TagSizeable* tagS = dynamic_cast<TagSizeable*>(tag);
				uint16 size = tagS->getSize();
				bool floating = tagS->isFloating();

				switch(size) {
					case 1: {
						((ArrayTag<uint8>*) tag)->stringify(ss, tabs, currentIndention);
						break;
					}
					case 2: {
						((ArrayTag<uint16>*) tag)->stringify(ss, tabs, currentIndention);
						break;
					}
					case 4: {
						if(floating) {
							((ArrayTag<float>*) tag)->stringify(ss, tabs, currentIndention);
						} else {
							((ArrayTag<uint32>*) tag)->stringify(ss, tabs, currentIndention);
						}
						break;
					}
					case 8: {
						if(floating) {
							((ArrayTag<double>*) tag)->stringify(ss, tabs, currentIndention);
						} else {
							((ArrayTag<uint64>*) tag)->stringify(ss, tabs, currentIndention);
						}
						break;
					}
				}
			}

			first = false;
		}
		currentIndention = currentIndention.substr(0, currentIndention.size() - 1);

		if(tabs) {
			ss << "\n" << currentIndention;
		}

		ss << "}";
	}

	void CompoundTag::deserialize(std::istream& stream) {
		while(true) {
			uint8 id;
			stream.read((char*) &id, sizeof(uint8));

			if(id == BD_TAG_ID_COMPOUND) {
				std::string key = readKeyName(stream);
				#ifdef _DEBUG
				std::cout << "Starting new compound with key '" << key << "'" << std::endl;
				#endif
				CompoundTag* inner = createCompound(key);
				inner->deserialize(stream);
			} else if(id == BD_TAG_ID_CTAG_END) {
				return;
			} else if(id == BD_TAG_ID_NUMBER || id == BD_TAG_ID_NUMBER_FLOAT) {
				bool floating = id == BD_TAG_ID_NUMBER_FLOAT;
				std::string key = readKeyName(stream);
				uint16 size;
				stream.read((char*) &size, sizeof(uint16));
				#ifdef _DEBUG
				std::cout << "Reading key '" << key << "' (Size: " << size << " Floating: " << floating << ")" << std::endl;
				#endif
				
				switch(size) {
					case 1: {
						uint8 num;
						stream.read((char*) &num, sizeof(uint8));
						setUint8(key, num);
						break;
					}
					case 2: {
						uint16 num;
						stream.read((char*) &num, sizeof(uint16));
						setUint16(key, num);
						break;
					}
					case 4: {
						if(floating) {
							float num;
							stream.read((char*) &num, sizeof(float));
							setFloat(key, num);
						} else {
							uint32 num;
							stream.read((char*) &num, sizeof(uint32));
							setUint32(key, num);
						}
						break;
					}
					case 8: {
						if(floating) {
							double num;
							stream.read((char*) &num, sizeof(double));
							setDouble(key, num);
						} else {
							uint64 num;
							stream.read((char*) &num, sizeof(uint64));
							setUint64(key, num);
						}
						break;
					}
				}
			} else if(id == BD_TAG_ID_ARRAY || id == BD_TAG_ID_ARRAY_FLOAT) {
				bool floating = id == BD_TAG_ID_ARRAY_FLOAT;
				std::string key = readKeyName(stream);
				uint16 size;
				stream.read((char*) &size, sizeof(uint16));

				uint16 length;
				stream.read((char*) &length, sizeof(uint16));

				#ifdef _DEBUG
				std::cout << "Reading array '" << key << "' (Size: " << size << ", Length: " << length << ", Floatings: " << floating << ")" << std::endl;
				#endif

				switch(size) {
					case 1: {
						readArray<uint8>(stream, size, floating, key, length); 
						break;
					}
					case 2: {
						readArray<uint16>(stream, size, floating, key, length);
						break;
					}
					case 4: {
						if(floating) {
							readArray<float>(stream, size, floating, key, length);
						} else {
							readArray<uint32>(stream, size, floating, key, length);
						}
						break;
					}
					case 8: {
						if(floating) {
							readArray<double>(stream, size, floating, key, length);
						} else {
							readArray<uint64>(stream, size, floating, key, length);
						}
						break;
					}
				}
			} else if(id == BD_TAG_ID_STRING) {
				std::string key = readKeyName(stream);
				uint16 size;
				stream.read((char*) &size, sizeof(uint16));

				std::stringstream ss_val;
				char c;
				for(uint16 i = 0; i < size; ++i) {
					stream.read(&c, sizeof(char));
					if(c == ';') break;
					ss_val << c;
				}

				setString(key, ss_val.str());
			}
		}
	}

	std::string CompoundTag::readKeyName(std::istream& stream) {
		std::stringstream ss_key;
		char c;
		while(true) {
			stream.read(&c, sizeof(char));
			if(c == ';') break;
			ss_key << c;
		}
		std::string key = ss_key.str();
		return key;
	}
}
