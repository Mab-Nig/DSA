#include <iostream>
#include <vector>

class Solution
{
public:
    int cherryPickup(std::vector<std::vector<int>> &grid)
    {
        return cherry_pickup(grid);
    }

private:
#define f(i, j, k) f[(i) * n * n + (j) * n + (k)]

    int cherry_pickup(std::vector<std::vector<int>> &grid)
    {
        m = grid.size();
        n = grid.front().size();
        f.resize(m * n * n, -1);

        f(0, 0, n - 1) = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i)
        {
            for (int x = 0; x < n - 1; ++x)
            {
                for (int y = x + 1; y < n; ++y)
                {
                    for (int prev_x = x - 1; prev_x <= x + 1; ++prev_x)
                    {
                        for (int prev_y = y - 1; prev_y <= y + 1; ++prev_y)
                        {
                            if (!is_inside(i - 1, prev_x)
                                || !is_inside(i - 1, prev_y))
                            {
                                continue;
                            }

                            if (prev_x >= prev_y
                                || f(i - 1, prev_x, prev_y) == -1)
                            {
                                continue;
                            }

                            f(i, x, y) =
                                std::max(f(i, x, y), f(i - 1, prev_x, prev_y));
                        }
                    }
                    if (f(i, x, y) != -1)
                    {
                        f(i, x, y) += grid[i][x] + grid[i][y];
                    }
                }
            }
        }

        int result = 0;
        for (int x = 0; x < n - 1; ++x)
        {
            for (int y = x + 1; y < n; ++y)
            {
                result = std::max(result, f(m - 1, x, y));
            }
        }
        return result;
    }

    bool is_inside(int x, int y)
    {
        return 0 <= x && x < m && 0 <= y && y < n;
    }

    void print_f()
    {
        for (int i = 0; i < m; ++i)
        {
            for (int x = 0; x < n - 1; ++x)
            {
                for (int y = x + 1; y < n; ++y)
                {
                    std::cerr << f(i, x, y) << ' ';
                }
                std::cerr << '\n';
            }
            std::cerr << '\n';
        }
        std::cerr << '\n';
    }

    int m, n;
    std::vector<int> f;

    friend int main(int argc, char **argv);

#undef f
};

int main(int argc, char **argv)
{
    std::vector<std::vector<int>> grid = {
        {0, 8, 7,  10, 9, 10, 0, 9,  6 },
        {8, 7, 10, 8,  7, 4,  9, 6,  10},
        {8, 1, 1,  5,  1, 5,  5, 1,  2 },
        {9, 4, 10, 8,  8, 1,  9, 5,  0 },
        {4, 3, 6,  10, 9, 2,  4, 8,  10},
        {7, 3, 2,  8,  3, 3,  5, 9,  8 },
        {1, 2, 6,  5,  6, 2,  0, 10, 0 }
    };
    Solution solution;
    std::cout << solution.cherryPickup(grid) << '\n';
    solution.print_f();
}
