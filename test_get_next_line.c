#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 42  // ここでBUFFER_SIZEを設定（テスト中で変更可能）

// get_next_line関数のプロトタイプ
char *get_next_line(int fd);

void test_file_read(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Failed to open file");
        return;
    }

    printf("Reading from file: %s\n", filename);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);  // 行を表示
        free(line);  // メモリ解放
    }

    close(fd);
}

void test_stdin_read()
{
    char *line;

    printf("Please enter some text (Ctrl+D to end):\n");
    while ((line = get_next_line(0)) != NULL)  // 0は標準入力のファイルディスクリプタ
    {
        printf("You entered: %s", line);
        free(line);  // メモリ解放
    }
}

void test_empty_file()
{
    int fd = open("empty.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Failed to open file");
        return;
    }

    printf("Reading from an empty file\n");
    line = get_next_line(fd);
    if (line == NULL)
    {
        printf("Correctly returned NULL for empty file\n");
    }
    free(line);  // メモリ解放

    close(fd);
}

void test_single_line_file()
{
    int fd = open("single_line.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Failed to open file");
        return;
    }

    printf("Reading from a file with a single line\n");
    line = get_next_line(fd);
    if (line)
    {
        printf("Line: %s", line);
        free(line);
    }

    close(fd);
}

void test_large_buffer_size()
{
    int fd = open("large_file.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Failed to open file");
        return;
    }

    printf("Reading from a file with large buffer size\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }

    close(fd);
}

int main()
{
    test_file_read("test.txt");
    test_stdin_read();
    test_empty_file();
    test_single_line_file();
    test_large_buffer_size();

    return 0;
}
