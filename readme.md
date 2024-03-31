# Why
With this app you can use M575 macro buttons for edit sensivity.

# Install process
You need xbindkeys.
`sudo pacman -S xbindkeys`
`touch ~/.xbindkeysrc`
After these commands, you should edit `xbindkeysrc` file.
Add:
```sh
"ergosniffer up"
  b:9

"ergosniffer down"
  b:8

```
Compile app then move to `/usr/bin/` folder.

`killall xbindkeys` for reload
`xbindkeys` it should work in background (I recommend autostart)