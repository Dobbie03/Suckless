/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

/* appearance */
static const unsigned int borderpx       = 1;
static const unsigned int barborderpx    = 1;  /* border pixel of bar */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 1;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int showbar                 = 0;   /* 0 means no bar */
static const int topbar                  = 0;   /* 0 means bottom bar */
static const int bar_height              = 55;   /* 0 means derive from font, >= 1 explicit height */
static const int statusmon               = 'A';
static const int horizpadbar             = 10;   /* horizontal padding for statusbar */
static const int vertpadbar              = 15;   /* vertical padding for statusbar */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 0;   /* 0 means no systray */

/* alt-tab configuration */
static const unsigned int tabmodkey      = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey    = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy        = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx        = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab        = 600;  /* tab menu width */
static const unsigned int maxhtab        = 200;  /* tab menu height */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_CLIENT_DOTS;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
/*static const char *fonts[]          	 = { "SF Pro Rounded:style=Bold:size=9:antialias=true", "Font Awesome 6 Pro:style=Solid:pixelsize=17:antialias=true", "Font Awesome 6 Brands:style=Solid:pixelsize=17:antialias=true", "Material Design Icons:Regular:pixelsize=23:antialias=true" };*/
static const char *fonts[]          	 = { "SF Pro Rounded:style=Bold:size=9:antialias=true", "Font Awesome 6 Pro:style=Solid:pixelsize=17", "Font Awesome 6 Brands:style=Solid:pixelsize=17", "Material Design Icons:Regular:pixelsize=23" };
static const char dmenufont[]       	 = "SF Pro Rounded:style=Regular:size=9:antialias=true";

static char c000000[]                    = "#141414"; // placeholder value

static char normfgcolor[]                = "#a7a7a7";
static char normbgcolor[]                = "#141414";
static char normbordercolor[]            = "#202020";
static char normfloatcolor[]             = "#303030";
static const char col_borderbar[]   	 = "#141414";

static char selfgcolor[]                 = "#5b6976";
static char selbgcolor[]                 = "#141414";
static char selbordercolor[]             = "#505050";
static char selfloatcolor[]              = "#505050";

static char titlenormfgcolor[]           = "#a7a7a7";
static char titlenormbgcolor[]           = "#141414";
static char titlenormbordercolor[]       = "#141414";
static char titlenormfloatcolor[]        = "#303030";

static char titleselfgcolor[]            = "#5b6976";
static char titleselbgcolor[]            = "#141414";
static char titleselbordercolor[]        = "#141414";
static char titleselfloatcolor[]         = "#a7a7a7";

static char tagsnormfgcolor[]            = "#a7a7a7";
static char tagsnormbgcolor[]            = "#141414";
static char tagsnormbordercolor[]        = "#141414";
static char tagsnormfloatcolor[]         = "#303030";

static char tagsselfgcolor[]             = "#5b6976";
static char tagsselbgcolor[]             = "#141414";
static char tagsselbordercolor[]         = "#141414";
static char tagsselfloatcolor[]          = "#a7a7a7";

static char hidnormfgcolor[]             = "#a7a7a7";
static char hidselfgcolor[]              = "#5b6976";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#755a5b";
static char urgbgcolor[]                 = "#141414";
static char urgbordercolor[]             = "#755a5b";
static char urgfloatcolor[]              = "#755a5b";

static const unsigned int baralpha = 255;
static const unsigned int borderalpha = 255;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
};

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
};

static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "", "", "", "", "", "", "", "", "" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "", "", "", "", "", "", "", "", "" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 8, .switchtag = 1)
	RULE(.class = "firefox", .tags = 1, .switchtag = 1)
	RULE(.class = "LibreWolf", .tags = 1, .switchtag = 1)
	RULE(.class = "mercury-default", .tags = 1, .switchtag = 1)	
	RULE(.class = "qutebrowser", .tags = 1, .switchtag = 1)
	RULE(.class = "transmission-gtk", .tags = 1 << 2)
	RULE(.class = "Nicotine", .tags = 1 << 2, .switchtag = 1)
	RULE(.class = "ncmpcpp", .tags = 1 << 3, .switchtag = 1)
	RULE(.class = "Thunar", .tags = 1 << 4, .switchtag = 1)
	RULE(.class = "Sxiv", .tags = 1 << 4, .isfloating = 1, .iscentered = 1, .switchtag = 1)
	RULE(.class = "Nsxiv", .tags = 1 << 4, .isfloating = 1, .iscentered = 1, .switchtag = 1)
	RULE(.class = "mpv", .tags = 1 << 4, .isfloating = 1, .iscentered = 1, .switchtag = 1)
	RULE(.class = "file-roller", .tags = 1 << 4, .isfloating = 1, .iscentered = 1)
	RULE(.class = "Subl", .tags = 1 << 6, .switchtag = 1)
	RULE(.class = "nano", .tags = 1 << 6, .switchtag = 1)
	RULE(.class = "Toolkit", .title = "Picture-in-Picture", .wintype = "_NET_WM_WINDOW_TYPE_UTILITY", .tags = 0, .isfloating = 1, .iscentered = 1)
	RULE(.class = "steam", .tags = 1 << 7, .switchtag = 1,.isfloating = 0, .iscentered = 1)
	RULE(.class = "Easytag", .tags = 1 << 8, .switchtag = 1)
	RULE(.instance = "GtkFileChooserDialog", .title = "Save File", .tags = 0, .isfloating = 1, .iscentered = 1)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.wintype = "About Mozilla Firefox", .tags = 0, .isfloating = 1, .iscentered = 1)
	RULE(.wintype = "_NET_WM_WINDOW_TYPE_DIALOG", .title = "File Operation Progress", .tags = 0, .isfloating = 1, .iscentered = 1)
	RULE(.wintype = "_NET_WM_WINDOW_TYPE_UTILITY", .title = "Picture-in-Picture", .tags = 0, .isfloating = 1, .iscentered = 1)
};

