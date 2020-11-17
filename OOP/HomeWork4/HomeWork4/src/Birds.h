#pragma once
#include <iostream>

class Bird
{
public:
	Bird(std::string feathers,std::string type = "") : feathers(feathers), type(type) {}
	virtual void fly() = 0;
	bool LayEggs() { return this->layEggs; }
	std::string FeatherColor() { return this->feathers; }
	std::string GetType() { return this->type; }
protected:
	std::string type;
	std::string feathers;
	bool layEggs = true;
};
//----
class FlyingBird : public Bird
{
public:
	FlyingBird(std::string feathers,std::string type) : Bird(feathers,type) {}
	virtual void fly() override { std::cout << "fly" << std::endl; }
};
class NonFlyingBird : public Bird
{
public:
	NonFlyingBird(std::string feathers, std::string type) : Bird(feathers, type) {}
	virtual void fly() override { std::cout << "walk" << std::endl; }
};
//----
class Eagle : public FlyingBird
{
public:
	
	Eagle(std::string feathers = "black", std::string type = "Eagle") : FlyingBird(feathers,type) {}
	virtual void fly() override { std::cout << "fly and dance" << std::endl; }
};
class Swallow : public FlyingBird
{
public:
	
	Swallow(std::string feathers = "brown", std::string type = "Swallow") : FlyingBird(feathers, type) {}
	virtual void fly() override { std::cout << "fly and bounce" << std::endl; }
};
class Penguin : public NonFlyingBird
{
public:
	
	Penguin(std::string feathers = "green", std::string type = "Penguin") : NonFlyingBird(feathers, type) {}
	virtual void fly() override { std::cout << "walk and jump" << std::endl; }
};
class Chicken : public NonFlyingBird
{
public:
	
	Chicken(std::string feathers = "white", std::string type = "Chicken") : NonFlyingBird(feathers, type) {}
	virtual void fly() override { std::cout << "walk and yummy" << std::endl; }
};