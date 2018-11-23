#include <gtk/gtk.h>

static void add_items_to_file_menu(GtkWidget *menu)
{
	const char *file_menu_items[7] = {"New", "Open", "Save", "Save as", "Export", "Close", "Exit"};
	GtkWidget *file_menu_item;

	for (int i = 0; i < 7; i++)
	{
		file_menu_item = gtk_menu_item_new_with_label(file_menu_items[i]);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), file_menu_item);
	}
}

static void add_items_to_edit_menu(GtkWidget *menu)
{
	const char *edit_menu_items[7] = {"Undo", "Redo", "Cut", "Copy", "Paste", "Delete", "Select All"};
	GtkWidget *edit_menu_item;

	for (int i = 0; i < 7; i++)
	{
		edit_menu_item = gtk_menu_item_new_with_label(edit_menu_items[i]);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), edit_menu_item);
	}
}

static void add_items_to_view_menu(GtkWidget *menu)
{
	const char *view_menu_items[2] = {"Font", "Background-Color"};
	GtkWidget *view_menu_item;

	for (int i = 0; i < 2; i++)
	{
		view_menu_item = gtk_menu_item_new_with_label(view_menu_items[i]);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), view_menu_item);
	}
}

static void add_items_to_search_menu(GtkWidget *menu)
{
	const char *search_menu_items[4] = {"Search", "Search next", "Search previous", "Goto offset"};
	GtkWidget *search_menu_item;

	for (int i = 0; i < 4; i++)
	{
		search_menu_item = gtk_menu_item_new_with_label(search_menu_items[i]);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), search_menu_item);
	}
}

static void add_items_to_menu(GtkWidget *menu, int menu_number)
{
	switch (menu_number)
	{
		case 0: add_items_to_file_menu(menu); break;
		case 1: add_items_to_edit_menu(menu); break;
		case 2: add_items_to_view_menu(menu); break;
		case 3: add_items_to_search_menu(menu); break;
		case 4: add_items_to_file_menu(menu); break;
		case 5: add_items_to_file_menu(menu); break;
		default: fprintf(stderr, "%s\n", "No such menu item!"); break;
	}
}

static void create_file_menu(GtkWidget *menu_bar, GtkWidget *vbox)
{
	GtkWidget *menu;
	GtkWidget *m_item;

	const char *menu_names[6] = {"File", "Edit", "View", "Search", "Tools", "Help"};

	for(int i = 0; i < 6; i++)
	{
		menu = gtk_menu_new();

		m_item = gtk_menu_item_new_with_label(menu_names[i]);

		gtk_menu_item_set_submenu(GTK_MENU_ITEM(m_item), menu);	// do itemu "File" przypisujemy kwadrat
		add_items_to_menu(menu, i);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), m_item);
		gtk_box_pack_start(GTK_BOX(vbox), menu_bar, FALSE, FALSE, 0);
	}
}

void create_menu(GtkWidget *vbox)
{
	GtkWidget *menu_bar;
	GtkWidget *file_menu, *view_menu, *search_menu, *help_menu;

	menu_bar = gtk_menu_bar_new();	
	create_file_menu(menu_bar, vbox);
}