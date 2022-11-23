#pragma once
#include <SFML/Graphics.hpp>
#include <utility>

class Entity : public sf::Drawable
{
public:

	//Non copyable or assignable
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;

	Entity();
	virtual ~Entity();

	template<typename ... Args>
	void setPosition(Args&& ... args);

	const sf::Vector2f& getPosition()const;

	virtual void update(sf::Time deltaTime) = 0;

protected:
	sf::Sprite _sprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

template<typename ...Args>
inline void Entity::setPosition(Args && ...args)
{
	_sprite.setPosition(std::forward<Args>(args)...);
}
