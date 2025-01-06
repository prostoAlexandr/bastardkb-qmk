VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
TAP_DANCE_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE = yes

#MACCEL
SRC += ../../../../charybdis/4x6/keymaps/via/qmk_userspace_features/maccel/maccel.c
OPT_DEFS += -DMACCEL_ENABLE