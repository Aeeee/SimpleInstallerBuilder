#ifndef FILE_EXTRACTER_H
#define FILE_EXTRACTER_H

typedef enum {
    EXTRACT_SUCCESS,
    EXTRACT_OPEN_SOURCE_ERROR,
    EXTRACT_OPEN_DEST_ERROR,
    EXTRACT_READ_ERROR,
    EXTRACT_WRITE_ERROR,
    EXTRACT_DECOMPRESS_ERROR
} FILE_EXTRACT_RESULT;

FILE_EXTRACT_RESULT extract_files(const char* from_file, const char* dest_dir);

#endif