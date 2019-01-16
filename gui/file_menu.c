#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

struct f_menu {
	GtkWidget *container;	// file menu 
	GtkWidget *new_file;
	GtkWidget *open;
	GtkWidget *save;
	GtkWidget *save_as;
	GtkWidget *export_file;
	GtkWidget *close;
	GtkWidget *quit;
};

static GtkWidget *create_item(const gchar *file_menu_item)
{
	return gtk_image_menu_item_new_from_stock(file_menu_item, NULL);
}

void add_items_to_file_menu(struct f_menu *file_menu, GtkAccelGroup *accel_group)
{
	const gchar *file_menu_items[7] = { GTK_STOCK_NEW, GTK_STOCK_OPEN, GTK_STOCK_SAVE, 
	 								   GTK_STOCK_SAVE_AS, "EXPORT", GTK_STOCK_CLOSE,
	 								   GTK_STOCK_QUIT };
	GtkWidget *tmp = NULL;

	for (int i = 0; i < 7; i++) {
		switch (i) {
			case 0:
			{
				tmp = file_menu->new_file = create_item(file_menu_items[i]); 
				gtk_widget_add_accelerator(file_menu->new_file, "activate", accel_group, 
										   GDK_n, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} break;
			case 1: 
			{
				tmp = file_menu->open = create_item(file_menu_items[i]); 
				gtk_widget_add_accelerator(file_menu->open, "activate", accel_group,
										   GDK_o, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} break;
			case 2:
			{
				tmp = file_menu->save = create_item(file_menu_items[i]);
				gtk_widget_add_accelerator(file_menu->save, "activate", accel_group,
										   GDK_s, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} break;
			case 3: 
			{
				tmp = file_menu->save_as = create_item(file_menu_items[i]); 
				gtk_widget_add_accelerator(file_menu->save_as, "activate", accel_group,
										   GDK_s, (GDK_SHIFT_MASK + GDK_CONTROL_MASK), 
										   GTK_ACCEL_VISIBLE);
			} break;
			case 4: tmp = file_menu->export_file = gtk_menu_item_new_with_label("Export..."); break;
			case 5: 
			{
				tmp = file_menu->close = create_item(file_menu_items[i]); 
				gtk_widget_add_accelerator(file_menu->close, "activate", accel_group,
										   GDK_w, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} break;
			case 6: 
			{
				tmp = file_menu->quit = create_item(file_menu_items[i]); 
				gtk_widget_add_accelerator(file_menu->quit, "activate", accel_group,
										   GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(file_menu->container), tmp);
	}
}
