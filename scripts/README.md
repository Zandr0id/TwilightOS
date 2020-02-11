This is the location of helpful scripts for development.

The make_disk.sh **WILL NOT** work properly on WSL, so a copy of the disk image has been included in the root folder.
While WSL can create the disk.img file, it is not able to use the `mount` and `umount` commands, 
so you will end up with a disk image with nothing on it.

It works perfectly fine on a debian system. You also must run it with `sudo`.
