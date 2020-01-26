#install nasm
if hash nasm 2>/dev/null; then
	echo "NASM already present"
else
	apt-get install -y nasm
fi

#install figlet
if hash figlet 2>/dev/null; then
	echo "figlet already present"
else
	apt-get install -y figlet
fi

#install qemu
if hash qemu-system-i386 2>/dev/null; then
	echo "QEMU already present"
else
	apt-get install -y qemu
fi

#install gdb
if hash gdb 2>/dev/null; then
	echo "gdb already present"
else
	apt-get install -y gdb
fi

#this will install all needed dependancies to
#build Clang from source
if type ./clang/build/bin/clang++ 2>/dev/null; then
	echo "Toolchain already present"
else
	echo "Building Clang++ toolchain"

	if hash git 2>/dev/null; then
		echo "git installed"
	else
		echo "need to install git"
		apt-get install -y git
	fi

	if hash cmake 2>/dev/null; then
		echo "cmake installed"
	else
		echo "need to install cmake"
		apt-get install -y cmake
	fi

	if hash gcc 2>/dev/null; then
		echo "gcc installed"
	else
		echo "need to install gcc"
		apt-get install -y gcc
	fi

	if hash gcc 2>/dev/null; then
		echo "g++ installed"
	else
		echo "need to install g++"
		apt-get install -y g++
	fi

	if hash make 2>/dev/null; then
		echo "make installed"
	else 
		echo "need to install make"
		apt-get install make
	fi

	#build clang
	mkdir clang
	cd clang
	git clone http://llvm.org/git/llvm.git
	cd llvm/tools
	git clone http://llvm.org/gig/clang.git
	cd ../projects
	git clone http://llvm.org/git/compiler-rt.git
	cd ../..
	mkdir build
	cd build
	cmake -DCMAKE_BUILD_TYPE:STRING=Release ../llvm/
	make
fi

