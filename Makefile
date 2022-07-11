LAYOUT_NAME = tmpbeing
TARGET = ergodox_ez_$(LAYOUT_NAME).hex
QMK_LOCATION = ../qmk_firmware

SRC = rules.mk keymap.c config.h
SRC_DESTINATION = $(QMK_LOCATION)/keyboards/ergodox_ez/keymaps/$(LAYOUT_NAME)

all: $(TARGET)

$(TARGET):
	mkdir -p $(SRC_DESTINATION)
	cp $(SRC) $(SRC_DESTINATION)
	make -C $(QMK_LOCATION) ergodox_ez:$(LAYOUT_NAME)
	cp $(QMK_LOCATION)/$(TARGET) .

clean:
	rm -f $(TARGET)

clean-qmk:
	rm -rf $(SRC_DESTINATION)
	rm $(QMK_LOCATION)/$(TARGET)

fclean: clean clean-qmk

re: clean all

.PHONY: all clean clean-qmk fclean re
