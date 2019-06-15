#include "typecheck.hpp"
#include <algorithm>
#include <numeric>
// Defines the function used to throw type errors. The possible
// type errors are defined as an enumeration in the header file.
void typeError(TypeErrorCode code) {
  switch (code) {
    case undefined_variable:
      std::cerr << "Undefined variable." << std::endl;
      break;
    case undefined_method:
      std::cerr << "Method does not exist." << std::endl;
      break;
    case undefined_class:
      std::cerr << "Class does not exist." << std::endl;
      break;
    case undefined_member:
      std::cerr << "Class member does not exist." << std::endl;
      break;
    case not_object:
      std::cerr << "Variable is not an object." << std::endl;
      break;
    case expression_type_mismatch:
      std::cerr << "Expression types do not match." << std::endl;
      break;
    case argument_number_mismatch:
      std::cerr << "Method called with incorrect number of arguments." << std::endl;
      break;
    case argument_type_mismatch:
      std::cerr << "Method called with argument of incorrect type." << std::endl;
      break;
    case while_predicate_type_mismatch:
      std::cerr << "Predicate of while loop is not boolean." << std::endl;
      break;
    case do_while_predicate_type_mismatch:
      std::cerr << "Predicate of do while loop is not boolean." << std::endl;
      break;
    case if_predicate_type_mismatch:
      std::cerr << "Predicate of if statement is not boolean." << std::endl;
      break;
    case assignment_type_mismatch:
      std::cerr << "Left and right hand sides of assignment types mismatch." << std::endl;
      break;
    case return_type_mismatch:
      std::cerr << "Return statement type does not match declared return type." << std::endl;
      break;
    case constructor_returns_type:
      std::cerr << "Class constructor returns a value." << std::endl;
      break;
    case no_main_class:
      std::cerr << "The \"Main\" class was not found." << std::endl;
      break;
    case main_class_members_present:
      std::cerr << "The \"Main\" class has members." << std::endl;
      break;
    case no_main_method:
      std::cerr << "The \"Main\" class does not have a \"main\" method." << std::endl;
      break;
    case main_method_incorrect_signature:
      std::cerr << "The \"main\" method of the \"Main\" class has an incorrect signature." << std::endl;
      break;
  }
  exit(1);
}
// TypeCheck Visitor Functions: These are the functions you will
// complete to build the symbol table and type check the program.
// Not all functions must have code, many may be left empty.
CompoundType TNT(TypeNode *node);
CompoundType TC(BaseType baseType, std::string objectClassName);
bool MCS(TypeCheck *t, std::string identifier, std::string className);
MethodInfo MID(TypeCheck *t, std::string identifier, std::string className);
bool MDF(TypeCheck *t, std::string identifier, std::string className);
CompoundType TMCS(TypeCheck *t, std::string identifier, std::string className);
CompoundType TVCS(TypeCheck *t, std::string identifier);
void TypeCheck::visitProgramNode(ProgramNode* node) {
    classTable = new ClassTable();
    node->visit_children(this);
    
    //Main type checking
    if (classTable->find("Main") == classTable->end()) {
        typeError(no_main_class);
    }
    auto mainClass = classTable->at("Main");
    if (mainClass.members->size() != 0 ) {
        typeError(main_class_members_present);
    }
    if (mainClass.methods->find("main") == mainClass.methods->end()) {
        typeError(no_main_method);
    }
    auto mainMethod = mainClass.methods->at("main");
    if (mainMethod.parameters->size() != 0 || mainMethod.returnType.baseType != bt_none) {
        typeError(main_method_incorrect_signature);
    }
}
void TypeCheck::visitClassNode(ClassNode* node) {
    if (node->identifier_2 && classTable->find(node->identifier_2->name) == classTable->end()) {
        typeError(undefined_class);
    }
    currentClassName = node->identifier_1->name;
    currentMethodTable = new MethodTable();
    currentMemberOffset = 0;
    auto members = new VariableTable();
    
    for (auto *declaration : *(node->declaration_list)) {
        for (auto identifier : *(declaration->identifier_list)) {
            VariableInfo variableInfo;
            variableInfo.offset = currentMemberOffset;
            variableInfo.size = 4;
            variableInfo.type = TNT(declaration->type);
            currentMemberOffset += 4;
            (*members)[identifier->name] = variableInfo;
        }
    }
    
    ClassInfo classInfo;
    if (node->identifier_2) {
        classInfo.superClassName = node->identifier_2->name;
    }
    classInfo.members = members;
    classInfo.methods = currentMethodTable;
    classInfo.membersSize = currentMemberOffset;
    
    (*classTable)[node->identifier_1->name] = classInfo;
    
    node->visit_children(this);
    
}
void TypeCheck::visitMethodNode(MethodNode* node) {
    auto returnType = TNT(node->type);
    if (returnType.baseType == bt_object && classTable->find(returnType.objectClassName) == classTable->end()) {
        typeError(undefined_class);
    }
    if (node->identifier->name == currentClassName && returnType.baseType != bt_none) {
        typeError(constructor_returns_type);
    }
    
    MethodInfo methodInfo;
    
    auto *methodVariableTable = new VariableTable();
    currentParameterOffset = 12;
    auto *parameters = new std::list<CompoundType>();
    for (auto parameter : *(node->parameter_list)) {
        VariableInfo variableInfo;
        variableInfo.size = 4;
        variableInfo.type = TNT(parameter->type);
        variableInfo.offset = currentParameterOffset;
        (*methodVariableTable)[parameter->identifier->name] = variableInfo;
        parameters->push_back(TNT(parameter->type));
        currentParameterOffset += 4;
    }
    
    
    auto *oldVariableTable = currentVariableTable;
    currentVariableTable = methodVariableTable;
    node->visit_children(this);
    currentVariableTable = oldVariableTable;
    
    bool tf = false;
    do {
        if (node->methodbody->objectClassName == returnType.objectClassName) {
            tf =  true;
            break;
        }
    } while ((node->methodbody->objectClassName = this->classTable->at(node->methodbody->objectClassName).superClassName) != "");
    
    if (node->methodbody->basetype != returnType.baseType || (!tf && node->methodbody->basetype == bt_object)) { 
        typeError(return_type_mismatch);
    }
    
    methodInfo.parameters = parameters;
    methodInfo.returnType = TNT(node->type);
    methodInfo.variables = methodVariableTable;
    methodInfo.localsSize = -currentLocalOffset - 4;
    
    
    (*currentMethodTable)[node->identifier->name] = methodInfo;
}
void TypeCheck::visitMethodBodyNode(MethodBodyNode* node) {
    currentLocalOffset = -4;
    for (auto *declaration : *(node->declaration_list)) {
        for (auto identifier : *(declaration->identifier_list)) {
            VariableInfo variableInfo;
            variableInfo.offset = currentLocalOffset;
            variableInfo.size = 4;
            variableInfo.type = TNT(declaration->type);
            currentLocalOffset -= 4;
            (*currentVariableTable)[identifier->name] = variableInfo;
        }
    }
    
    node->visit_children(this);
    if (node->returnstatement) {
        node->basetype = node->returnstatement->basetype;
        node->objectClassName = node->returnstatement->objectClassName;
    } else {
        node->basetype = bt_none;
    }
    
}
void TypeCheck::visitParameterNode(ParameterNode* node) {
    node->visit_children(this);
    bool tf = false;
    if (this->classTable->find(node->type->objectClassName) == this->classTable->end()) { 
        tf = false;
    }else{
        tf = true;
    }
    if (node->type->basetype == bt_object && !tf) {
        typeError(undefined_class);
    }
}
void TypeCheck::visitDeclarationNode(DeclarationNode* node) {
    node->visit_children(this);
    auto declaredType = TNT(node->type);
    bool tf = false;
    if (this->classTable->find(declaredType.objectClassName) == this->classTable->end()) { 
        tf = false;
    }else{
        tf = true;
    }
    if (declaredType.baseType == bt_object && !tf) {
        typeError(undefined_class);
    }
}
void TypeCheck::visitReturnStatementNode(ReturnStatementNode* node) {
    node->visit_children(this);
    node->basetype = node->expression->basetype;
    node->objectClassName = node->expression->objectClassName;
}
void TypeCheck::visitAssignmentNode(AssignmentNode* node) {
    node->visit_children(this);
    bool tf = false;
    if (this->currentVariableTable->find(node->identifier_1->name) == this->currentVariableTable->end()){
        tf = MCS(this, node->identifier_1->name, this->currentClassName);
    }else{
        tf = true;
    }
    if (tf) {
        if (node->identifier_2) {
            if (TVCS(this, node->identifier_1->name).baseType == bt_object) {
                if (MCS(this, node->identifier_2->name, TVCS(this, node->identifier_1->name).objectClassName)) {
                    auto lhsType = TMCS(this, node->identifier_2->name, TVCS(this, node->identifier_1->name).objectClassName);
                    auto rhsType = TC(node->expression->basetype, node->expression->objectClassName);
             bool tf = false;
             do {
                if (rhsType.objectClassName == lhsType.objectClassName) {
                    tf =  true;
                    break;
                }
            } while ((rhsType.objectClassName = this->classTable->at(rhsType.objectClassName).superClassName) != "");        
                    
                    if (lhsType.baseType != rhsType.baseType || !tf) {
                        typeError(assignment_type_mismatch);
                    }
                } else {
                    typeError(undefined_member);
                }
            } else {
                typeError(not_object);
            }
            
        } else {
            auto lhsType = TVCS(this, node->identifier_1->name);
            auto rhsType = TC(node->expression->basetype, node->expression->objectClassName);
            bool tf = false;
            do {
                if (rhsType.objectClassName == lhsType.objectClassName) {
                    tf =  true;
                    break;
                }
            } while ((rhsType.objectClassName = this->classTable->at(rhsType.objectClassName).superClassName) != ""); 
            if (lhsType.baseType != rhsType.baseType || !tf) {
                typeError(assignment_type_mismatch);
            }
        }
    } else {
        typeError(undefined_variable);
    }
    
}
void TypeCheck::visitCallNode(CallNode* node) {
    node->visit_children(this);
    node->basetype = node->methodcall->basetype;
    node->objectClassName = node->methodcall->basetype;
}
void TypeCheck::visitIfElseNode(IfElseNode* node) {
    node->visit_children(this);
    if (node->expression->basetype != bt_boolean) {
        typeError(if_predicate_type_mismatch);
    }
}
void TypeCheck::visitWhileNode(WhileNode* node) {
    node->visit_children(this);
    if (node->expression->basetype != bt_boolean) {
        typeError(while_predicate_type_mismatch);
    }
}
void TypeCheck::visitDoWhileNode(DoWhileNode* node) {
    node->visit_children(this);
    if (node->expression->basetype != bt_boolean) {
        typeError(do_while_predicate_type_mismatch);
    }
}
void TypeCheck::visitPrintNode(PrintNode* node) {
    node->visit_children(this);
}
void TypeCheck::visitPlusNode(PlusNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_integer;
    }
}
void TypeCheck::visitMinusNode(MinusNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_integer;
    }
}
void TypeCheck::visitTimesNode(TimesNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_integer;
    }
}
void TypeCheck::visitDivideNode(DivideNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_integer;
    }
}
void TypeCheck::visitGreaterNode(GreaterNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_boolean;
    }
}
void TypeCheck::visitGreaterEqualNode(GreaterEqualNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_boolean;
    }
}
void TypeCheck::visitEqualNode(EqualNode* node) {
    node->visit_children(this);
    auto lhs = node->expression_1->basetype;
    auto rhs = node->expression_2->basetype;
    if (!((lhs == bt_integer && rhs == bt_integer) || (lhs == bt_boolean && rhs == bt_boolean))) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_boolean;
    }
}
void TypeCheck::visitAndNode(AndNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_boolean || node->expression_2->basetype != bt_boolean) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_boolean;
    }
}
void TypeCheck::visitOrNode(OrNode* node) {
    node->visit_children(this);
    if (node->expression_1->basetype != bt_boolean || node->expression_2->basetype != bt_boolean) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_boolean;
    }
}
void TypeCheck::visitNotNode(NotNode* node) {
    node->visit_children(this);
    if (node->expression->basetype != bt_boolean) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_boolean;
    }
}
void TypeCheck::visitNegationNode(NegationNode* node) {
    node->visit_children(this);
    if (node->expression->basetype != bt_integer) {
        typeError(expression_type_mismatch);
    } else {
        node->basetype = bt_integer;
    }
}
void TypeCheck::visitMethodCallNode(MethodCallNode* node) {
    node->visit_children(this);
    std::string methodIdentifier;
    std::string className;
    if (node->identifier_2) {
        std::string objectIdentifier = node->identifier_1->name;
        methodIdentifier = node->identifier_2->name;
    bool tf = false;
    if(this->currentVariableTable->find(objectIdentifier) == this->currentVariableTable->end()){
        tf = MCS(this, objectIdentifier, this->currentClassName);
    }else{
        tf = true;
    }
        if (!tf) {
            typeError(undefined_variable);
        } else if (TVCS(this, objectIdentifier).baseType != bt_object) {
            typeError(not_object);
        }
        className = TVCS(this, objectIdentifier).objectClassName;
        
        if (!MDF(this, methodIdentifier, TVCS(this, objectIdentifier).objectClassName)) {
            typeError(undefined_method);
        }
    } else {
        methodIdentifier = node->identifier_1->name;
        className = currentClassName;
        if (!MDF(this, methodIdentifier, currentClassName)) {
            typeError(undefined_method);
        }
    }
    
    auto methodInfo = MID(this, methodIdentifier, className);
    auto *parameterList = methodInfo.parameters;
    if (parameterList->size() != node->expression_list->size()) {
        typeError(argument_number_mismatch);
    }
    auto it1 = parameterList->begin();
    auto it2 = node->expression_list->begin();
    for(; it1 != parameterList->end(); ++it1, ++it2) {
        bool tf = false;
        do {
            if ((*it2)->objectClassName == it1->objectClassName) {
                tf =  true;
                break;
            }
        } while (((*it2)->objectClassName = this->classTable->at((*it2)->objectClassName).superClassName) != "");     
        if (it1->baseType != (*it2)->basetype || (!tf && (*it2)->basetype == bt_object)) {
            typeError(argument_type_mismatch);
        }
    }
    
    auto returnType = methodInfo.returnType;
    node->basetype = returnType.baseType;
    node->objectClassName = returnType.objectClassName;
    
}
void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
    auto objectIdentifier = node->identifier_1->name;
    auto memberIdentifier = node->identifier_2->name;
    
    bool tf = false;
    if (this->currentVariableTable->find(objectIdentifier) == this->currentVariableTable->end()) {
        tf =  MCS(this, objectIdentifier, this->currentClassName); 
        
    } else {
        tf =  true;
    }
    if (!tf) {
        typeError(undefined_variable);
    } else if (TVCS(this, objectIdentifier).baseType != bt_object) {
        typeError(not_object);
    } else if (!MCS(this, memberIdentifier, TVCS(this, objectIdentifier).objectClassName)) {
        typeError(undefined_member);
    }
    auto memberType = TMCS(this, memberIdentifier, TVCS(this, objectIdentifier).objectClassName);
    node->basetype = memberType.baseType;
    node->objectClassName = memberType.objectClassName;
}
void TypeCheck::visitVariableNode(VariableNode* node) {
    bool tf = false;
    if (this->currentVariableTable->find(node->identifier->name) == this->currentVariableTable->end()) {
        tf =  MCS(this, node->identifier->name, this->currentClassName); 
        
    } else {
        tf =  true;
    }
    if (!tf) {
        typeError(undefined_variable);
    }
    node->basetype = TVCS(this, node->identifier->name).baseType;
    node->objectClassName = TVCS(this, node->identifier->name).objectClassName;
}
void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
    node->basetype = bt_integer;
}
void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
    node->basetype = bt_boolean;
}
void TypeCheck::visitNewNode(NewNode* node) {
    node->visit_children(this);
    bool tf = false;
    if (this->currentVariableTable->find(node->identifier->name) == this->currentVariableTable->end()) {
        tf =  MCS(this, node->identifier->name, this->currentClassName); 
        
    } else {
        tf =  true;
    }
    if (tf) {
        typeError(undefined_class);
    }
    
    if (MDF(this, node->identifier->name, node->identifier->name)) { 
        auto methodInfo = MID(this, node->identifier->name, node->identifier->name);
        auto *parameterList = methodInfo.parameters;
        if (parameterList->size() != node->expression_list->size()) {
            typeError(argument_number_mismatch);
        }
        auto it1 = parameterList->begin();
        auto it2 = node->expression_list->begin();
        for(; it1 != parameterList->end(); ++it1, ++it2) {
        bool tf = false;
        do {
            if ( (*it2)->objectClassName == it1->objectClassName) {
                tf =  true;
                break;
            }
        } while (( (*it2)->objectClassName = this->classTable->at( (*it2)->objectClassName ).superClassName) != "");   
            if (it1->baseType != (*it2)->basetype || (!tf && (*it2)->basetype == bt_object)) {
                typeError(argument_type_mismatch);
            }
        }
    }
    
    
    node->objectClassName = node->identifier->name;
    node->basetype = bt_object;
}
void TypeCheck::visitIntegerTypeNode(IntegerTypeNode* node) {
  // WRITEME: Replace with code if necessary
}
void TypeCheck::visitBooleanTypeNode(BooleanTypeNode* node) {
  // WRITEME: Replace with code if necessary
}
void TypeCheck::visitObjectTypeNode(ObjectTypeNode* node) {
  // WRITEME: Replace with code if necessary
}
void TypeCheck::visitNoneNode(NoneNode* node) {
  // WRITEME: Replace with code if necessary
}
void TypeCheck::visitIdentifierNode(IdentifierNode* node) {
  // WRITEME: Replace with code if necessary
}
void TypeCheck::visitIntegerNode(IntegerNode* node) {
  // WRITEME: Replace with code if necessary
}
std::string genIndent(int indent) {
  std::string string = std::string("");
  for (int i = 0; i < indent; i++)
    string += std::string(" ");
  return string;
}
std::string string(CompoundType type) {
  switch (type.baseType) {
    case bt_integer:
      return std::string("Integer");
    case bt_boolean:
      return std::string("Boolean");
    case bt_none:
      return std::string("None");
    case bt_object:
      return std::string("Object(") + type.objectClassName + std::string(")");
    default:
      return std::string("");
  }
}
void print(VariableTable variableTable, int indent) {
  std::cout << genIndent(indent) << "VariableTable {";
  if (variableTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (VariableTable::iterator it = variableTable.begin(); it != variableTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << string(it->second.type);
    std::cout << ", " << it->second.offset << ", " << it->second.size << "}";
    if (it != --variableTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}
void print(MethodTable methodTable, int indent) {
  std::cout << genIndent(indent) << "MethodTable {";
  if (methodTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (MethodTable::iterator it = methodTable.begin(); it != methodTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    std::cout << genIndent(indent + 4) << string(it->second.returnType) << "," << std::endl;
    std::cout << genIndent(indent + 4) << it->second.localsSize << "," << std::endl;
    print(*it->second.variables, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --methodTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}
void print(ClassTable classTable, int indent) {
  std::cout << genIndent(indent) << "ClassTable {" << std::endl;
  for (ClassTable::iterator it = classTable.begin(); it != classTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    if (it->second.superClassName != "")
      std::cout << genIndent(indent + 4) << it->second.superClassName << "," << std::endl;
    print(*it->second.members, indent + 4);
    std::cout << "," << std::endl;
    print(*it->second.methods, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --classTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}" << std::endl;
}
void print(ClassTable classTable) {
  print(classTable, 0);
}
CompoundType TNT(TypeNode *node) {
    CompoundType compoundType;
    if (dynamic_cast<NoneNode*>(node)) { 
        compoundType.baseType = bt_none;
    } else if (dynamic_cast<IntegerTypeNode*>(node)) {
        compoundType.baseType = bt_integer;
    } else if (dynamic_cast<BooleanTypeNode*>(node)) {
        compoundType.baseType = bt_boolean;
    } else if (dynamic_cast<ObjectTypeNode*>(node)){
        compoundType.baseType = bt_object;
        compoundType.objectClassName = dynamic_cast<ObjectTypeNode*>(node)->identifier->name;
    }
    return compoundType;
}
CompoundType TC(BaseType baseType, std::string objectClassName) {
    CompoundType t;
    t.baseType = baseType;
    t.objectClassName = objectClassName;
    return t;
}
bool MCS(TypeCheck *t, std::string identifier, std::string className) {
    do {
        auto *members = t->classTable->at(className).members;
        if (members->find(identifier) != members->end()) {
            return true;
        }
    } while ((className = t->classTable->at(className).superClassName) != "");
    
    return false;
}
MethodInfo MID(TypeCheck *t, std::string identifier, std::string className) {
    do {
        auto *methods = t->classTable->at(className).methods;
        if (methods->find(identifier) != methods->end()) {
            return (*methods)[identifier];
        }
    } while ((className = t->classTable->at(className).superClassName) != "");
    std::cout << "Error member does not exist";
    exit(1);
}
bool MDF(TypeCheck *t, std::string identifier, std::string className) {
    do {
        auto *methods = t->classTable->at(className).methods;
        if (methods->find(identifier) != methods->end()) {
            return true;
        }
    } while ((className = t->classTable->at(className).superClassName) != "");
    
    return false;
}
CompoundType TMCS(TypeCheck *t, std::string identifier, std::string className) {
    do {
        auto *members = t->classTable->at(className).members;
        if (members->find(identifier) != members->end()) {
            return members->at(identifier).type;
        }
    } while ((className = t->classTable->at(className).superClassName) != "");
    std::cout << "Error member does not exist";
    exit(1);
}
CompoundType TVCS(TypeCheck *t, std::string identifier) {
    if (t->currentVariableTable->find(identifier) == t->currentVariableTable->end()) {
        return TMCS(t, identifier, t->currentClassName); 
        
    } else { 
        return t->currentVariableTable->at(identifier).type;
    }
}
