#include <stdio.h>
#include "../gui/container.h"
#include "../gui/menu.h"

void create_gui(GtkWidget *window)
{
	window = create_window();
	create_icon("eye.jpg", window);
	create_menu(window);

	gtk_widget_show_all(window);
}

int main(int argc, char* argv[])
{
	GtkWidget *window;

	gtk_init(&argc, &argv);
	
	create_gui(window);
	
	gtk_main();
	
	return 0;
}
