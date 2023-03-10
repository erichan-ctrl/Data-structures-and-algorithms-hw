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


double polygonArea(const Polygon& poly) {
    double area = 0;
    size_t n = poly.vertices.size();
    for (int i = 0; i < n; i++) {
        size_t j = (i + 1) % n;
        area += poly.vertices[i].x * poly.vertices[j].y;
        area -= poly.vertices[j].x * poly.vertices[i].y;
    }
    return abs(area) / 2;
}

bool isNested(const Polygon& poly1, const Polygon& poly2) {
    for (const Point& vertex : poly1.vertices) {
        bool inside = false;

        for (size_t i = 0, j = poly2.vertices.size() - 1; i < poly2.vertices.size(); j = i++) {
            if (((poly2.vertices[i].y <= vertex.y && vertex.y < poly2.vertices[j].y) ||
                 (poly2.vertices[j].y <= vertex.y && vertex.y < poly2.vertices[i].y)) &&
                (vertex.x < (poly2.vertices[j].x - poly2.vertices[i].x) * (vertex.y - poly2.vertices[i].y) / (poly2.vertices[j].y - poly2.vertices[i].y) + poly2.vertices[i].x)) {
                inside = !inside;
            }
        }

        if (inside) {
            return true;
        }
    }

    for (const Point& vertex : poly2.vertices) {
        bool inside = false;

        for (size_t i = 0, j = poly1.vertices.size() - 1; i < poly1.vertices.size(); j = i++) {
            if (((poly1.vertices[i].y <= vertex.y && vertex.y < poly1.vertices[j].y) ||
                 (poly1.vertices[j].y <= vertex.y && vertex.y < poly1.vertices[i].y)) &&
                (vertex.x < (poly1.vertices[j].x - poly1.vertices[i].x) * (vertex.y - poly1.vertices[i].y) / (poly1.vertices[j].y - poly1.vertices[i].y) + poly1.vertices[i].x)) {
                inside = !inside;
            }
        }

        if (inside) {
            return true;
        }
    }

    return false;
}



void polygonInputHandler(Polygon& poly) {
    int n;
    cout << "Enter the number of vertices of a polygon\n";
    cin >> n;
    poly.vertices.resize(n);
    cout << "Input the points of the polygon\n";
    for (int i = 0; i < n; i++) {
        cin >> poly.vertices[i].x >> poly.vertices[i].y;
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
            Polygon poly1, poly2;
            polygonInputHandler(poly1);
            polygonInputHandler(poly2);
            double area1 = polygonArea(poly1);
            double area2 = polygonArea(poly2);

            cout << "Area of polygon 1: " << area1 << endl;
            cout << "Area of polygon 2: " << area2 << endl;

            if (isNested(poly1, poly2) || isNested(poly2, poly1)) {
                cout << "Polygons are nested" << endl;
            } else {
                cout << "The polygons do not intersect" << endl;
            }
        }
    }
    return 0;
}

