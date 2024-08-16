#pragma once

#include <type_traits>
#include <memory>
#include <typeinfo>
#include "gameEntity.h"

using entityVector = std::vector<std::unique_ptr<gameEntity>>;
using entityAliasVector = std::vector<gameEntity*>;

class entityManager
{
private:
	entityVector allEntites;

	// A map to store the entities grouped by type
	// We can iterate over this to get a vector of all brick objects, then a vector of all ball objects, etc
	// The vector will contain non-owning pointers to the objects
	// Do not delete these pointers!
	// Do not use them after the objects they point to have been destroyed!
	std::map<size_t, entityAliasVector> groupedEntites;
public:
	// Function to scan all entities and clean up the destroyed ones
	void refresh();

	// Function to destroy all entities
	void clear();

	// Function to update all the entities
	void update();

	// Function to make all the entities draw themselves
	void draw(sf::RenderWindow& window);

	// Function to create an entity object of type T using args as the constructor arguments
	// We use a variadic template to pass any number of arguments
	// We use perfect forwarding to avoid any unnecessary copying of the arguments
	template<typename T,typename...Params>
	T& create(Params...args)
	{
		static_assert(std::is_base_of_v<gameEntity, T>,
			R"("T" type parameter in create() must be derived from "entity")");

		auto ptr{ std::make_unique<T>(std::forward<Params>(args)...) };

		auto ptrAlias = ptr.get();

		auto hash = typeid(T).hash_code();

		groupedEntites[hash].emplace_back(ptrAlias);

		allEntites.emplace_back(std::move(ptr));

		return *ptrAlias;
	}
	
	template<typename T>
	auto& getALL()
	{
		return groupedEntites[typeid(T).hash_code()];
	}

	template<typename T, typename processEach>
	void applyToALL(const processEach& apply)
	{
		auto& entityGroup{ getALL<T>() };

		for (auto& entity : entityGroup)
			apply(*dynamic_cast<T*>(entity));
	}
};

