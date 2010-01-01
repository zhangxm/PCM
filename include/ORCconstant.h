#ifndef H_CONSTANT
#define H_CONSTANT

// POP type
enum ORCPOPTYPE {ORCPOPQUEUE = 0, ORCPOPSTACK};

#define ORCLISTINITSIZE    5
#define ORCLISTINCREMENT   5

#define ORCFILEMAXLINE         1000
#define ORCFILENAME            20

// ERROR CODE
enum ORCERR {
   ORCERRSTART = 10000,
   ORCERRNOMEMORY,
   ORCERRNOTVALIDINDEX,
   ORCERRNULLPOINTER,
   ORCERRELEMENTNOTFOUND,
   ORCERREMPTYLIST,
   ORCERRNOTSTACKANDQUEUE,
   ORCERREND   = 20000
};

// Alg
enum ORCSORTALG {ORCALGSORTSELECT = 80001,
   ORCALGSORTBUBBLE};
enum ORCSEARCHALG {ORCALGORIGINFIND = 90001};

#endif

