#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TDF_Attribute.hxx>
#include <Standard_Handle.hxx>
#include <TFunction_Function.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <TFunction_Logbook.hxx>
#include <TDF_LabelMap.hxx>
#include <Standard_Transient.hxx>
#include <TDF_LabelList.hxx>
#include <TFunction_Driver.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <TFunction_DataMapOfGUIDDriver.hxx>
#include <NCollection_Array1.hxx>
#include <TFunction_Array1OfDataMapOfGUIDDriver.hxx>
#include <TFunction_DataMapOfLabelListOfLabel.hxx>
#include <NCollection_DoubleMap.hxx>
#include <TFunction_DoubleMapOfIntegerLabel.hxx>
#include <TFunction_HArray1OfDataMapOfGUIDDriver.hxx>
#include <TFunction_DriverTable.hxx>
#include <TFunction_ExecutionStatus.hxx>
#include <TFunction_GraphNode.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TFunction_IFunction.hxx>
#include <TFunction_Scope.hxx>
#include <TFunction_Iterator.hxx>

PYBIND11_MODULE(TFunction, mod) {

	// IMPORT
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_ExecutionStatus.hxx
	py::enum_<TFunction_ExecutionStatus>(mod, "TFunction_ExecutionStatus", "None")
		.value("TFunction_ES_WrongDefinition", TFunction_ExecutionStatus::TFunction_ES_WrongDefinition)
		.value("TFunction_ES_NotExecuted", TFunction_ExecutionStatus::TFunction_ES_NotExecuted)
		.value("TFunction_ES_Executing", TFunction_ExecutionStatus::TFunction_ES_Executing)
		.value("TFunction_ES_Succeeded", TFunction_ExecutionStatus::TFunction_ES_Succeeded)
		.value("TFunction_ES_Failed", TFunction_ExecutionStatus::TFunction_ES_Failed)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_Function.hxx
	py::class_<TFunction_Function, opencascade::handle<TFunction_Function>, TDF_Attribute> cls_TFunction_Function(mod, "TFunction_Function", "Provides the following two services - a link to an evaluation driver - the means of providing a link between a function and an evaluation driver.");
	cls_TFunction_Function.def(py::init<>());
	cls_TFunction_Function.def_static("Set_", (opencascade::handle<TFunction_Function> (*)(const TDF_Label &)) &TFunction_Function::Set, "Static methods: ============== Finds or Creates a function attribute on the label <L>. Returns the function attribute.", py::arg("L"));
	cls_TFunction_Function.def_static("Set_", (opencascade::handle<TFunction_Function> (*)(const TDF_Label &, const Standard_GUID &)) &TFunction_Function::Set, "Finds or Creates a function attribute on the label <L>. Sets a driver ID to the function. Returns the function attribute.", py::arg("L"), py::arg("DriverID"));
	cls_TFunction_Function.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Function::GetID, "Returns the GUID for functions. Returns a function found on the label. Instance methods: ================");
	cls_TFunction_Function.def("GetDriverGUID", (const Standard_GUID & (TFunction_Function::*)() const ) &TFunction_Function::GetDriverGUID, "Returns the GUID for this function's driver.");
	cls_TFunction_Function.def("SetDriverGUID", (void (TFunction_Function::*)(const Standard_GUID &)) &TFunction_Function::SetDriverGUID, "Sets the driver for this function as that indentified by the GUID guid.", py::arg("guid"));
	cls_TFunction_Function.def("Failed", (Standard_Boolean (TFunction_Function::*)() const ) &TFunction_Function::Failed, "Returns true if the execution failed");
	cls_TFunction_Function.def("SetFailure", [](TFunction_Function &self) -> void { return self.SetFailure(); });
	cls_TFunction_Function.def("SetFailure", (void (TFunction_Function::*)(const Standard_Integer)) &TFunction_Function::SetFailure, "Sets the failed index.", py::arg("mode"));
	cls_TFunction_Function.def("GetFailure", (Standard_Integer (TFunction_Function::*)() const ) &TFunction_Function::GetFailure, "Returns an index of failure if the execution of this function failed. If this integer value is 0, no failure has occurred. Implementation of Attribute methods: ===================================");
	cls_TFunction_Function.def("ID", (const Standard_GUID & (TFunction_Function::*)() const ) &TFunction_Function::ID, "None");
	cls_TFunction_Function.def("Restore", (void (TFunction_Function::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Function::Restore, "None", py::arg("with"));
	cls_TFunction_Function.def("Paste", (void (TFunction_Function::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TFunction_Function::Paste, "None", py::arg("into"), py::arg("RT"));
	cls_TFunction_Function.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Function::*)() const ) &TFunction_Function::NewEmpty, "None");
	cls_TFunction_Function.def("References", (void (TFunction_Function::*)(const opencascade::handle<TDF_DataSet> &) const ) &TFunction_Function::References, "None", py::arg("aDataSet"));
	// FIXME cls_TFunction_Function.def("Dump", (Standard_OStream & (TFunction_Function::*)(Standard_OStream &) const ) &TFunction_Function::Dump, "None", py::arg("anOS"));
	cls_TFunction_Function.def_static("get_type_name_", (const char * (*)()) &TFunction_Function::get_type_name, "None");
	cls_TFunction_Function.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Function::get_type_descriptor, "None");
	cls_TFunction_Function.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Function::*)() const ) &TFunction_Function::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_Logbook.hxx
	py::class_<TFunction_Logbook, opencascade::handle<TFunction_Logbook>, TDF_Attribute> cls_TFunction_Logbook(mod, "TFunction_Logbook", "This class contains information which is written and read during the solving process. Information is divided in three groups.");
	cls_TFunction_Logbook.def(py::init<>());
	cls_TFunction_Logbook.def_static("Set_", (opencascade::handle<TFunction_Logbook> (*)(const TDF_Label &)) &TFunction_Logbook::Set, "Finds or Creates a TFunction_Logbook attribute at the root label accessed by <Access>. Returns the attribute.", py::arg("Access"));
	cls_TFunction_Logbook.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Logbook::GetID, "Returns the GUID for logbook attribute.");
	cls_TFunction_Logbook.def("Clear", (void (TFunction_Logbook::*)()) &TFunction_Logbook::Clear, "Clears this logbook to its default, empty state.");
	cls_TFunction_Logbook.def("IsEmpty", (Standard_Boolean (TFunction_Logbook::*)() const ) &TFunction_Logbook::IsEmpty, "None");
	cls_TFunction_Logbook.def("SetTouched", (void (TFunction_Logbook::*)(const TDF_Label &)) &TFunction_Logbook::SetTouched, "Sets the label L as a touched label in this logbook. In other words, L is understood to have been modified by the end user.", py::arg("L"));
	cls_TFunction_Logbook.def("SetImpacted", [](TFunction_Logbook &self, const TDF_Label & a0) -> void { return self.SetImpacted(a0); }, py::arg("L"));
	cls_TFunction_Logbook.def("SetImpacted", (void (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean)) &TFunction_Logbook::SetImpacted, "Sets the label L as an impacted label in this logbook. This method is called by execution of the function driver.", py::arg("L"), py::arg("WithChildren"));
	cls_TFunction_Logbook.def("SetValid", [](TFunction_Logbook &self, const TDF_Label & a0) -> void { return self.SetValid(a0); }, py::arg("L"));
	cls_TFunction_Logbook.def("SetValid", (void (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean)) &TFunction_Logbook::SetValid, "Sets the label L as a valid label in this logbook.", py::arg("L"), py::arg("WithChildren"));
	cls_TFunction_Logbook.def("SetValid", (void (TFunction_Logbook::*)(const TDF_LabelMap &)) &TFunction_Logbook::SetValid, "None", py::arg("Ls"));
	cls_TFunction_Logbook.def("IsModified", [](TFunction_Logbook &self, const TDF_Label & a0) -> Standard_Boolean { return self.IsModified(a0); }, py::arg("L"));
	cls_TFunction_Logbook.def("IsModified", (Standard_Boolean (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean) const ) &TFunction_Logbook::IsModified, "Returns True if the label L is touched or impacted. This method is called by <TFunction_FunctionDriver::MustExecute>. If <WithChildren> is set to true, the method checks all the sublabels of <L> too.", py::arg("L"), py::arg("WithChildren"));
	cls_TFunction_Logbook.def("GetTouched", (const TDF_LabelMap & (TFunction_Logbook::*)() const ) &TFunction_Logbook::GetTouched, "Returns the map of touched labels in this logbook. A touched label is the one modified by the end user.");
	cls_TFunction_Logbook.def("GetImpacted", (const TDF_LabelMap & (TFunction_Logbook::*)() const ) &TFunction_Logbook::GetImpacted, "Returns the map of impacted labels contained in this logbook.");
	cls_TFunction_Logbook.def("GetValid", (const TDF_LabelMap & (TFunction_Logbook::*)() const ) &TFunction_Logbook::GetValid, "Returns the map of valid labels in this logbook.");
	cls_TFunction_Logbook.def("GetValid", (void (TFunction_Logbook::*)(TDF_LabelMap &) const ) &TFunction_Logbook::GetValid, "None", py::arg("Ls"));
	cls_TFunction_Logbook.def("Done", (void (TFunction_Logbook::*)(const Standard_Boolean)) &TFunction_Logbook::Done, "Sets status of execution.", py::arg("status"));
	cls_TFunction_Logbook.def("IsDone", (Standard_Boolean (TFunction_Logbook::*)() const ) &TFunction_Logbook::IsDone, "Returns status of execution.");
	cls_TFunction_Logbook.def("ID", (const Standard_GUID & (TFunction_Logbook::*)() const ) &TFunction_Logbook::ID, "Returns the ID of the attribute.");
	cls_TFunction_Logbook.def("Restore", (void (TFunction_Logbook::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Logbook::Restore, "Undos (and redos) the attribute.", py::arg("with"));
	cls_TFunction_Logbook.def("Paste", (void (TFunction_Logbook::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TFunction_Logbook::Paste, "Pastes the attribute to another label.", py::arg("into"), py::arg("RT"));
	cls_TFunction_Logbook.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Logbook::*)() const ) &TFunction_Logbook::NewEmpty, "Returns a new empty instance of the attribute.");
	// FIXME cls_TFunction_Logbook.def("Dump", (Standard_OStream & (TFunction_Logbook::*)(Standard_OStream &) const ) &TFunction_Logbook::Dump, "Prints th data of the attributes (touched, impacted and valid labels).", py::arg("anOS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_Driver.hxx
	py::class_<TFunction_Driver, opencascade::handle<TFunction_Driver>, Standard_Transient> cls_TFunction_Driver(mod, "TFunction_Driver", "This driver class provide services around function execution. One instance of this class is built for the whole session. The driver is bound to the DriverGUID in the DriverTable class. It allows you to create classes which inherit from this abstract class. These subclasses identify the various algorithms which can be applied to the data contained in the attributes of sub-labels of a model. A single instance of this class and each of its subclasses is built for the whole session.");
	cls_TFunction_Driver.def("Init", (void (TFunction_Driver::*)(const TDF_Label &)) &TFunction_Driver::Init, "Initializes the label L for this function prior to its execution.", py::arg("L"));
	cls_TFunction_Driver.def("Label", (TDF_Label (TFunction_Driver::*)() const ) &TFunction_Driver::Label, "Returns the label of the driver for this function.");
	cls_TFunction_Driver.def("Validate", (void (TFunction_Driver::*)(opencascade::handle<TFunction_Logbook> &) const ) &TFunction_Driver::Validate, "Validates labels of a function in <log>. This function is the one initialized in this function driver. Warning In regeneration mode, the solver must call this method even if the function is not executed. execution of function =====================", py::arg("log"));
	cls_TFunction_Driver.def("MustExecute", (Standard_Boolean (TFunction_Driver::*)(const opencascade::handle<TFunction_Logbook> &) const ) &TFunction_Driver::MustExecute, "Analyzes the labels in the logbook log. Returns true if attributes have been modified. If the function label itself has been modified, the function must be executed.", py::arg("log"));
	cls_TFunction_Driver.def("Execute", (Standard_Integer (TFunction_Driver::*)(opencascade::handle<TFunction_Logbook> &) const ) &TFunction_Driver::Execute, "Executes the function in this function driver and puts the impacted labels in the logbook log. arguments & results of functions ================================", py::arg("log"));
	cls_TFunction_Driver.def("Arguments", (void (TFunction_Driver::*)(TDF_LabelList &) const ) &TFunction_Driver::Arguments, "The method fills-in the list by labels, where the arguments of the function are located.", py::arg("args"));
	cls_TFunction_Driver.def("Results", (void (TFunction_Driver::*)(TDF_LabelList &) const ) &TFunction_Driver::Results, "The method fills-in the list by labels, where the results of the function are located.", py::arg("res"));
	cls_TFunction_Driver.def_static("get_type_name_", (const char * (*)()) &TFunction_Driver::get_type_name, "None");
	cls_TFunction_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Driver::get_type_descriptor, "None");
	cls_TFunction_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Driver::*)() const ) &TFunction_Driver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TFunction_Array1OfDataMapOfGUIDDriver, std::unique_ptr<TFunction_Array1OfDataMapOfGUIDDriver, Deleter<TFunction_Array1OfDataMapOfGUIDDriver>>> cls_TFunction_Array1OfDataMapOfGUIDDriver(mod, "TFunction_Array1OfDataMapOfGUIDDriver", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def(py::init<>());
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def(py::init([] (const TFunction_Array1OfDataMapOfGUIDDriver &other) {return new TFunction_Array1OfDataMapOfGUIDDriver(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TFunction_Array1OfDataMapOfGUIDDriver.def(py::init<TFunction_Array1OfDataMapOfGUIDDriver &&>(), py::arg("theOther"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def(py::init<const TFunction_DataMapOfGUIDDriver &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("begin", (TFunction_Array1OfDataMapOfGUIDDriver::iterator (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("end", (TFunction_Array1OfDataMapOfGUIDDriver::iterator (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("cbegin", (TFunction_Array1OfDataMapOfGUIDDriver::const_iterator (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("cend", (TFunction_Array1OfDataMapOfGUIDDriver::const_iterator (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Init", (void (TFunction_Array1OfDataMapOfGUIDDriver::*)(const TFunction_DataMapOfGUIDDriver &)) &TFunction_Array1OfDataMapOfGUIDDriver::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Size", (Standard_Integer (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::Size, "Size query");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Length", (Standard_Integer (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::Length, "Length query (the same)");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("IsEmpty", (Standard_Boolean (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::IsEmpty, "Return TRUE if array has zero length.");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Lower", (Standard_Integer (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::Lower, "Lower bound");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Upper", (Standard_Integer (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::Upper, "Upper bound");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("IsDeletable", (Standard_Boolean (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::IsDeletable, "myDeletable flag");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("IsAllocated", (Standard_Boolean (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Assign", (TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(const TFunction_Array1OfDataMapOfGUIDDriver &)) &TFunction_Array1OfDataMapOfGUIDDriver::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Move", (TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(TFunction_Array1OfDataMapOfGUIDDriver &&)) &TFunction_Array1OfDataMapOfGUIDDriver::Move, "Move assignment", py::arg("theOther"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("assign", (TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(const TFunction_Array1OfDataMapOfGUIDDriver &)) &TFunction_Array1OfDataMapOfGUIDDriver::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TFunction_Array1OfDataMapOfGUIDDriver.def("assign", (TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(TFunction_Array1OfDataMapOfGUIDDriver &&)) &TFunction_Array1OfDataMapOfGUIDDriver::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("First", (const TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::First, "Returns first element");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("ChangeFirst", (TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)()) &TFunction_Array1OfDataMapOfGUIDDriver::ChangeFirst, "Returns first element");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Last", (const TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)() const ) &TFunction_Array1OfDataMapOfGUIDDriver::Last, "Returns last element");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("ChangeLast", (TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)()) &TFunction_Array1OfDataMapOfGUIDDriver::ChangeLast, "Returns last element");
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Value", (const TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(const Standard_Integer) const ) &TFunction_Array1OfDataMapOfGUIDDriver::Value, "Constant value access", py::arg("theIndex"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("__call__", (const TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(const Standard_Integer) const ) &TFunction_Array1OfDataMapOfGUIDDriver::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("ChangeValue", (TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(const Standard_Integer)) &TFunction_Array1OfDataMapOfGUIDDriver::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("__call__", (TFunction_DataMapOfGUIDDriver & (TFunction_Array1OfDataMapOfGUIDDriver::*)(const Standard_Integer)) &TFunction_Array1OfDataMapOfGUIDDriver::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("SetValue", (void (TFunction_Array1OfDataMapOfGUIDDriver::*)(const Standard_Integer, const TFunction_DataMapOfGUIDDriver &)) &TFunction_Array1OfDataMapOfGUIDDriver::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("Resize", (void (TFunction_Array1OfDataMapOfGUIDDriver::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TFunction_Array1OfDataMapOfGUIDDriver::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TFunction_Array1OfDataMapOfGUIDDriver.def("__iter__", [](const TFunction_Array1OfDataMapOfGUIDDriver &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_DriverTable.hxx
	py::class_<TFunction_DriverTable, opencascade::handle<TFunction_DriverTable>, Standard_Transient> cls_TFunction_DriverTable(mod, "TFunction_DriverTable", "A container for instances of drivers. You create a new instance of TFunction_Driver and use the method AddDriver to load it into the driver table.");
	cls_TFunction_DriverTable.def(py::init<>());
	cls_TFunction_DriverTable.def_static("Get_", (opencascade::handle<TFunction_DriverTable> (*)()) &TFunction_DriverTable::Get, "Returns the driver table. If a driver does not exist, creates it.");
	cls_TFunction_DriverTable.def("AddDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0, const opencascade::handle<TFunction_Driver> & a1) -> Standard_Boolean { return self.AddDriver(a0, a1); }, py::arg("guid"), py::arg("driver"));
	cls_TFunction_DriverTable.def("AddDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const opencascade::handle<TFunction_Driver> &, const Standard_Integer)) &TFunction_DriverTable::AddDriver, "Returns true if the driver has been added successfully to the driver table.", py::arg("guid"), py::arg("driver"), py::arg("thread"));
	cls_TFunction_DriverTable.def("HasDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0) -> Standard_Boolean { return self.HasDriver(a0); }, py::arg("guid"));
	cls_TFunction_DriverTable.def("HasDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const Standard_Integer) const ) &TFunction_DriverTable::HasDriver, "Returns true if the driver exists in the driver table.", py::arg("guid"), py::arg("thread"));
	cls_TFunction_DriverTable.def("FindDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0, opencascade::handle<TFunction_Driver> & a1) -> Standard_Boolean { return self.FindDriver(a0, a1); }, py::arg("guid"), py::arg("driver"));
	cls_TFunction_DriverTable.def("FindDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, opencascade::handle<TFunction_Driver> &, const Standard_Integer) const ) &TFunction_DriverTable::FindDriver, "Returns true if the driver was found.", py::arg("guid"), py::arg("driver"), py::arg("thread"));
	// FIXME cls_TFunction_DriverTable.def("Dump", (Standard_OStream & (TFunction_DriverTable::*)(Standard_OStream &) const ) &TFunction_DriverTable::Dump, "None", py::arg("anOS"));
	// FIXME cls_TFunction_DriverTable.def("operator<<", (Standard_OStream & (TFunction_DriverTable::*)(Standard_OStream &) const ) &TFunction_DriverTable::operator<<, "None", py::arg("anOS"));
	cls_TFunction_DriverTable.def("RemoveDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0) -> Standard_Boolean { return self.RemoveDriver(a0); }, py::arg("guid"));
	cls_TFunction_DriverTable.def("RemoveDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const Standard_Integer)) &TFunction_DriverTable::RemoveDriver, "Removes a driver with the given GUID. Returns true if the driver has been removed successfully.", py::arg("guid"), py::arg("thread"));
	cls_TFunction_DriverTable.def("Clear", (void (TFunction_DriverTable::*)()) &TFunction_DriverTable::Clear, "Removes all drivers. Returns true if the driver has been removed successfully.");
	cls_TFunction_DriverTable.def_static("get_type_name_", (const char * (*)()) &TFunction_DriverTable::get_type_name, "None");
	cls_TFunction_DriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_DriverTable::get_type_descriptor, "None");
	cls_TFunction_DriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_DriverTable::*)() const ) &TFunction_DriverTable::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_GraphNode.hxx
	py::class_<TFunction_GraphNode, opencascade::handle<TFunction_GraphNode>, TDF_Attribute> cls_TFunction_GraphNode(mod, "TFunction_GraphNode", "Provides links between functions.");
	cls_TFunction_GraphNode.def(py::init<>());
	cls_TFunction_GraphNode.def_static("Set_", (opencascade::handle<TFunction_GraphNode> (*)(const TDF_Label &)) &TFunction_GraphNode::Set, "Static methods ============== Finds or Creates a graph node attribute at the label <L>. Returns the attribute.", py::arg("L"));
	cls_TFunction_GraphNode.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_GraphNode::GetID, "Returns the GUID for GraphNode attribute. Instant methods =============== Constructor (empty).");
	cls_TFunction_GraphNode.def("AddPrevious", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::AddPrevious, "Defines a reference to the function as a previous one.", py::arg("funcID"));
	cls_TFunction_GraphNode.def("AddPrevious", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::AddPrevious, "Defines a reference to the function as a previous one.", py::arg("func"));
	cls_TFunction_GraphNode.def("RemovePrevious", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::RemovePrevious, "Removes a reference to the function as a previous one.", py::arg("funcID"));
	cls_TFunction_GraphNode.def("RemovePrevious", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::RemovePrevious, "Removes a reference to the function as a previous one.", py::arg("func"));
	cls_TFunction_GraphNode.def("GetPrevious", (const TColStd_MapOfInteger & (TFunction_GraphNode::*)() const ) &TFunction_GraphNode::GetPrevious, "Returns a map of previous functions.");
	cls_TFunction_GraphNode.def("RemoveAllPrevious", (void (TFunction_GraphNode::*)()) &TFunction_GraphNode::RemoveAllPrevious, "Clears a map of previous functions.");
	cls_TFunction_GraphNode.def("AddNext", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::AddNext, "Defines a reference to the function as a next one.", py::arg("funcID"));
	cls_TFunction_GraphNode.def("AddNext", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::AddNext, "Defines a reference to the function as a next one.", py::arg("func"));
	cls_TFunction_GraphNode.def("RemoveNext", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::RemoveNext, "Removes a reference to the function as a next one.", py::arg("funcID"));
	cls_TFunction_GraphNode.def("RemoveNext", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::RemoveNext, "Removes a reference to the function as a next one.", py::arg("func"));
	cls_TFunction_GraphNode.def("GetNext", (const TColStd_MapOfInteger & (TFunction_GraphNode::*)() const ) &TFunction_GraphNode::GetNext, "Returns a map of next functions.");
	cls_TFunction_GraphNode.def("RemoveAllNext", (void (TFunction_GraphNode::*)()) &TFunction_GraphNode::RemoveAllNext, "Clears a map of next functions.");
	cls_TFunction_GraphNode.def("GetStatus", (TFunction_ExecutionStatus (TFunction_GraphNode::*)() const ) &TFunction_GraphNode::GetStatus, "Returns the execution status of the function.");
	cls_TFunction_GraphNode.def("SetStatus", (void (TFunction_GraphNode::*)(const TFunction_ExecutionStatus)) &TFunction_GraphNode::SetStatus, "Defines an execution status for a function. Implementation of Attribute methods ===================================", py::arg("status"));
	cls_TFunction_GraphNode.def("ID", (const Standard_GUID & (TFunction_GraphNode::*)() const ) &TFunction_GraphNode::ID, "None");
	cls_TFunction_GraphNode.def("Restore", (void (TFunction_GraphNode::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_GraphNode::Restore, "None", py::arg("with"));
	cls_TFunction_GraphNode.def("Paste", (void (TFunction_GraphNode::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TFunction_GraphNode::Paste, "None", py::arg("into"), py::arg("RT"));
	cls_TFunction_GraphNode.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_GraphNode::*)() const ) &TFunction_GraphNode::NewEmpty, "None");
	cls_TFunction_GraphNode.def("References", (void (TFunction_GraphNode::*)(const opencascade::handle<TDF_DataSet> &) const ) &TFunction_GraphNode::References, "None", py::arg("aDataSet"));
	// FIXME cls_TFunction_GraphNode.def("Dump", (Standard_OStream & (TFunction_GraphNode::*)(Standard_OStream &) const ) &TFunction_GraphNode::Dump, "None", py::arg("anOS"));
	cls_TFunction_GraphNode.def_static("get_type_name_", (const char * (*)()) &TFunction_GraphNode::get_type_name, "None");
	cls_TFunction_GraphNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_GraphNode::get_type_descriptor, "None");
	cls_TFunction_GraphNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_GraphNode::*)() const ) &TFunction_GraphNode::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_IFunction.hxx
	py::class_<TFunction_IFunction, std::unique_ptr<TFunction_IFunction, Deleter<TFunction_IFunction>>> cls_TFunction_IFunction(mod, "TFunction_IFunction", "Interface class for usage of Function Mechanism");
	cls_TFunction_IFunction.def(py::init<>());
	cls_TFunction_IFunction.def(py::init<const TDF_Label &>(), py::arg("L"));
	cls_TFunction_IFunction.def_static("NewFunction_", (Standard_Boolean (*)(const TDF_Label &, const Standard_GUID &)) &TFunction_IFunction::NewFunction, "Sets a new function attached to a label <L> with <ID>. It creates a new TFunction_Function attribute initialized by the <ID>, a new TFunction_GraphNode with an empty list of dependencies and the status equal to TFunction_ES_WrongDefinition. It registers the function in the scope of functions for this document.", py::arg("L"), py::arg("ID"));
	cls_TFunction_IFunction.def_static("DeleteFunction_", (Standard_Boolean (*)(const TDF_Label &)) &TFunction_IFunction::DeleteFunction, "Deletes a function attached to a label <L>. It deletes a TFunction_Function attribute and a TFunction_GraphNode. It deletes the functions from the scope of function of this document.", py::arg("L"));
	cls_TFunction_IFunction.def_static("UpdateDependencies_", (Standard_Boolean (*)(const TDF_Label &)) &TFunction_IFunction::UpdateDependencies, "Updates dependencies for all functions of the scope. It returns false in case of an error. An empty constructor.", py::arg("Access"));
	cls_TFunction_IFunction.def("Init", (void (TFunction_IFunction::*)(const TDF_Label &)) &TFunction_IFunction::Init, "Initializes the interface by the label of function.", py::arg("L"));
	cls_TFunction_IFunction.def("Label", (const TDF_Label & (TFunction_IFunction::*)() const ) &TFunction_IFunction::Label, "Returns a label of the function.");
	cls_TFunction_IFunction.def("UpdateDependencies", (Standard_Boolean (TFunction_IFunction::*)() const ) &TFunction_IFunction::UpdateDependencies, "Updates the dependencies of this function only.");
	cls_TFunction_IFunction.def("Arguments", (void (TFunction_IFunction::*)(TDF_LabelList &) const ) &TFunction_IFunction::Arguments, "The method fills-in the list by labels, where the arguments of the function are located.", py::arg("args"));
	cls_TFunction_IFunction.def("Results", (void (TFunction_IFunction::*)(TDF_LabelList &) const ) &TFunction_IFunction::Results, "The method fills-in the list by labels, where the results of the function are located.", py::arg("res"));
	cls_TFunction_IFunction.def("GetPrevious", (void (TFunction_IFunction::*)(TDF_LabelList &) const ) &TFunction_IFunction::GetPrevious, "Returns a list of previous functions.", py::arg("prev"));
	cls_TFunction_IFunction.def("GetNext", (void (TFunction_IFunction::*)(TDF_LabelList &) const ) &TFunction_IFunction::GetNext, "Returns a list of next functions.", py::arg("prev"));
	cls_TFunction_IFunction.def("GetStatus", (TFunction_ExecutionStatus (TFunction_IFunction::*)() const ) &TFunction_IFunction::GetStatus, "Returns the execution status of the function.");
	cls_TFunction_IFunction.def("SetStatus", (void (TFunction_IFunction::*)(const TFunction_ExecutionStatus) const ) &TFunction_IFunction::SetStatus, "Defines an execution status for a function.", py::arg("status"));
	cls_TFunction_IFunction.def("GetAllFunctions", (const TFunction_DoubleMapOfIntegerLabel & (TFunction_IFunction::*)() const ) &TFunction_IFunction::GetAllFunctions, "Returns the scope of all functions.");
	cls_TFunction_IFunction.def("GetLogbook", (opencascade::handle<TFunction_Logbook> (TFunction_IFunction::*)() const ) &TFunction_IFunction::GetLogbook, "Returns the Logbook - keeper of modifications.");
	cls_TFunction_IFunction.def("GetDriver", [](TFunction_IFunction &self) -> opencascade::handle<TFunction_Driver> { return self.GetDriver(); });
	cls_TFunction_IFunction.def("GetDriver", (opencascade::handle<TFunction_Driver> (TFunction_IFunction::*)(const Standard_Integer) const ) &TFunction_IFunction::GetDriver, "Returns a driver of the function.", py::arg("thread"));
	cls_TFunction_IFunction.def("GetGraphNode", (opencascade::handle<TFunction_GraphNode> (TFunction_IFunction::*)() const ) &TFunction_IFunction::GetGraphNode, "Returns a graph node of the function.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_Scope.hxx
	py::class_<TFunction_Scope, opencascade::handle<TFunction_Scope>, TDF_Attribute> cls_TFunction_Scope(mod, "TFunction_Scope", "Keeps a scope of functions.");
	cls_TFunction_Scope.def(py::init<>());
	cls_TFunction_Scope.def_static("Set_", (opencascade::handle<TFunction_Scope> (*)(const TDF_Label &)) &TFunction_Scope::Set, "Static methods ============== Finds or Creates a TFunction_Scope attribute at the root label accessed by <Access>. Returns the attribute.", py::arg("Access"));
	cls_TFunction_Scope.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Scope::GetID, "Returns the GUID for Scope attribute. Instant methods =============== Constructor (empty).");
	cls_TFunction_Scope.def("AddFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &)) &TFunction_Scope::AddFunction, "Adds a function to the scope of functions.", py::arg("L"));
	cls_TFunction_Scope.def("RemoveFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &)) &TFunction_Scope::RemoveFunction, "Removes a function from the scope of functions.", py::arg("L"));
	cls_TFunction_Scope.def("RemoveFunction", (Standard_Boolean (TFunction_Scope::*)(const Standard_Integer)) &TFunction_Scope::RemoveFunction, "Removes a function from the scope of functions.", py::arg("ID"));
	cls_TFunction_Scope.def("RemoveAllFunctions", (void (TFunction_Scope::*)()) &TFunction_Scope::RemoveAllFunctions, "Removes all functions from the scope of functions.");
	cls_TFunction_Scope.def("HasFunction", (Standard_Boolean (TFunction_Scope::*)(const Standard_Integer) const ) &TFunction_Scope::HasFunction, "Returns true if the function exists with such an ID.", py::arg("ID"));
	cls_TFunction_Scope.def("HasFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &) const ) &TFunction_Scope::HasFunction, "Returns true if the label contains a function of this scope.", py::arg("L"));
	cls_TFunction_Scope.def("GetFunction", (Standard_Integer (TFunction_Scope::*)(const TDF_Label &) const ) &TFunction_Scope::GetFunction, "Returns an ID of the function.", py::arg("L"));
	cls_TFunction_Scope.def("GetFunction", (const TDF_Label & (TFunction_Scope::*)(const Standard_Integer) const ) &TFunction_Scope::GetFunction, "Returns the label of the function with this ID.", py::arg("ID"));
	cls_TFunction_Scope.def("GetLogbook", (opencascade::handle<TFunction_Logbook> (TFunction_Scope::*)() const ) &TFunction_Scope::GetLogbook, "Returns the Logbook used in TFunction_Driver methods. Implementation of Attribute methods ===================================");
	cls_TFunction_Scope.def("ID", (const Standard_GUID & (TFunction_Scope::*)() const ) &TFunction_Scope::ID, "None");
	cls_TFunction_Scope.def("Restore", (void (TFunction_Scope::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Scope::Restore, "None", py::arg("with"));
	cls_TFunction_Scope.def("Paste", (void (TFunction_Scope::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const ) &TFunction_Scope::Paste, "None", py::arg("into"), py::arg("RT"));
	cls_TFunction_Scope.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Scope::*)() const ) &TFunction_Scope::NewEmpty, "None");
	// FIXME cls_TFunction_Scope.def("Dump", (Standard_OStream & (TFunction_Scope::*)(Standard_OStream &) const ) &TFunction_Scope::Dump, "None", py::arg("anOS"));
	cls_TFunction_Scope.def("GetFunctions", (const TFunction_DoubleMapOfIntegerLabel & (TFunction_Scope::*)() const ) &TFunction_Scope::GetFunctions, "Returns the scope of functions.");
	cls_TFunction_Scope.def("ChangeFunctions", (TFunction_DoubleMapOfIntegerLabel & (TFunction_Scope::*)()) &TFunction_Scope::ChangeFunctions, "Returns the scope of functions for modification. Warning: Don't use this method if You are not sure what You do!");
	cls_TFunction_Scope.def("SetFreeID", (void (TFunction_Scope::*)(const Standard_Integer)) &TFunction_Scope::SetFreeID, "None", py::arg("ID"));
	cls_TFunction_Scope.def("GetFreeID", (Standard_Integer (TFunction_Scope::*)() const ) &TFunction_Scope::GetFreeID, "None");
	cls_TFunction_Scope.def_static("get_type_name_", (const char * (*)()) &TFunction_Scope::get_type_name, "None");
	cls_TFunction_Scope.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Scope::get_type_descriptor, "None");
	cls_TFunction_Scope.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Scope::*)() const ) &TFunction_Scope::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_Iterator.hxx
	py::class_<TFunction_Iterator, std::unique_ptr<TFunction_Iterator, Deleter<TFunction_Iterator>>> cls_TFunction_Iterator(mod, "TFunction_Iterator", "Iterator of the graph of functions");
	cls_TFunction_Iterator.def(py::init<>());
	cls_TFunction_Iterator.def(py::init<const TDF_Label &>(), py::arg("Access"));
	cls_TFunction_Iterator.def("Init", (void (TFunction_Iterator::*)(const TDF_Label &)) &TFunction_Iterator::Init, "Initializes the Iterator.", py::arg("Access"));
	cls_TFunction_Iterator.def("SetUsageOfExecutionStatus", (void (TFunction_Iterator::*)(const Standard_Boolean)) &TFunction_Iterator::SetUsageOfExecutionStatus, "Defines the mode of iteration - usage or not of the execution status. If the iterator takes into account the execution status, the method ::Current() returns only 'not executed' functions while their status is not changed. If the iterator ignores the execution status, the method ::Current() returns the functions following their dependencies and ignoring the execution status.", py::arg("usage"));
	cls_TFunction_Iterator.def("GetUsageOfExecutionStatus", (Standard_Boolean (TFunction_Iterator::*)() const ) &TFunction_Iterator::GetUsageOfExecutionStatus, "Returns usage of execution status by the iterator.");
	cls_TFunction_Iterator.def("GetMaxNbThreads", (Standard_Integer (TFunction_Iterator::*)() const ) &TFunction_Iterator::GetMaxNbThreads, "Analyses the graph of dependencies and returns maximum number of threads may be used to calculate the model.");
	cls_TFunction_Iterator.def("Current", (const TDF_LabelList & (TFunction_Iterator::*)() const ) &TFunction_Iterator::Current, "Returns the current list of functions. If the iterator uses the execution status, the returned list contains only the functions with 'not executed' status.");
	cls_TFunction_Iterator.def("More", (Standard_Boolean (TFunction_Iterator::*)() const ) &TFunction_Iterator::More, "Returns false if the graph of functions is fully iterated.");
	cls_TFunction_Iterator.def("Next", (void (TFunction_Iterator::*)()) &TFunction_Iterator::Next, "Switches the iterator to the next list of current functions.");
	cls_TFunction_Iterator.def("GetStatus", (TFunction_ExecutionStatus (TFunction_Iterator::*)(const TDF_Label &) const ) &TFunction_Iterator::GetStatus, "A help-function aimed to help the user to check the status of retrurned function. It calls TFunction_GraphNode::GetStatus() inside.", py::arg("func"));
	cls_TFunction_Iterator.def("SetStatus", (void (TFunction_Iterator::*)(const TDF_Label &, const TFunction_ExecutionStatus) const ) &TFunction_Iterator::SetStatus, "A help-function aimed to help the user to change the execution status of a function. It calls TFunction_GraphNode::SetStatus() inside.", py::arg("func"), py::arg("status"));
	// FIXME cls_TFunction_Iterator.def("Dump", (Standard_OStream & (TFunction_Iterator::*)(Standard_OStream &) const ) &TFunction_Iterator::Dump, "None", py::arg("OS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TFunction_DataMapOfGUIDDriver, std::unique_ptr<TFunction_DataMapOfGUIDDriver, Deleter<TFunction_DataMapOfGUIDDriver>>, NCollection_BaseMap> cls_TFunction_DataMapOfGUIDDriver(mod, "TFunction_DataMapOfGUIDDriver", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TFunction_DataMapOfGUIDDriver.def(py::init<>());
	cls_TFunction_DataMapOfGUIDDriver.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TFunction_DataMapOfGUIDDriver.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TFunction_DataMapOfGUIDDriver.def(py::init([] (const TFunction_DataMapOfGUIDDriver &other) {return new TFunction_DataMapOfGUIDDriver(other);}), "Copy constructor", py::arg("other"));
	cls_TFunction_DataMapOfGUIDDriver.def("begin", (TFunction_DataMapOfGUIDDriver::iterator (TFunction_DataMapOfGUIDDriver::*)() const ) &TFunction_DataMapOfGUIDDriver::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TFunction_DataMapOfGUIDDriver.def("end", (TFunction_DataMapOfGUIDDriver::iterator (TFunction_DataMapOfGUIDDriver::*)() const ) &TFunction_DataMapOfGUIDDriver::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TFunction_DataMapOfGUIDDriver.def("cbegin", (TFunction_DataMapOfGUIDDriver::const_iterator (TFunction_DataMapOfGUIDDriver::*)() const ) &TFunction_DataMapOfGUIDDriver::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TFunction_DataMapOfGUIDDriver.def("cend", (TFunction_DataMapOfGUIDDriver::const_iterator (TFunction_DataMapOfGUIDDriver::*)() const ) &TFunction_DataMapOfGUIDDriver::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TFunction_DataMapOfGUIDDriver.def("Exchange", (void (TFunction_DataMapOfGUIDDriver::*)(TFunction_DataMapOfGUIDDriver &)) &TFunction_DataMapOfGUIDDriver::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TFunction_DataMapOfGUIDDriver.def("Assign", (TFunction_DataMapOfGUIDDriver & (TFunction_DataMapOfGUIDDriver::*)(const TFunction_DataMapOfGUIDDriver &)) &TFunction_DataMapOfGUIDDriver::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TFunction_DataMapOfGUIDDriver.def("assign", (TFunction_DataMapOfGUIDDriver & (TFunction_DataMapOfGUIDDriver::*)(const TFunction_DataMapOfGUIDDriver &)) &TFunction_DataMapOfGUIDDriver::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TFunction_DataMapOfGUIDDriver.def("ReSize", (void (TFunction_DataMapOfGUIDDriver::*)(const Standard_Integer)) &TFunction_DataMapOfGUIDDriver::ReSize, "ReSize", py::arg("N"));
	cls_TFunction_DataMapOfGUIDDriver.def("Bind", (Standard_Boolean (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &, const opencascade::handle<TFunction_Driver> &)) &TFunction_DataMapOfGUIDDriver::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TFunction_DataMapOfGUIDDriver.def("Bound", (opencascade::handle<TFunction_Driver> * (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &, const opencascade::handle<TFunction_Driver> &)) &TFunction_DataMapOfGUIDDriver::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TFunction_DataMapOfGUIDDriver.def("IsBound", (Standard_Boolean (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TFunction_DataMapOfGUIDDriver::IsBound, "IsBound", py::arg("theKey"));
	cls_TFunction_DataMapOfGUIDDriver.def("UnBind", (Standard_Boolean (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TFunction_DataMapOfGUIDDriver::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfGUIDDriver.def("Seek", (const opencascade::handle<TFunction_Driver> * (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TFunction_DataMapOfGUIDDriver::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfGUIDDriver.def("Find", (const opencascade::handle<TFunction_Driver> & (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TFunction_DataMapOfGUIDDriver::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfGUIDDriver.def("Find", (Standard_Boolean (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &, opencascade::handle<TFunction_Driver> &) const ) &TFunction_DataMapOfGUIDDriver::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TFunction_DataMapOfGUIDDriver.def("__call__", (const opencascade::handle<TFunction_Driver> & (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &) const ) &TFunction_DataMapOfGUIDDriver::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfGUIDDriver.def("ChangeSeek", (opencascade::handle<TFunction_Driver> * (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TFunction_DataMapOfGUIDDriver::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TFunction_DataMapOfGUIDDriver.def("ChangeFind", (opencascade::handle<TFunction_Driver> & (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TFunction_DataMapOfGUIDDriver::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TFunction_DataMapOfGUIDDriver.def("__call__", (opencascade::handle<TFunction_Driver> & (TFunction_DataMapOfGUIDDriver::*)(const Standard_GUID &)) &TFunction_DataMapOfGUIDDriver::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TFunction_DataMapOfGUIDDriver.def("Clear", [](TFunction_DataMapOfGUIDDriver &self) -> void { return self.Clear(); });
	cls_TFunction_DataMapOfGUIDDriver.def("Clear", (void (TFunction_DataMapOfGUIDDriver::*)(const Standard_Boolean)) &TFunction_DataMapOfGUIDDriver::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TFunction_DataMapOfGUIDDriver.def("Clear", (void (TFunction_DataMapOfGUIDDriver::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TFunction_DataMapOfGUIDDriver::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TFunction_DataMapOfGUIDDriver.def("Size", (Standard_Integer (TFunction_DataMapOfGUIDDriver::*)() const ) &TFunction_DataMapOfGUIDDriver::Size, "Size");
	cls_TFunction_DataMapOfGUIDDriver.def("__iter__", [](const TFunction_DataMapOfGUIDDriver &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_DataMapOfGUIDDriver.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_HArray1OfDataMapOfGUIDDriver.hxx
	py::class_<TFunction_HArray1OfDataMapOfGUIDDriver, opencascade::handle<TFunction_HArray1OfDataMapOfGUIDDriver>, TFunction_Array1OfDataMapOfGUIDDriver, Standard_Transient> cls_TFunction_HArray1OfDataMapOfGUIDDriver(mod, "TFunction_HArray1OfDataMapOfGUIDDriver", "None");
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const Standard_Integer, const Standard_Integer, const TFunction_Array1OfDataMapOfGUIDDriver::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const TFunction_Array1OfDataMapOfGUIDDriver &>(), py::arg("theOther"));
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("Array1", (const TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_HArray1OfDataMapOfGUIDDriver::*)() const ) &TFunction_HArray1OfDataMapOfGUIDDriver::Array1, "None");
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("ChangeArray1", (TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_HArray1OfDataMapOfGUIDDriver::*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::ChangeArray1, "None");
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("get_type_name_", (const char * (*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::get_type_name, "None");
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::get_type_descriptor, "None");
	cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_HArray1OfDataMapOfGUIDDriver::*)() const ) &TFunction_HArray1OfDataMapOfGUIDDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<TFunction_DataMapOfLabelListOfLabel, std::unique_ptr<TFunction_DataMapOfLabelListOfLabel, Deleter<TFunction_DataMapOfLabelListOfLabel>>, NCollection_BaseMap> cls_TFunction_DataMapOfLabelListOfLabel(mod, "TFunction_DataMapOfLabelListOfLabel", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_TFunction_DataMapOfLabelListOfLabel.def(py::init<>());
	cls_TFunction_DataMapOfLabelListOfLabel.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TFunction_DataMapOfLabelListOfLabel.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TFunction_DataMapOfLabelListOfLabel.def(py::init([] (const TFunction_DataMapOfLabelListOfLabel &other) {return new TFunction_DataMapOfLabelListOfLabel(other);}), "Copy constructor", py::arg("other"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("begin", (TFunction_DataMapOfLabelListOfLabel::iterator (TFunction_DataMapOfLabelListOfLabel::*)() const ) &TFunction_DataMapOfLabelListOfLabel::begin, "Returns an iterator pointing to the first element in the map.");
	cls_TFunction_DataMapOfLabelListOfLabel.def("end", (TFunction_DataMapOfLabelListOfLabel::iterator (TFunction_DataMapOfLabelListOfLabel::*)() const ) &TFunction_DataMapOfLabelListOfLabel::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_TFunction_DataMapOfLabelListOfLabel.def("cbegin", (TFunction_DataMapOfLabelListOfLabel::const_iterator (TFunction_DataMapOfLabelListOfLabel::*)() const ) &TFunction_DataMapOfLabelListOfLabel::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_TFunction_DataMapOfLabelListOfLabel.def("cend", (TFunction_DataMapOfLabelListOfLabel::const_iterator (TFunction_DataMapOfLabelListOfLabel::*)() const ) &TFunction_DataMapOfLabelListOfLabel::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_TFunction_DataMapOfLabelListOfLabel.def("Exchange", (void (TFunction_DataMapOfLabelListOfLabel::*)(TFunction_DataMapOfLabelListOfLabel &)) &TFunction_DataMapOfLabelListOfLabel::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("Assign", (TFunction_DataMapOfLabelListOfLabel & (TFunction_DataMapOfLabelListOfLabel::*)(const TFunction_DataMapOfLabelListOfLabel &)) &TFunction_DataMapOfLabelListOfLabel::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("assign", (TFunction_DataMapOfLabelListOfLabel & (TFunction_DataMapOfLabelListOfLabel::*)(const TFunction_DataMapOfLabelListOfLabel &)) &TFunction_DataMapOfLabelListOfLabel::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("ReSize", (void (TFunction_DataMapOfLabelListOfLabel::*)(const Standard_Integer)) &TFunction_DataMapOfLabelListOfLabel::ReSize, "ReSize", py::arg("N"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("Bind", (Standard_Boolean (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &, const TDF_LabelList &)) &TFunction_DataMapOfLabelListOfLabel::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_TFunction_DataMapOfLabelListOfLabel.def("Bound", (TDF_LabelList * (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &, const TDF_LabelList &)) &TFunction_DataMapOfLabelListOfLabel::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("IsBound", (Standard_Boolean (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &) const ) &TFunction_DataMapOfLabelListOfLabel::IsBound, "IsBound", py::arg("theKey"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("UnBind", (Standard_Boolean (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &)) &TFunction_DataMapOfLabelListOfLabel::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfLabelListOfLabel.def("Seek", (const TDF_LabelList * (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &) const ) &TFunction_DataMapOfLabelListOfLabel::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfLabelListOfLabel.def("Find", (const TDF_LabelList & (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &) const ) &TFunction_DataMapOfLabelListOfLabel::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfLabelListOfLabel.def("Find", (Standard_Boolean (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &, TDF_LabelList &) const ) &TFunction_DataMapOfLabelListOfLabel::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("__call__", (const TDF_LabelList & (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &) const ) &TFunction_DataMapOfLabelListOfLabel::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_TFunction_DataMapOfLabelListOfLabel.def("ChangeSeek", (TDF_LabelList * (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &)) &TFunction_DataMapOfLabelListOfLabel::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("ChangeFind", (TDF_LabelList & (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &)) &TFunction_DataMapOfLabelListOfLabel::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("__call__", (TDF_LabelList & (TFunction_DataMapOfLabelListOfLabel::*)(const TDF_Label &)) &TFunction_DataMapOfLabelListOfLabel::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("Clear", [](TFunction_DataMapOfLabelListOfLabel &self) -> void { return self.Clear(); });
	cls_TFunction_DataMapOfLabelListOfLabel.def("Clear", (void (TFunction_DataMapOfLabelListOfLabel::*)(const Standard_Boolean)) &TFunction_DataMapOfLabelListOfLabel::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("Clear", (void (TFunction_DataMapOfLabelListOfLabel::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TFunction_DataMapOfLabelListOfLabel::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TFunction_DataMapOfLabelListOfLabel.def("Size", (Standard_Integer (TFunction_DataMapOfLabelListOfLabel::*)() const ) &TFunction_DataMapOfLabelListOfLabel::Size, "Size");
	cls_TFunction_DataMapOfLabelListOfLabel.def("__iter__", [](const TFunction_DataMapOfLabelListOfLabel &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_DataMapOfLabelListOfLabel.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DoubleMap.hxx
	py::class_<TFunction_DoubleMapOfIntegerLabel, std::unique_ptr<TFunction_DoubleMapOfIntegerLabel, Deleter<TFunction_DoubleMapOfIntegerLabel>>, NCollection_BaseMap> cls_TFunction_DoubleMapOfIntegerLabel(mod, "TFunction_DoubleMapOfIntegerLabel", "Purpose: The DoubleMap is used to bind pairs (Key1,Key2) and retrieve them in linear time.");
	cls_TFunction_DoubleMapOfIntegerLabel.def(py::init<>());
	cls_TFunction_DoubleMapOfIntegerLabel.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_TFunction_DoubleMapOfIntegerLabel.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_TFunction_DoubleMapOfIntegerLabel.def(py::init([] (const TFunction_DoubleMapOfIntegerLabel &other) {return new TFunction_DoubleMapOfIntegerLabel(other);}), "Copy constructor", py::arg("other"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Exchange", (void (TFunction_DoubleMapOfIntegerLabel::*)(TFunction_DoubleMapOfIntegerLabel &)) &TFunction_DoubleMapOfIntegerLabel::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Assign", (TFunction_DoubleMapOfIntegerLabel & (TFunction_DoubleMapOfIntegerLabel::*)(const TFunction_DoubleMapOfIntegerLabel &)) &TFunction_DoubleMapOfIntegerLabel::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("assign", (TFunction_DoubleMapOfIntegerLabel & (TFunction_DoubleMapOfIntegerLabel::*)(const TFunction_DoubleMapOfIntegerLabel &)) &TFunction_DoubleMapOfIntegerLabel::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("ReSize", (void (TFunction_DoubleMapOfIntegerLabel::*)(const Standard_Integer)) &TFunction_DoubleMapOfIntegerLabel::ReSize, "ReSize", py::arg("N"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Bind", (void (TFunction_DoubleMapOfIntegerLabel::*)(const Standard_Integer &, const TDF_Label &)) &TFunction_DoubleMapOfIntegerLabel::Bind, "Bind", py::arg("theKey1"), py::arg("theKey2"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("AreBound", (Standard_Boolean (TFunction_DoubleMapOfIntegerLabel::*)(const Standard_Integer &, const TDF_Label &) const ) &TFunction_DoubleMapOfIntegerLabel::AreBound, "* AreBound", py::arg("theKey1"), py::arg("theKey2"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("IsBound1", (Standard_Boolean (TFunction_DoubleMapOfIntegerLabel::*)(const Standard_Integer &) const ) &TFunction_DoubleMapOfIntegerLabel::IsBound1, "IsBound1", py::arg("theKey1"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("IsBound2", (Standard_Boolean (TFunction_DoubleMapOfIntegerLabel::*)(const TDF_Label &) const ) &TFunction_DoubleMapOfIntegerLabel::IsBound2, "IsBound2", py::arg("theKey2"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("UnBind1", (Standard_Boolean (TFunction_DoubleMapOfIntegerLabel::*)(const Standard_Integer &)) &TFunction_DoubleMapOfIntegerLabel::UnBind1, "UnBind1", py::arg("theKey1"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("UnBind2", (Standard_Boolean (TFunction_DoubleMapOfIntegerLabel::*)(const TDF_Label &)) &TFunction_DoubleMapOfIntegerLabel::UnBind2, "UnBind2", py::arg("theKey2"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Find1", (const TDF_Label & (TFunction_DoubleMapOfIntegerLabel::*)(const Standard_Integer &) const ) &TFunction_DoubleMapOfIntegerLabel::Find1, "Find1", py::arg("theKey1"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Find2", (const Standard_Integer & (TFunction_DoubleMapOfIntegerLabel::*)(const TDF_Label &) const ) &TFunction_DoubleMapOfIntegerLabel::Find2, "Find2", py::arg("theKey2"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Clear", [](TFunction_DoubleMapOfIntegerLabel &self) -> void { return self.Clear(); });
	cls_TFunction_DoubleMapOfIntegerLabel.def("Clear", (void (TFunction_DoubleMapOfIntegerLabel::*)(const Standard_Boolean)) &TFunction_DoubleMapOfIntegerLabel::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Clear", (void (TFunction_DoubleMapOfIntegerLabel::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TFunction_DoubleMapOfIntegerLabel::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_TFunction_DoubleMapOfIntegerLabel.def("Size", (Standard_Integer (TFunction_DoubleMapOfIntegerLabel::*)() const ) &TFunction_DoubleMapOfIntegerLabel::Size, "Size");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TFunction_DoubleMapOfIntegerLabel.hxx

}
