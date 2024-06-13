#pragma once
#include <vector>
#include <string>
#include "visitor.h"
#ifndef VECTOR_SERVICE
#define VECTOR_SERVICE

using namespace std;

// Функция для установки списка всех посетителей
void setAllVisitors(const vector<Visitor>& visitors);

// Функция для получения всех элементов списка
vector<Visitor>& getAllVisitors();

// Функция для получения элемента по номеру документа
//Visitor& getVisitorByDocumentNumber(const string& documentNumber);

// Функция для получения элемента по идентификатору
Visitor& getVisitorById(const int& visitorId);

// Функция для вывода на консоль всех элементов списка
void printVisitorList();

// Функция для добавления нового элемента в список
void createVisitor(Visitor& newVisitor);

// Функция для редактирования элемента по идентификатору
void updateVisitor(const int& visitorId, const Visitor& updatedVisitor);

// Функция для удаления элемента по идентификатору
void deleteVisitor(const int& visitorId);

#endif