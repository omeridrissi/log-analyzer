#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char **argv) {
    
    if (argc <= 1) {
        printf("Usage: log-analyzer [filename]\n");
        exit(EXIT_FAILURE);
    }

    // Open file
    char *file_name = argv[1];
    printf("Opening file: %s\n", file_name);
    FILE *fp = fopen(file_name, "r");

    if (fp == NULL) {
        perror(file_name);
        return EXIT_FAILURE;
    }

    // Figure out file size
    fseek(fp, 0L, SEEK_END);
    size_t file_size = (size_t)ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory for entire file
    char* data_ptr;
    data_ptr = (char*)malloc(sizeof(char)*file_size);

    // Read file contents to memory
    if (fread(data_ptr, sizeof(char), file_size, fp) != file_size) {
        perror(file_name);
        free(data_ptr);
        fclose(fp);
        return EXIT_FAILURE;
    }
    
    long info_log_count = count_string("INFO", data_ptr);
    long warning_log_count = count_string("WARNING", data_ptr);
    long error_log_count = count_string("ERROR", data_ptr);
    long debug_log_count = count_string("DEBUG", data_ptr);
    long idle_log_count = count_string("IDLE", data_ptr);

    printf("INFO log count: %ld\n", info_log_count);
    printf("WARNING log count: %ld\n", warning_log_count);
    printf("ERROR log count: %ld\n", error_log_count);
    printf("DEBUG log count: %ld\n", debug_log_count);
    printf("IDLE log count: %ld\n", idle_log_count);

    free(data_ptr);
    fclose(fp);

    return 0;
}
