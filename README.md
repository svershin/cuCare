cuCare
======

__Authors:__ David Carson ([davecarson](http://github.com/davecarson)), Devin Denis ([CURigel](http://github.com/CURigel)), Sergey Vershinin ([svershin](http://github.com/svershin)), and Michael Yuill ([mikeyuill](http://github.com/mikeyuill))

__NOTE:__
- The repository has been moved here from BitBucket, and represents the final state of the codebase before it was packaged for submission.
- Although the commit history appears to have been ported over, it DOES NOT accurately represent the team members' respective contributions (probably because they weren't tagged properly).

Introduction
------

cuCare is a medical patient management system, written in C++ using the Qt Creator IDE, designed to run under Linux.

Application Deployment Instructions
------

The CuCare system is made up of five Qt projects:
- Three library projects:
  1.	CuCareStorage
  2.	CuCareCommunications
  3.	CuCareModel

- Two executable projects:
  1.	CuCare
  2.	CuCareServer

We have precompiled all of these projects in order to enable fast use of the system.  You only need to open the executable projects in Qt Creator, but if you wish to do a full compile you can do so by opening all of the projects, running qmake on each one, and then building them (note that the library projects must be built before the executable projects).  All of the .pro.user files are intentionally omitted, forcing the build directory to be set to the project directory and avoiding issues with different filesystem paths on different computers.

For a quick start, you will need to do the following:

-	Open the projects for CuCare and CuCareServer
-	Set launch arguments for the CuCareServer that are used to set the port number and the audit time.  In Qt, you can do this by clicking the projects tab on the left, selecting the CuCareServer at the top, going to ‘Run Settings’, and adding the arguments to the ‘Arguments' field.  The format is “portnumber audittime”, where portnumber is simply a port number and audittime is the time for the audit to run in 24-hour format separated by colons (e.g. “60003 19:00:00”).
-	Also note that if you are testing on the stock VM, you will need to use a port between 60000 and 60010.
-	Additionally, you will need to edit the NetworkSettings.init file in the CuCare project to reflect the IP and port number of the server.  Note again for the stock VM, the IP address is the local IP address of the physical machine that you are using.

Once you’ve completed the steps above, you can now run qmake on each project, and then run each one, starting with CuCareServer.

You can log in using ‘Physician’ to log in with a physician user account, or with ‘AdminAssistant’ to log in as an administrative assistant user account.

System Administration GUI
------

There are no ‘grayed-out’ GUI elements representing system administration features. This behaviour is by design.Following a successful login, our system’s design calls for a system administrator to be taken to an entirely different view than the one presented to physicians and administrative assistants.

Running via the Command Line (i.e. not out of Qt Creator)
------

Because we use shared libraries in our project, there are a number of steps that need to be taken in order to run the client or server process from the command line.  This is because Qt Creator stores the paths to shared libraries within a project, in an environment variable that is present only in the runtime environment that is created when you run processes from within Qt Creator.

- If you want to run the client or the server from the command line, it is necessary to add the shared library path to your command line environment.  To accomplish this you will need to do the following:
- First, confirm that you can successfully run the client  and server applications from within Qt Creator.
- Once you've done that, select the 'Projects' button on the sidebar
- Select the top tab corresponding to the process you want to run (CuCare for the client or CuCareServer for the server).
- Select 'Run Settings'.
- Under 'Run Environment', expand the variables list by selecting the 'Details' tab.
- Scroll down to the variable called LD_LIBRARY_PATH.

You are going to need to append the value of that variable (referred to as 'appended_stuff_here') to the following terminal command:

<export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:appended_stuff_here>

A sample command for the client might look like this:

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/baltar/git/cucare/CuCare/../CuCareCommunications/qjson/build/lib/:/home/baltar/git/cucare/CuCare/../CuCareCommunications/Communications/:/home/baltar/git/cucare/CuCare/../CuCareModel/:/usr/lib/i386-linux-gnu

Note that the value is different for the server, since the client and server use different libraries.  If you wanted to have both in one variable, the formula is as follows:

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:client_variable_value:server_variable_value

Where client_variable_value is the value of LD_LIBRARY_PATH in the run settings for the CuCare project in Qt Creator, and server_variable_value is the value of LD_LIBRARY_PATH in the run settings for the CuCareServer project.
