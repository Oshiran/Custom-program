#include <gtk/gtk.h>

static void menu_item_selected(GtkWidget *widget, gpointer data) {
    g_print("Selected: %s\n", (char *)data);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *menu_item;
    const char *menu_items[] = {"Main Dish", "Burger", "Sides", "Drinks", "Finish Order"};

    // Set the padding value
    int padding = 100;

    // Calculate the adjusted window size
    int window_width = 1080 - 2 * padding;
    int window_height = 720 - 2 * padding;

    // Create the main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Menu Example");
    gtk_window_set_default_size(GTK_WINDOW(window), window_width, window_height);

    // Create a grid to hold the menu items with padding
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_container_set_border_width(GTK_CONTAINER(grid), padding);

    // Create menu items
    for (int i = 0; i < G_N_ELEMENTS(menu_items); ++i) {
        menu_item = gtk_button_new_with_label(menu_items[i]);
        g_signal_connect(menu_item, "clicked", G_CALLBACK(menu_item_selected), (gpointer)menu_items[i]);

        // Add the menu item to the grid with additional padding
        int row = i / 2;
        int col = i % 2;
        gtk_grid_attach(GTK_GRID(grid), menu_item, col, row, 1, 1);
        gtk_widget_set_margin_start(menu_item, 10);  // Adjust padding as needed
        gtk_widget_set_margin_end(menu_item, 10);    // Adjust padding as needed
        gtk_widget_set_margin_top(menu_item, 10);     // Adjust padding as needed
        gtk_widget_set_margin_bottom(menu_item, 10);  // Adjust padding as needed
    }

    // Show all the widgets
    gtk_widget_show_all(window);
}

int main(int argc, char *argv[]) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
