#!/bin/bash

#what version of llvm?
llvm_version=6.x

echo "This script will attempt to install all the needed tools for building and running TwilightOS"
echo "The following programs are required:"
echo "   nasm"
echo "   figlet"
echo "   qemu"
echo "   gdb"
echo "   gcc"
echo "   g++"
echo "   git"
echo "   cmake"
echo "   make"
echo "   clang" 
read -n 1 -p "Do you want to continue? [y/N]: " prompt
#if [[ $prompt = "y" || $prompt = "Y" ]]
if [[ $prompt =~ [yY](es)* ]]
then
	echo "Let's begin!"
else
	exit 0
fi


#install nasm
if type nasm 2>/dev/null; then
	echo "NASM already present"
else
	apt-get install -y nasm
fi

#install figlet
if type figlet 2>/dev/null; then
	echo "figlet already present"
else
	apt-get install -y figlet
fi

#install qemu
if type qemu-system-i386 2>/dev/null; then
	echo "QEMU already present"
else
	apt-get install -y qemu
fi

#install gdb
if type gdb 2>/dev/null; then
	echo "gdb already present"
else
	apt-get install -y gdb
fi

#this will install all needed dependancies to
#build Clang from source
if type clang++ 2>/dev/null; then
	echo "Toolchain already present"
else
	#apt-get install -y clang
	echo "skip"

	if type clang++ 2>/dev/null; then
		exit 1;
	else
		echo "Building Clang++ toolchain"

		if type git 2>/dev/null; then
			echo "git installed"
		else
			echo "need to install git"
			apt-get install -y git
		fi

		if type cmake 2>/dev/null; then
			echo "cmake installed"
		else
			echo "need to install cmake"
			apt-get install -y cmake
		fi

		if type gcc 2>/dev/null; then
			echo "gcc installed"
		else
			echo "need to install gcc"
			apt-get install -y gcc
		fi

		if type g++ 2>/dev/null; then
			echo "g++ installed"
		else
			echo "need to install g++"
			apt-get install -y g++
		fi

		if type make 2>/dev/null; then
			echo "make installed"
		else 
			echo "need to install make"
			apt-get install make
		fi

		#build clang
		mkdir clang
		cd clang
		#git clone http://llvm.org/git/llvm.git
		git clone http://github.com/llvm/llvm-project.git
		cd llvm-project
		git checkout remotes/origin/release/$llvm_version
		#git clone http://llvm.org/git/clang.git
		#cd ../projects
		#git clone http://llvm.org/git/compiler-rt.git
		#cd ../..
		mkdir build
		cd build
		cc_path=$(which gcc)
		cxx_path=$(which g++)
		export CC=$cc_path
		export CXX=$cxx_path
		cmake -DCMAKE_BUILD_TYPE:STRING=Release ../llvm/
		make
		make install
	fi
fi

