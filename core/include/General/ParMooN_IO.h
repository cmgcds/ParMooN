// =======================================================================
// ParMooN_IO.h    1.1  
// 
// Purpose:    Collection of IO routine and methods for ParMooN
//
// Author:     Sashikumaar Ganesan, Volker John Research Group,  01.12.18
// =======================================================================

#ifndef __PARMOON_IO__
#define __PARMOON_IO__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>

#ifdef _MPI
#include <mpi.h>
#endif

using std::cout;
using std::cerr;
using std::endl;
using std::ends;
using std::setw;
using std::setprecision;


#define ErrMsg(x) { cerr <<"Error in file "<<__FILE__<<", line "<<__LINE__<<":\n"<<x<<endl; OutFile<<"Error in file "<<__FILE__<<", line "<<__LINE__<<":\n"<<x<<endl;}
#define Error(x) {ErrMsg(x)}

extern std::ofstream& OutFile;



/**
@brief everything related to output to console and files
 
Especially the methods print and printToFile are defined in this namespace. The
proposed usage within ParMooN is as follows:

At the beginning of any ParMooN program make a call to 

    Output::set_outfile("test_outfile.txt");
This will make sure that all calls to print will write its arguments to
`std::cout` as well as to the file 'test_outfile.txt'. Before calling 
Output::set_outfile the print methods only write to `std::cout`.

Use print with any number of arguments. An additional template parameter 
(`unsigned int`) is recommended to indicate at which verbosity level you 
really want to print. Higher numbers mean smaller likelihood of being 
printed. There is a threshold value stored in this namespace (Output.c++) 
which determines whether or not to print and is in the range of 1 and 5 
(maxVerbosity). For example

    print<2>("print only if verbosity level is 2 or larger")
    print<3>("print only if verbosity level is 3 or larger")
    print<4>("print only if verbosity level is 4 or larger")

Calling Output::print without a template argument, is equivalent to calling 
Output::print<1>. This means it will be printed for any verbosity level.
There is only one exception: If Output::suppressAll() is called, then nothing
is ever written to `std::cout` or the outfile. However in that case it is still
possible to write to a second outfile through calling redirect.


In summary the Output::print method writes to

- only `std::cout` if Output::set_outfile has not yet been called (discouraged)
- `std::cout` and the outfile if Output::set_outfile has been called
  (recommended)
- only to an extra outfile if Output::redirect has been called
- nowhere if Output::suppressAll has been called

where only in the first two cases the verbosity matters at all.

You can control the verbosity level using the methods 
Output::setVerbosity(unsigned int i),
Output::increaseVerbosity() and Output::decreaseVerbosity().

At the end of the program call Output::close_file().

The user should only call the following methods from this namespace and ignore
the rest of it:

- Output::increaseVerbosity
- Output::decreaseVerbosity
- Output::setVerbosity
- Output::print<>
- Output::printToFile<>
- Output::set_outfile
- Output::close_file
- Output::suppressAll
- Output::redirect
- Output::resetOutfile
- #ErrThrow
 */
namespace Output
{
  /// @brief increase the verbosity by \p i
  void increaseVerbosity(unsigned int i = 1);
  /// @brief decrease the verbosity by \p i
  void decreaseVerbosity(unsigned int i = 1);
  /// @brief set the verbosity to a given level (must be between 1 and 5)
  void setVerbosity(unsigned int i);
  /// @brief get the verbosity, typically to reset it to this value later again
  unsigned int getVerbosity();
  /// @brief suppress all output to std::cout and the outfile
  ///
  /// Only calls to Output::print are suppressed. Direct calls to std::cout are
  /// still possible. This lasts until Output::increaseVerbosity, 
  /// Output::decreaseVerbosity, or Output::setVerbosity is called again.
  void suppressAll();
  
  /// @brief set the outfile
  ///
  /// The print methods print to both std::cout and the outfile. This method 
  /// opens the file and it should be closed again calling Output::close_file().
  void set_outfile(std::string filename);
  
  /// @brief close files which have been previously opened
  ///
  /// Files can be opened through Output::set_outfile and Output::redirect.
  void close_file();
  
  /** \brief redirect all output to this file, nowhere else
   *
   * This method opens the file and all subsequent calls to print and std::cout
   * will write into this file (no matter what the verbosity template parameter
   * is set to). To return to the normal behavior of the print methods call
   * Output::resetOutfile(). Typically this is used to write all output of a
   * block of code into a separate file:
   * \code{.cpp}
   *      Output::redirect("file_for_output_of_f");
   *      f(); // call some function which calls print a lot
   *      Output::resetOutfile();
   * \endcode
   * \note Using `printf` will still give you output on the console
   */
  void redirect(std::string filename);
  /// @brief close the file after a call to Output::redirect.
  ///
  /// This restores the normal behavior of the print methods.
  void resetOutfile();
  
  
  /// @brief Write something to std::cout and the outfile 
  ///
  /// This is printed only if the template parameter verbosity is not too large.
  /// That means verbosity 1 (the default) will always be printed, while with 
  /// larger numbers it is only printed if the verbosity level is high enough.
  /// Note that verbosity must be within 1 and 5 (maxVerbosity), other values
  /// (including 0) give a compile error. 
  /// 
  /// The template parameters `Arguments` can be of any type which can be 
  /// inserted into a std::ostream via `<<`.
  ///
  /// This is a variadic template to enable variable number of arguments to 
  /// print.
  template<unsigned int verbosity = 1, typename ... Arguments>
  void print(Arguments const& ... rest);
  
  template<unsigned int verbosity = 1, typename ... Arguments>
  void warn(std::string context, Arguments const& ... rest);

