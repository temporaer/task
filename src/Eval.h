////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2013 - 2014, Paul Beckingham, Federico Hernandez.
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

#ifndef INCLUDED_EVAL
#define INCLUDED_EVAL

#include <vector>
#include <string>
#include <Lexer.h>
#include <Variant.h>

class Eval
{
public:
  Eval ();
  virtual ~Eval ();
  Eval (const Eval&);            // Not implemented.
  Eval& operator= (const Eval&); // Not implemented.
  bool operator== (const Eval&); // Not implemented.

  void addSource (bool (*fn)(const std::string&, Variant&));
  void evaluateInfixExpression (const std::string&, Variant&) const;
  void evaluatePostfixExpression (const std::string&, Variant&) const;
  void ambiguity (bool);
  void debug ();

private:
  void evaluatePostfixStack (const std::vector <std::pair <std::string, Lexer::Type> >&, Variant&) const;
  void infixToPostfix (std::vector <std::pair <std::string, Lexer::Type> >&) const;
  bool identifyOperator (const std::string&, char&, int&, char&) const;

private:
  std::vector <bool (*)(const std::string&, Variant&)> _sources;
  bool _ambiguity;
  bool _debug;
};



#endif

////////////////////////////////////////////////////////////////////////////////