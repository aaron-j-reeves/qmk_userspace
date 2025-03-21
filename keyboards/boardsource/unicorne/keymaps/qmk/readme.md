```bash
qmk setup --home "C:\keyboard_stuff\repos\qmk_firmware"
Ψ Found qmk_firmware at C:/keyboard_stuff/repos/qmk_firmware.
Would you like to set C:/keyboard_stuff/repos/qmk_firmware as your QMK home? [y/n] y
Ψ Wrote configuration to C:/Users/13667/AppData/Local/QMK.EXE/qmk.exe/qmk.exe.ini

qmk config user.keymap=qmk
qmk config user.keyboard=boardsource/unicorne
qmk compile -kb boardsource/unicorne -km qmk
qmk userspace-compile -c
qmk compile -kb boardsource/unicorne -km qmk -c -j 0

qmk flash -kb boardsource/unicorne -km qmk -bl uf2-split-left
qmk flash -kb boardsource/unicorne -km qmk -bl uf2-split-right

& 'C:\keyboard_stuff\repos\qmk_userspace\copy-kbfirmware.ps1'


git submodule add https://github.com/getreuer/qmk-modules.git modules/getreuer
git submodule add https://github.com/drashna/qmk_modules.git modules/drashna  



cd /path/to/your/external/userspace
mkdir -p modules
git submodule add https://github.com/{user}/{repo}.git modules/{user}
git submdule update --init --recursive
```
