#include "Car.h"
#include <iostream>

int Car::current_id = 0;

// Standard constructor
Car::Car(int year, std::string model){
	this->id = Car::current_id++;
	this->year = year;
	this->model = model;
}

// Constructor for copying off another car
Car::Car(const Car &other) {
	this->id = Car::current_id++;
	this->year = other.year;
	this->model = other.model;
	this->records = other.records;
}

int Car::getId() const {
	return this->id;
}

void Car::setYear(int year){
	this->year = year;
}

int Car::getYear() const {
	return year;
}

void Car::setModel(std::string model){
	this->model = model;
}

std::string Car::getModel() const {
	return model;
}

std::vector<ServiceRecord> Car::getRecords() const {
	return records;
}

void Car::addRecord(ServiceRecord record){
	records.push_back(record);
}

bool operator<(const Car& other) {
	return this->records < other.records;
}

