#ifndef FILE_MENU_H_
	#define FILE_MENU_H_
	#include <gtk/gtk.h>
	
	struct f_menu {
		GtkWidget *container;
		GtkWidget *new_file;
		GtkWidget *open;
		GtkWidget *save;
		GtkWidget *save_as;
		GtkWidget *export_file;
		GtkWidget *close;
		GtkWidget *quit;
	};

	void add_items_to_file_menu(struct f_menu *, GtkAccelGroup *);
#endif
