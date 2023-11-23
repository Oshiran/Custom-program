#include <gtk/gtk.h>

static void menu_item_selected(GtkWidget *widget, gpointer data) {
    g_print("Selected: %s\n", (char *)data);
}

static void spin_button_changed(GtkSpinButton *spin_button, gpointer user_data) {
    int value = gtk_spin_button_get_value_as_int(spin_button);
    char buffer[20];
    sprintf(buffer, "Selected: %d", value);
    gtk_label_set_text(GTK_LABEL(user_data), buffer);
}

static void confirmation_button_clicked(GtkButton *button, gpointer user_data) {
    int selected_number = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(user_data));
    g_print("Confirmation Button Pressed! Selected Number: %d\n", selected_number);

    // Store the selected number in the variable I
    // You can declare this variable at the beginning of your file
    // e.g., int I;
    // Then assign the value here:
    // I = selected_number;
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *menu_item;
    GtkWidget *spin_button;
    GtkWidget *label;
    GtkWidget *confirmation_button;

    // Create the main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Menu Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Create a vertical box to hold the widgets
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create menu items
    const char *menu_items[] = {"Main Dish", "Burger", "Sides", "Drinks", "Finish Order"};
    for (int i = 0; i < G_N_ELEMENTS(menu_items); ++i) {
        menu_item = gtk_button_new_with_label(menu_items[i]);
        g_signal_connect(menu_item, "clicked", G_CALLBACK(menu_item_selected), (gpointer)menu_items[i]);
        gtk_box_pack_start(GTK_BOX(vbox), menu_item, TRUE, TRUE, 0);
    }

    // Create a spin button for numeric input
    spin_button = gtk_spin_button_new_with_range(1, 10, 1);
    gtk_box_pack_start(GTK_BOX(vbox), spin_button, TRUE, TRUE, 0);

    // Create a label to display the selected number
    label = gtk_label_new("Selected: 1");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    // Create a confirmation button
    confirmation_button = gtk_button_new_with_label("Confirm");
    gtk_box_pack_start(GTK_BOX(vbox), confirmation_button, TRUE, TRUE, 0);

    // Connect the spin button signal to update the label
    g_signal_connect(spin_button, "value-changed", G_CALLBACK(spin_button_changed), label);

    // Connect the confirmation button signal to store the selected number
    g_signal_connect(confirmation_button, "clicked", G_CALLBACK(confirmation_button_clicked), spin_button);

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
