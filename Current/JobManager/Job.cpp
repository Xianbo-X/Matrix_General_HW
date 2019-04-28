#include "Job.h"
#include <sstream>

string num2str(int num) {
  string res;
  stringstream ss;
  ss.clear();
  ss << num;
  ss >> res;
  return res;
}

Job::Job(int priority) : nextJob{NULL} {
  setId(this->id);
  setPriority(priority);
}
void Job::setId(int id) { id = number++; }
int Job::getId() const { return id; }
void Job::setPriority(int priority) { this->priority = priority; }
int Job::getPriority() const { return priority; }
void Job::setNext(Job* job) { job->nextJob = this; }
Job* Job::getNext() const { return nextJob; }
string Job::toString() {
  string res = "";
  res = "[" + num2str(id) + ":" + num2str(priority) + "]";
  return res;
}