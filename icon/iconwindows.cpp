#include <Windows.h>

int main()
{
    // Charger l'icône à partir d'un fichier
    HICON hIcon = (HICON)LoadImageW(NULL, L"logo.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);

    // Récupérer le handle de la fenêtre principale de l'application
    HWND hWnd = GetActiveWindow();

    // Ajouter l'icône à la classe de fenêtre
    SetClassLongPtr(hWnd, GCLP_HICON, (LONG_PTR)hIcon);

    return 0;
}
