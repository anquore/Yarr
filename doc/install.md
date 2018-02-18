# Hardware Setup and Software Installation

In order to setuo the DAQ system the following two steps are needed:
    1. Install the YARR SW package
    2. Prepare and setup the DAQ hardware

## Software installation
    
### Dependencies

    - Make sure you have GCC version 4.8 or higher installed:

    .. code-block:: none
        :linenos:

        $ g++ --version
        g++ (GCC) 4.8.3 20140911 (Red Hat 4.8.3-9)
        Copyright (C) 2013 Free Software Foundation, Inc.
        This is free software; see the source for copying conditions.  There is NO
        warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    - If not a specifc version can also be sourced from AFS (CERN AFS access necessary):

    .. code-block:: none
        :linenos:

        $ source /afs/cern.ch/sw/lcg/contrib/gcc/4.8/x86_64-slc6/setup.sh

    - If not installed before, you need some standard packages:

    .. code-block:: none
        :linenos:

        $ sudo yum install gnuplot texlive-epstopdf cmake

### Initialise repository
    
    - Clone the repository to your local machine:
    
    .. code-block:: none
        :linenos:

        $ git clone https://github.com/Yarr/Yarr.git Yarr

    or

    .. code-block:: none
        :linenos:

        $ git clone https://gitlab.cern.ch/Yarr/Yarr.git Yarr
 
    - The master branch should contain the latest stable release, the most up-to date version can be found in the devel branch
    - A version history and description can be found [here](version.md)

### Compile the software

    There are two ways to compile the software, either via a simple Makefile or via cmake. Pick your poison.
    If in doubt, use the simple Makefile method.
        
#### Compile software with Makefile

    - Compile the software:

    .. code-block:: none
        :linenos:

        $ cd Yarr/src
        $ make -j4
        <Lots of text>

#### Compile software with cmake

    - Generate makefile

    .. code-block:: none
        :linenos:

        $ cd Yarr/src
        $ mkdir build
        $ cd build
        $ cmake ../
        <Some text>

    - Expert note: you can choose a specific toolchain via:
    
    .. code-block:: none
        :linenos:

        $ cmake ..  -DCMAKE_TOOLCHAIN_FILE=../cmake/linux-clang # requires clang installed on Linux
        $ cmake ..  -DCMAKE_TOOLCHAIN_FILE=../cmake/linux-gcc # gcc 4.8 or higher
        $ cmake ..  -DCMAKE_TOOLCHAIN_FILE=../cmake/rce-gcc # ARM/Archlinux on RCE
        $ cmake ..  -DCMAKE_TOOLCHAIN_FILE=../cmake/macos-clang # MacOS build

    - Compile the software
    
    .. code-block:: none
        :linenos:

        $ make -j4
        <Lots of text>


## Setting up your hardware

Hardware setup depends on the hardware platform, check list below for installation guides:
    - [PCIe cards](pcie.md) (e.g. XpressK7, KC705, Trenz TEF1001, SPEC, ...)
    - more to come