static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_status2d,          NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
};

/* layout(s) */
static const float mfact        = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int nstack         = 0;    /* number of clients in primary stack area */
static const int resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function, { nmaster, nstack, layout, master axis, stack axis, secondary stack axis, symbol func } */
	{ "󱒉",        spiral,           {0} }, // default tile layout
	{ "",        flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } },
 	{ "󰕯",        NULL,             {0} },    /* no layout function means floating behavior */
	{ "󰾍",        flextile,         { -1, -1, NO_SPLIT, MONOCLE, MONOCLE, 0, NULL } }, // monocle
	{ "󱇚",        flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // columns (col) layout
	{ "󱒈",        flextile,         { -1, -1, FLOATING_MASTER, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // floating master
	{ "󰕭",        flextile,         { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
	{ "󱒇",        flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, LEFT_TO_RIGHT, 0, NULL } }, // bstack
	{ "󰕴",        flextile,         { -1, -1, SPLIT_HORIZONTAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, 0, NULL } }, // bstackhoriz
	{ "",        flextile,         { -1, -1, SPLIT_CENTERED_VERTICAL, LEFT_TO_RIGHT, TOP_TO_BOTTOM, TOP_TO_BOTTOM, NULL } }, // centeredmaster
	{ "",        flextile,         { -1, -1, SPLIT_CENTERED_HORIZONTAL, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // centeredmaster horiz
	{ "",        flextile,         { -1, -1, NO_SPLIT, GAPPLESSGRID, GAPPLESSGRID, 0, NULL } }, // gappless grid
	{ "",        flextile,         { -1, -1, NO_SPLIT, DWINDLE, DWINDLE, 0, NULL } }, // fibonacci dwindle
	{ "",        flextile,         { -1, -1, NO_SPLIT, SPIRAL, SPIRAL, 0, NULL } }, // fibonacci spiral
	{ "",        flextile,         { -1, -1, SPLIT_VERTICAL, LEFT_TO_RIGHT, TATAMI, 0, NULL } }, // tatami mats
	{ "󰕰",        tile,             {0} },
	{ "󰃚",        monocle,          {0} },
	{ "󰡃",        dwindle,          {0} },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run_history", NULL};
static const char *termcmd[]  = { "st", NULL };
static const char *webcmd[]   = { "librewolf", NULL};
static const char *altwebcmd[]= { "qutebrowser", NULL};
static const char *musiccmd[] = { "st", "-c", "ncmpcpp", "-e", "ncmpcpp", NULL};
static const char *nanocmd[]  = { "st", "-c", "nano", "-e", "nano", NULL};
static const char *filecmd[]  = { "thunar", NULL};
static const char *editcmd[]  = { "subl", NULL};
static const char *dunsthcmd[]= { "dunstctl", "history-pop", NULL};
static const char *dunstccmd[]= { "dunstctl", "close", NULL};
static const char *lockcmd[]  = { "slock", NULL};

#define APP_VOLU        "/home/dobbie/.bin/volume up"
#define APP_VOLD        "/home/dobbie/.bin/volume down"
#define APP_EXIT        "/usr/bin/dmenu_logout"
#define APP_MAIM			"/home/dobbie/.bin/ss.sh"
#define APP_MAIMS			"/home/dobbie/.bin/sss.sh -m select"
#define APP_MAIMT			"/home/dobbie/.bin/sst.sh -w 10"
#define APP_CLIP 			"greenclip print | grep . | dmenu -l 10 -p clipboard | xargs -r -d'\n' -I '{}' greenclip print '{}'"

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_space,      spawn,                {.v = dmenucmd } },
	{ MODKEY,                       XK_t,          spawn,                {.v = termcmd } },
	{ MODKEY,                       XK_w,          spawn,                {.v = webcmd } },
  	{ MODKEY|ShiftMask,             XK_w,          spawn,                {.v = altwebcmd} },
  	{ MODKEY,                       XK_m,          spawn,                {.v = musiccmd} },
  	{ MODKEY,                       XK_e,          spawn,                {.v = editcmd} },
	{ MODKEY,							  XK_f,          spawn, 	            {.v = filecmd} },
  	{ ControlMask,                  XK_grave,      spawn,                {.v = dunsthcmd} },
  	{ ControlMask,                  XK_space,      spawn,                {.v = dunstccmd} },
	{ MODKEY|ShiftMask,	        	  XK_e,          spawn,                {.v = nanocmd} },
	{ MODKEY,							  XK_l,          spawn, 		         {.v = lockcmd} },	
  	{ 0,                            XK_Print,      spawn,                SHCMD(APP_MAIM) },
	{ 0|ShiftMask,                  XK_Print,      spawn,                SHCMD(APP_MAIMS) },
	{ 0|Mod1Mask,		        		  XK_Print,      spawn,	               SHCMD(APP_MAIMT) },
	{ 0, XF86XK_AudioRaiseVolume,                  spawn,                SHCMD(APP_VOLU) },
	{ 0, XF86XK_AudioLowerVolume,                  spawn,                SHCMD(APP_VOLD) },
	{ MODKEY|ShiftMask,	        	  XK_r,	        spawn, 		         SHCMD(APP_EXIT) },
  	{ MODKEY|ShiftMask,	           XK_v,          spawn,                SHCMD(APP_CLIP) },
	{ MODKEY,                       XK_b,          togglebar,            {0} },
	{ MODKEY|ControlMask,           XK_space,      focusmaster,          {0} },
	{ MODKEY|ShiftMask,             XK_j,          rotatestack,          {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          rotatestack,          {.i = -1 } },
	{ MODKEY,                       XK_j,          focusstack,           {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,           {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,           {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,           {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,             {.f = -0.05} },
	{ MODKEY|ControlMask,           XK_l,          setmfact,             {.f = +0.05} },
	{ MODKEY,                       XK_Return,     zoom,                 {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,            {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,            {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,            {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,            {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,           {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,           {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,           {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,           {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,           {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,           {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,           {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,           {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,           {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,          {0} },
	{ Mod1Mask,                     XK_Tab,        alttabstart,          {0} },
	{ MODKEY|ControlMask,           XK_z,          showhideclient,       {0} },
	{ MODKEY,                       XK_q,          killclient,           {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                 {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,           	   {1} },
	{ MODKEY,                       XK_u,          focusurgent,          {0} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                 {.v = NULL } },
	{ MODKEY|ShiftMask,             XK_t,          setlayout,            {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_f,          setlayout,            {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_m,          setlayout,            {.v = &layouts[2]} },
	{ MODKEY|ControlMask|ShiftMask, XK_space,      setlayout,            {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,       {0} },
	{ MODKEY,                       XK_s,          togglescratch,        {.ui = 0 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_s,          setscratch,           {.ui = 0 } },
	{ MODKEY|ControlMask|ShiftMask, XK_s,          removescratch,        {.ui = 0 } },
	{ MODKEY,                       XK_0,          view,                 {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                  {.ui = ~SPTAGMASK } },
	{ MODKEY,                       XK_comma,      focusmon,             {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,               {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,               {.i = +1 } },
	{ MODKEY,                       XK_n,          togglealttag,         {0} },
	{ MODKEY|ControlMask,           XK_minus,      setborderpx,          {.i = -1 } },
	{ MODKEY|ControlMask,           XK_plus,       setborderpx,          {.i = +1 } },
	{ MODKEY|ControlMask,           XK_numbersign, setborderpx,          {.i = 0 } },
	{ MODKEY,                       XK_F1,         mpdchange,            {.i = -1} },
	{ MODKEY,                       XK_F2,         mpdchange,            {.i = +1} },
	{ MODKEY,                       XK_Escape,     mpdcontrol,           {0} },
	TAGKEYS(                        XK_1,                                0)
	TAGKEYS(                        XK_2,                                1)
	TAGKEYS(                        XK_3,                                2)
	TAGKEYS(                        XK_4,                                3)
	TAGKEYS(                        XK_5,                                4)
	TAGKEYS(                        XK_6,                                5)
	TAGKEYS(                        XK_7,                                6)
	TAGKEYS(                        XK_8,                                7)
	TAGKEYS(                        XK_9,                                8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY,              Button4,        rotatestack,    {.i = +1 } },
	{ ClkClientWin,         MODKEY,              Button5,        rotatestack,    {.i = -1 } },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

