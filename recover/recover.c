#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("ERROR: Cannot open the file.\n");
        return 2;
    }

    uint8_t buffer[512];
    char filename[8];
    int file_count = 0;
    FILE *img = NULL;

    while (fread(buffer, sizeof(uint8_t), 512, card) == 512)
    {
        // Vérifier le début d'un nouveau fichier JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Fermer le fichier précédent s'il est ouvert
            if (img != NULL)
            {
                fclose(img);
            }

            // Créer un nouveau fichier pour le nouvel image
            sprintf(filename, "%03i.jpg", file_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Cannot open file: %s\n", filename);
                return 3;
            }

            file_count++;
        }

        // Écrire le buffer dans le fichier image si le fichier est ouvert
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }

    // Fermer le dernier fichier s'il est ouvert
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
