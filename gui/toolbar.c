#include <gtk/gtk.h>

struct toolbar {
	GtkWidget *items_container;
	GtkToolItem *new_file;
	GtkToolItem *open_file;
	GtkToolItem *save_file;
	GtkToolItem *first_separator;
	GtkToolItem *undo;
	GtkToolItem *redo;
	GtkToolItem *second_separator;
	GtkToolItem *cut;
	GtkToolItem *copy;
	GtkToolItem *paste;
	GtkToolItem *third_separator;
	GtkToolItem *find;
	GtkToolItem *find_and_replace;
};

static GtkToolItem *create_toolbar_item(const gchar *item_to_create)
{
	return gtk_tool_button_new_from_stock(item_to_create);
}

static void add_items_to_toolbar(struct toolbar *main_toolbar)
{
	GtkToolItem *tmp = NULL;

	const gchar *items_to_add[13] = { GTK_STOCK_NEW, GTK_STOCK_OPEN, GTK_STOCK_SAVE, 
		                             "SEPARATOR", GTK_STOCK_UNDO, GTK_STOCK_REDO,
		                             "SEPARATOR", GTK_STOCK_CUT, GTK_STOCK_COPY,
		                             GTK_STOCK_PASTE, "SEPARATOR", GTK_STOCK_FIND,
		                             GTK_STOCK_FIND_AND_REPLACE };
	const int toolbar_size = 13;

	for (int item_idx = 0; item_idx < toolbar_size; item_idx++) {
	 	
	 	switch (item_idx)
	 	{
	 		case 0: 
	 		{
	 			tmp = main_toolbar->new_file = create_toolbar_item(items_to_add[item_idx]);
	 			gtk_tool_item_set_tooltip_text(main_toolbar->new_file, "New file"); 
	 		} break;
	 		case 1: 
	 		{
	 			tmp = main_toolbar->open_file = create_toolbar_item(items_to_add[item_idx]); 
	 			gtk_tool_item_set_tooltip_text(main_toolbar->open_file, "Open file");
	 		} break;
	 		case 2:
	 		{
	 			tmp = main_toolbar->save_file = create_toolbar_item(items_to_add[item_idx]);
	 			gtk_tool_item_set_tooltip_text(main_toolbar->save_file, "Save file");
	 		} break;
	 		case 3: tmp = main_toolbar->first_separator = gtk_separator_tool_item_new(); break;
	 		case 4: 
	 		{
	 			tmp = main_toolbar->undo = create_toolbar_item(items_to_add[item_idx]); 
	 			gtk_tool_item_set_tooltip_text(main_toolbar->undo, "Undo");
	 		} break;
	 		case 5: 
	 		{
	 			tmp = main_toolbar->redo = create_toolbar_item(items_to_add[item_idx]); 
	 			gtk_tool_item_set_tooltip_text(main_toolbar->redo, "Redo");
	 		} break;
	 		case 6: tmp = main_toolbar->second_separator = gtk_separator_tool_item_new(); break;
	 		case 7: 
	 		{
	 			tmp = main_toolbar->cut = create_toolbar_item(items_to_add[item_idx]); 
	 			gtk_tool_item_set_tooltip_text(main_toolbar->cut, "Cut");
	 		} break;
	 		case 8: 
	 		{ 
	 			tmp = main_toolbar->copy = create_toolbar_item(items_to_add[item_idx]); 
	 			gtk_tool_item_set_tooltip_text(main_toolbar->copy, "Copy");
	 		} break;
	 		case 9: 
	 		{
	 			tmp = main_toolbar->paste = create_toolbar_item(items_to_add[item_idx]);
	 			gtk_tool_item_set_tooltip_text(main_toolbar->paste, "Paste"); 
	 		} break;
	 		case 10: tmp = main_toolbar->third_separator = gtk_separator_tool_item_new(); break;
	 		case 11: 
	 		{ 
	 			tmp = main_toolbar->find = create_toolbar_item(items_to_add[item_idx]); 
	 			gtk_tool_item_set_tooltip_text(main_toolbar->find, "Find");
	 		} break;
	 		case 12:
	 		{
	 			tmp = main_toolbar->find_and_replace = create_toolbar_item(items_to_add[item_idx]);
	 			gtk_tool_item_set_tooltip_text(main_toolbar->find_and_replace, "Find and replace");
	 		} break;
	 	}
	 	gtk_toolbar_insert(GTK_TOOLBAR(main_toolbar->items_container), tmp, -1);
	}
}

void create_toolbar(GtkWidget *window, GtkWidget *main_vbox)
{
	struct toolbar main_toolbar;
	GtkWidget *toolbar_vbox = NULL;

	toolbar_vbox = gtk_vbox_new(FALSE, 0);

	main_toolbar.items_container = gtk_toolbar_new();
	gtk_toolbar_set_style(GTK_TOOLBAR(main_toolbar.items_container), GTK_TOOLBAR_ICONS);

	add_items_to_toolbar(&main_toolbar);

	gtk_box_pack_start(GTK_BOX(toolbar_vbox), main_toolbar.items_container, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(main_vbox), toolbar_vbox, FALSE, FALSE, 0);
}
