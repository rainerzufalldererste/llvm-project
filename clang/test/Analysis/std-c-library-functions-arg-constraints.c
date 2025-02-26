// Check the basic reporting/warning and the application of constraints.
// RUN: %clang_analyze_cc1 %s \
// RUN:   -analyzer-checker=core \
// RUN:   -analyzer-checker=alpha.unix.StdCLibraryFunctions \
// RUN:   -analyzer-config alpha.unix.StdCLibraryFunctions:ModelPOSIX=true \
// RUN:   -analyzer-checker=debug.StdCLibraryFunctionsTester \
// RUN:   -analyzer-checker=debug.ExprInspection \
// RUN:   -triple x86_64-unknown-linux-gnu \
// RUN:   -verify=report

// Check the bugpath related to the reports.
// RUN: %clang_analyze_cc1 %s \
// RUN:   -analyzer-checker=core \
// RUN:   -analyzer-checker=alpha.unix.StdCLibraryFunctions \
// RUN:   -analyzer-config alpha.unix.StdCLibraryFunctions:ModelPOSIX=true \
// RUN:   -analyzer-checker=debug.StdCLibraryFunctionsTester \
// RUN:   -analyzer-checker=debug.ExprInspection \
// RUN:   -triple x86_64-unknown-linux-gnu \
// RUN:   -analyzer-output=text \
// RUN:   -verify=bugpath

#include "Inputs/std-c-library-functions-POSIX.h"

void clang_analyzer_eval(int);
void clang_analyzer_warnIfReached();

int glob;

void test_alnum_concrete(int v) {
  int ret = isalnum(256); // \
  // report-warning{{The 1st argument to 'isalnum' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-warning{{The 1st argument to 'isalnum' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-note{{The 1st argument to 'isalnum' is 256 but should be an unsigned char value or EOF}}
  (void)ret;
}

void test_alnum_symbolic(int x) {
  int ret = isalnum(x);
  (void)ret;

  clang_analyzer_eval(EOF <= x && x <= 255); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{Left side of '&&' is true}} \
  // bugpath-note{{'x' is <= 255}}
}

void test_alnum_symbolic2(int x) {
  if (x > 255) { // \
    // bugpath-note{{Assuming 'x' is > 255}} \
    // bugpath-note{{Taking true branch}}

    int ret = isalnum(x); // \
    // report-warning{{The 1st argument to 'isalnum' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-warning{{The 1st argument to 'isalnum' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-note{{The 1st argument to 'isalnum' is >= 256 but should be an unsigned char value or EOF}}

    (void)ret;
  }
}

void test_toupper_concrete(int v) {
  int ret = toupper(256); // \
  // report-warning{{The 1st argument to 'toupper' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-warning{{The 1st argument to 'toupper' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-note{{The 1st argument to 'toupper' is 256 but should be an unsigned char value or EOF}}
  (void)ret;
}

void test_toupper_symbolic(int x) {
  int ret = toupper(x);
  (void)ret;

  clang_analyzer_eval(EOF <= x && x <= 255); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{Left side of '&&' is true}} \
  // bugpath-note{{'x' is <= 255}}
}

void test_toupper_symbolic2(int x) {
  if (x > 255) { // \
    // bugpath-note{{Assuming 'x' is > 255}} \
    // bugpath-note{{Taking true branch}}

    int ret = toupper(x); // \
    // report-warning{{The 1st argument to 'toupper' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-warning{{The 1st argument to 'toupper' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-note{{The 1st argument to 'toupper' is >= 256 but should be an unsigned char value or EOF}}

    (void)ret;
  }
}

void test_tolower_concrete(int v) {
  int ret = tolower(256); // \
  // report-warning{{The 1st argument to 'tolower' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-warning{{The 1st argument to 'tolower' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-note{{The 1st argument to 'tolower' is 256 but should be an unsigned char value or EOF}}
  (void)ret;
}

void test_tolower_symbolic(int x) {
  int ret = tolower(x);
  (void)ret;

  clang_analyzer_eval(EOF <= x && x <= 255); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{Left side of '&&' is true}} \
  // bugpath-note{{'x' is <= 255}}
}

void test_tolower_symbolic2(int x) {
  if (x > 255) { // \
    // bugpath-note{{Assuming 'x' is > 255}} \
    // bugpath-note{{Taking true branch}}

    int ret = tolower(x); // \
    // report-warning{{The 1st argument to 'tolower' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-warning{{The 1st argument to 'tolower' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-note{{The 1st argument to 'tolower' is >= 256 but should be an unsigned char value or EOF}}

    (void)ret;
  }
}

void test_toascii_concrete(int v) {
  int ret = toascii(256); // \
  // report-warning{{The 1st argument to 'toascii' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-warning{{The 1st argument to 'toascii' is 256 but should be an unsigned char value or EOF}} \
  // bugpath-note{{The 1st argument to 'toascii' is 256 but should be an unsigned char value or EOF}}
  (void)ret;
}

