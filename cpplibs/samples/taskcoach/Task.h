
/**
 * @file Task.h
 */

/**********************************************************************

  Created: 17 May 2008

    Copyright (C) 2008 Frank Buss, J�r�me Laheurte

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The names of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**********************************************************************/
// $Id$

#ifndef _TASK_H
#define _TASK_H

#include <string>
#include <list>

#include <time.h>
#include <stdio.h>

class Task
{
  public:
    Task(const std::string&,
         const std::string&,
         const std::string& startDate,
         const std::string& dueDate,
         const std::string& completionDate,
         bool dirty=false);
    ~Task();

    void addChild(Task*);

    const std::string& subject();
    std::list<Task*>& children();

    bool completed();
    bool overdue();
    bool inactive();
    bool active();
    bool dueToday();

    void markCompleted();

    void write(FILE*, unsigned int);

  protected:
    std::string m_ID;
    std::string m_Subject;
    std::string m_StartDate;
    std::string m_DueDate;
    std::string m_CompletionDate;
    bool m_bDirty;
    std::list<Task*> m_Children;
};

#endif /* _TASK_H */
