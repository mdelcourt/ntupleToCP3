// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "include/MiniEvent.h"
#include "include/cp3Types.h"
#include "include/cp3Types.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *pairlEsignedsPcharcOsignedsPchargR_Dictionary();
   static void pairlEsignedsPcharcOsignedsPchargR_TClassManip(TClass*);
   static void *new_pairlEsignedsPcharcOsignedsPchargR(void *p = 0);
   static void *newArray_pairlEsignedsPcharcOsignedsPchargR(Long_t size, void *p);
   static void delete_pairlEsignedsPcharcOsignedsPchargR(void *p);
   static void deleteArray_pairlEsignedsPcharcOsignedsPchargR(void *p);
   static void destruct_pairlEsignedsPcharcOsignedsPchargR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<signed char,signed char>*)
   {
      pair<signed char,signed char> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<signed char,signed char>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<signed char,signed char>", "string", 198,
                  typeid(pair<signed char,signed char>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEsignedsPcharcOsignedsPchargR_Dictionary, isa_proxy, 4,
                  sizeof(pair<signed char,signed char>) );
      instance.SetNew(&new_pairlEsignedsPcharcOsignedsPchargR);
      instance.SetNewArray(&newArray_pairlEsignedsPcharcOsignedsPchargR);
      instance.SetDelete(&delete_pairlEsignedsPcharcOsignedsPchargR);
      instance.SetDeleteArray(&deleteArray_pairlEsignedsPcharcOsignedsPchargR);
      instance.SetDestructor(&destruct_pairlEsignedsPcharcOsignedsPchargR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const pair<signed char,signed char>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEsignedsPcharcOsignedsPchargR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<signed char,signed char>*)0x0)->GetClass();
      pairlEsignedsPcharcOsignedsPchargR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEsignedsPcharcOsignedsPchargR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLLepton_Dictionary();
   static void HHcLcLLepton_TClassManip(TClass*);
   static void *new_HHcLcLLepton(void *p = 0);
   static void *newArray_HHcLcLLepton(Long_t size, void *p);
   static void delete_HHcLcLLepton(void *p);
   static void deleteArray_HHcLcLLepton(void *p);
   static void destruct_HHcLcLLepton(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::Lepton*)
   {
      ::HH::Lepton *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::Lepton));
      static ::ROOT::TGenericClassInfo 
         instance("HH::Lepton", "include/cp3Types.h", 11,
                  typeid(::HH::Lepton), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLLepton_Dictionary, isa_proxy, 4,
                  sizeof(::HH::Lepton) );
      instance.SetNew(&new_HHcLcLLepton);
      instance.SetNewArray(&newArray_HHcLcLLepton);
      instance.SetDelete(&delete_HHcLcLLepton);
      instance.SetDeleteArray(&deleteArray_HHcLcLLepton);
      instance.SetDestructor(&destruct_HHcLcLLepton);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::Lepton*)
   {
      return GenerateInitInstanceLocal((::HH::Lepton*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::Lepton*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLLepton_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::Lepton*)0x0)->GetClass();
      HHcLcLLepton_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLLepton_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLDilepton_Dictionary();
   static void HHcLcLDilepton_TClassManip(TClass*);
   static void *new_HHcLcLDilepton(void *p = 0);
   static void *newArray_HHcLcLDilepton(Long_t size, void *p);
   static void delete_HHcLcLDilepton(void *p);
   static void deleteArray_HHcLcLDilepton(void *p);
   static void destruct_HHcLcLDilepton(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::Dilepton*)
   {
      ::HH::Dilepton *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::Dilepton));
      static ::ROOT::TGenericClassInfo 
         instance("HH::Dilepton", "include/cp3Types.h", 38,
                  typeid(::HH::Dilepton), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLDilepton_Dictionary, isa_proxy, 4,
                  sizeof(::HH::Dilepton) );
      instance.SetNew(&new_HHcLcLDilepton);
      instance.SetNewArray(&newArray_HHcLcLDilepton);
      instance.SetDelete(&delete_HHcLcLDilepton);
      instance.SetDeleteArray(&deleteArray_HHcLcLDilepton);
      instance.SetDestructor(&destruct_HHcLcLDilepton);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::Dilepton*)
   {
      return GenerateInitInstanceLocal((::HH::Dilepton*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::Dilepton*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLDilepton_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::Dilepton*)0x0)->GetClass();
      HHcLcLDilepton_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLDilepton_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLMet_Dictionary();
   static void HHcLcLMet_TClassManip(TClass*);
   static void *new_HHcLcLMet(void *p = 0);
   static void *newArray_HHcLcLMet(Long_t size, void *p);
   static void delete_HHcLcLMet(void *p);
   static void deleteArray_HHcLcLMet(void *p);
   static void destruct_HHcLcLMet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::Met*)
   {
      ::HH::Met *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::Met));
      static ::ROOT::TGenericClassInfo 
         instance("HH::Met", "include/cp3Types.h", 88,
                  typeid(::HH::Met), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLMet_Dictionary, isa_proxy, 4,
                  sizeof(::HH::Met) );
      instance.SetNew(&new_HHcLcLMet);
      instance.SetNewArray(&newArray_HHcLcLMet);
      instance.SetDelete(&delete_HHcLcLMet);
      instance.SetDeleteArray(&deleteArray_HHcLcLMet);
      instance.SetDestructor(&destruct_HHcLcLMet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::Met*)
   {
      return GenerateInitInstanceLocal((::HH::Met*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::Met*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLMet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::Met*)0x0)->GetClass();
      HHcLcLMet_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLMet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLDileptonMet_Dictionary();
   static void HHcLcLDileptonMet_TClassManip(TClass*);
   static void *new_HHcLcLDileptonMet(void *p = 0);
   static void *newArray_HHcLcLDileptonMet(Long_t size, void *p);
   static void delete_HHcLcLDileptonMet(void *p);
   static void deleteArray_HHcLcLDileptonMet(void *p);
   static void destruct_HHcLcLDileptonMet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::DileptonMet*)
   {
      ::HH::DileptonMet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::DileptonMet));
      static ::ROOT::TGenericClassInfo 
         instance("HH::DileptonMet", "include/cp3Types.h", 97,
                  typeid(::HH::DileptonMet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLDileptonMet_Dictionary, isa_proxy, 4,
                  sizeof(::HH::DileptonMet) );
      instance.SetNew(&new_HHcLcLDileptonMet);
      instance.SetNewArray(&newArray_HHcLcLDileptonMet);
      instance.SetDelete(&delete_HHcLcLDileptonMet);
      instance.SetDeleteArray(&deleteArray_HHcLcLDileptonMet);
      instance.SetDestructor(&destruct_HHcLcLDileptonMet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::DileptonMet*)
   {
      return GenerateInitInstanceLocal((::HH::DileptonMet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::DileptonMet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLDileptonMet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::DileptonMet*)0x0)->GetClass();
      HHcLcLDileptonMet_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLDileptonMet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLJet_Dictionary();
   static void HHcLcLJet_TClassManip(TClass*);
   static void *new_HHcLcLJet(void *p = 0);
   static void *newArray_HHcLcLJet(Long_t size, void *p);
   static void delete_HHcLcLJet(void *p);
   static void deleteArray_HHcLcLJet(void *p);
   static void destruct_HHcLcLJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::Jet*)
   {
      ::HH::Jet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::Jet));
      static ::ROOT::TGenericClassInfo 
         instance("HH::Jet", "include/cp3Types.h", 113,
                  typeid(::HH::Jet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLJet_Dictionary, isa_proxy, 4,
                  sizeof(::HH::Jet) );
      instance.SetNew(&new_HHcLcLJet);
      instance.SetNewArray(&newArray_HHcLcLJet);
      instance.SetDelete(&delete_HHcLcLJet);
      instance.SetDeleteArray(&deleteArray_HHcLcLJet);
      instance.SetDestructor(&destruct_HHcLcLJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::Jet*)
   {
      return GenerateInitInstanceLocal((::HH::Jet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::Jet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLJet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::Jet*)0x0)->GetClass();
      HHcLcLJet_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLJet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLDijet_Dictionary();
   static void HHcLcLDijet_TClassManip(TClass*);
   static void *new_HHcLcLDijet(void *p = 0);
   static void *newArray_HHcLcLDijet(Long_t size, void *p);
   static void delete_HHcLcLDijet(void *p);
   static void deleteArray_HHcLcLDijet(void *p);
   static void destruct_HHcLcLDijet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::Dijet*)
   {
      ::HH::Dijet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::Dijet));
      static ::ROOT::TGenericClassInfo 
         instance("HH::Dijet", "include/cp3Types.h", 135,
                  typeid(::HH::Dijet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLDijet_Dictionary, isa_proxy, 4,
                  sizeof(::HH::Dijet) );
      instance.SetNew(&new_HHcLcLDijet);
      instance.SetNewArray(&newArray_HHcLcLDijet);
      instance.SetDelete(&delete_HHcLcLDijet);
      instance.SetDeleteArray(&deleteArray_HHcLcLDijet);
      instance.SetDestructor(&destruct_HHcLcLDijet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::Dijet*)
   {
      return GenerateInitInstanceLocal((::HH::Dijet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::Dijet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLDijet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::Dijet*)0x0)->GetClass();
      HHcLcLDijet_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLDijet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLMELAAngles_Dictionary();
   static void HHcLcLMELAAngles_TClassManip(TClass*);
   static void *new_HHcLcLMELAAngles(void *p = 0);
   static void *newArray_HHcLcLMELAAngles(Long_t size, void *p);
   static void delete_HHcLcLMELAAngles(void *p);
   static void deleteArray_HHcLcLMELAAngles(void *p);
   static void destruct_HHcLcLMELAAngles(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::MELAAngles*)
   {
      ::HH::MELAAngles *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::MELAAngles));
      static ::ROOT::TGenericClassInfo 
         instance("HH::MELAAngles", "include/cp3Types.h", 171,
                  typeid(::HH::MELAAngles), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLMELAAngles_Dictionary, isa_proxy, 4,
                  sizeof(::HH::MELAAngles) );
      instance.SetNew(&new_HHcLcLMELAAngles);
      instance.SetNewArray(&newArray_HHcLcLMELAAngles);
      instance.SetDelete(&delete_HHcLcLMELAAngles);
      instance.SetDeleteArray(&deleteArray_HHcLcLMELAAngles);
      instance.SetDestructor(&destruct_HHcLcLMELAAngles);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::MELAAngles*)
   {
      return GenerateInitInstanceLocal((::HH::MELAAngles*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::MELAAngles*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLMELAAngles_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::MELAAngles*)0x0)->GetClass();
      HHcLcLMELAAngles_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLMELAAngles_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HHcLcLDileptonMetDijet_Dictionary();
   static void HHcLcLDileptonMetDijet_TClassManip(TClass*);
   static void *new_HHcLcLDileptonMetDijet(void *p = 0);
   static void *newArray_HHcLcLDileptonMetDijet(Long_t size, void *p);
   static void delete_HHcLcLDileptonMetDijet(void *p);
   static void deleteArray_HHcLcLDileptonMetDijet(void *p);
   static void destruct_HHcLcLDileptonMetDijet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HH::DileptonMetDijet*)
   {
      ::HH::DileptonMetDijet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HH::DileptonMetDijet));
      static ::ROOT::TGenericClassInfo 
         instance("HH::DileptonMetDijet", "include/cp3Types.h", 179,
                  typeid(::HH::DileptonMetDijet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HHcLcLDileptonMetDijet_Dictionary, isa_proxy, 4,
                  sizeof(::HH::DileptonMetDijet) );
      instance.SetNew(&new_HHcLcLDileptonMetDijet);
      instance.SetNewArray(&newArray_HHcLcLDileptonMetDijet);
      instance.SetDelete(&delete_HHcLcLDileptonMetDijet);
      instance.SetDeleteArray(&deleteArray_HHcLcLDileptonMetDijet);
      instance.SetDestructor(&destruct_HHcLcLDileptonMetDijet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HH::DileptonMetDijet*)
   {
      return GenerateInitInstanceLocal((::HH::DileptonMetDijet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HH::DileptonMetDijet*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HHcLcLDileptonMetDijet_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HH::DileptonMetDijet*)0x0)->GetClass();
      HHcLcLDileptonMetDijet_TClassManip(theClass);
   return theClass;
   }

   static void HHcLcLDileptonMetDijet_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEsignedsPcharcOsignedsPchargR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<signed char,signed char> : new pair<signed char,signed char>;
   }
   static void *newArray_pairlEsignedsPcharcOsignedsPchargR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<signed char,signed char>[nElements] : new pair<signed char,signed char>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEsignedsPcharcOsignedsPchargR(void *p) {
      delete ((pair<signed char,signed char>*)p);
   }
   static void deleteArray_pairlEsignedsPcharcOsignedsPchargR(void *p) {
      delete [] ((pair<signed char,signed char>*)p);
   }
   static void destruct_pairlEsignedsPcharcOsignedsPchargR(void *p) {
      typedef pair<signed char,signed char> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<signed char,signed char>

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLLepton(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Lepton : new ::HH::Lepton;
   }
   static void *newArray_HHcLcLLepton(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Lepton[nElements] : new ::HH::Lepton[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLLepton(void *p) {
      delete ((::HH::Lepton*)p);
   }
   static void deleteArray_HHcLcLLepton(void *p) {
      delete [] ((::HH::Lepton*)p);
   }
   static void destruct_HHcLcLLepton(void *p) {
      typedef ::HH::Lepton current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::Lepton

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLDilepton(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Dilepton : new ::HH::Dilepton;
   }
   static void *newArray_HHcLcLDilepton(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Dilepton[nElements] : new ::HH::Dilepton[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLDilepton(void *p) {
      delete ((::HH::Dilepton*)p);
   }
   static void deleteArray_HHcLcLDilepton(void *p) {
      delete [] ((::HH::Dilepton*)p);
   }
   static void destruct_HHcLcLDilepton(void *p) {
      typedef ::HH::Dilepton current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::Dilepton

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLMet(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Met : new ::HH::Met;
   }
   static void *newArray_HHcLcLMet(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Met[nElements] : new ::HH::Met[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLMet(void *p) {
      delete ((::HH::Met*)p);
   }
   static void deleteArray_HHcLcLMet(void *p) {
      delete [] ((::HH::Met*)p);
   }
   static void destruct_HHcLcLMet(void *p) {
      typedef ::HH::Met current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::Met

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLDileptonMet(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::DileptonMet : new ::HH::DileptonMet;
   }
   static void *newArray_HHcLcLDileptonMet(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::DileptonMet[nElements] : new ::HH::DileptonMet[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLDileptonMet(void *p) {
      delete ((::HH::DileptonMet*)p);
   }
   static void deleteArray_HHcLcLDileptonMet(void *p) {
      delete [] ((::HH::DileptonMet*)p);
   }
   static void destruct_HHcLcLDileptonMet(void *p) {
      typedef ::HH::DileptonMet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::DileptonMet

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLJet(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Jet : new ::HH::Jet;
   }
   static void *newArray_HHcLcLJet(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Jet[nElements] : new ::HH::Jet[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLJet(void *p) {
      delete ((::HH::Jet*)p);
   }
   static void deleteArray_HHcLcLJet(void *p) {
      delete [] ((::HH::Jet*)p);
   }
   static void destruct_HHcLcLJet(void *p) {
      typedef ::HH::Jet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::Jet

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLDijet(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Dijet : new ::HH::Dijet;
   }
   static void *newArray_HHcLcLDijet(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::Dijet[nElements] : new ::HH::Dijet[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLDijet(void *p) {
      delete ((::HH::Dijet*)p);
   }
   static void deleteArray_HHcLcLDijet(void *p) {
      delete [] ((::HH::Dijet*)p);
   }
   static void destruct_HHcLcLDijet(void *p) {
      typedef ::HH::Dijet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::Dijet

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLMELAAngles(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::MELAAngles : new ::HH::MELAAngles;
   }
   static void *newArray_HHcLcLMELAAngles(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::MELAAngles[nElements] : new ::HH::MELAAngles[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLMELAAngles(void *p) {
      delete ((::HH::MELAAngles*)p);
   }
   static void deleteArray_HHcLcLMELAAngles(void *p) {
      delete [] ((::HH::MELAAngles*)p);
   }
   static void destruct_HHcLcLMELAAngles(void *p) {
      typedef ::HH::MELAAngles current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::MELAAngles

namespace ROOT {
   // Wrappers around operator new
   static void *new_HHcLcLDileptonMetDijet(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::DileptonMetDijet : new ::HH::DileptonMetDijet;
   }
   static void *newArray_HHcLcLDileptonMetDijet(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::HH::DileptonMetDijet[nElements] : new ::HH::DileptonMetDijet[nElements];
   }
   // Wrapper around operator delete
   static void delete_HHcLcLDileptonMetDijet(void *p) {
      delete ((::HH::DileptonMetDijet*)p);
   }
   static void deleteArray_HHcLcLDileptonMetDijet(void *p) {
      delete [] ((::HH::DileptonMetDijet*)p);
   }
   static void destruct_HHcLcLDileptonMetDijet(void *p) {
      typedef ::HH::DileptonMetDijet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HH::DileptonMetDijet

namespace ROOT {
   static TClass *vectorlEHHcLcLMetgR_Dictionary();
   static void vectorlEHHcLcLMetgR_TClassManip(TClass*);
   static void *new_vectorlEHHcLcLMetgR(void *p = 0);
   static void *newArray_vectorlEHHcLcLMetgR(Long_t size, void *p);
   static void delete_vectorlEHHcLcLMetgR(void *p);
   static void deleteArray_vectorlEHHcLcLMetgR(void *p);
   static void destruct_vectorlEHHcLcLMetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HH::Met>*)
   {
      vector<HH::Met> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HH::Met>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HH::Met>", -2, "vector", 216,
                  typeid(vector<HH::Met>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHHcLcLMetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HH::Met>) );
      instance.SetNew(&new_vectorlEHHcLcLMetgR);
      instance.SetNewArray(&newArray_vectorlEHHcLcLMetgR);
      instance.SetDelete(&delete_vectorlEHHcLcLMetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHHcLcLMetgR);
      instance.SetDestructor(&destruct_vectorlEHHcLcLMetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HH::Met> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HH::Met>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHHcLcLMetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HH::Met>*)0x0)->GetClass();
      vectorlEHHcLcLMetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHHcLcLMetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHHcLcLMetgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::Met> : new vector<HH::Met>;
   }
   static void *newArray_vectorlEHHcLcLMetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::Met>[nElements] : new vector<HH::Met>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHHcLcLMetgR(void *p) {
      delete ((vector<HH::Met>*)p);
   }
   static void deleteArray_vectorlEHHcLcLMetgR(void *p) {
      delete [] ((vector<HH::Met>*)p);
   }
   static void destruct_vectorlEHHcLcLMetgR(void *p) {
      typedef vector<HH::Met> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HH::Met>

namespace ROOT {
   static TClass *vectorlEHHcLcLLeptongR_Dictionary();
   static void vectorlEHHcLcLLeptongR_TClassManip(TClass*);
   static void *new_vectorlEHHcLcLLeptongR(void *p = 0);
   static void *newArray_vectorlEHHcLcLLeptongR(Long_t size, void *p);
   static void delete_vectorlEHHcLcLLeptongR(void *p);
   static void deleteArray_vectorlEHHcLcLLeptongR(void *p);
   static void destruct_vectorlEHHcLcLLeptongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HH::Lepton>*)
   {
      vector<HH::Lepton> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HH::Lepton>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HH::Lepton>", -2, "vector", 216,
                  typeid(vector<HH::Lepton>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHHcLcLLeptongR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HH::Lepton>) );
      instance.SetNew(&new_vectorlEHHcLcLLeptongR);
      instance.SetNewArray(&newArray_vectorlEHHcLcLLeptongR);
      instance.SetDelete(&delete_vectorlEHHcLcLLeptongR);
      instance.SetDeleteArray(&deleteArray_vectorlEHHcLcLLeptongR);
      instance.SetDestructor(&destruct_vectorlEHHcLcLLeptongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HH::Lepton> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HH::Lepton>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHHcLcLLeptongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HH::Lepton>*)0x0)->GetClass();
      vectorlEHHcLcLLeptongR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHHcLcLLeptongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHHcLcLLeptongR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::Lepton> : new vector<HH::Lepton>;
   }
   static void *newArray_vectorlEHHcLcLLeptongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::Lepton>[nElements] : new vector<HH::Lepton>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHHcLcLLeptongR(void *p) {
      delete ((vector<HH::Lepton>*)p);
   }
   static void deleteArray_vectorlEHHcLcLLeptongR(void *p) {
      delete [] ((vector<HH::Lepton>*)p);
   }
   static void destruct_vectorlEHHcLcLLeptongR(void *p) {
      typedef vector<HH::Lepton> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HH::Lepton>

namespace ROOT {
   static TClass *vectorlEHHcLcLJetgR_Dictionary();
   static void vectorlEHHcLcLJetgR_TClassManip(TClass*);
   static void *new_vectorlEHHcLcLJetgR(void *p = 0);
   static void *newArray_vectorlEHHcLcLJetgR(Long_t size, void *p);
   static void delete_vectorlEHHcLcLJetgR(void *p);
   static void deleteArray_vectorlEHHcLcLJetgR(void *p);
   static void destruct_vectorlEHHcLcLJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HH::Jet>*)
   {
      vector<HH::Jet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HH::Jet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HH::Jet>", -2, "vector", 216,
                  typeid(vector<HH::Jet>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHHcLcLJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HH::Jet>) );
      instance.SetNew(&new_vectorlEHHcLcLJetgR);
      instance.SetNewArray(&newArray_vectorlEHHcLcLJetgR);
      instance.SetDelete(&delete_vectorlEHHcLcLJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHHcLcLJetgR);
      instance.SetDestructor(&destruct_vectorlEHHcLcLJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HH::Jet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HH::Jet>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHHcLcLJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HH::Jet>*)0x0)->GetClass();
      vectorlEHHcLcLJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHHcLcLJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHHcLcLJetgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::Jet> : new vector<HH::Jet>;
   }
   static void *newArray_vectorlEHHcLcLJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::Jet>[nElements] : new vector<HH::Jet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHHcLcLJetgR(void *p) {
      delete ((vector<HH::Jet>*)p);
   }
   static void deleteArray_vectorlEHHcLcLJetgR(void *p) {
      delete [] ((vector<HH::Jet>*)p);
   }
   static void destruct_vectorlEHHcLcLJetgR(void *p) {
      typedef vector<HH::Jet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HH::Jet>

namespace ROOT {
   static TClass *vectorlEHHcLcLDileptonMetDijetgR_Dictionary();
   static void vectorlEHHcLcLDileptonMetDijetgR_TClassManip(TClass*);
   static void *new_vectorlEHHcLcLDileptonMetDijetgR(void *p = 0);
   static void *newArray_vectorlEHHcLcLDileptonMetDijetgR(Long_t size, void *p);
   static void delete_vectorlEHHcLcLDileptonMetDijetgR(void *p);
   static void deleteArray_vectorlEHHcLcLDileptonMetDijetgR(void *p);
   static void destruct_vectorlEHHcLcLDileptonMetDijetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HH::DileptonMetDijet>*)
   {
      vector<HH::DileptonMetDijet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HH::DileptonMetDijet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HH::DileptonMetDijet>", -2, "vector", 216,
                  typeid(vector<HH::DileptonMetDijet>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHHcLcLDileptonMetDijetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HH::DileptonMetDijet>) );
      instance.SetNew(&new_vectorlEHHcLcLDileptonMetDijetgR);
      instance.SetNewArray(&newArray_vectorlEHHcLcLDileptonMetDijetgR);
      instance.SetDelete(&delete_vectorlEHHcLcLDileptonMetDijetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHHcLcLDileptonMetDijetgR);
      instance.SetDestructor(&destruct_vectorlEHHcLcLDileptonMetDijetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HH::DileptonMetDijet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HH::DileptonMetDijet>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHHcLcLDileptonMetDijetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HH::DileptonMetDijet>*)0x0)->GetClass();
      vectorlEHHcLcLDileptonMetDijetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHHcLcLDileptonMetDijetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHHcLcLDileptonMetDijetgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::DileptonMetDijet> : new vector<HH::DileptonMetDijet>;
   }
   static void *newArray_vectorlEHHcLcLDileptonMetDijetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HH::DileptonMetDijet>[nElements] : new vector<HH::DileptonMetDijet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHHcLcLDileptonMetDijetgR(void *p) {
      delete ((vector<HH::DileptonMetDijet>*)p);
   }
   static void deleteArray_vectorlEHHcLcLDileptonMetDijetgR(void *p) {
      delete [] ((vector<HH::DileptonMetDijet>*)p);
   }
   static void destruct_vectorlEHHcLcLDileptonMetDijetgR(void *p) {
      typedef vector<HH::DileptonMetDijet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HH::DileptonMetDijet>

namespace {
  void TriggerDictionaryInitialization_Dict_Impl() {
    static const char* headers[] = {
"include/MiniEvent.h",
"include/cp3Types.h",
0
    };
    static const char* includePaths[] = {
"./",
"/cvmfs/cp3.uclouvain.be/root/root-6.10.08-sl6_amd64_gcc72/include",
"/nfs/scratch/fynu/delcourt/phase2HH/ntupleToCP3/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{template <typename _T1, typename _T2> struct __attribute__((annotate("$clingAutoload$bits/stl_pair.h")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  DileptonMetDijet;}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  Met;}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  Jet;}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  Lepton;}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  Dilepton;}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  DileptonMet;}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  Dijet;}
namespace HH{struct __attribute__((annotate("$clingAutoload$include/cp3Types.h")))  MELAAngles;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Dict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/MiniEvent.h"
#include "include/cp3Types.h"
#pragma once

#include "include/cp3Types.h"
#include <TROOT.h>
#include <vector>
#include <map>
#include <string>
#include <utility>


#ifdef __MAKECINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;


#pragma link C++ class HH::Lepton+;
#pragma link C++ class HH::Jet+;
#pragma link C++ class HH::Met+;
#pragma link C++ class HH::DileptonMetDijet+;
#pragma link C++ class HH::DileptonMet+;
#pragma link C++ class HH::Dijet+;
#pragma link C++ class HH::MELAAngles+;
#pragma link C++ class HH::Dilepton+;
#pragma link C++ class std::pair<signed char,signed char>+;

#pragma link C++ class std::vector<HH::Lepton>+;
#pragma link C++ class std::vector<HH::Jet>+;
#pragma link C++ class std::vector<HH::Met>+;
#pragma link C++ class std::vector<HH::DileptonMetDijet>+;
#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HH::Dijet", payloadCode, "@",
"HH::Dilepton", payloadCode, "@",
"HH::DileptonMet", payloadCode, "@",
"HH::DileptonMetDijet", payloadCode, "@",
"HH::Jet", payloadCode, "@",
"HH::Lepton", payloadCode, "@",
"HH::MELAAngles", payloadCode, "@",
"HH::Met", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Dict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Dict() {
  TriggerDictionaryInitialization_Dict_Impl();
}
