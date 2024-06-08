#pragma once
#include <vector>
#include <string>
#include "visitor.h"
#ifndef VECTOR_SERVICE
#define VECTOR_SERVICE

using namespace std;

// Функция для получения всех элементов списка
vector<Visitor> getAllVisitors();

// Функция для вывода на консоль всех элементов списка
void printVisitorList(const vector<Visitor>& visitors);

// Функция для добавления нового элемента в список
void addVisitor(vector<Visitor>& visitors, const Visitor& newVisitor);

// Функция для редактирования элемента по ключу documentNumber
void editVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber, const Visitor& updatedVisitor);

// Функция для удаления элемента по ключу documentNumber
//void removeVisitorByDocumentNumber(vector<Visitor>& visitors, const string& documentNumber);

#endif