////////////////////////////////////////////////////////////////////////////////
// taskwarrior - a command line task list manager.
//
// Copyright 2006-2014, Paul Beckingham, Federico Hernandez.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

#include <cmake.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <Date.h>
#include <Duration.h>
#include <E9.h>
#include <text.h>
#include <util.h>
#include <i18n.h>
#include <Command.h>
#include <main.h>

#include <CmdAdd.h>
#include <CmdAliases.h>
#include <CmdAnnotate.h>
#include <CmdAppend.h>
#include <CmdBurndown.h>
#include <CmdCalendar.h>
#include <CmdColor.h>
#include <CmdColumns.h>
#include <CmdCommands.h>
#include <CmdConfig.h>
#include <CmdCount.h>
#include <CmdCustom.h>
#include <CmdDelete.h>
#include <CmdDenotate.h>
#include <CmdDiagnostics.h>
#include <CmdDone.h>
#include <CmdDuplicate.h>
#include <CmdEdit.h>
#ifdef HAVE_EXECUTE
#include <CmdExec.h>
#endif
#include <CmdExport.h>
#include <CmdGet.h>
#include <CmdHelp.h>
#include <CmdHistory.h>
#include <CmdIDs.h>
#include <CmdImport.h>
#include <CmdInfo.h>
//#include <CmdInstall.h>
#include <CmdLog.h>
#include <CmdLogo.h>
#include <CmdMerge.h>
#include <CmdModify.h>
#include <CmdPrepend.h>
#include <CmdProjects.h>
#include <CmdPull.h>
#include <CmdPush.h>
#include <CmdReports.h>
#include <CmdShow.h>
#include <CmdStart.h>
#include <CmdStats.h>
#include <CmdStop.h>
#include <CmdSummary.h>
#include <CmdSync.h>
#include <CmdTags.h>
#include <CmdTimesheet.h>
#include <CmdUDAs.h>
#include <CmdUndo.h>
#include <CmdUrgency.h>
#include <CmdVersion.h>

#include <Context.h>
#include <ColProject.h>
#include <ColPriority.h>
#include <ColDue.h>

extern Context context;

