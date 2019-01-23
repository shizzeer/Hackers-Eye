#include <stdio.h>
#include "container.h"
#include "menu.h"
#include "toolbar.h"

void create_gui(GtkWidget *window, GtkWidget *main_vbox)
{
	window = create_window();
	main_vbox = create_main_vbox(window);

	create_icon("eye.jpg", window);
	create_menu(window, main_vbox);
	create_toolbar(window, main_vbox);

	gtk_widget_show_all(window);
}

int main(int argc, char* argv[])
{
	GtkWidget *window, *main_vbox;

	gtk_init(&argc, &argv);
	
	create_gui(window, main_vbox);
	
	gtk_main();
	
	return 0;
}