  template<unsigned int verbosity = 1, typename ... Arguments>
  void stat(std::string context, Arguments const& ... rest);

  template<unsigned int verbosity = 1, typename ... Arguments>
  void info(std::string context, Arguments const& ... rest);

  template<unsigned int verbosity = 1, typename ... Arguments>
  void dash(Arguments const& ... rest);

  /// @brief print only to the outfile depending on verbosity
  ///
  /// This method behaves like the corresponding print, but does not print to
  /// std::cout, only to the outfile.
  ///
  /// This is a variadic template to enable variable number of arguments to 
  /// print.
  template<unsigned int verbosity = 1, typename ... Arguments>
  void printToFile(Arguments const& ... rest);
  
  /// @brief write an error message to the outfile and throw an exception
  ///
  /// This is the preferred way to terminate the program if necessary. The OutPut
  /// exception thrown is of type `std::runtime_error`. For convenience there 
  /// is a macro #ErrThrow defined which calls this method with the correct 
  /// \p file and \p line.
  template<typename ... Arguments>
  [[ noreturn ]] void errThrow(std::string file, int line,
                               Arguments const& ... args);
  
  /// @brief macro to call Output::errThrow with the correct file and line
  ///
  /// You have to provide a meaningful error message here.
  #define ErrThrow(...) {Output::errThrow(__FILE__, __LINE__, __VA_ARGS__);}
};


// this is an attempt to separate declaration and implementation. The template
// methods unfortunately can not be put in the source file, so they are 
// implemented here together with some helping methods. But in general you only
// have to worry about the above declarations.
namespace Output
{
  /// @brief maximum allowed verbosity level
  constexpr unsigned int maxVerbosity = 5;
  /// @brief a helper function the user should not call
  ///
  /// Return true if is v smaller or equal to the current verbosity level.
  /// v should be between 1 and maxVerbosity, but this is not enforced here.
  bool verbose(unsigned int v);
  
  /// @brief a helper function the user should not call
  ///
  /// Returns true after a call to Output::redirect, otherwise false.
  bool writeOnlyToFile();
  /// @brief a helper function the user should not call
  /// 
  /// Get the stream of the outfile. If Output::redirect has been called this 
  /// returns the stream of that file.
  std::ofstream& get_outfile();
  
  // implementation of the print method
  template<unsigned int verbosity, typename ... Arguments>
  void print(Arguments const& ... args)
  {
    static_assert(verbosity > 0,
                  "It makes no sense to call print with 0 verbosity"
                  "Use a value greater than 0");
    static_assert(verbosity <= maxVerbosity, 
                  "calling Output::print with verbosity too large");
    
    // the following writes all the arguments into the stream. With c++17 we can
    // also use 'fold expressions':
    // (std::cout << ... << args) << std::endl;
    // (get_outfile() << ... << args) << std::endl;
    // http://stackoverflow.com/a/21812549
    // http://stackoverflow.com/a/33621132
    std::ostringstream stream;
#ifdef _MPI
    // In MPI case, tell us which process is talking to us.
    // This feature is in testing stage.
    int finalized = 0;
    MPI_Finalized(&finalized);
    int initialized = 0;
    MPI_Initialized(&initialized);
    if(!finalized && initialized)
    {
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    stream << my_rank << ": ";
    }
    else
    {
      stream << "(?): ";
    }
#endif
    using List= int[];
    (void)List{0, ( (void)(stream << args), 0 ) ... };
    
    if(!writeOnlyToFile())
    {
      if(verbose(verbosity))
      {
        std::cout << stream.str() << std::endl;
        get_outfile() << stream.str() << std::endl;
      }
    }
    else
    {
      get_outfile() << stream.str() << std::endl;
    }
  }
  
  template<unsigned int verbosity, typename ... Arguments>
  void warn(std::string context, Arguments const& ... rest)
  {
	  print<verbosity>("WARNING (",context,"): ", rest ...);
  }

  template<unsigned int verbosity, typename ... Arguments>
  void stat(std::string context, Arguments const& ... rest)
  {
	  print<verbosity>("STATS (",context,"): ", rest ...);
  }

  template<unsigned int verbosity, typename ... Arguments>
  void info(std::string context, Arguments const& ... rest)
  {
	  print<verbosity>("INFO (",context,"): ", rest ...);
  }

  template<unsigned int verbosity, typename ... Arguments>
  void dash(Arguments const& ... rest)
  {
	  print<verbosity>(" > ", rest ...);
  }

  // implementation of the printToFile method
  template<unsigned int verbosity, typename ... Arguments>
  void printToFile(Arguments const& ... args)
  {
    static_assert(verbosity > 0,
                  "It makes no sense to call print with 0 verbosity"
                  "Use a value greater than 0");
    static_assert(verbosity <= maxVerbosity, 
                  "calling Output::print with verbosity too large");
    
    if(verbose(verbosity))
    {
      using List= int[];
      (void)List{0, ( (void)(get_outfile() << args), 0 ) ... };
      get_outfile() << std::endl;
    }
  }
  
  // implementationof the errThrow method
  template<typename ... Arguments>
  [[ noreturn ]] void errThrow(std::string file, int line,
                               Arguments const& ... args)
  {
    // see the implementation of Output::print
    std::ostringstream stream;
    stream << std::string(60, '*') << "\nError in file " << file << ", line " 
           << line << ":\n";
    using List= int[];
    (void)List{0, ( (void)(stream << args), 0 ) ... };
    
    get_outfile() << stream.str() << std::endl;
    throw std::runtime_error(stream.str());
  }
};

/// @brief old macro to print things into a file and t std::cout, deprecated
/// use instead the Output::print methods.
#define OutPut(x) {std::stringstream temporary; temporary << x; Output::print(temporary.str());}



#endif
