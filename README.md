# ofig - PHP config(php.ini) editor

A GUI application to easily edit the php.ini file for PHP installations.

## UNDER DEVELOPMENT


## Installing

### For Debian based systems:

```bash
git clone https://github.com/pushkar-anand/ofig.git
cd ofig
chmod +x build-setup-deb.sh # this will install all required dependencies
./build-setup-deb.sh
chmod +x pack-resources.sh
mkdir cmake-build-release
cd cmake-build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
make 
./ofig #start the app
```

### For others
This has yet not been tested in other versions yet.
To compile this you need cmake(version >= 3.13), gcc, g++, make and gtk3-dev libraries.