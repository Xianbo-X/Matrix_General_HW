#include "JobManager.h"

JobManager::JobManager() {}

bool JobManager::deleteInstance() {
  if (instance == NULL) return false;
  instance->clear();
  delete instance;
  return false;
}

void JobManager::addJob(int priority) {
  Job* newJob = new Job{priority};
  Job* jobPtr = jobFrontPointer;
  while (jobPtr->getNext() != NULL) {
    jobPtr = jobPtr->getNext();
  }
  newJob->setNext(jobPtr);
}