#ifndef FILELIB_HPP
#define FILELIB_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
 * @class FileHandler
 * @brief A class to handle basic file operations such as opening, reading,
 *        writing, and managing files.
 */
class FileHandler
{
private:
    std::fstream fs; ///< File stream object used for file operations.

public:
    /**
     * @brief Opens a file with the given filename and mode.
     * @param filename The name of the file to be opened.
     * @param mode The mode in which to open the file (e.g., read, write).
     * @return True if the file is successfully opened; throws an exception if it fails.
     * @throws std::runtime_error if the file cannot be opened.
     */
    bool open(std::string filename, std::ios_base::openmode mode)
    {
        fs.open(filename, mode);
        if (!fs.is_open())
        {
            throw std::runtime_error("Failed to open file: " + filename + ", are you sure this file exists?");
        }
        return fs.is_open();
    }

    /**
     * @brief Closes the currently opened file.
     * @return True if the file is successfully closed; false if the file was not open.
     */
    bool close()
    {
        if (fs.is_open())
        {
            fs.close();
            return true;
        }
        return false;
    }

    /**
     * @brief Reads a single line from the file.
     * @return The line read from the file or an empty string if reading fails.
     */
    std::string readline()
    {
        std::string line;
        return (fs.is_open() && std::getline(fs, line)) ? line : "";
    }

    /**
     * @brief Reads all lines from the file and returns them as a vector of strings.
     * @return A vector containing all lines read from the file.
     */
    std::vector<std::string> readlines()
    {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(fs, line))
        {
            lines.push_back(line);
        }
        return lines;
    }

    /**
     * @brief Counts the number of lines in the file.
     * @return The number of lines in the file.
     */
    int count_lines();

    /**
     * @brief Writes a string to the currently opened file.
     * @param data The string to write to the file.
     * @return True if the write operation was successful; false otherwise.
     */
    bool write(const std::string &data);

    /**
     * @brief Writes a list of strings to the currently opened file.
     * @param lines A vector containing the strings to write to the file.
     * @return True if the write operation was successful; false otherwise.
     */
    bool writelines(const std::vector<std::string> &lines);

    /**
     * @brief Moves the file cursor to a specific position.
     * @param position The position to move the file cursor to.
     */
    void seek(int position);

    /**
     * @brief Returns the current position of the file cursor.
     * @return The current position of the file cursor.
     */
    int tell();

    /**
     * @brief Resizes the file to the specified size.
     * @param size The new size for the file.
     * @return True if the resize operation was successful; false otherwise.
     */
    bool truncate(size_t size);

    /**
     * @brief Flushes the output buffer to the file.
     */
    void flush();

    /**
     * @brief Reads a specified number of bytes from the file.
     * @param bytes The number of bytes to read.
     * @return A string containing the bytes read from the file.
     */
    std::string read(size_t bytes);

    /**
     * @brief Checks if a file exists at the specified path.
     * @param filepath The path to the file.
     * @return True if the file exists; false otherwise.
     */
    static bool exists(const std::string &filepath);

    /**
     * @brief Copies the content of the currently opened file to another file.
     * @param destination The path of the destination file.
     * @return True if the copy operation was successful; false otherwise.
     */
    bool copy(const std::string &destination);

    /**
     * @brief Deletes the current file from the filesystem.
     * @return True if the file was successfully deleted; false otherwise.
     */
    bool delete_file();

    /**
     * @brief Renames the current file.
     * @param new_name The new name for the file.
     * @return True if the rename operation was successful; false otherwise.
     */
    bool rename(const std::string &new_name);

    /**
     * @brief Gets the size of the file in bytes.
     * @return The size of the file in bytes.
     */
    size_t get_size() const;

    /**
     * @brief Opens a file in append mode to add content.
     * @param data The string to append to the file.
     * @return True if the append operation was successful; false otherwise.
     */
    bool append(const std::string &data);

    /**
     * @brief Reads from the file until a specified delimiter is encountered.
     * @param delimiter The character to stop reading at.
     * @return A string containing the read data up to the delimiter.
     */
    std::string read_until(char delimiter);

    /**
     * @brief Retrieves the length of each line in the file.
     * @return A vector containing the lengths of each line.
     */
    std::vector<int> get_each_lines_length();
};

#endif
