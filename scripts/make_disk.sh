#This is a quick script to make a FAT32 disk image with some data in it

#make a 50mb file
dd if=/dev/zero of=disk.img count=50 bs=1M

#format it to FAT32
mkfs.fat -F 32 disk.img

#mount it somewhere
mkdir disk_mount
mount disk.img disk_mount

#put some stuff into it
echo "File 1 stuff" >> disk_mount/file1.txt
mkdir disk_mount/dir
echo "More Data!!!" >> disk_mount/dir/file2.txt

#unmount and clean up
umount disk_mount
rm -rf disk_mount/*
rmdir disk_mount
