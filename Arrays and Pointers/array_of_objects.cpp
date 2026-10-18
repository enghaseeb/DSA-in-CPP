#include <iostream>
#include <cstdlib>
#include <ctime>

class Car {
private:
    int xPosition;
    int yPosition;
    int speed;

public:
    // Default constructor
    Car() : xPosition(0), yPosition(0), speed(1) {}

    // Parameterized constructor
    Car(int x, int y, int s = 1) : xPosition(x), yPosition(y), speed(s) {}

    // Movement methods using current speed
    void moveForward() {
        yPosition += speed;
    }

    void moveBackwards() {
        yPosition -= speed;
    }

    void turnLeft() {
        xPosition -= speed;
    }

    void turnRight() {
        xPosition += speed;
    }

    // Speed adjustments
    void accelerate() {
        speed++;
    }

    void decelerate() {
        if (speed > 1) {
            speed--;
        }
    }

    // Coordinate getters for collision detection
    int getX() const { return xPosition; }
    int getY() const { return yPosition; }

    // Displays current attribute states
    void currState() const {
        std::cout << "Pos: (" << xPosition << ", " << yPosition << ") | Speed: " << speed;
    }
};

// Function to scan all pairs of cars for coordinate overlaps
void checkCollisions(const Car cars[], int totalCars) {
    for (int i = 0; i < totalCars; ++i) {
        for (int j = i + 1; j < totalCars; ++j) {
            if (cars[i].getX() == cars[j].getX() && cars[i].getY() == cars[j].getY()) {
                std::cout << "  [!] COLLISION DETECTED: Car " << i << " and Car " << j 
                          << " are both at (" << cars[i].getX() << ", " << cars[i].getY() << ")\n";
            }
        }
    }
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    const int NUM_CARS = 10;
    const int GRID_BOUND = 10; // Restricted range (0-9) to encourage detectable collisions
    Car cars[NUM_CARS];

    // Initialize 10 cars with random coordinates using the parameterized constructor
    std::cout << "=== Initializing Cars ===\n";
    for (int i = 0; i < NUM_CARS; ++i) {
        int randomX = rand() % GRID_BOUND;
        int randomY = rand() % GRID_BOUND;
        int randomSpeed = (rand() % 3) + 1; // Speed between 1 and 3
        
        cars[i] = Car(randomX, randomY, randomSpeed);

        std::cout << "Car " << i << " -> ";
        cars[i].currState();
        std::cout << "\n";
    }

    std::cout << "\n=== Starting Simulation (100 Iterations) ===\n";

    for (int iter = 1; iter <= 100; ++iter) {
        // 1. Randomly select car index (0 to 9)
        int carIndex = rand() % 10;

        // 2. Randomly select movement direction (1 to 4)
        int direction = (rand() % 4) + 1;

        // Switch statement to trigger direction function
        switch (direction) {
            case 1:
                cars[carIndex].moveForward();
                break;
            case 2:
                cars[carIndex].moveBackwards();
                break;
            case 3:
                cars[carIndex].turnLeft();
                break;
            case 4:
                cars[carIndex].turnRight();
                break;
        }

        // Display current update
        std::cout << "Step " << iter << " | Moved Car " << carIndex 
                  << " (Dir " << direction << ") -> ";
        cars[carIndex].currState();
        std::cout << "\n";

        // Check for collisions across all cars
        checkCollisions(cars, NUM_CARS);
    }

    return 0;
}
