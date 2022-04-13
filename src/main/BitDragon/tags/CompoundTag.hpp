#pragma once
#include "Tag.hpp"
#include <unordered_map>
#include "ArrayTag.hpp"
#include <stack>

namespace bd {
	class CompoundTag: public Tag {
	public:
		CompoundTag(): Tag("", BD_TAG_ID_COMPOUND) {
		}

		void add(Tag& tag);
		Tag* get(std::string key) const;

		void setUint8(std::string key, uint8 value);
		void setUint16(std::string key,	uint16 value);
		void setUint32(std::string key,	uint32 value);
		void setUint64(std::string key,	uint64 value);
		void setFloat(std::string key, float value);
		void setDouble(std::string key, double value);
		void setBool(std::string key, bool value);

		void setString(std::string key, std::string value);
		CompoundTag* createCompound(std::string key);

		ArrayTag<uint8>* createUint8Array(std::string key);
		ArrayTag<uint16>* createUint16Array(std::string key);
		ArrayTag<uint32>* createUint32Array(std::string key);
		ArrayTag<uint64>* createUint64Array(std::string key);
		ArrayTag<float>* createFloatArray(std::string key);
		ArrayTag<double>* createDoubleArray(std::string key);

		uint8 getUint8(std::string key) const;
		uint16 getUint16(std::string key) const;
		uint32 getUint32(std::string key) const;
		uint64 getUint64(std::string key) const;
		float getFloat(std::string key) const;
		double getDouble(std::string key) const;
		bool getBool(std::string key) const;

		std::string getString(std::string key) const;
		CompoundTag& getCompound(std::string key) const;

		ArrayTag<uint8>& getUint8Array(std::string key);
		ArrayTag<uint16>& getUint16Array(std::string key);
		ArrayTag<uint32>& getUint32Array(std::string key);
		ArrayTag<uint64>& getUint64Array(std::string key);
		ArrayTag<float>& getFloatArray(std::string key);
		ArrayTag<double>& getDoubleArray(std::string key);

		Tag* operator[](std::string key) {
			return get(key);
		}

		void keys(std::function<void(std::string)> f);
		void keysDeep(std::function<void(std::string)> f);

		std::vector<std::string> keys() const {
			std::vector<std::string> out;
			for(auto it = tags.begin(); it != tags.end(); ++it) {
				out.push_back(it->first);
			}
			return out;
		}

		void serialize(std::ostream& stream) const override;
		void deserialize(std::istream& stream) override;

		/// <summary>
		/// Outputs the human readable version of this tag to a out stream
		/// </summary>
		/// <param name="stream">The out stream</param>
		/// <param name="tabs">If tabs should be used instead of spaces</param>
		/// <param name="spaceSize">If no tabs are used, the number of spaces to indent</param>
		void stringify(std::ostream& stream, bool tabs = false) const {
			stringify(stream, tabs, "");
		}

		void stringify(std::ostream& stream, bool tabs, std::string currentIndention) const;

	private:
		std::string readKeyName(std::istream& stream);
		std::unordered_map<std::string, Tag*> tags;

		void keysDeep(std::string key, std::function<void(std::string)> f);
		static void keyFromStack(std::stack<std::string>& stack, std::stringstream& ss);

		template<typename T>
		void readArray(std::istream& stream, uint16 size, bool floating, std::string key, uint16 length) {
			switch(size) {
				case 1: {
					ArrayTag<uint8>* arr = createUint8Array(key);
					for(uint16 i = 0; i < length; ++i) {
						T num;
						stream.read((char*) &num, sizeof(T));
						arr->add(num);
					}

					break;
				}
				case 2: {
					ArrayTag<uint16>* arr = createUint16Array(key);
					for(uint16 i = 0; i < length; ++i) {
						T num;
						stream.read((char*) &num, sizeof(T));
						arr->add(num);
					}

					break;
				}
				case 4: {
					if(floating) {
						ArrayTag<float>* arr = createFloatArray(key);
						for(uint16 i = 0; i < length; ++i) {
							T num;
							stream.read((char*) &num, sizeof(T));
							arr->add(num);
						}
					} else {
						ArrayTag<uint32>* arr = createUint32Array(key);
						for(uint16 i = 0; i < length; ++i) {
							T num;
							stream.read((char*) &num, sizeof(T));
							arr->add(num);
						}
					}
					break;
				}
				case 8: {
					if(floating) {
						ArrayTag<double>* arr = createDoubleArray(key);
						for(uint16 i = 0; i < length; ++i) {
							T num;
							stream.read((char*) &num, sizeof(T));
							arr->add(num);
						}
					} else {
						ArrayTag<uint64>* arr = createUint64Array(key);
						for(uint16 i = 0; i < length; ++i) {
							T num;
							stream.read((char*) &num, sizeof(T));
							arr->add(num);
						}
					}
					break;
				}
			}
		}
	};
}
