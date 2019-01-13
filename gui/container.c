#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

void create_icon(const gchar *filename, GtkWidget *window)
{
	GdkPixbuf *icon;
	GError *error = NULL;

	icon = gdk_pixbuf_new_from_file(filename, &error);

	if (!icon) {
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}
	else {
		gtk_window_set_icon(GTK_WINDOW(window), icon);
		g_object_unref(icon);
	}
}

GtkWidget *create_window()
{
	GtkWidget *window = NULL;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hackers Eye");
	gtk_window_set_default_size(GTK_WINDOW(window), 720, 480);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	return window;
}
