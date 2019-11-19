rem Go run the qemu program with the kernel
rem The windows command prompt will use the same working directory as we ran make from

set QEMU="C:\Installed_Programs\qemu\qemu-system-i386.exe"

%QEMU% -kernel "bin\kernel.bin" -S -s -serial stdio
rem %QEMU% -kernel "bin\kernel.bin" -serial stdio
