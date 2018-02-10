class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        score = 0;
        pos.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = pos.front(), tail = pos.back(); pos.pop_back();
        if (direction == "U") --head.first;
        else if (direction == "L") --head.second;
        else if (direction == "R") ++head.second;
        else if (direction == "D") ++head.first;
        if (count(pos.begin(), pos.end(), head) || head.first < 0 || head.first >= height || head.second < 0 || head.second >= width) {
            return -1;
        }
        pos.push_front(head);
        if (!food.empty() && head == food.front()) {
            food.erase(food.begin());
            pos.push_back(tail);
            ++score;
        }
        return score;
    }
private:
    int width, height, score;
    deque<pair<int, int>> pos;
    vector<pair<int, int>> food;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */