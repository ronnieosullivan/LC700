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
        for (int i = 0; i < n; ++i) {
            if (readPos == writePos) {
                writePos = read4(_buf);
                readPos = 0;
                if (writePos == 0) return i;
            }
            buf[i] = _buf[readPos++];
        }
        return n;
    }
private:
    char _buf[4];
    int writePos = 0, readPos = 0;
};