void test_toascii_symbolic(int x) {
  int ret = toascii(x);
  (void)ret;

  clang_analyzer_eval(EOF <= x && x <= 255); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{Left side of '&&' is true}} \
  // bugpath-note{{'x' is <= 255}}
}

void test_toascii_symbolic2(int x) {
  if (x > 255) { // \
    // bugpath-note{{Assuming 'x' is > 255}} \
    // bugpath-note{{Taking true branch}}

    int ret = toascii(x); // \
    // report-warning{{The 1st argument to 'toascii' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-warning{{The 1st argument to 'toascii' is >= 256 but should be an unsigned char value or EOF}} \
    // bugpath-note{{The 1st argument to 'toascii' is >= 256 but should be an unsigned char value or EOF}}

    (void)ret;
  }
}

void test_notnull_concrete(FILE *fp) {
  fread(0, sizeof(int), 10, fp); // \
  // report-warning{{The 1st argument to 'fread' is NULL but should not be NULL}} \
  // bugpath-warning{{The 1st argument to 'fread' is NULL but should not be NULL}} \
  // bugpath-note{{The 1st argument to 'fread' is NULL but should not be NULL}}
}
void test_notnull_symbolic(FILE *fp, int *buf) {
  fread(buf, sizeof(int), 10, fp);
  clang_analyzer_eval(buf != 0); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{'buf' is not equal to null}}
}
void test_notnull_symbolic2(FILE *fp, int *buf) {
  if (!buf)                          // bugpath-note{{Assuming 'buf' is null}} \
            // bugpath-note{{Taking true branch}}
    fread(buf, sizeof(int), 10, fp); // \
    // report-warning{{The 1st argument to 'fread' is NULL but should not be NULL}} \
    // bugpath-warning{{The 1st argument to 'fread' is NULL but should not be NULL}} \
    // bugpath-note{{The 1st argument to 'fread' is NULL but should not be NULL}}
}
void test_no_node_after_bug(FILE *fp, size_t size, size_t n, void *buf) {
  if (fp) // \
  // bugpath-note{{Assuming 'fp' is null}} \
  // bugpath-note{{Taking false branch}}
    return;
  size_t ret = fread(buf, size, n, fp); // \
  // report-warning{{The 4th argument to 'fread' is NULL but should not be NULL}} \
  // bugpath-warning{{The 4th argument to 'fread' is NULL but should not be NULL}} \
  // bugpath-note{{The 4th argument to 'fread' is NULL but should not be NULL}}
  clang_analyzer_warnIfReached(); // not reachable
}

// This is one test case for the ARR38-C SEI-CERT rule.
void ARR38_C_F(FILE *file) {
  enum { BUFFER_SIZE = 1024 };
  wchar_t wbuf[BUFFER_SIZE]; // bugpath-note{{'wbuf' initialized here}}

  const size_t size = sizeof(*wbuf);   // bugpath-note{{'size' initialized to}}
  const size_t nitems = sizeof(wbuf);  // bugpath-note{{'nitems' initialized to}}

  // The 3rd parameter should be the number of elements to read, not
  // the size in bytes.
  fread(wbuf, size, nitems, file); // \
  // report-warning{{The 1st argument to 'fread' is a buffer with size 4096 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4) times the 3rd argument (which is 4096)}} \
  // bugpath-warning{{The 1st argument to 'fread' is a buffer with size 4096 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4) times the 3rd argument (which is 4096)}} \
  // bugpath-note{{The 1st argument to 'fread' is a buffer with size 4096 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4) times the 3rd argument (which is 4096)}}
}

int __two_constrained_args(int, int);
void test_constraints_on_multiple_args(int x, int y) {
  // State split should not happen here. I.e. x == 1 should not be evaluated
  // FALSE.
  __two_constrained_args(x, y);
  //NOTE! Because of the second `clang_analyzer_eval` call we have two bug
  clang_analyzer_eval(x == 1); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}}
  clang_analyzer_eval(y == 1); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}}
}

int __arg_constrained_twice(int);
void test_multiple_constraints_on_same_arg(int x) {
  __arg_constrained_twice(x);
  clang_analyzer_eval(x < 1 || x > 2); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{Assuming 'x' is < 1}} \
  // bugpath-note{{Left side of '||' is true}}
}

int __variadic(void *stream, const char *format, ...);
void test_arg_constraint_on_variadic_fun(void) {
  __variadic(0, "%d%d", 1, 2); // \
  // report-warning{{The 1st argument to '__variadic' is NULL but should not be NULL}} \
  // bugpath-warning{{The 1st argument to '__variadic' is NULL but should not be NULL}} \
  // bugpath-note{{The 1st argument to '__variadic' is NULL but should not be NULL}}
}

