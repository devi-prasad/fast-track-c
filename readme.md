
# Becoming a Pragmatic Programmer in the C Language

C is the programming language of choice in many computing fields. The small size
of the language, its straightforward machine model, minimal or no abstraction
barriers, availability of efficient compilers, and its historic ability to
directly invoke (operating) system calls, and its ability to interface with
assembly code have made C a prominent systems programming language.

Although the language core is small and simple, becoming an effective C
programmer takes substantial effort. There are minute details and complexities
that one needs to grasp before attempting to develop reasonably large code. One
of its merits - simple machine-model with minimal abstractions - turns out to
be one of the hardest to get right for many a novice. If the learner does not
pay attention, it is very easy for one to create hard to understand and
impossible to debug C programs. It takes careful study, practice, and 
professional reflection to mature into a pragmatic C programmer.

Embedded systems development has been the forte of C programmers. For one, C
programs tend to be memory efficient. Thanks to efficient compilation, C
programs generally tend to outperform competing implementations in other
programming languages. No wonder, many performance benchmarking suites employ
implementations in C as a reference or baseline for comparison.

It is natutal to ask **what makes learning to program in C difficult?**

There are many reasons. We shall look at only a few.

1. C offers very little in terms of type safety. This is intensional
in its design. C is extremely permissive in mixing values of different types.
Typecasting, for example, can give rise to dumb but hard to locate bugs. 
Treating pointers as raw addresses that may be typecast to "pint to" arbitrary
typed-values imparts great flexibility and power to programmers while also
making it extremely easy to cause dreaded buffer overflows and numerous other
security vulnerabilities. Pointers in C language were called out as a 
"step backward in computer science" by a renowned computer scietist.

2. Manual memory management is tricky to get right. A programmer needs to
take extreme care while maanaging heap allocared memory. If one is not cautious,
one might very easily end up using dangling pointers, and affect program's state
and behavior in weird ways.

3. C does not define a module system. It lacks even a naive namespace
management system. All symbols and names exist in one flat namespace, and it is
trivially possible to mix up names, and thus create hard to detect bugs.

Despite all its blemishes and flaws, it is interesting to note that C is used to
develop numerous state of the art software systems. Web Servers (such as NGINX),
SQL Database Management Systems (PostgreSQL, for instance), NoSQL in-memory
key-value store such as Redis, Distributed Version Control Systems
(Git, for example) and the list goes on. These and many other systems are
extensively used by businesses enterprises, scientific community, professional
developers, hobby programmers, and far numerous end-users.

**C is undoubtedly one of the most loved and most hated programming languages.**

The question is this: **how should one approach learning to program in C?**

In Fast-Track C Programming sessions, we employ a blend of principles,
practices, and techniques to write better C programs. We try hard to impart the
following habits from the word go:

1. Draw upon sound principles and methods from Formal Methods.
    From the very beginning - that is, from the very first example - we practice
    thinking about, and specifying preconditions, postconditions, and 
    invariants. We use assertions as an effective tool for specifying and
    checking (functional and technical) requirements.

2. Employ simple methods for documenting program's design and implementation.
    Programmers have a tendency to shun away from detailed documentation. We
    show simple and effective habits of documenting design and implementation
    details, within programs as embedded comments, and also as external 
    documents.

3. Leverage various options and knobs that modern C compilers offer.
    GCC and Clang can be used to perform strictest form of code analysis, thus
    helping programmers catch potential bugs arising out of wrong usage of
    language constructs.

4. Use best practices and develop habits required to develop large systems.
    Despite C language's lack of module system, we show simple practices and 
    methods for organizinging (sub)programs across conceptual modules, defining
    interfaces, programming against interfaces (data abstraction), and hiding
    implementation details. These practices serve a long way.

5. Learn from reading code from the masters and experts.
    Open Souce Software (OSS) projects offer a wealth of knowledge. One needs
    to learn to read and review techniques used in large and successful software
    projects.

Here is a laundry list of ideas that we pursue in the Fast-Track sessions:

  - The execution model of C programs.
  - Memory model of a C program - global memory, program stack, and heap memory.
  - Types and type safety (or the lack of it) in C language.
  - Pointers, and the data type - memory access patterns.
  - Procedure invocation - Call-by-value and Call-by-reference methods.
  - Assertions - specifying precondition, postcondition, and program invariants.
  - Dynamic memory allocation, and manual memory management.
  - Fundamental program-organization methods in C language.
  - Creating abstract data types, and hiding implementation details.
  - Guidelines and practices for constructing safer programs.
  - Basic techniques for instructing compilers to perform strict code analysis.
  - Documenting design decisions and implementation details.





