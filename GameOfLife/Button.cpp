#include "Button.h"

Button::Button(std::string text, sf::Vector2f position) : m_buttonText(text), m_buttonPositon(position)
{
}

void Button::Render(sf::RenderWindow &window)
{
    if (!font.loadFromFile("Data/Fonts/basic_font.ttf"))
        return;

    //button
    button.setPosition(m_buttonPositon);
    button.setSize(m_buttonSize);
    button.setOrigin(button.getSize().x / 2, button.getSize().y / 2);
    button.setFillColor(m_buttonColor);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(1);

    //text
    text.setColor(sf::Color::Black);
    text.setPosition(m_buttonPositon);
    text.setString(m_buttonText);
    text.setFont(font);
    text.setCharacterSize(20);
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);

    //draw
    window.draw(button);
    window.draw(text);
}
