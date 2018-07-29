
Debian
====================
This directory contains files used to package piond/pion-qt
for Debian-based Linux systems. If you compile piond/pion-qt yourself, there are some useful files here.

## pion: URI support ##


pion-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install pion-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your pion-qt binary to `/usr/bin`
and the `../../share/pixmaps/pion128.png` to `/usr/share/pixmaps`

pion-qt.protocol (KDE)

