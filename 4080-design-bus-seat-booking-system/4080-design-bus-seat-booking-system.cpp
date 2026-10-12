class BusBooking {
    vector<vector<bool>> _seats;
    vector<vector<int>> _cost;

    int totalTime = 0;
    int minTime = 0;

public:
    BusBooking(int n)
        : _seats(n, vector<bool>(4, false)),
          _cost(n, vector<int>(4, 0)) {}

    void toggle(string seat) {
        char lbl = seat[0];
        int row = stoi(seat.substr(1)) - 1;
        int col = lbl - 'A';

        if (_seats[row][col]) {
            // Free the seat: remove its original booking cost.
            totalTime -= _cost[row][col];
            minTime--;

            _seats[row][col] = false;
            _cost[row][col] = 0;
        } else {
            // Book the seat.
            int cost = 1;

            if (col == 0 && _seats[row][1])
                cost = 3;
            else if (col == 3 && _seats[row][2])
                cost = 3;

            _seats[row][col] = true;
            _cost[row][col] = cost;

            totalTime += cost;
            minTime++;
        }
    }

    int getTotalTime() {
        return totalTime;
    }

    int getMinTime() {
        return minTime;
    }
};