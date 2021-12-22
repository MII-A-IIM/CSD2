#pragma once

#include <iostream>

class UserInput
{
public:
  // returns the users choice, which depends on the passed selectionOptions
  static std::string retrieveSelection(std::string selectionOptions[],
    int numOptions);

  // returns the index of the users choice in the passed selectionOptions array
  static int retrieveSelectionIndex(std::string selectionOptions[],
    int numOptions);

  // returns the users input value, which has to be in the range of [min, max]
  static float retrieveValueInRange(float min, float max);
  //gets user input and returns input length
  static int retrieveMelodyInput();

protected:
  // hide default constructor and destructor
  UserInput() {};
  ~UserInput() {};
  static bool validateSelection(std::string selection, std::string selectionOptions[],
      int numOptions);
  static std::string retrieveInput(std::string selectionOptions[], int numOptions);

};
