#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BYTES_PER_LINE 16

int convert_to_ibn_format(const char *input_filename)
{
    uint16_t header_size;
    uint16_t code_offset;
    char output_filename[FILENAME_MAX];
    unsigned char buffer[BYTES_PER_LINE];
    FILE *input_file;
    char *dot;
    FILE *output_file;
    size_t bytes_read;
    size_t i;

    input_file = fopen(input_filename, "rb");
    if (!input_file)
    {
        printf("Error opening input file\n");
        return 1;
    }

    if (fseek(input_file, 0x08, SEEK_SET) != 0 || 
        fread(&header_size, sizeof(header_size), 1, input_file) != 1)
    {
        printf("Error reading MZ header size\n");
        fclose(input_file);
        return 1;
    }

    code_offset = header_size * 16;

    // Seek to the start of the code section
    if (fseek(input_file, code_offset, SEEK_SET) != 0)
    {
        printf("Error seeking to code section\n");
        fclose(input_file);
        return 1;
    }

    strncpy(output_filename, input_filename, FILENAME_MAX - 5);
    output_filename[FILENAME_MAX - 5] = '\0';
    dot = strrchr(output_filename, '.');
    if (dot) 
    {
        *dot = '\0';  // Remove extension
    }
    strcat(output_filename, ".IBN");

    output_file = fopen(output_filename, "w");
    if (!output_file)
    {
        printf("Error opening output file\n");
        fclose(input_file);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, BYTES_PER_LINE, input_file)) > 0)
    {
        fprintf(output_file, "\tDB  ");
        for (i = 0; i < bytes_read; i++)
        {
            fprintf(output_file, "%03Xh", buffer[i]);
            if (i < bytes_read - 1)
            {
                fprintf(output_file, ",");
            }
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);
    printf("Conversion complete: %s\n", output_filename);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    return convert_to_ibn_format(argv[1]);
}
