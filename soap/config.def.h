/* See LICENSE file for copyright and license details. */

/* special command for directories */
static const char *dircmd = "st -e noice %s";

static const Pair pairs[] = {
	/*  regex                                           action */
	{ "\\.pdf$",                                        "mupdf %s"            }, // pdf
	{ "\\.(jpg|png|tiff|gif)$",                         "sxiv -a %s"          }, // image
	{ "\\.(avi|mp4|m4v|mkv|mp3|ogg|flac|mov|wav|wmv)$", "ffplay %s"           }, // audio/video
	{ "\\.(html|svg)$",                                 "firefox %s"          }, // local html and svg
	{ "^(http://|https://)",                            "firefox %s"          }, // web URI link
	{ "(^magnet:\?|\\.torrent$)",                       "transmission-gtk %s" }, // magnet/torrent URI link
	{ "^steam:\?",                                      "steam %s"            }, // steam URI link
	{ "^zoommtg:\?",                                    "zoom %s"             }, // zoom URI link
	{ "^slack:\?",                                      "slack %s"            }, // slack URI link
	{ ".h",                                             "st -c nano -e nano  %s" }, // catch-all default
};
