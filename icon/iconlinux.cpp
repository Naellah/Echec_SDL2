

int main(int argc, char *argv[])
{
    // Initialiser GTK+
    gtk_init(&argc, &argv);

    // Créer la fenêtre principale de l'application
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Charger l'icône à partir d'un fichier
    GdkPixbuf *icon = gdk_pixbuf_new_from_file("icone.png", NULL);

    // Ajouter l'icône à la fenêtre principale
    gtk_window_set#include <gtk/gtk.h>_icon(GTK_WINDOW(window), icon);

    // Afficher la fenêtre
    gtk_widget_show_all(window);

    // Lancer la boucle principale de GTK+
    gtk_main();

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


    return 0;
}
