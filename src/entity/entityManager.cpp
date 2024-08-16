#include "EntityManager.h"

void entityManager::refresh()
{
	// We must clean up the alias pointers first, to avoid dangling pointers
	// We simply remove them from their vector
	for (auto& [key, aliasVect] : groupedEntites)
	{
		// remove_if takes an iterator range and a predicate
		// All the elements for which the predicate is true are moved to the back
		// It returns an iterator to the first moved element
		// erase takes an iterator range and deletes all the elements in the range
		aliasVect.erase(std::remove_if(std::begin(aliasVect), std::end(aliasVect),
			[](const auto& basePtr) {
				return basePtr->isDestroyed();
			}),
			std::end(aliasVect));
	}

	// Now we can safely destroy the objects, now that there are no aliases to them
	allEntites.erase(std::remove_if(std::begin(allEntites), std::end(allEntites),
		[](const auto& basePtr) {
			return basePtr->isDestroyed();
		}),
		std::end(allEntites));
}

void entityManager::clear()
{
	groupedEntites.clear();
	allEntites.clear();
}

void entityManager::update()
{
	for (auto& entity : allEntites)
		entity->update();
}

void entityManager::draw(sf::RenderWindow& window)
{
	for (auto& entity : allEntites)
		entity->draw(window);
}
