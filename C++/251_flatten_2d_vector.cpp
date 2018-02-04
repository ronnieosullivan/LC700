class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin();
        end = vec2d.end();
    }

    int next() {
        return (*it)[index++];
    }

    bool hasNext() {
        while (it != end && index == (*it).size()) {
            it++;
            index = 0;
        }
        return it != end;
    }
private:
    int index = 0;
    vector<vector<int>>::iterator it, end;
};