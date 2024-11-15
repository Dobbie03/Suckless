//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/	 	/*Update Interval*/	/*Update Signal*/
    {"   ", "/opt/dwmblocks/scripts/kernel",		    360,		        2},

	{"    ", "/opt/dwmblocks/scripts/pacupdate",		360,		        9},
	
	{"   ", "/opt/dwmblocks/scripts/memory",	        6,		            1},

	{" ", "/opt/dwmblocks/scripts/cpu",			 		1,					11},

	{"  ", "/opt/dwmblocks/scripts/clock",			5,		            0},

};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = ' ';
