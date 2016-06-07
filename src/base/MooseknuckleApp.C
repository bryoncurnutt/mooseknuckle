#include "MooseknuckleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<MooseknuckleApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MooseknuckleApp::MooseknuckleApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MooseknuckleApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MooseknuckleApp::associateSyntax(_syntax, _action_factory);
}

MooseknuckleApp::~MooseknuckleApp()
{
}

// External entry point for dynamic application loading
extern "C" void MooseknuckleApp__registerApps() { MooseknuckleApp::registerApps(); }
void
MooseknuckleApp::registerApps()
{
  registerApp(MooseknuckleApp);
}

// External entry point for dynamic object registration
extern "C" void MooseknuckleApp__registerObjects(Factory & factory) { MooseknuckleApp::registerObjects(factory); }
void
MooseknuckleApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MooseknuckleApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MooseknuckleApp::associateSyntax(syntax, action_factory); }
void
MooseknuckleApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
