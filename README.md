
# Command & Conquer Red Alert

This repository includes source code for Command & Conquer Red Alert. This release provides support to the [Steam Workshop](https://steamcommunity.com/workshop/browse/?appid=2229840) for the game.


## Dependencies

If you wish to rebuild the source code and tools successfully you will need to find or write new replacements (or remove the code using them entirely) for the following libraries;

- DirectX 5 SDK
- DirectX Media 5.1 SDK
- Greenleaf Communications Library (GCL)
- Human Machine Interface (HMI) “Sound Operating System” (SOS)


## Compiling

The current state of the source code does not fully compile and will require some effort to restore it. If you wish to restore the original build environment, the following tools are required;

- OpenWatcom C/C++ (v2.0) for C/C++ source files
- Borland Turbo Assembler (TASM v4.0) for assembly files

Specifically the following files from Turbo Assembler are needed:

```
	DPMI16BI.OVL
	DPMILOAD.EXE
	RTM.EXE		
	TASM32.EXE	
	TLINK.EXE	
	TLINK32.EXE
	DPMI32VM.OVL
	DPMIMEM.DLL
	TASM.EXE
	TDSTRIP.EXE
```

WARNING: 


An environment to build is currently provided which works in dosbox-x. To build, place openwatcom in `watcom`, and `tasm.exe` in the bin folder, then:

```
	./launch.sh
	[inside dosbox]
	env.bat
	cd wwflat32
	prepare.bat
	wmake
	cd ..\vq
	env.bat
	cd vqa32
	wmake
	cd ..\vqm32
	wmake
	cd ..\..\code
	wmake
```

For the windows build, the following should suffice:

```
	./launch.sh
	[inside dosbox]
	env.bat
	cd win32lib
	prepare.bat
	wmake WIN32=1
	cd ..\code
	wmake WIN32=1
```

You also need to build the "EBN.EXE" tool to build the .IBN files which can be done as follows:

```
	./launch.sh
	[inside dosbox]
	env.bat
	cd extras
	make.bat
```

Please note that to keep things simple, the current focus of this repository it to build the DOS version in the current version of OpenWatcom, which requires a few changes as the modern compiler is slightly more strict in places. Also the codebase seems to require a lot of manual tweaking to get the correct build state (such as the CD DOS version not building with the expansion pack changes).

To use the compiled binaries, you must own the game. The C&C Ultimate Collection is available for purchase on [EA App](https://www.ea.com/en-gb/games/command-and-conquer/command-and-conquer-the-ultimate-collection/buy/pc) or [Steam](https://store.steampowered.com/bundle/39394/Command__Conquer_The_Ultimate_Collection/).


## Contributing

This repository will not be accepting contributions (pull requests, issues, etc). If you wish to create changes to the source code and encourage collaboration, please create a fork of the repository under your GitHub user/organization space.


## Support

This repository is for preservation purposes only and is archived without support. 


## License

This repository and its contents are licensed under the GPL v3 license, with additional terms applied. Please see [LICENSE.md](LICENSE.md) for details.
