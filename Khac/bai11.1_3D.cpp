// jeju_circles_sfml.cpp
// Ve chu "JEJU" bang 500 vong tron kieu bubble letter, dung thu vien SFML.
//
// Cai SFML (Ubuntu/Debian):  sudo apt install libsfml-dev
// Bien dich:                 g++ -std=c++17 -O2 jeju_circles_sfml.cpp -o jeju_circles \
//                             -lsfml-graphics -lsfml-window -lsfml-system
// Chay:                      ./jeju_circles

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
#include <random>
#include <algorithm>

// ---- Font ma tran diem 5 cot x 7 hang cho tung chu cai ----
static const std::map<char, std::vector<std::string>> FONT = {
    {'J', {"00111", "00010", "00010", "00010", "00010", "10010", "01100"}},
    {'E', {"11111", "10000", "10000", "11110", "10000", "10000", "11111"}},
    {'U', {"10001", "10001", "10001", "10001", "10001", "10001", "01110"}}};

struct Circle
{
    float x, y, r;
};

int main()
{
    const std::string WORD = "JEJU";
    const int TOTAL_CIRCLES = 500;
    const float CELL = 40.f;
    const int LETTER_COLS = 5;
    const int LETTER_ROWS = 7;
    const int LETTER_GAP = 2;

    // 1. Thu thap toa do cac o "1" cua ca tu, theo he toa do luoi toan cuc
    std::vector<sf::Vector2f> cells;
    int colOffset = 0;
    for (char ch : WORD)
    {
        const auto &pattern = FONT.at(ch);
        for (int r = 0; r < LETTER_ROWS; r++)
        {
            for (int c = 0; c < LETTER_COLS; c++)
            {
                if (pattern[r][c] == '1')
                {
                    cells.push_back({(colOffset + c) * CELL + CELL / 2.f,
                                     r * CELL + CELL / 2.f});
                }
            }
        }
        colOffset += LETTER_COLS + LETTER_GAP;
    }

    int width = static_cast<int>(colOffset * CELL) + 80;
    int height = static_cast<int>(LETTER_ROWS * CELL) + 120;

    // 2. Sinh 500 vong tron: chon ngau nhien 1 o, them nhieu (jitter) + ban kinh ngau nhien
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> pickCell(0, (int)cells.size() - 1);
    std::uniform_real_distribution<float> jitter(-8.f, 8.f);
    std::uniform_real_distribution<float> radiusDist(6.f, 16.f);

    std::vector<Circle> circles;
    circles.reserve(TOTAL_CIRCLES);
    for (int i = 0; i < TOTAL_CIRCLES; i++)
    {
        sf::Vector2f p = cells[pickCell(rng)];
        circles.push_back({p.x + jitter(rng) + 40.f,
                           p.y + jitter(rng) + 60.f,
                           radiusDist(rng)});
    }

    // Ve vong tron lon truoc, nho ve sau de trong tu nhien hon
    std::sort(circles.begin(), circles.end(), [](const Circle &a, const Circle &b)
              { return a.r > b.r; });

    // 3. Mo cua so va ve
    sf::RenderWindow window(sf::VideoMode(width, height), "JEJU - 500 vong tron");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Nhan phim R de sinh lai bo cuc vong tron ngau nhien
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
            {
                for (auto &c : circles)
                {
                    sf::Vector2f p = cells[pickCell(rng)];
                    c.x = p.x + jitter(rng) + 40.f;
                    c.y = p.y + jitter(rng) + 60.f;
                    c.r = radiusDist(rng);
                }
                std::sort(circles.begin(), circles.end(), [](const Circle &a, const Circle &b)
                          { return a.r > b.r; });
            }
        }

        window.clear(sf::Color::White);

        for (const auto &c : circles)
        {
            sf::CircleShape shape(c.r);
            shape.setOrigin(c.r, c.r);
            shape.setPosition(c.x, c.y);
            shape.setFillColor(sf::Color::White);
            shape.setOutlineThickness(1.6f);
            shape.setOutlineColor(sf::Color(26, 26, 26));
            window.draw(shape);

            // cham sang nho tao hieu ung bubble
            float hr = c.r * 0.18f;
            sf::CircleShape highlight(hr);
            highlight.setOrigin(hr, hr);
            highlight.setPosition(c.x - c.r * 0.3f, c.y - c.r * 0.3f);
            highlight.setFillColor(sf::Color(0, 0, 0, 90));
            window.draw(highlight);
        }

        window.display();
    }

    return 0;
}