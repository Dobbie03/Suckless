/* appearance */
static const unsigned int borderpx      = 2;   /* border pixel of windows */
static const unsigned int snap          = 32;  /* snap pixel */
static const unsigned int gappih        = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv        = 10;  /* vert inner gap between windows */
static const unsigned int gappoh        = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov        = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact         = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[]    = "autostart_blocking.sh";
static const char autostartsh[]         = "autostart.sh";
static const char dwmdir[]              = "dwm";
static const char localshare[]          = ".local/share";
static const int usealtbar              = 1;   /* 1 means use non-dwm status bar */
static const char *altbarclass          = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd            = "$HOME/.config/polybar/bar.sh"; /* Alternate bar launch command */
static const int showbar                = 0;   /* 0 means no bar */
static const int topbar                 = 1;   /* 0 means bottom bar */
static const int bar_height             = 45;  /* 0 means derive from font, >= 1 explicit height */
static const int statusmon              = 'A'; /* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int horizpadbar            = 10;  /* horizontal padding for statusbar */
static const int vertpadbar             = 10;  /* vertical padding for statusbar */

/* alt-tab configuration */
static const unsigned int tabmodkey     = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey   = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy       = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx       = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab       = 600;  /* tab menu width */
static const unsigned int maxhtab       = 200;  /* tab menu height */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype             = INDICATOR_CLIENT_DOTS;
static int tiledindicatortype           = INDICATOR_NONE;
static int floatindicatortype           = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]          	 = { "SF Pro Rounded:style=Regular:size=9:antialias=true", "Font Awesome 6 Pro:style=Solid:pixelsize=16:antialias=true", "Font Awesome 6 Brands:style=Solid:pixelsize=16:antialias=true", "Material Design Icons:Regular:pixelsize=19:antialias=true" };
static const char dmenufont[]       	 = "SF Pro Rounded:style=Regular:size=9:antialias=true";

static char c000000[]                   = "#141414"; // placeholder value

static char normfgcolor[]               = "#a7a7a7";
static char normbgcolor[]               = "#141414";
static char normbordercolor[]           = "#202020";
static char normfloatcolor[]            = "#303030";

static char selfgcolor[]                = "#808fa0";
static char selbgcolor[]                = "#141414";
static char selbordercolor[]            = "#505050";
static char selfloatcolor[]             = "#505050";

static char titlenormfgcolor[]          = "#a7a7a7";
static char titlenormbgcolor[]          = "#141414";
static char titlenormbordercolor[]      = "#141414";
static char titlenormfloatcolor[]       = "#303030";

static char titleselfgcolor[]           = "#808fa0";
static char titleselbgcolor[]           = "#141414";
static char titleselbordercolor[]       = "#141414";
static char titleselfloatcolor[]        = "#a7a7a7";

static char tagsnormfgcolor[]           = "#a7a7a7";
static char tagsnormbgcolor[]           = "#141414";
static char tagsnormbordercolor[]       = "#141414";
static char tagsnormfloatcolor[]        = "#303030";

static char tagsselfgcolor[]            = "#808fa0";
static char tagsselbgcolor[]            = "#141414";
static char tagsselbordercolor[]        = "#141414";
static char tagsselfloatcolor[]         = "#a7a7a7";

static char hidnormfgcolor[]            = "#a7a7a7";
static char hidselfgcolor[]             = "#808fa0";
static char hidnormbgcolor[]            = "#222222";
static char hidselbgcolor[]             = "#222222";

static char urgfgcolor[]                = "#b16286";
static char urgbgcolor[]                = "#141414";
static char urgbordercolor[]            = "#b16286";
static char urgfloatcolor[]             = "#b16286";


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

	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
static const Rule rules[] = {
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 8, .switchtag = 1)
	RULE(.class = "firefox", .tags = 1, .switchtag = 1)
	RULE(.class = "qutebrowser", .tags = 1, .switchtag = 1)
	RULE(.class = "transmission-gtk", .tags = 1 << 2)
	RULE(.class = "Nicotine", .tags = 1 << 2, .switchtag = 1)
	RULE(.class = "ncmpcpp", .tags = 1 << 3, .switchtag = 1)
	RULE(.class = "Thunar", .tags = 1 << 4, .switchtag = 1)
	RULE(.class = "Sxiv", .tags = 1 << 4, .isfloating = 1, .iscentered = 1, .switchtag = 1)
	RULE(.class = "Nsxiv", .tags = 1 << 4, .isfloating = 1, .iscentered = 1, .switchtag = 1)
	RULE(.class = "mpv", .tags = 1 << 4, .isfloating = 1, .iscentered = 1, .switchtag = 1)
	RULE(.class = "File-roller", .tags = 1 << 4, .isfloating = 1, .iscentered = 1)
	RULE(.class = "Subl", .tags = 1 << 6, .switchtag = 1)
	RULE(.class = "firefox", .title = "Toolkit", .wintype = "Picture-in-Picture", .tags = 0, .isfloating = 1, .iscentered = 1)
	RULE(.class = "Easytag", .tags = 1 << 7, .switchtag = 1)
	RULE(.instance = "GtkFileChooserDialog", .title = "Save File", .tags = 0, .isfloating = 1, .iscentered = 1)
	RULE(.instance = "Thunar", .title = "File Operation Progress", .tags = 0,  .isfloating =1, .iscentered = 1)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.wintype = "About Mozilla Firefox", .tags = 0, .isfloating = 1, .iscentered = 1)
};