////////////////////////////////////////////////////////////////////////////////
void Command::factory (std::map <std::string, Command*>& all)
{
  Command* c;

  c = new CmdAdd ();                all[c->keyword ()] = c;
  c = new CmdAnnotate ();           all[c->keyword ()] = c;
  c = new CmdAppend ();             all[c->keyword ()] = c;
  c = new CmdBurndownDaily ();      all[c->keyword ()] = c;
  c = new CmdBurndownMonthly ();    all[c->keyword ()] = c;
  c = new CmdBurndownWeekly ();     all[c->keyword ()] = c;
  c = new CmdCalendar ();           all[c->keyword ()] = c;
  c = new CmdColor ();              all[c->keyword ()] = c;
  c = new CmdColumns ();            all[c->keyword ()] = c;
  c = new CmdCompletionAliases ();  all[c->keyword ()] = c;
  c = new CmdCompletionColumns ();  all[c->keyword ()] = c;
  c = new CmdCompletionCommands (); all[c->keyword ()] = c;
  c = new CmdCompletionConfig ();   all[c->keyword ()] = c;
  c = new CmdCompletionIds ();      all[c->keyword ()] = c;
  c = new CmdCompletionUDAs ();     all[c->keyword ()] = c;
  c = new CmdCompletionUuids ();    all[c->keyword ()] = c;
  c = new CmdCompletionProjects (); all[c->keyword ()] = c;
  c = new CmdCompletionTags ();     all[c->keyword ()] = c;
  c = new CmdCompletionVersion ();  all[c->keyword ()] = c;
  c = new CmdConfig ();             all[c->keyword ()] = c;
  c = new CmdCount ();              all[c->keyword ()] = c;
  c = new CmdDelete ();             all[c->keyword ()] = c;
  c = new CmdDenotate ();           all[c->keyword ()] = c;
  c = new CmdDiagnostics ();        all[c->keyword ()] = c;
  c = new CmdDone ();               all[c->keyword ()] = c;
  c = new CmdDuplicate ();          all[c->keyword ()] = c;
  c = new CmdEdit ();               all[c->keyword ()] = c;
#ifdef HAVE_EXECUTE
  c = new CmdExec ();               all[c->keyword ()] = c;
#endif
  c = new CmdExport ();             all[c->keyword ()] = c;
  c = new CmdGet ();                all[c->keyword ()] = c;
  c = new CmdGHistoryMonthly ();    all[c->keyword ()] = c;
  c = new CmdGHistoryAnnual ();     all[c->keyword ()] = c;
  c = new CmdHelp ();               all[c->keyword ()] = c;
  c = new CmdHistoryMonthly ();     all[c->keyword ()] = c;
  c = new CmdHistoryAnnual ();      all[c->keyword ()] = c;
  c = new CmdIDs ();                all[c->keyword ()] = c;
  c = new CmdImport ();             all[c->keyword ()] = c;
  c = new CmdInfo ();               all[c->keyword ()] = c;
//  c = new CmdInstall ();            all[c->keyword ()] = c;
  c = new CmdLog ();                all[c->keyword ()] = c;
  c = new CmdLogo ();               all[c->keyword ()] = c;
  c = new CmdMerge ();              all[c->keyword ()] = c;
  c = new CmdModify ();             all[c->keyword ()] = c;
  c = new CmdPrepend ();            all[c->keyword ()] = c;
  c = new CmdProjects ();           all[c->keyword ()] = c;
  c = new CmdPull ();               all[c->keyword ()] = c;
  c = new CmdPush ();               all[c->keyword ()] = c;
  c = new CmdReports ();            all[c->keyword ()] = c;
  c = new CmdShow ();               all[c->keyword ()] = c;
  c = new CmdShowRaw ();            all[c->keyword ()] = c;
  c = new CmdStart ();              all[c->keyword ()] = c;
  c = new CmdStats ();              all[c->keyword ()] = c;
  c = new CmdStop ();               all[c->keyword ()] = c;
  c = new CmdSummary ();            all[c->keyword ()] = c;
  c = new CmdSync ();               all[c->keyword ()] = c;
  c = new CmdTags ();               all[c->keyword ()] = c;
  c = new CmdTimesheet ();          all[c->keyword ()] = c;
  c = new CmdUDAs ();               all[c->keyword ()] = c;
  c = new CmdUndo ();               all[c->keyword ()] = c;
  c = new CmdUrgency ();            all[c->keyword ()] = c;
  c = new CmdUUIDs ();              all[c->keyword ()] = c;
  c = new CmdVersion ();            all[c->keyword ()] = c;
  c = new CmdZshCommands ();        all[c->keyword ()] = c;
  c = new CmdZshCompletionIds ();   all[c->keyword ()] = c;
  c = new CmdZshCompletionUuids (); all[c->keyword ()] = c;

  // Instantiate a command object for each custom report.
  std::vector <std::string> reports;
  Config::const_iterator i;
  for (i = context.config.begin (); i != context.config.end (); ++i)
  {
    if (i->first.substr (0, 7) == "report.")
    {
      std::string report = i->first.substr (7);
      std::string::size_type columns = report.find (".columns");
      if (columns != std::string::npos)
        reports.push_back (report.substr (0, columns));
    }
  }

  std::vector <std::string>::iterator report;
  for (report = reports.begin (); report != reports.end (); ++report)
  {
    // Make sure a custom report does not clash with a built-in command.
    if (all.find (*report) != all.end ())
      throw format (STRING_CMD_CONFLICT, *report);

    c = new CmdCustom (
              *report,
              "task <filter> " + *report,
              context.config.get ("report." + *report + ".description"));

    all[c->keyword ()] = c;
  }
}

////////////////////////////////////////////////////////////////////////////////
Command::Command ()
: _usage ("")
, _description ("")
, _read_only (true)
, _displays_id (true)
, _needs_confirm (false)
, _permission_quit (false)
, _permission_all (false)
, _first_iteration (true)
{
}

////////////////////////////////////////////////////////////////////////////////
Command::Command (const Command& other)
{
  _usage           = other._usage;
  _description     = other._description;
  _read_only       = other._read_only;
  _displays_id     = other._displays_id;
  _needs_confirm   = other._needs_confirm;
  _permission_quit = other._permission_quit;
  _permission_all  = other._permission_all;
  _first_iteration = other._first_iteration;
}

