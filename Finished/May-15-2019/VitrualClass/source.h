#ifndef SOURCE_H_
#define SOURCE_H_
#include <cstring>
void copyData(const char *src, char *&des) {
  des = new char[20];
  strcpy(des, src);
  return;
}

class base {
 private:
  char *name;
  int age;

 public:
  base();

  // accessor
  char *getname() const;
  int getage() const;

  // mutator
  void setname(char arr[]);
  void setage(int age);
};

base::base() : name{NULL}, age{0} {}

void base::setname(char arr[]) { copyData(arr, name); }

void base::setage(int age) { this->age = age; }
char *base::getname() const { return name; }
int base::getage() const { return age; }

class leader : virtual public base {
 private:
  char *job;
  char *dep;

 public:
  leader();
  // accessor
  char *getjob() const;
  char *getdep() const;

  // mutator
  void setjob(char job[]);
  void setdep(char dep[]);
};

leader::leader() : base{}, job{NULL}, dep{NULL} {}
char *leader::getjob() const { return job; }
char *leader::getdep() const { return dep; }

void leader::setjob(char job[]) { copyData(job, this->job); }
void leader::setdep(char dep[]) { copyData(dep, this->dep); }

class engineer : virtual public base {
 private:
  char *major;
  char *prof;

 public:
  engineer();
  // accessor
  char *getmajor() const;
  char *getprof() const;

  // mutator
  void setmajor(char job[]);
  void setprof(char dep[]);
};

engineer::engineer() : base{}, major{NULL}, prof{NULL} {}
char *engineer::getmajor() const { return major; }
char *engineer::getprof() const { return prof; }

void engineer::setmajor(char major[]) { copyData(major, this->major); }
void engineer::setprof(char prof[]) { copyData(prof, this->prof); }

class chairman : public leader, public engineer {};
#endif