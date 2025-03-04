
# Command & Conquer Red Alert

This repository includes source code for Command & Conquer Red Alert. This release provides support to the [Steam Workshop](https://steamcommunity.com/workshop/browse/?appid=2229840) for the game.

## Compiling

The following tools are required:

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


An environment to build is currently provided which works in dosbox-x. To build, first place openwatcom in `watcom`, and `tasm.exe` in the bin folder.

Firstly, you need to build the "EBN.EXE" tool to build the .IBN files which can be done as follows:

```
	./launch.sh
	[inside dosbox]
	env.bat
	cd extras
	make.bat
```

## Compiling - DOS version

Run the following commands:

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

Assuming compilation is successful, you should have a `GAME.EXE` in the `RUN` folder which is the main executable. `GAME.DAT` is also provided but currently this has not been tested with the launcher, so for now simply using `GAME.EXE` should suffice.

To play, simply put the executable in the game directory and launch!

## Compiling - Windows version

Run the the following commands:

```
	./launch.sh
	[inside dosbox]
	env.bat
	cd win32lib
	prepare.bat
	wmake WIN32=1
	cd ..\winvq
	env.bat
	cd vqa32
	wmake
	cd ..\vqm32
	wmake WIN32=1
	cd ..\code
	wmake WIN32=1
```

Assuming compilation is successful, you should have a `RA95.EXE` in the `RUN` folder.

To play, simply put the executable in the game directory and launch!


## Notes

Please note that to keep things simple, the current focus of this repository it to build the DOS version in the current version of OpenWatcom, which requires a few changes as the modern compiler is slightly more strict in places. Also the codebase seems to require a lot of manual tweaking to get the correct build state (such as the CD DOS version not building with the expansion pack changes).

To use the compiled binaries, you must own the game. The C&C Ultimate Collection is available for purchase on [EA App](https://www.ea.com/en-gb/games/command-and-conquer/command-and-conquer-the-ultimate-collection/buy/pc) or [Steam](https://store.steampowered.com/bundle/39394/Command__Conquer_The_Ultimate_Collection/).


## Contributing

Contributions are welcome, though the current focus is just to get the standard game executables building for a mostly vanilla experience.


## License

This repository and its contents are licensed under the GPL v3 license, with additional terms applied. Please see [LICENSE.md](LICENSE.md) for details.
