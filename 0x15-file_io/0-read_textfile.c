#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters) {
    if (!filename) {
        return 0;
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return 0;
    }

    char *buf = malloc(sizeof(char) * letters);
    if (!buf) {
        close(fd);
        return 0;
    }

    ssize_t bytes_read = read(fd, buf, letters);
    if (bytes_read == -1) {
        free(buf);
        close(fd);
        return 0;
    }

    ssize_t bytes_written = write(STDOUT_FILENO, buf, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read) {
        free(buf);
        close(fd);
        return 0;
    }

    free(buf);
    close(fd);
    return bytes_read;
}
