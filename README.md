# Corewar_Release

_**Core War**_ is a Programming game created by D. G. Jones and [A. K. Dewdney](https://en.wikipedia.org/wiki/A._K._Dewdney "A. K. Dewdney") in which two or more battle programs (called "warriors") compete for control of a [virtual computer](https://en.wikipedia.org/wiki/Virtual_machine "Virtual machine"). These battle programs are written in an abstract [assembly language](https://en.wikipedia.org/wiki/Assembly_language "Assembly language") called _Redcode_.

# Redcode Compilator
The asm compiler allows us to compile the assembler code (RedCode) into machine code (bytecode) that will be interpreted by the virtual machine

**Usage**:
***./asm path_to_file.s***
**-output:** *path_to_file.cor*

# Virtual Machine
The programs are loaded in the same memory buffer (4096 Octets) in order to space their entry points (max 4 players). The virtual machine will create a dedicated memory space for players to fight, then load the champions and their associated processes, and execute them sequentially.

After CYCLE_TO_DIE cycles, the VM must make sure every process has performed at least one live instruction since the last check. A process that does not subject to this rule will be put to death. When there is no more process alive, the game is over. The winner is the last player reported to be alive.

**Usage:**
*./corewar [-dump N -n N -verbose...] <chp.cor> <...>* <br>
         ***-dump N :*** Dumps memory after N cycles then exit. <br>
         ***-verbose:*** Display execution log and cycles.<br>
         ***-n N:*** Fix next champion number (N).
         ***-render:*** Display graphic render.

**Render Usage:**
	     ***ESC:*** Exit render after game end.
	     ***SPACE:*** Run game.
	     ***P:*** Pause game.
	     
![enter image description here](https://github.com/bait-sli/Corewar_Release/blob/master/render.gif?raw=true)
