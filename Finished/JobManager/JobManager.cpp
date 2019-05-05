#include "JobManager.h"
#include <iostream>

Job* divide_from(Job*& head) {
  Job *position, *midpoint, *second_half;
  if ((midpoint = head) == NULL) return NULL;
  position = midpoint->getNext();
  while (position != NULL) {
    position = position->getNext();
    if (position != NULL) {
      midpoint = midpoint->getNext();
      position = position->getNext();
    }
  }
  second_half = midpoint->getNext();
  midpoint->setNext(NULL);
  return second_half;
}

Job* merge(Job* first, Job* second, bool (*compare)(Job* a, Job* b)) {
  Job* last_sorted;
  Job combined;
  last_sorted = &combined;
  while (first != NULL && second != NULL) {
    if (compare(first, second)) {
      last_sorted->setNext(first);
      last_sorted = last_sorted->getNext();
      first = first->getNext();
    } else {
      last_sorted->setNext(second);
      last_sorted = last_sorted->getNext();
      second = second->getNext();
    }
  }
  if (first != NULL)
    last_sorted->setNext(first);
  else
    last_sorted->setNext(second);
  return combined.getNext();
}

void mergeSort(Job*& head, bool (*compare)(Job* a, Job* b)) {
  if (head != NULL && head->getNext() != NULL) {
    Job* second_half = divide_from(head);
    mergeSort(head, compare);
    mergeSort(second_half, compare);
    head = merge(head, second_half, compare);
  }
}

JobManager::JobManager() : jobFrontPointer{NULL} {}
JobManager::~JobManager() { clear(); }

JobManager* JobManager::instance = NULL;
JobManager* JobManager::getInstance() {
  if (instance == NULL) instance = new JobManager;
  return instance;
}
bool JobManager::deleteInstance() {
  if (instance == NULL) return false;
  delete instance;
  instance = NULL;
  return true;
}

void JobManager::addJob(int priority) {
  if (jobFrontPointer == NULL) {
    jobFrontPointer = new Job{priority};
    return;
  }
  Job* newJob = new Job{priority};
  Job* jobPtr = jobFrontPointer;
  while (jobPtr->getNext() != NULL) {
    jobPtr = jobPtr->getNext();
  }
  jobPtr->setNext(newJob);
}

void JobManager::finishOneJob() {
  Job* ptr = jobFrontPointer;
  if (ptr == NULL) return;
  jobFrontPointer = jobFrontPointer->getNext();
  delete ptr;
}
bool comp(Job* a, Job* b) {
  if (a->getPriority() > b->getPriority()) return true;
  if (a->getPriority() < b->getPriority()) return false;
  if (a->getId() < b->getId()) return true;
  return false;
}
void JobManager::sortJob() { mergeSort(jobFrontPointer, comp); }

void JobManager::printJob() {
  Job* p = jobFrontPointer;
  if (p == NULL) {
    std::cout << "empty!" << std::endl;
    return;
  }
  std::cout << p->toString();
  p = p->getNext();
  while (p != NULL) {
    std::cout << "->" << p->toString();
    p = p->getNext();
  }
  std::cout << std::endl;
}
int JobManager::getNumOfJob() {
  int total = 0;
  Job* p = jobFrontPointer;
  while (p != NULL) {
    total++;
    p = p->getNext();
  }
  return total;
}

void JobManager::clear() {
  while (jobFrontPointer != NULL) {
    Job* p = jobFrontPointer;
    jobFrontPointer = jobFrontPointer->getNext();
    delete p;
  }
  jobFrontPointer = NULL;
}