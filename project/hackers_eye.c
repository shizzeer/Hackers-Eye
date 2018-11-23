#include <stdio.h>
#include "../gui/container.h"
#include "../gui/menu.h"
// #include <gdk/gdkkeysyms.h>

int main(int argc, char* argv[])
{
	GtkWidget *window, *vbox;
	GdkPixbuf *icon;

	gtk_init(&argc, &argv);
	
	window = create_window();

	icon = create_icon("eye.jpg");
	gtk_window_set_icon(GTK_WINDOW(window), icon);

	vbox = gtk_vbox_new(FALSE, 0);
	create_menu(vbox);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	set_destroy_signal(window);
	free_icon_object(icon);
	
	gtk_widget_show_all(window);

	gtk_main();
	
	return 0;
}