int __buf_size_arg_constraint(const void *, size_t);
void test_buf_size_concrete(void) {
  char buf[3];                       // bugpath-note{{'buf' initialized here}}
  __buf_size_arg_constraint(buf, 4); // \
  // report-warning{{The 1st argument to '__buf_size_arg_constraint' is a buffer with size 3 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4)}} \
  // bugpath-warning{{The 1st argument to '__buf_size_arg_constraint' is a buffer with size 3 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4)}} \
  // bugpath-note{{The 1st argument to '__buf_size_arg_constraint' is a buffer with size 3 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4)}}
}
void test_buf_size_symbolic(int s) {
  char buf[3];
  __buf_size_arg_constraint(buf, s);
  clang_analyzer_eval(s <= 3); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{'s' is <= 3}}
}
void test_buf_size_symbolic_and_offset(int s) {
  char buf[3];
  __buf_size_arg_constraint(buf + 1, s);
  clang_analyzer_eval(s <= 2); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}} \
  // bugpath-note{{'s' is <= 2}}
}

int __buf_size_arg_constraint_mul(const void *, size_t, size_t);
void test_buf_size_concrete_with_multiplication(void) {
  short buf[3];                                         // bugpath-note{{'buf' initialized here}}
  __buf_size_arg_constraint_mul(buf, 4, sizeof(short)); // \
  // report-warning{{The 1st argument to '__buf_size_arg_constraint_mul' is a buffer with size 6 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4) times the 3rd argument (which is 2)}} \
  // bugpath-warning{{The 1st argument to '__buf_size_arg_constraint_mul' is a buffer with size 6 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4) times the 3rd argument (which is 2)}} \
  // bugpath-note{{The 1st argument to '__buf_size_arg_constraint_mul' is a buffer with size 6 but should be a buffer with size equal to or greater than the value of the 2nd argument (which is 4) times the 3rd argument (which is 2)}}
}
void test_buf_size_symbolic_with_multiplication(size_t s) {
  short buf[3];
  __buf_size_arg_constraint_mul(buf, s, sizeof(short));
  clang_analyzer_eval(s * sizeof(short) <= 6); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}}
}
void test_buf_size_symbolic_and_offset_with_multiplication(size_t s) {
  short buf[3];
  __buf_size_arg_constraint_mul(buf + 1, s, sizeof(short));
  clang_analyzer_eval(s * sizeof(short) <= 4); // \
  // report-warning{{TRUE}} \
  // bugpath-warning{{TRUE}} \
  // bugpath-note{{TRUE}}
}

// The minimum buffer size for this function is set to 10.
int __buf_size_arg_constraint_concrete(const void *);
void test_min_buf_size(void) {
  char buf[9];// bugpath-note{{'buf' initialized here}}
  __buf_size_arg_constraint_concrete(buf); // \
  // report-warning{{The 1st argument to '__buf_size_arg_constraint_concrete' is a buffer with size 9 but should be a buffer with size equal to or greater than 10}} \
  // bugpath-warning{{The 1st argument to '__buf_size_arg_constraint_concrete' is a buffer with size 9 but should be a buffer with size equal to or greater than 10}} \
  // bugpath-note{{The 1st argument to '__buf_size_arg_constraint_concrete' is a buffer with size 9 but should be a buffer with size equal to or greater than 10}}
}

void test_file_fd_at_functions() {
  (void)linkat(-22, "from", AT_FDCWD, "to", 0); // \
  // report-warning{{The 1st argument to 'linkat' is -22 but should be a valid file descriptor or AT_FDCWD}} \
  // bugpath-warning{{The 1st argument to 'linkat' is -22 but should be a valid file descriptor or AT_FDCWD}} \
  // bugpath-note{{The 1st argument to 'linkat' is -22 but should be a valid file descriptor or AT_FDCWD}}

  // no warning for these functions if the AT_FDCWD value is used
  (void)openat(AT_FDCWD, "path", 0);
  (void)linkat(AT_FDCWD, "from", AT_FDCWD, "to", 0);
  (void)faccessat(AT_FDCWD, "path", 0, 0);
  (void)symlinkat("oldpath", AT_FDCWD, "newpath");
  (void)mkdirat(AT_FDCWD, "path", 0);
  (void)mknodat(AT_FDCWD, "path", 0, 0);
  (void)fchmodat(AT_FDCWD, "path", 0, 0);
  (void)fchownat(AT_FDCWD, "path", 0, 0, 0);
  (void)linkat(AT_FDCWD, "oldpath", AT_FDCWD, "newpath", 0);
  (void)unlinkat(AT_FDCWD, "newpath", 0);
  struct stat St;
  (void)fstatat(AT_FDCWD, "newpath", &St, 0);
  char Buf[10];
  (void)readlinkat(AT_FDCWD, "newpath", Buf, 10);
  (void)renameat(AT_FDCWD, "oldpath", AT_FDCWD, "newpath");
}