////////////////////////////////////////////////////////////////////////////////
Command& Command::operator= (const Command& other)
{
  if (this != &other)
  {
    _usage           = other._usage;
    _description     = other._description;
    _read_only       = other._read_only;
    _displays_id     = other._displays_id;
    _needs_confirm   = other._needs_confirm;
    _permission_quit = other._permission_quit;
    _permission_all  = other._permission_all;
    _first_iteration = other._first_iteration;
  }

  return *this;
}

////////////////////////////////////////////////////////////////////////////////
bool Command::operator== (const Command& other) const
{
  return _usage         == other._usage       &&
         _description   == other._description &&
         _read_only     == other._read_only   &&
         _displays_id   == other._displays_id &&
         _needs_confirm == other._needs_confirm;
}

////////////////////////////////////////////////////////////////////////////////
Command::~Command ()
{
}

////////////////////////////////////////////////////////////////////////////////
std::string Command::keyword () const
{
  return _keyword;
}

////////////////////////////////////////////////////////////////////////////////
std::string Command::usage () const
{
  return _usage;
}

////////////////////////////////////////////////////////////////////////////////
std::string Command::description () const
{
  return _description;
}

////////////////////////////////////////////////////////////////////////////////
bool Command::read_only () const
{
  return _read_only;
}

////////////////////////////////////////////////////////////////////////////////
bool Command::displays_id () const
{
  return _displays_id;
}

////////////////////////////////////////////////////////////////////////////////
// Filter a specific list of tasks.
void Command::filter (const std::vector <Task>& input, std::vector <Task>& output)
{
  context.timer_filter.start ();

  A3 filt = context.a3.extract_filter ();
  filt.dump ("extract_filter");

  if (filt.size ())
  {
    E9 e (filt);

    std::vector <Task>::const_iterator task;
    for (task = input.begin (); task != input.end (); ++task)
      if (e.evalFilter (*task))
        output.push_back (*task);
  }
  else
    output = input;

  context.timer_filter.stop ();
}

////////////////////////////////////////////////////////////////////////////////
// Filter all tasks.
void Command::filter (std::vector <Task>& output)
{
  context.timer_filter.start ();
  A3 filt = context.a3.extract_filter ();
  filt.dump ("extract_filter");

  if (filt.size ())
  {
    context.timer_filter.stop ();
    const std::vector <Task>& pending = context.tdb2.pending.get_tasks ();
    context.timer_filter.start ();
    E9 e (filt);

    output.clear ();
    std::vector <Task>::const_iterator task;

    for (task = pending.begin (); task != pending.end (); ++task)
      if (e.evalFilter (*task))
        output.push_back (*task);

    if (! filter_shortcut (filt))
    {
      context.timer_filter.stop ();
      const std::vector <Task>& completed = context.tdb2.completed.get_tasks (); // TODO Optional
      context.timer_filter.start ();

      for (task = completed.begin (); task != completed.end (); ++task)
        if (e.evalFilter (*task))
          output.push_back (*task);
    }
  }
  else
  {
    safety ();

    context.timer_filter.stop ();
    const std::vector <Task>& pending   = context.tdb2.pending.get_tasks ();
    const std::vector <Task>& completed = context.tdb2.completed.get_tasks ();
    context.timer_filter.start ();

    std::vector <Task>::const_iterator task;
    for (task = pending.begin (); task != pending.end (); ++task)
      output.push_back (*task);

    for (task = completed.begin (); task != completed.end (); ++task)
      output.push_back (*task);
  }

  context.timer_filter.stop ();
}

////////////////////////////////////////////////////////////////////////////////
// If the filter contains the restriction "status:pending", as the first filter
// term, then completed.data does not need to be loaded.
bool Command::filter_shortcut (const A3& filter)
{
  // Postfix: <status> <"pending"> <=>
  //                 0           1   2
  if (filter.size ()                  >= 3                 &&
      filter[0]._raw                  == "status"          &&
      filter[1]._raw.find ("pending") != std::string::npos &&
      filter[2]._raw                  == "=")
  {
    context.debug ("Command::filter skipping completed.data (status:pending only)");
    return true;
  }

  // Shortcut: If the filter contains no 'or' or 'xor' operators, IDs and no UUIDs.
  int countId   = 0;
  int countUUID = 0;
  int countOr   = 0;
  int countXor  = 0;
  std::vector <Arg>::const_iterator i;
  for (i = filter.begin (); i != filter.end (); ++i)
  {
    if (i->_category == Arg::cat_op)
    {
      if (i->_raw == "or")  ++countOr;
      if (i->_raw == "xor") ++countXor;

    }
    else if (i->_category == Arg::cat_id)   ++countId;
    else if (i->_category == Arg::cat_uuid) ++countUUID;
  }

  if (countOr   == 0 &&
      countXor  == 0 &&
      countUUID == 0 &&
      countId    > 0)
  {
    context.debug ("Command::filter skipping completed.data (IDs, no OR, no XOR, no UUID)");
    return true;
  }

  return false;
}

