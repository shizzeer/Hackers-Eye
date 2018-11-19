#include <stdio.h>
#include <gtk/gtk.h>

GdkPixbuf *create_icon(const gchar *filename)
{
	GdkPixbuf *icon;
	GError *error = NULL;

	icon = gdk_pixbuf_new_from_file(filename, &error);

	if (!icon) {
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}

	return icon;
}

GtkWidget *create_window()
{
	GtkWidget *window;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Hackers Eye");
	gtk_window_set_default_size(GTK_WINDOW(window), 320, 380);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	return window;
}

void set_destroy_signal(GtkWidget *window)
{
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

void free_icon_object(GdkPixbuf *icon)
{
	g_object_unref(icon);
}