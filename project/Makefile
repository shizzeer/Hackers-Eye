CC = gcc
ELF_CFLAGS = -I../gui -o
GTK_CFLAGS = `pkg-config --libs --cflags gtk+-2.0`
OBJ_CFLAGS = -c
OBJ_GUI_FILES = $(wildcard ../gui/*.o)

all: create_gui_obj_files hackers_eye remove_gui_obj_files

create_gui_obj_files:
	$(MAKE) -C ../gui

hackers_eye: hackers_eye.c ../gui/container.o ../gui/menu.o ../gui/toolbar.o ../gui/file_menu.o
	$(CC) $(ELF_CFLAGS) $@ $< $(OBJ_GUI_FILES) $(GTK_CFLAGS)

remove_gui_obj_files:
	$(MAKE) clean -C ../gui
