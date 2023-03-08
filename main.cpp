#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

const int rows = 100;
const int cols = 100;

void arrayOutputHandler(int arr[][cols], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void arrayOutputHandler(int **arr, int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void arrayInputHandler(int arr[][cols], int row, int col, int option) {
    if (option == 1) {
        cout << "Input array, use enter to switch to new row\n";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> arr[i][j];
            }
        }
    } else if (option == 2) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                arr[i][j] = rand() % 100 + 1;
            }
        }
    }
}

void arrayInputHandler(int **arr, int row, int col, int option) {
    if (option == 1) {
        cout << "Input array, use enter to switch to new row\n";
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                cin >> arr[i][j];
            }
        }
    } else if (option == 2) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                arr[i][j] = rand() % 100 + 1;
            }
        }
    }
}

void matrixTransposition(int arr[][cols], int row, int col) {
    int t;
    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < col; ++j) {
            t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}

void matrixTransposition(int **arr, int row, int col) {
    int t;
    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < col; ++j) {
            t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}

struct Point {
    double x, y;
};
struct Polygon {
    vector <Point> vertices;
};
bool is_inside_polygon(const Point &p, const Polygon &polygon) {
    int n = polygon.vertices.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if ((polygon.vertices[i].y > p.y) != (polygon.vertices[j].y > p.y) &&
            p.x < (polygon.vertices[j].x - polygon.vertices[i].x) * (p.y - polygon.vertices[i].y) /
                  (polygon.vertices[j].y - polygon.vertices[i].y) + polygon.vertices[i].x) {
            inside = !inside;
        }
    }
}

double GaussianArea(const Polygon &polygon) {
    double result = 0.0;
    int n = polygon.vertices.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        result += polygon.vertices[i].x * polygon.vertices[j].y - polygon.vertices[j].x * polygon.vertices[i].y;
    }
    return abs(result) / 2.0;
}

bool is_nested(const Polygon& polygon1, const Polygon& polygon2) {
    // Find the smallest enclosing rectangles for each polygon.
    double min_x1 = polygon1.vertices[0].x, max_x1 = polygon1.vertices[0].x, min_y1 = polygon1.vertices[0].y, max_y1 = polygon1.vertices[0].y;
    for (const auto& p : polygon1.vertices) {
        min_x1 = min(min_x1, p.x);
        max_x1 = max(max_x1, p.x);
        min_y1 = min(min_y1, p.y);
        max_y1 = max(max_y1, p.y);
    }
    double min_x2 = polygon2.vertices[0].x, max_x2 = polygon2.vertices[0].x, min_y2 = polygon2.vertices[0].y, max_y2 = polygon2.vertices[0].y;
    for (const auto& p : polygon2.vertices) {
        min_x2 = min(min_x2, p.x);
        max_x2 = max(max_x2, p.x);
        min_y2 = min(min_y2, p.y);
        max_y2 = max(max_y2, p.y);
    }

    // Check if the rectangles intersect.
    if (max_x1 < min_x2 || max_x2 < min_x1 || max_y1 < min_y2 || max_y2 < min_y1) {
        return false;
    }

    // Check if one polygon is completely contained within the other.
    bool polygon1_inside_polygon2 = true;
    for (const auto& p : polygon1.vertices) {
        if (!is_inside_polygon(p, polygon2)) {
            polygon1_inside_polygon2 = false;
            break;
        }
    }
    if (polygon1_inside_polygon2) {
        return true;
    }

    bool polygon2_inside_polygon1 = true;
    for (const auto& p : polygon2.vertices) {
        if (!is_inside_polygon(p, polygon1)) {
            polygon2_inside_polygon1 = false;
            break;
        }
    }
    if (polygon2_inside_polygon1) {
        return true;
    }

    return false;
}

void pointsInputHandler(double &points, int pointsNumber) {
    for (size_t i = 0; i < pointsNumber; ++i) {
        Point p{};
        cout << "Input x, y of point number " << i + 1 << "\n";
        cin >> p.x >> p.y;
        points.push_back(p);
    }
}
int main() {
    int taskOption = 0, n = 0;
    while (taskOption != 3) {
        cout << "Select the task \n"
                "1 - A matrix of size n*n is given. Transpose the matrices.\n"
                "2 - Two convex polygons in the plane are given by the coordinates of the vertices in the order of the boundary.\n Determine the area of the polygon and determine if they are nested. \n"
                "3 - exit \n";
        cin >> taskOption;

        if (taskOption == 1) {
            cout << "Select the type of an array: \n"
                    "1 - static \n"
                    "2 - dynamic \n";
            cin >> n;
            if (n == 1) {
                int option;
                int arr[rows][cols];
                int row, col;
                cout << "Enter the number of rows and columns: \n";
                cin >> row >> col;
                cout << "Select the option of input: \n"
                        "1 - Manual\n"
                        "2 - Random\n";
                cin >> option;
                if (option == 1 || option == 2) {
                    arrayInputHandler(arr, row, col, option);
                    cout << "Current matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                    matrixTransposition(arr, row, col);
                    cout << "Transposed matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                } else {
                    cout << "There is no such option \n";
                }
            } else if (n == 2) {
                int row, col, option = 0;
                cout << "Enter the number of rows and columns:\n";
                cin >> row >> col;
                int **arr = new int *[row];
                for (int i = 0; i < row; ++i) {
                    arr[i] = new int[cols];
                }
                cout << "Select the method of input: \n"
                        "1 - Manual\n"
                        "2 - Random\n";
                cin >> option;
                if (option == 1 || option == 2) {
                    arrayInputHandler(arr, row, col, option);
                    cout << "Current matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                    matrixTransposition(arr, row, col);
                    cout << "Transposed matrix is:\n";
                    arrayOutputHandler(arr, row, col);
                } else {
                    cout << "There is no such option \n";
                }
                for (int i = 0; i < row; ++i) {
                    delete[] arr[i];
                }
                delete[] arr;
            }
        }
        if (taskOption == 2) {
            // Define the polygons.
            Polygon polygon1{{{0, 0}, {2, 0}, {2, 2}, {0, 2}}};
            Polygon polygon2{{{1, 1}, {3, 1}, {3, 3}, {1, 3}}};

            // Calculate the areas of the polygons.
            double area1 = GaussianArea(polygon1);
            double area2 = GaussianArea(polygon2);

            // Determine if the polygons are nested.
            bool nested = is_nested(polygon1, polygon2);

            // Print the results.
            cout << "Polygon 1 area: " << area1 << endl;
            cout << "Polygon 2 area: " << area2 << endl;
            if (nested) {
                cout << "The polygons are nested." << endl;
            } else {
                cout << "The polygons are not nested." << endl;
            }
        }
    }
    return 0;
}

