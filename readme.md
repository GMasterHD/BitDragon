# Bit Dragon 0.1
## Features
This library was written to serialize data from any C++ instance into a binary file.
This is done by a JSON/YML-Like way of saving attributes to tags and compounds.
A compound is an "Object" and the tags are it's values.
The file does not have a specifc format, but currently I am using **.bd**.

**Important** this library is not for everyone. If you are trying to save a gigantic amount of array data, do your own serialization.  
This library is only useful if your output file is under a megabyte.  
Additionaly if your serialization does not need to be key/value based, this won't be useful for you because you will lose a lot of data.

## How to use
### Serialize data to file
First, you need to create a compound tag and add your values to it
```C++
bd::CompoundTag tag;
tag.setUint32("value", 27);
```

You can also add a new compound into your existing compound by writing:
```C++
bd::CompoundTag* inner = tag.createCompound("inner");
inner->setString("tag", "This is inner Tag!");
```

> Important is that you declare your inner tag as a pointer, otherwise your data won't get applied

Now we want to add a array to our compound
```C++
bd::ArrayTag<uint32>* arr = tag.createUint32Array("arr");
arr->add(1);
arr->add(2);
arr->add(3);
```

> As of version 0.1, no string and compound arrrays are supported but they will get added in the future

The last step is to save our compound tag into a file
```C++
std::ofstream out("./test.bd", std::ios::binary | std::ios::out);
bd::BitDragon::serialize(tag, out);
out.close();
```

If we want to print our data to a human readable verison we can simply write
```C++
tag.stringify(std::out, true);
```

Instead of `std::out` you can add any out stream, also, for example a fout or a stringstream.  
If you don't want to add line breaks and spaces, you can enable teh compact version by replacing the `true` with a `false` or just remove it from the parameter list
```C++
std::stringstream stream;
tag.stringify(stream);
std::cout << stream.str() << std::endl;
```

### Deserialize data from file
Deserializing is as simple as by just defining compound tag and read to it
```C++
bd::CompoundTag tag;
std::ifstream in("./test.bd", std::ios::binary |std::ios::in);
bd::BitDragon::deserialize(tag, in);
in.close();
```

That's it, now you deserialized your data and you can retreive your tags the get functions
```C++
uint32_t value = tag.getUint32("value");
```

To get values from arrays or an entire tag, you can use the follwing statements
```C++
float value = tag.getCompound("inner").getFloatArray().get(0);
```

> Notice: if you want to read a signed integer instead of an unsigned one, just cast it to your desired integer size
> ```C++
> int32_t value = (int32) tag.getUint32("value");
> ```

## Parse values
Now that we can read values, we should also parse them and verify, that they are correct.

### Parse arrays
To parse arrays, you can use the foreach functions
```C++
deserialized.getUint32Array("arr").foreach([](uint32 value) {
	// your keys will be saved in value
});
```

You can also get the current index with the values
```C++
deserialized.getUint32Array("arr").foreach([](uint32 value, uint16 index) {
	// your keys will be saved in value
	// your index will be saved in index
});
```

### Parse compounds
Parsing compounds is a little bit harder because a compound can contain any ammount and any type of data

First, we want to get our keys in a compound
```C++
deserialized.keys([](std::string key) {
	// your keys will be stored in key
});
```

If you also want all the inner keys of your compound, you can simply use the `keysDeep` function
```C++
deserialized.keysDeep([](std::string key) {
	// your keys will be stored in key
});
```
Deep means, your key could look like this: `inner.arr.0`

Now we have our keys, but still don't know of what kind they are.  
To the type of our key, we can simply use the `is` functions
```C++
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
```
Now we know if our key is **defined**, it is a **number** and/or it is a **uint32**.

## Supress Logs
If you don't want debug logs, you can turn your Debug symbols off.  
In this case this would be the **Dist** Config, in the most cases it would be the **Release** Config.

## Installtion
You can install this library by cloning the source and add the required files to your project.  
If you are using Premake5 (recommended) you can just include the `premake5.lua` file
```Lua
include "./BitDragon/premake5.lua"
```

## Upcoming Features
* Compound Tags in Arrays
* String Tags in Arrays
* GZip compression and decompression
