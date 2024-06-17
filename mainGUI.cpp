#include <SFML/Graphics.hpp>
#include "node.hpp"
#include <iostream>
#include <string>
#include <type_traits> // For std::is_same
#include <vector>

const float NODE_RADIUS = 20.0f;
using namespace std;

template <typename T>
void drawNode(sf::RenderWindow &window, Node<T> node, float x, float y, sf::Font &font)
{
    sf::CircleShape shape(NODE_RADIUS);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(x - NODE_RADIUS, y - NODE_RADIUS); // Center the circle

    // Calculate text position to center it inside the circle
    sf::Text text;

    if constexpr (std::is_same<T, std::string>::value)
    {
        text.setString(node.get_value());
    }
    else
    {
        text.setString(std::to_string(node.get_value()));
    }

    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);

    // Set maximum width to fit inside the circle
    float maxWidth = 2 * NODE_RADIUS * 0.8f; // 80% of circle diameter
    sf::FloatRect textRect = text.getLocalBounds();

    // Check if text width exceeds maxWidth
    if (textRect.width > maxWidth)
    {
        // Calculate scaling factor
        float scale = maxWidth / textRect.width;
        text.setScale(scale, scale);
        textRect = text.getLocalBounds(); // Update text bounds after scaling

        // Truncate text with ellipsis if still too wide
        if (textRect.width > maxWidth)
        {
            // Truncate string and append "..."
            std::string displayText;
            if constexpr (std::is_same<T, std::string>::value)
            {
                displayText = node.get_value();
            }
            else
            {
                displayText = std::to_string(node.get_value());
            }

            while (textRect.width > maxWidth && displayText.size() > 3)
            {
                displayText.resize(displayText.size() - 1);
                displayText.resize(displayText.size() - 1);
                displayText += "...";
                text.setString(displayText);
                textRect = text.getLocalBounds(); // Re-calculate bounds
            }
        }
    }

    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(shape.getPosition().x + NODE_RADIUS, shape.getPosition().y + NODE_RADIUS);

    window.draw(shape);
    window.draw(text);
}

int main()
{
    Node<string> root_node = Node<string>("root");
    Node<int> n1 = Node<int>(1);

    sf::RenderWindow window(sf::VideoMode(500, 500), "EX4-TREE");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font file 'arial.ttf'" << std::endl;
        return 1; // Exit the program with an error code
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawNode(window, root_node, 250, 250, font); // Pass font as a parameter
        
        window.display();
    }

    return 0;
}
