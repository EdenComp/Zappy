if [ "$EUID" -ne 0 ]
  then echo "Please run as root"
  exit
fi

echo "Installing OGRE for Fedora..."

# Install dependencies
dnf install -y mesa-libGL-devel glslang-devel SDL2-devel libXt-devel libXaw-devel doxygen pugixml-devel

# Download OGRE and unzip
mkdir -p ogre
cd ogre/
wget https://github.com/OGRECave/ogre/archive/v13.6.4.zip
unzip v13.6.4.zip
cd ogre-13.6.4/

# Install OGRE
cmake .
cmake --build . --config Release
make OgreDoc
cmake --build . --config Release --target install

# Remove temp files
cd ../../
rm -rf ogre/

echo "OGRE successfully installed!"
