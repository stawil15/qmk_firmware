# thistle

![thistle](imgur.com image replace me!)

*A split-handwired keyboard with a traditional staggered QWERTY layout with two 'B' keys*

This keyboard was designed to fill what I perceived as a gap in the available open-sourced keyboard designs. 
There's no shortage of split-designs, but they're nearly all ortholinear.
Of the traditional staggered-layout variety, I found none that both had arrow keys and a second alice-style 'B' key. 

I believe Arrow Keys and the right-hand B are very important to most typist who do not want to change their muscle memory and typing habits just to try out a split keyboard design.
This is also why I opted to use RJ11 instead of the traditional TRRS cable. It may not be as pretty but the end user won't accidentally short their board by unplugging it while in use.

* Keyboard Maintainer: [Saeed Tawil](https://github.com/stawil15)
* Hardware Supported: This build uses two Pro-Micros or other AtMega32U4 chipsets, two USB-C daughter boards and RJ11 jacks.

Make example for this keyboard (after setting up your build environment):

    make thistle:default

Flashing example for this keyboard:

    make thistle:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

## Layout

![Keymap layout (generated with keyboard-layout-editor.com)](https://i.imgur.com/BQ4JIRC.jpg)
