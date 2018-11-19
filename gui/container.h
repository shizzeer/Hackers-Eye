#ifndef CONTAINER_H_
	#define CONTAINER_H_

	#include <gtk/gtk.h>

	GtkWidget *create_window();
	GdkPixbuf *create_icon(const gchar *);
	void set_destroy_signal(GtkWidget *);
	void free_icon_object(GdkPixbuf *);
#endif