////////////////////////////////////////////////////////////////////////////////
// Apply the modifications in arguments to the task.
void Command::modify_task_description_replace (Task& task, const A3& arguments)
{
  std::string description;
  modify_task (task, arguments, description);

  if (description.length ())
  {
    _needs_confirm = true;
    task.set ("description", description);
  }
}

////////////////////////////////////////////////////////////////////////////////
void Command::modify_task_description_prepend (Task& task, const A3& arguments)
{
  std::string description;
  modify_task (task, arguments, description);

  if (description.length ())
    task.set ("description", description + " " + task.get ("description"));
}

////////////////////////////////////////////////////////////////////////////////
void Command::modify_task_description_append (Task& task, const A3& arguments)
{
  std::string description;
  modify_task (task, arguments, description);

  if (description.length ())
    task.set ("description", task.get ("description") + " " + description);
}

////////////////////////////////////////////////////////////////////////////////
void Command::modify_task_annotate (Task& task, const A3& arguments)
{
  std::string description;
  modify_task (task, arguments, description);

  if (description.length ())
    task.addAnnotation (description);
}

////////////////////////////////////////////////////////////////////////////////
// Worker function that does all the updates, but never overwrites description.
void Command::modify_task (
  Task& task,
  const A3& arguments,
  std::string& description)
{
  // Utilize Task::modify
  task.modify (arguments, description);
}

////////////////////////////////////////////////////////////////////////////////
// Disaster avoidance mechanism.
void Command::safety ()
{
  if (! _read_only)
  {
    A3 write_filter = context.a3.extract_filter ();
    if (!write_filter.size ())  // Potential disaster.
    {
      // If user is willing to be asked, this can be avoided.
      if (context.config.getBoolean ("confirmation") &&
          confirm (STRING_TASK_SAFETY_VALVE))
        return;

      // No.
      throw std::string (STRING_TASK_SAFETY_FAIL);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////
// Returns true or false indicating whether to proceed with a write command, on
// a per-task basis, after (potentially) asking for permission.
//
// Factors:
//   filtered.size ()
//   rc.bulk
//   rc.confirmation
//   this->_read_only
bool Command::permission (
  const Task& task,
  const std::string& question,
  unsigned int quantity)
{
  // Read-only commands do not need to seek permission.  Write commands are
  // granted permission automatically if the 'all' selection was made in an
  // earlier call.  Or if the 'all' option has already been made.
  if (_read_only ||
      _permission_all)
    return true;

  // If the 'quit' selection has already been made.
  if (_permission_quit)
    return false;

  // What remains are write commands that have not yet selected 'all' or 'quit'.
  // Describe the task.
  bool         confirmation = context.config.getBoolean ("confirmation");
  unsigned int bulk         = context.config.getInteger ("bulk");

  // Quantity 1 modifications have optional confirmation, and only (y/n).
  if (quantity == 1)
  {
    if (!_needs_confirm ||
        !confirmation)
      return true;

    bool answer = confirm (question);
    return answer;
  }

  // 1 < Quantity < bulk modifications have optional confirmation, in the (y/n/a/q)
  // style.
  if (quantity < bulk && (!_needs_confirm || !confirmation))
    return true;

  if (context.verbose ("blank") && !_first_iteration)
    std::cout << "\n";
  int answer = confirm4 (question);
  _first_iteration = false;
  switch (answer)
  {
  case 1:                           return true;     // yes
  case 2: _permission_all  = true;  return true;     // all
  case 3: _permission_quit = true;  return false;    // quit
  }

  return false;  // This line keeps the compiler happy.
}

////////////////////////////////////////////////////////////////////////////////
