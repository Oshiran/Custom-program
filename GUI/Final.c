#include <gtk/gtk.h>

static void activate(GTKApplication *app, gpointer user_data)
{
    GTkWidget *window;
    GtkWidget *spin_button;
    
    //* Window Creation
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 1080 , 720);

    //* Button
    spin_button = 

    //* Display all widgets
    gtk_widget_show_all (window);
}

main (int argc, char **argv)
{
    GtkApplication *app;
    int status;
    
    app= gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;    
}