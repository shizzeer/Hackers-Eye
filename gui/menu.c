#include <gtk/gtk.h>
#include <string.h>

static void add_separator_to_menu(GtkWidget *menu)
{
	GtkWidget *separator;
	separator = gtk_separator_menu_item_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), separator);
}

static void add_items_to_file_menu(GtkWidget *menu)
{
	GtkWidget *file_menu_item;

	for (int i = 0; i < 7; i++)
	{
		switch (i)
		{
			case 0: file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL); break;
			case 1: file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL); break;
			case 2: file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, NULL); break;
			case 3: file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, NULL); break;
			case 4: 
			{
				add_separator_to_menu(menu);
				file_menu_item = gtk_menu_item_new_with_label("Export"); 
			}
			break;
			case 5:
			{
				add_separator_to_menu(menu);
				file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_CLOSE, NULL);
			}
			break;
			case 6: file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL); break;
			default: fprintf(stderr, "%s\n", "No such menu item!"); break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), file_menu_item);
	}
}

static void add_items_to_edit_menu(GtkWidget *menu)
{
	GtkWidget *edit_menu_item;

	for (int i = 0; i < 7; i++)
	{
		switch (i)
		{
			case 0: edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_UNDO, NULL); break;
			case 1: edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_REDO, NULL); break;
			case 2:
			{
				add_separator_to_menu(menu);
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT, NULL);
			}
			break;
			case 3: edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY, NULL); break;
			case 4: edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE, NULL); break;
			case 5: edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_DELETE, NULL); break;
			case 6:
			{
				add_separator_to_menu(menu);
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SELECT_ALL, NULL);
			}
			break;
			default: fprintf(stderr, "%s\n", "No such menu item!"); break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), edit_menu_item);
	}
}

static void add_items_to_view_menu(GtkWidget *menu)
{
	const char *view_menu_items[2] = {"Font", "Background-Color"};
	GtkWidget *view_menu_item;

	for (int i = 0; i < 2; i++)
	{
		switch (i)
		{
			case 0: view_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SELECT_FONT, NULL); break;
			case 1: view_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SELECT_COLOR, NULL); break;
			default: fprintf(stderr, "%s\n", "No such menu item!"); break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), view_menu_item);
	}
}

static void add_items_to_search_menu(GtkWidget *menu)
{
	GtkWidget *search_menu_item;

	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
			case 0: search_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND, NULL); break;
			case 1: search_menu_item = gtk_menu_item_new_with_label("Find next"); break;
			case 2: search_menu_item = gtk_menu_item_new_with_label("Find previous"); break;
			case 3: search_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND_AND_REPLACE, NULL); break;
			case 4: 
			{
				add_separator_to_menu(menu);
				search_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_JUMP_TO, NULL); 
			}
			break;
			default: fprintf(stderr, "%s\n", "No such menu item!"); break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), search_menu_item);
	}
}

static void add_items_to_tools_menu(GtkWidget *menu)
{
	const char *tools_menu_items[3] = {"Disassemble", "Bitwise operations", "Conversion table"};
	GtkWidget *tools_menu_item;

	for (int i = 0; i < 3; i++)
	{
		tools_menu_item = gtk_menu_item_new_with_label(tools_menu_items[i]);

		if (i == 1)
			add_separator_to_menu(menu);
		
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), tools_menu_item);
	}
}

static void add_items_to_help_menu(GtkWidget *menu)
{
	GtkWidget *help_menu_item;

	for (int i = 0; i < 2; i++)
	{
		switch (i)
		{
			case 0: help_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP, NULL); break;
			case 1: help_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL); break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), help_menu_item);
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
		case 4: add_items_to_tools_menu(menu); break;
		case 5: add_items_to_help_menu(menu); break;
		default: fprintf(stderr, "%s\n", "No such menu item!"); break;
	}
}

void create_menu(GtkWidget *vbox)
{
	GtkWidget *menu_bar, *menu;
	GtkWidget *m_item;

	menu_bar = gtk_menu_bar_new();

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
