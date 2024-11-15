/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 5000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 4048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const struct arg args[] = {
    /* function format                  argument */
    /*{ run_command, "^b#141414^^c#756e5a^    ^b#141414^^c#a7a7a7^%s    ^c#a7a7a7^ ",        "mpc current"          },*/
    { run_command, "^b#141414^^c#756e5a^    ^b#141414^^c#a7a7a7^%s    ^c#a7a7a7^ ",        "mpc -f '%title% - %artist% - %album%'"          },
    { cpu_perc, "^b#141414^^c#685269^  ^b#141414^^c#a7a7a7^ %s%%    ^c#a7a7a7^ ",         NULL },
    { ram_perc, "^b#141414^^c#5b6976^  ^b#141414^^c#a7a7a7^ %s%%    ^c#a7a7a7^ ",         NULL },
/*    { run_command, "  %4s%%    ",  "pamixer --get-volume" },*/
    { run_command,  "^b#141414^^c#68755a^  ^b#141414^^c#a7a7a7^ %s   ^c#a7a7a7^ ",     "amixer get Master | tail -1 | awk -F'[][]' '{if($4==\"on\"){print \" \"$2}else{print \" \"$2}}'" },
/*  { wifi_essid, "   %s    ",         "wlo1"},*/
    { netspeed_tx, "^b#141414^^c#755a5b^   ^b#141414^^c#a7a7a7^%s    ^c#a7a7a7^ ",        "enp34s0" },
    { netspeed_rx, "^b#141414^^c#755a5b^   ^b#141414^^c#a7a7a7^%s    ^c#a7a7a7^ ",        "enp34s0" },
    { disk_perc, "^b#141414^^c#5b7674^  ^b#141414^^c#a7a7a7^%s%%    ^c#a7a7a7^ ",        "/home" },
/*  { disk_perc, "  %s%%",            "/home" },
    { disk_total, " / %s   ",           "/home" },*/ /*use to show total disk space*/
    { disk_perc, "^b#141414^^c#756e5a^   ^b#141414^^c#a7a7a7^%s%%    ^c#a7a7a7^ ",        "/opt/Music/" },
/*    { disk_perc, "  %s%%    ",        "/opt/Important/" },
    { disk_perc, "  %s%%    ",        "/opt/Photos/" },
    { disk_perc, "  %s%%    ",        "/opt/Archive/" },*/
/*  { disk_perc, "  %s%%",            "/run/media/dobbie/Music/" },
    { disk_total, " / %s   ",           "/run/media/dobbie/Music/" },*/ /*use to show total disk space*/
/*  { run_command, "   %s    ",        "mpc current"          },*/
/*  { run_command, "   %s    ",        "mpc -f '%title% by %artist% from %album% (%date%)'"           },*/
    { keyboard_indicators, "^b#141414^^c#685269^  ^b#141414^^c#a7a7a7^%s     ^c#a7a7a7^ ",  "c"},
    { datetime, "^b#141414^^c#5b6976^   ^b#141414^^c#a7a7a7^%s^c#a7a7a7^ ",           "%A, %b %d, %l:%M %p"},
    /*{ hostname, "  [%s]",             NULL},*/
/*  { username, "   %s",               NULL},*/
};
