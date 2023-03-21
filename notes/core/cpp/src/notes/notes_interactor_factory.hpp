#pragma once

#include <memory>
#include "notes_interactor.hpp"

class NotesInteractorFactory {
 public:
  static std::shared_ptr<NotesInteractor> create();
};