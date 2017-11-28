## Fast-Track-C
## Becoming a Pragmatic Programmer in C

C is the programming language of choice in many fields of computing. The small size
of the language, its straightforward machine model, minimal or no abstraction
barriers, availability of efficient compilers, its historic ability to
directly invoke (operating) system calls, and its ability to interface with
assembly code have made C a prominent systems programming language.

Embedded systems development has been the forte of C programmers. For one, C
programs tend to be memory efficient. Thanks to advances in compiler technology,
C programs generally outperform competing implementations in other
programming languages. No wonder, many performance benchmarking suites employ
implementations in C as reference (or baseline) for comparison.

Although the language core is small and simple, becoming an effective C
programmer takes substantial effort. There are minute details that one needs to
grasp before attempting to develop reasonably large programs. One
of its merits - simple machine-model with minimal abstractions - turns out to
be the hardest to get right for many a novice. If the learner does not
pay attention, it is remarkably easy to create hard to understand, and
impossible to debug C programs. It takes careful study, practice, and 
professional reflection to mature into a pragmatic C programmer.

It is natutal to ask **what makes learning to program in C difficult?**

There are many reasons. We will mention only a few here.

1. C offers very little in terms of type safety. This is intentional
in its design. C is extremely permissive in mixing values of different types.
Typecasting, for example, can give rise to dumb but hard to detect bugs. 
Allowing raw addresses to be manipulated by pointer arithmetic is an
intriguing idea. Unfortunately, it is easy to go wrong with pointer
arithmetic, ending up with dreaded security vulnerabilities (think of buffer
overflows). [Edsger Dijkstra](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra),
a renowned computer scientist, called pointers in C language a "step backward 
in computer science."

2. Manual memory management is tricky to get right. A programmer needs to
take extreme care while managing memory allocared on process' heap. If one
is not cautious, programs end up using dangling pointers, affecting program's
state and behavior in unpredictable ways.

3. C does not define a module system. It lacks even a naive namespace
management system. All names used in a program (small or large) live in one
flat namespace. It is trivially possible to mix-up names, resulting in hard to
detect bugs.

Despite all its flaws, it is interesting to note that C is used to
develop numerous state-of-the-art software systems. Web Servers (such as NGINX),
SQL Database Management Systems (PostgreSQL, for instance), NoSQL in-memory
key-value store such as Redis, Version Control Systems (Git), and the list 
goes on. These and many other systems are extensively used by business
enterprises, scientific community, professional developers, hobby programmers,
and far numerous end-users.

**C is undoubtedly one of the most loved and the most hated programming languages.**

The question is, **how should one approach learning to program in C?**

In Fast-Track-C sessions, we employ a blend of principles, practices, and
techniques to write better C programs. We try hard to impart the
following habits from the beginning:

1. Draw upon sound principles and methods of
   [Formal Methods](https://en.wikipedia.org/wiki/Formal_methods).

    From the very beginning - that is, from the first example - we practice
    thinking about and specifying preconditions, postconditions, and 
    invariants. We use assertions as an effective tool for specifying and
    checking (functional and technical) requirements.

2. Use best practices, and develop attitudes required to design large systems.

    Despite C language's lack of module system, we show simple practices and 
    methods for organizing (sub)programs across conceptual modules, defining
    interfaces, and hiding implementation details. These practices shape the way
    one views systems-design, in general.

3. Employ simple methods for documenting program's design and implementation.

    Programmers have a tendency to shy away from writing detailed documents.
    We show simple and effective habits of documenting design and implementation
    details - within programs, in the form of embedded comments, and also as reference
    documents.

4. Leverage various options and switches that C compilers offer.

    GCC and [Clang](https://en.wikipedia.org/wiki/Clang) can be used to perform
    strict code analysis, helping programmers catch potential bugs arising
    out of wrong usage of language constructs.

5. Learn by studying source code created by masters of the art.

    Open Souce Software (OSS) projects offer a wealth of knowledge. One needs
    to learn to read and review techniques used in large and successful software
    projects. There are [excellent online books](http://aosabook.org/en/index.html)
    that serve as great reference material.

To summarize, here is a laundry list of ideas that we pursue in the Fast-Track-C
sessions:

  - The execution model of C programs.
  - Memory model of a C program: global memory, program stack, and heap memory.
  - Types and type safety (or the lack of it) in C.
  - Procedure invocation: call-by-value, call-by-reference, and variadic arguments.
  - Assertions - specifying precondition, postcondition, and loop invariants.
  - Methods for organizing C programs.
  - Abstract data types, and hiding implementation details.
  - Dynamic memory allocation, and manual memory management.
  - Guidelines and practices for constructing well-behaved/safe programs.
  - Leveraging compiler technology: perform strict code analysis.
  - Documenting design decisions and implementation details.

### Are you interested in learning from Fast-Track-C?
Send your emails to dprasadm@gmail.com, mentioning your motivation.

Contact me (**9591429050**) to know more about Fast-Track-C.

If you are looking for advanced training in Java, Python, or Functional Programming,
I would be glad to help.

