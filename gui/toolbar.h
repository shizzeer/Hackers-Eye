#ifndef TOOLBAR_H_
	#define TOOLBAR_H_
	#include <gtk/gtk.h>

	struct toolbar {
		GtkWidget *toolbar_container;
		GtkToolItem *new_file;
		GtkToolItem *open_file;
		GtkToolItem *save_file;
	};

	void create_toolbar(GtkWidget *, GtkWidget *);
#endif