static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -2,        -2,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ -2,        -2,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, -2,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
	{ -2,        -2,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol    arrange function */
	{ "󰕴",      dwindle }, 	/* first entry is default */	
	{ "󰕰",      tile },    
	{ "󰕯",      NULL },    /* no layout function means floating behavior */
	{ "󰃚",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = {"dmenu_run_history", NULL};
static const char *termcmd[]  = { "st", NULL };

#define APP_BROWSER     "firefox"
#define APP_QUTE			"qutebrowser"
#define APP_MUSIC       "st -c ncmpcpp -e ncmpcpp"
#define APP_MPDTOG      "mpc toggle"
#define APP_FILE        "thunar"
#define APP_EDIT        "subl"
#define APP_VOLU        "/home/dobbie/.bin/volume up"
#define APP_VOLD        "/home/dobbie/.bin/volume down"
#define APP_EXIT        "/usr/bin/dmenu_logout"
#define APP_MAIM			"/home/dobbie/.bin/ss.sh"
#define APP_MAIMS			"/home/dobbie/.bin/sss.sh"
#define APP_DUNSTHIST   "dunstctl history-pop"
#define APP_DUNSTCLOSE  "dunstctl close"
#define APP_LOCK        "slock"

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier                     key            function              argument */
	{ MODKEY,                       XK_space,      spawn,                {.v = dmenucmd } },
	{ MODKEY,                       XK_t,          spawn,                {.v = termcmd } },
  	{ MODKEY,                       XK_w,          spawn,                SHCMD(APP_BROWSER) },
  	{ MODKEY|ShiftMask,             XK_w,          spawn,                SHCMD(APP_QUTE) },
  	{ MODKEY,                       XK_m,          spawn,                SHCMD(APP_MUSIC) },
  	{ MODKEY,                       XK_e,          spawn,                SHCMD(APP_EDIT) },
  	{ 0,                       	  XK_Print,  	  spawn,	          		SHCMD(APP_MAIM) },
	{ 0|ShiftMask,             	  XK_Print,  	  spawn,	          		SHCMD(APP_MAIMS) },
  	{ MODKEY,                       XK_Escape,     spawn, 				 	SHCMD(APP_MPDTOG) },
	{ 0, XF86XK_AudioPlay,                     	  spawn,                SHCMD(APP_MPDTOG) },
	{ 0, XF86XK_AudioRaiseVolume,                  spawn,                SHCMD(APP_VOLU) },
	{ 0, XF86XK_AudioLowerVolume,                  spawn,                SHCMD(APP_VOLD) },
	{ MODKEY|ShiftMask,				  XK_r,	        spawn, 				 	SHCMD(APP_EXIT) },
	{ MODKEY,							  XK_f,	   	  spawn, 			 	 	SHCMD(APP_FILE) },
	{ MODKEY,							  XK_l,          spawn, 			 	 	SHCMD(APP_LOCK) },
  	{ ControlMask,                  XK_grave,  	  spawn,                SHCMD(APP_DUNSTHIST) },
  	{ ControlMask,                  XK_space,      spawn,                SHCMD(APP_DUNSTCLOSE) },
	{ MODKEY,                       XK_b,          togglebar,            {0} },
	{ MODKEY|ControlMask,           XK_space,      focusmaster,          {0} },
	{ MODKEY|ShiftMask,             XK_j,      	  rotatestack,          {.i = +1 } },
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
	{ MODKEY,                       XK_q,      	  killclient,           {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                 {0} },
	{ MODKEY,                       XK_u,          focusurgent,          {0} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                 {.v = NULL } },
	{ MODKEY|ShiftMask,             XK_t,          setlayout,            {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_f,          setlayout,            {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_m,          setlayout,            {.v = &layouts[2]} },
	{ MODKEY|ControlMask|ShiftMask, XK_space,      setlayout,            {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,       {0} },
	{ MODKEY,                       XK_s,          togglescratch,        {.ui = 0 } },
	{ MODKEY|ControlMask,           XK_s,      	  setscratch,           {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_s,          removescratch,        {.ui = 0 } },
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
	TAGKEYS(                        XK_1,                           	 	0)
	TAGKEYS(                        XK_2,                           	 	1)
	TAGKEYS(                        XK_3,                           	 	2)
	TAGKEYS(                        XK_4,                           	 	3)
	TAGKEYS(                        XK_5,                           	 	4)
	TAGKEYS(                        XK_6,                           	 	5)
	TAGKEYS(                        XK_7,                           	 	6)
	TAGKEYS(                        XK_8,                           	 	7)
	TAGKEYS(                        XK_9,                           	 	8)
	TAGKEYS(                        XK_0,                           	 	9)
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


static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
	IPCCOMMAND( focusmon, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( focusstack, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incnmaster, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( killclient, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( quit, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( setlayoutsafe, 1, {ARG_TYPE_PTR} ),
	IPCCOMMAND( setmfact, 1, {ARG_TYPE_FLOAT} ),
	IPCCOMMAND( setstatus, 1, {ARG_TYPE_STR} ),
	IPCCOMMAND( tag, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( tagmon, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( togglebar, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( togglefloating, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( toggletag, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( toggleview, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( view, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( zoom, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( togglealttag, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( focusurgent, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( rotatestack, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( togglescratch, 1, {ARG_TYPE_UINT} ),
	IPCCOMMAND( setborderpx, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( showhideclient, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( incrgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrigaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrogaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrihgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrivgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrohgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( incrovgaps, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( togglegaps, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( defaultgaps, 1, {ARG_TYPE_NONE} ),
	IPCCOMMAND( setgapsex, 1, {ARG_TYPE_SINT} ),
	IPCCOMMAND( xrdb, 1, {ARG_TYPE_NONE} ),
};
