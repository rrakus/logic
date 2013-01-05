/*
 * TerminalIO.cpp
 *
 *  Created on: Dec 31, 2012
 *      Author: rrakus
 */

#include "TerminalIO.h"
#include "Overview.h"
#include "Logic_core.h"
#include <iostream>
#include <iomanip>

namespace Logic
{
  using namespace std;
  using namespace Logic_core;

  TerminalIO::TerminalIO()
  {
    cout << "Welcome to Logic game\n";
  }

  Bigpinset TerminalIO::read()
  {
    Bigpinset b;
    string in;
    for (int i = 0; i < num_pins; i++)
    {
      retry:
      cout << i+1 << " of " << num_pins << ": ";
      cin >> in;
      try
      {
        try_add(b, in);
      }
      catch (Not_valid_color& nvc)
      {
        cout << in << " is invalid color. Please try one of ";
        cout << "red green blue black white yellow grey brown\n";
        goto retry;
      }
      cout << in << "\n";
    }
    return b;
  }

  Bigpinset& TerminalIO::try_add(Bigpinset& b, const string& color)
  {
    if (color == "red") { b.add(Bigpin::RED); return b; }
    if (color == "green") { b.add(Bigpin::GREEN); return b; }
    if (color == "blue") { b.add(Bigpin::BLUE); return b; }
    if (color == "black") { b.add(Bigpin::BLACK); return b; }
    if (color == "white") { b.add(Bigpin::WHITE); return b; }
    if (color == "yellow") { b.add(Bigpin::YELLOW); return b; }
    if (color == "grey") { b.add(Bigpin::GREY); return b; }
    if (color == "brown") { b.add(Bigpin::BROWN); return b; }
    throw Not_valid_color();
  }

  void TerminalIO::show(const Logic_core::Overview& o, bool show_hidden)
  {
    try
    {
      for (int i = 0; i < num_chances; i++)
      {
        BSPair *p = o[i];
        cout << i+1 << " of " << num_chances << ": ";
        print(p->first);
        cout << " --- ";
        print(p->second);
        cout << "\n";
      }
    }
    catch (Out_of_range& oor) {};
    if (show_hidden)
      {
        print(o.get_to_guess());
        cout << "\n";
      }
    else
      {
        print_hidden();
      }
    return;
  }

  bool TerminalIO::play_again()
  {
    std::string again;
    while(1)
    {
      cout << "Do you want to play again? [y/n]";
      cin >> again;
      if (again == "y") return true;
      if (again == "n") return false;
    }
  }

  void TerminalIO::win()
  {
    cout << "Congratulations. You have win!\n";
    return;
  }

  void TerminalIO::print_hidden()
  {
    for (int i = 0; i < num_pins; i++)
    {
      cout << std::setw(7) << "??? ";
    }
    cout << "\n";
  }

  TerminalIO::~TerminalIO()
  {
    cout << "Bye bye\n";
  }

  void TerminalIO::print(const Bigpinset& b)
  {
    try
    {
      for (int i = 0; i < num_pins; i++)
      {
        print(b[i]);
      }
    }
    catch (Out_of_range& o) {};
    return;
  }

  void TerminalIO::print(const Smallpinset& s)
  {
    try
    {
      for (int i = 0; i < num_pins; i++)
      {
        print(s[i]);
      }
    }
    catch (Out_of_range& o) {};
    return;
  }

  void TerminalIO::print(const Smallpin& s)
  {
    cout << s;
    return;
  }

  void TerminalIO::print(const Bigpin& s)
  {
    cout << s;
    return;
  }
}
