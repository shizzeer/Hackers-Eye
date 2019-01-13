#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>

static void add_separator_to_menu(GtkWidget *menu)
{
	GtkWidget *separator = NULL;
	separator = gtk_separator_menu_item_new();
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), separator);
}

static void add_items_to_file_menu(GtkWidget *menu, GtkAccelGroup *accel_group)
{
	GtkWidget *file_menu_item = NULL;

	for (int i = 0; i < 7; i++)
	{
		switch (i)
		{
			case 0:
			{
				file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
				
				gtk_widget_add_accelerator(file_menu_item, "activate", accel_group, GDK_n,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 1:
			{
				file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
				
				gtk_widget_add_accelerator(file_menu_item, "activate", accel_group, GDK_o,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 2:
			{ 
				add_separator_to_menu(menu);
				file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, NULL);
				
				gtk_widget_add_accelerator(file_menu_item, "activate", accel_group, GDK_s,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 3:
			{
				file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, NULL);
				
				gtk_widget_add_accelerator(file_menu_item, "activate", accel_group, GDK_s,
					(GDK_SHIFT_MASK + GDK_CONTROL_MASK), GTK_ACCEL_VISIBLE);
			}
			break;
			case 4: 
			{
				add_separator_to_menu(menu);
				file_menu_item = gtk_menu_item_new_with_label("Export..."); 
			}
			break;
			case 5:
			{
				add_separator_to_menu(menu);
				file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_CLOSE, NULL);
				
				gtk_widget_add_accelerator(file_menu_item, "activate", accel_group, GDK_w,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 6:
			{
				file_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
				
				gtk_widget_add_accelerator(file_menu_item, "activate", accel_group, 
					GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), file_menu_item);
	}
}

static void add_items_to_edit_menu(GtkWidget *menu, GtkAccelGroup *accel_group)
{
	GtkWidget *edit_menu_item = NULL;

	for (int i = 0; i < 7; i++)
	{
		switch (i)
		{
			case 0:
			{
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_UNDO, NULL);

				gtk_widget_add_accelerator(edit_menu_item, "activate", accel_group, GDK_z,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 1:
			{
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_REDO, NULL);

				gtk_widget_add_accelerator(edit_menu_item, "activate", accel_group, GDK_z,
					(GDK_SHIFT_MASK + GDK_CONTROL_MASK), GTK_ACCEL_VISIBLE);
			}
			break;
			case 2:
			{
				add_separator_to_menu(menu);
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_CUT, NULL);

				gtk_widget_add_accelerator(edit_menu_item, "activate", accel_group, GDK_x,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 3: 
			{
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_COPY, NULL);

				gtk_widget_add_accelerator(edit_menu_item, "activate", accel_group, GDK_c,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} 
			break;
			case 4:
			{
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_PASTE, NULL);

				gtk_widget_add_accelerator(edit_menu_item, "activate", accel_group, GDK_v,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} 
			break;
			case 5:
			{
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_DELETE, NULL);

				gtk_widget_add_accelerator(edit_menu_item, "activate", accel_group, GDK_Delete,
					0, GTK_ACCEL_VISIBLE);
			}
			break;
			case 6:
			{
				add_separator_to_menu(menu);
				edit_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SELECT_ALL, NULL);

				gtk_widget_add_accelerator(edit_menu_item, "activate", accel_group, GDK_a,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), edit_menu_item);
	}
}

static void add_items_to_view_menu(GtkWidget *menu)
{
	const char *view_menu_items[2] = {"Font", "Font-Color"};
	GtkWidget *view_menu_item = NULL; 

	for (int i = 0; i < 2; i++)
	{
		switch (i)
		{
			case 0: view_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SELECT_FONT, NULL); break;
			case 1: view_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_SELECT_COLOR, NULL); break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), view_menu_item);
	}
}

static void add_items_to_search_menu(GtkWidget *menu, GtkAccelGroup *accel_group)
{
	const char *search_menu_items[6] = {"Find", "Find next", "Find previous", "Search and replace", "Goto offset"};
	GtkWidget *search_menu_item = NULL;

	for (int i = 0; i < 5; i++)
	{
		switch (i)
		{
			case 0:
			{
				search_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND, NULL);

				gtk_widget_add_accelerator(search_menu_item, "activate", accel_group, GDK_f,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 1:
			{
				search_menu_item = gtk_menu_item_new_with_label("Find next");

				gtk_widget_add_accelerator(search_menu_item, "activate", accel_group, GDK_F3,
					0, GTK_ACCEL_VISIBLE);	
			}
			break;
			case 2: 
			{
				search_menu_item = gtk_menu_item_new_with_label("Find previous"); 

				gtk_widget_add_accelerator(search_menu_item, "activate", accel_group, GDK_F3,
					GDK_SHIFT_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
			case 3:
			{
				search_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_FIND_AND_REPLACE, NULL);

				gtk_widget_add_accelerator(search_menu_item, "activate", accel_group, GDK_r,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			} 
			break;
			case 4: 
			{
				add_separator_to_menu(menu);
				search_menu_item = gtk_image_menu_item_new_from_stock(GTK_STOCK_JUMP_TO, NULL); 

				gtk_widget_add_accelerator(search_menu_item, "activate", accel_group, GDK_g,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
			}
			break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), search_menu_item);
	}
}

static void add_items_to_tools_menu(GtkWidget *menu, GtkAccelGroup *accel_group)
{
	const char *tools_menu_items[3] = {"Disassemble", "Bitwise operations", "Conversion table"};
	GtkWidget *tools_menu_item = NULL;

	for (int i = 0; i < 3; i++)
	{
		tools_menu_item = gtk_menu_item_new_with_label(tools_menu_items[i]);

		switch (i)
		{
			case 0: gtk_widget_add_accelerator(tools_menu_item, "activate", accel_group, GDK_d,
				GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); break;
			case 1:
			{
				add_separator_to_menu(menu);
				gtk_widget_add_accelerator(tools_menu_item, "activate", accel_group, GDK_b,
					GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
			}
			break;
			case 2: gtk_widget_add_accelerator(tools_menu_item, "activate", accel_group, GDK_t,
				GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); break;
		}
		gtk_menu_shell_append(GTK_MENU_SHELL(menu), tools_menu_item);
	}
}

static void add_items_to_help_menu(GtkWidget *menu)
{
	GtkWidget *help_menu_item = NULL;

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

static void add_items_to_menu(GtkWidget *menu, GtkAccelGroup *accel_group, int menu_number)
{
	switch (menu_number)
	{
		case 0: add_items_to_file_menu(menu, accel_group); break;
		case 1: add_items_to_edit_menu(menu, accel_group); break;
		case 2: add_items_to_view_menu(menu); break;
		case 3: add_items_to_search_menu(menu, accel_group); break;
		case 4: add_items_to_tools_menu(menu, accel_group); break;
		case 5: add_items_to_help_menu(menu); break;
		default: fprintf(stderr, "%s\n", "No such menu item!"); break;
	}
}

GtkAccelGroup* add_accel_function_to_window(GtkWidget *window)
{
	GtkAccelGroup *accel_group = NULL;
	accel_group = gtk_accel_group_new();

	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	return accel_group;
}

void create_menu(GtkWidget *window)
{
	GtkWidget *vbox_menu = NULL, *menu_bar = NULL, *menu = NULL;
	GtkWidget *m_item = NULL;
	GtkAccelGroup *accel_group = NULL;

	accel_group = add_accel_function_to_window(window);

	vbox_menu = gtk_vbox_new(FALSE, 0);
	menu_bar = gtk_menu_bar_new();

	const char *menu_names[6] = {"File", "Edit", "View", "Search", "Tools", "Help"};

	for(int i = 0; i < 6; i++)
	{
		menu = gtk_menu_new();

		m_item = gtk_menu_item_new_with_label(menu_names[i]);

		gtk_menu_item_set_submenu(GTK_MENU_ITEM(m_item), menu);
		add_items_to_menu(menu, accel_group, i);
		gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), m_item);
	}

	gtk_box_pack_start(GTK_BOX(vbox_menu), menu_bar, FALSE, FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox_menu);
}
