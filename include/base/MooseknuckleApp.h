#ifndef MOOSEKNUCKLEAPP_H
#define MOOSEKNUCKLEAPP_H

#include "MooseApp.h"

class MooseknuckleApp;

template<>
InputParameters validParams<MooseknuckleApp>();

class MooseknuckleApp : public MooseApp
{
public:
  MooseknuckleApp(InputParameters parameters);
  virtual ~MooseknuckleApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSEKNUCKLEAPP_H */
