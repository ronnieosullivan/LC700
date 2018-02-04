// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        char buffer[4];
        int readPos = 0, writePos = 0;
        for (int i = 0; i < n; i++) {
            if (readPos == writePos) {
                writePos = read4(buffer);
                if (writePos == 0) return i;
                readPos = 0;
            }
            buf[i] = buffer[readPos];
            readPos++;
        }
        return n;
    }
};
