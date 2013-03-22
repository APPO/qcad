


	// ***** AUTOGENERATED CODE, DO NOT EDIT *****
    
        #include "REcmaShellViewFocusListenerAdapter.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RGraphicsView.h"
            
            
        // includes for base ecma wrapper classes
        
            #include "REcmaViewFocusListener.h"
          

            #define QTSCRIPT_IS_GENERATED_FUNCTION(fun) ((fun.data().toUInt32() & 0xFFFF0000) == 0xBABE0000)
            #define QTSCRIPT_IS_FUNCTION_IN_CALL(fun) ((fun.data().toUInt32() & 0x0000F000) == 0x0000B000)

        
    // Destructor:
    REcmaShellViewFocusListenerAdapter::~REcmaShellViewFocusListenerAdapter() {}
        RViewFocusListenerAdapter* REcmaShellViewFocusListenerAdapter::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RViewFocusListenerAdapter* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RViewFocusListenerAdapter >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RViewFocusListenerAdapter.%1(): "
                        "This object is not a RViewFocusListenerAdapter").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        REcmaShellViewFocusListenerAdapter* REcmaShellViewFocusListenerAdapter::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RViewFocusListenerAdapter* selfBase = getSelf(fName, context);
                REcmaShellViewFocusListenerAdapter* self = dynamic_cast<REcmaShellViewFocusListenerAdapter*>(selfBase);
                //return REcmaHelper::scriptValueTo<REcmaShellViewFocusListenerAdapter >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RViewFocusListenerAdapter.%1(): "
                    "This object is not a RViewFocusListenerAdapter").arg(fName),
                    context);
            }

            return self;
            


        }
        
    
    
      void REcmaShellViewFocusListenerAdapter::updateFocus(
                RGraphicsView * view
            ) {
                QScriptEngine* engine = __qtscript_self.engine();
                //REcmaHelper::shellFunctionStart("REcmaShellViewFocusListenerAdapter::updateFocus", engine);
                QScriptValue _q_function = __qtscript_self.property("updateFocus");



                if (!_q_function.isFunction() || 
                    QTSCRIPT_IS_GENERATED_FUNCTION(_q_function) ||
                    QTSCRIPT_IS_FUNCTION_IN_CALL(_q_function)
                    
                    /* function might have more arguments than expected:
                    || _q_function.property("length").toInt32()!=1*/
                    /*|| (__qtscript_self.propertyFlags("atEnd") & QScriptValue::QObjectMember)*/
                    ) {
                    //QString cppSig = "RViewFocusListenerAdapter::updateFocus";
                    
                        // re-enable recursion for calls from C++ into ECMAScript functions
                        // leave it marked as generated though if appropriate:
                        
                        quint32 prev = _q_function.data().toUInt32();
                        //if (cppSig!="RGraphicsViewQt::event") {
                            _q_function.setData(QScriptValue(engine, prev & 0xFFFF0000));
                        //}
                        RViewFocusListenerAdapter::updateFocus(
                            view
                        );

                        // block recursion again:
                        _q_function.setData(QScriptValue(engine, prev));

                        //REcmaHelper::shellFunctionEnd("REcmaShellViewFocusListenerAdapter::updateFocus", engine);

                        
                } else {
                    // prevent recursion if script implementation calls base implementation
                    // mark function as 'in call':
                    quint32 prev = _q_function.data().toUInt32();
                    _q_function.setData(QScriptValue(engine, uint(prev | 0x0000B000)));
                    
                            _q_function.call(__qtscript_self,
                                QScriptValueList()
                                



    // type: RGraphicsView *, copyable: false
        << qScriptValueFromValue(engine, 

        view
        )
      
                            )
                        
                    ;
                    _q_function.setData(QScriptValue(engine, prev));

                    //REcmaHelper::shellFunctionEnd("REcmaShellViewFocusListenerAdapter::updateFocus", engine);

                    
                }
            }
        
    
  
        // methods of 1st level base class RViewFocusListener:
        

    // protected methods (only available for ECMA shell classes) (generated by xsl2xpp.xsl):
	