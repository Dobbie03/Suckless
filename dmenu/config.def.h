/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom */
static int opacity = 1;                     /* -o  option; if 0, then alpha is disabled */
static int caret_width = 2;                 /* -cw option; set default caret width */
static int fuzzy = 1;                       /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static int center = 1;                      /* -c  option; if 0, dmenu won't be centered on the screen */
static int min_width = 800;                 /* minimum width when centered */
/* -fn option overrides fonts[0]; default X11 font or font set */
static char *fonts[] =
{
	"Geist Mono:size=14:antialias=true:autohint=true"
	"Font Awesome 6:pixelsize=16:antialias=true:autohint=true"
	"NotoColorEmoji:pixelsize=10:antialias=true:autohint=true"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

static const unsigned int baralpha = 225;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
	[SchemeBorder] = { OPAQUE, OPAQUE, OPAQUE },
	[SchemeMid] = { OPAQUE, baralpha, borderalpha },
	[SchemeSelHighlight] = { OPAQUE, baralpha, borderalpha },
	[SchemeNormHighlight] = { OPAQUE, baralpha, borderalpha },
};

static
char *colors[][2] = {
	/*               fg         bg       */
	[SchemeNorm] = { "#a7a7a7", "#141414" },
	[SchemeSel]  = { "#808fa0", "#141414" },
	[SchemeOut]  = { "#000000", "#00ffff" },
	[SchemeBorder] = { "#505050", "#505050" },
	[SchemeMid]  = { "#a7a7a7", "#141414" },
	[SchemeSelHighlight]  = { "#9d5b61", "#141414" },
	[SchemeNormHighlight] = { "#838d69", "#141414" },
};
/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 5;
static unsigned int columns    = 2;
static unsigned int lineheight = 35;         /* -h option; minimum height of a menu line     */
static unsigned int min_lineheight = 12;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 3;

/*
 * Use prefix matching by default; can be inverted with the -x flag.
 */
static int use_prefix = 1;
