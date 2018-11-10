# Siege's AEKII keymap for LFK78

I'm not sure setting the LFK_REV value here works as expected.

Make sure it's set correctly for the board rev in:
  ~/qmk_firmware/keyboards/lfkeyboards/lfk78/rules.mk


For my boards, that's:

Monterey board:
LFK_REV = A
Others:
LFK_REV = B


To compile:
  cd ~/qmk_firmware
  make lfkeyboards/lfk78:aekii
