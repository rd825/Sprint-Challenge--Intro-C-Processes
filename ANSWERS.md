**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**<br/>

- R: Running or ready (waiting for the CPU to process it)
- S: Interruptible sleep (waiting for an event to complete, such as input from the terminal)
- D: Uninterruptible sleep (processes that cannot be killed or interrupted with a signal)
- Z: Zombie
- T: Stopped (a process that has been suspended/stopped)
  <br/><br/>

**2. What is a zombie process?**<br/>
A zombie process is a process that has completed execution (i.e. exited) but still has an entry in the process table.
<br/><br/>

**3. How does a zombie process get created? How does one get destroyed?**<br/>
A child process always becomes a zombie for some time before being removed from the process table. This occurs because the child's entry on the process table is still needed to allow the parent process to read the child's exit status. The parent can do this via the wait system call, which will "reap" the child and remove it from the process table.
<br/><br/>

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**<br/>
The major advantage of compiled languages over interpreted languages is their execution speed. Because compiled languages are converted directly into machine code, they run significantly faster and more efficiently than interpreted languages. Lower-level languages tend to be compiled because efficiency is usually more of a concern than cross-platform support. Additionally, because compiled languages are converted directly into machine code, this gives the developer much more control over hardware aspects such as memory management and CPU usage.
